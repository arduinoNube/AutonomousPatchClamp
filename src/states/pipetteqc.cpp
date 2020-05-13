#include "pipetteqc.h"
#include "AxMultiClampMsg.h"
#include <QDebug>
#include <workers/daqworker.h>
/* The PipetteQC class enumerates the steps required to evaulate the quality of the
 * pipette initially.  It checks to make sure the pipette is in the right resistance
 * range, and whether there is a DC drift or unstable resistance values.  It also
 * djusts the pipette offset to prepare the amplifier for autopatching
 *
 * This state assumes the following pre-conditions:
 * 1. The pipette is 20-50 microns above the surface of the brain
 * 2. The pipette tip is submerged in ACSF and electrically connected to the reference ground.
 * 3. The amplifier is connected and initialized and the current multiclamp is selected
 *
 * Algorithm steps
 * 1. Switch to High Pressure (should have been at high pressure from previous state so this
 *    is just in case)
 * 2. Initialize the DAQ tasks
 * 3. Auto correct pipette offset and set holding to 0V.
 * 4. Start the raw data acquisition
 * 5. Start the resistance measurement
 * 6. Record numAve resistance measurements and do QC.  (looping callback)
 * 7. If the resistance looks good, lower the pipette into the brain and finish
 *    with status 1 (switch to clog check state). If not, finish with status 2 (retract)
 *
 *
 * ***** Used Interface Signals *****
 * multiclamp_autoPipetteOffset();
 * multiclamp_setHoldingV(int);
 * multiclamp_holdingVChecked(bool);
 *
 * daq_initRawAcquire();
 * daq_startRawAcquire();
 * daq_initResCheck();
 * daq_triggerRes();
 *
 * thorLabsMotor_moveByRelative(float dist, float vel);
 * ************  END  ****************
 *
 *
 * NOTE: the current implementation only uses relative position values so the brain height
 * offset and current position need to be handled elsewhere.  This state will emit position
 * changed signals to update an accurate absolute position variable elsewhere.
 */

PipetteQC::PipetteQC(QObject *parent) : State(parent)
{
    headstageNum = 1;
    //headstageNum = 2;
    numAve = 20;
    numResVals = 0;

    name        = "Pipette Quality Checks";
    description = "This state checks the resistance of the pipette to make sure it is between \
3 and 9 MOhms and that the maximum difference between any 2 of the 20 measurements is less than \
350 KOhms.";
    ptrMulticlampFinished = NULL;
    timer1.setSingleShot(true);
    timer1.setInterval(1000);
}

PipetteQC::~PipetteQC()
{
}

bool PipetteQC::checkResVals()
{
    double ave(0);
    for(int i=0; i<resVals.size(); i++)
    {
        ave = ave + resVals[i];
    }
    ave = ave/resVals.size();
    data.LOG_resAveAboveBrain = ave;

    // If the resistance is outside the range
    if(ave < data.minR || ave > data.maxR)
    {
        qWarning() << "Pipette outside the valid resistance range: R=" << ave;
        return 1; // problem with pipette
    }
    // If the resistance has too much variation
    double min(99999), max(-99999);
    for(int i=0; i<resVals.size(); i++)
    {
        if(resVals[i] < min) min = resVals[i];
    }
    for(int i=0; i<resVals.size(); i++)
    {
        if(resVals[i] > max) max = resVals[i];
    }
    data.LOG_resVarAboveBrain = max-min;
    if(max-min > data.maxVar)
    {
        qWarning() << "Too much variation in the pipette resistance: Var=" << data.maxVar;
        return 1; // problem with pipette
    }

    return 0;   // pipette ok!
}

void PipetteQC::pauseState(bool) // 1 tells the state to pause, 0 to continue
{

}

void PipetteQC::haltState()
{

}
// **************** PROCEDURAL CODE START *******************
// Code in this section should be very sequential and each
// method should be called after the previous.  This is the
// algorithmic portion of this state.
void PipetteQC::firstRun()
{
    decision = 0;
    ptrMulticlampFinished = NULL;
    resVals.clear();
    data.LOG_trialStartDateTime = QDateTime::currentDateTime();
    data.trialSaved = false;
    emit gui_busy_start("Performing pipette quality checks.");
    emit gui_setCurrentPageIndex("page_autopatching");
    emit daq_stopTask();
    emit daq_initTask(DAQWorker::TASKTYPE_RESISTANCE_CHECK);
    data.trialNum++;
    emit gui_incrementTrialNumber();
    qWarning() << "Trial " << data.trialNum << " started.";
    emit autopatcher_switchBNC(1,0);

    disconnect(&timer1,SIGNAL(timeout()),this,SLOT(finish()));
    connect(&timer1,SIGNAL(timeout()),this,SLOT(finish()),Qt::QueuedConnection);
}

void PipetteQC::daq_initTaskReady()
{
    emit daq_startTask();
    emit multiclamp_selectChannel(data.headstageNum);
    emit multiclamp_setMode(MCCMSG_MODE_VCLAMP);
    emit multiclamp_setHoldingVSafe(0,false);
    emit multiclamp_setHoldingVChecked(true);
    emit multiclamp_leakSubtractionChecked(false);
    ptrMulticlampFinished = &A;
    emit multiclamp_autoPipetteOffset();
}

void PipetteQC::daq_initTaskError()
{
    decision = 0;  // Error state
    emit stateFinished();
}

void PipetteQC::A()
{
    ptrMulticlampFinished = NULL;
    emit gui_busy_start("Acquiring " + QString::number(numAve) + " resistance measurements.");
    emit daq_trigger(); // trigger a resistance measurement
}

void PipetteQC::daq_resDataReady(double res)
{
    emit gui_plotResData(res);
    // Collecting resistance measurements
    data.LOG_pipetteCheckResVals.push_back(res);
    data.LOG_pipetteCheckResTime.push_back(QTime::currentTime());
    resVals.push_back(res);

    // Initial quick check.
    if(resVals.size() == 3)
    {
        if(checkResVals())  // If bad pipette
        {
            emit daq_stopTask();
            decision = 2;   // retract state
            emit stateFinished();
            return;
        }
    }

    // numAve slow check.
    if(resVals.size() < numAve)
    {
        QTime profile;
        emit daq_trigger();  // Start another resistance check
        //qWarning() << "Trigger time: " << profile.currentTime().second() << profile.currentTime().msec();
    }
    else
    {        
        if(checkResVals())  // If bad pipette
        {
            emit daq_stopTask();  // hope that this get's sent before this state get's disconnected.
            decision = 2;   // retract state
            emit stateFinished();
        }
        else  // Good pipette
        {
            ptrMulticlampFinished = &B;
            emit multiclamp_autoPipetteOffset();
        }
    }
}

void PipetteQC::B()
{
    ptrMulticlampFinished = NULL;
    decision = 1;   // go onward to clog check state
    emit gui_busy_start("The pipette passed the quality checks.  Descending to the \"Start Depth\".");
    thorLabsMotor_moveByRelative(-data.startDepth/1000.0,2);
}

void PipetteQC::thorLabsMotor_moveComplete()
{
    timer1.start();
}

void PipetteQC::finish()
{
    // The DAQ tasks are still running so the subsequent state needs to be prepared for that.
    emit stateFinished();
}

