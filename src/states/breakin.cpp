#include "breakin.h"
#include <QDebug>


BreakIn::BreakIn(QObject *parent) : State(parent)
{
    name = "Break In";
    description = "This state starts the break in process.  It uses a varied set of algorithms chosen by the user\
and repeats until the break in is successful or the cell is lost.";
    ptrResDataReady = NULL;
    attempt = 0;
    zapAttempt = 0;
    zapTimes << 0.000025 << 0.000050 << 0.0001 << 0.0002 << 0.0005 << 0.001;
    timer1.setSingleShot(true);
    timer1.setInterval(4000);
    connect(&timer1, SIGNAL(timeout()), this, SLOT(timer1_timeout()), Qt::QueuedConnection);
}

BreakIn::~BreakIn()
{

}


void BreakIn::pauseState(bool) // 1 tells the state to pause, 0 to continue
{

}

void BreakIn::haltState()
{

}

void BreakIn::zap()
{

}



// **************** PROCEDURAL CODE START *******************
// Code in this section should be very sequential and each
// method should be called after the previous.  This is the
// algorithmic portion of this state.
void BreakIn::firstRun()
{
    emit autopatcher_switchPressure(AutopatcherWorker::PRESSURE_ATM, 0);
    emit scara_powerDown();
    emit gui_setCurrentPageIndex("page_autopatching");
    emit daq_stopTask();
    emit gui_clearRawDataPlot();
    emit gui_clearResistancePlot();
    emit autopatcher_switchBNC(1, 0);
    int breakInSwitch = data.breakInType;
    data.rheobaseFound = 0;  // If we're messing with the membrane, then the injected current required to elicit spikes will change.

    switch (breakInSwitch) // This should probably be broken into 4 different states
    {
        case 0:     // Zap
            data.LOG_breakInType.push_back(0);
            data.LOG_breakInTime.push_back(QTime::currentTime());
            ptrResDataReady = &daq_resDataReadyAlg0;
            emit daq_initTask(DAQWorker::TASKTYPE_RESISTANCE_CHECK);
            emit daq_startTask();
            emit daq_trigger();
            alg0Counter = 0;
            break;
        case 1:     // Suction Pulse
            data.LOG_breakInType.push_back(1);
            data.LOG_breakInTime.push_back(QTime::currentTime());
            ptrResDataReady = &daq_resDataReadyAlg1;
            emit daq_initTask(DAQWorker::TASKTYPE_RESISTANCE_CHECK);
            emit daq_startTask();
            emit daq_trigger();
            break;
        case 2:     // Suction Ramp
            data.LOG_breakInType.push_back(2);
            data.LOG_breakInTime.push_back(QTime::currentTime());
            ptrResDataReady = &daq_resDataReadyAlg2;
            emit daq_initTask(DAQWorker::TASKTYPE_RESISTANCE_CHECK);
            emit daq_startTask();
            emit daq_trigger();
            break;
        case 3:     // Suction Ramp With Feedback
            data.LOG_breakInType.push_back(3);
            data.LOG_breakInTime.push_back(QTime::currentTime());

            ptrResDataReady = &daq_resDataReadyAlg3;
            emit daq_initTask(DAQWorker::TASKTYPE_BREAK_IN_LOOP);

            data.LOG_breakInResVals.clear();
            data.LOG_breakInResTime.clear();
            average = 0;
            sampNum = 0;
            emit multiclamp_selectChannel(data.headstageNum);
            emit multiclamp_setMode(MCCMSG_MODE_VCLAMP);
            emit multiclamp_setHoldingVChecked(true);
            emit multiclamp_autoSlowCapacitance();
            emit multiclamp_autoFastCapacitance();
            emit multiclamp_getPipetteCapacitanceCompensation();
            break;
    }
}

void BreakIn::multiclamp_pipetteCapacitanceCompensationValue(double val)
{
    qWarning() << "Pipette capacitance compensation value: " << val << " pF";
    data.pipetteCapacitance = val;
    emit multiclamp_setHoldingVSafe(-0.065, true);
}

// BE CAREFUL WITH THE CODE BELOW.  MAKE SURE THE SLOTS FROM THE WORKERS DON'T CROSS BETWEEN ALGORITHMS
void BreakIn::daq_initTaskReady()  // This is common to algorithms 0-2
{

}

void BreakIn::daq_initTaskError()
{
    zapAttempt = 0;
    attempt = 0;
    decision = 0;  // Error state
    emit stateFinished();
}

// **************************************
//   BREAK IN ALGORITHM 0: ZAP
// **************************************
void BreakIn::daq_resDataReadyAlg0(double res)
{
    data.LOG_breakInResVals.push_back(res);
    data.LOG_breakInResTime.push_back(QTime::currentTime());
    alg0Counter++;

    if (alg0Counter > 3)
    {
        alg0Counter = 0;

        // Averaging a few resistance values
        double ave(0);
        for (int i = 0; i < 3; i++)
        {
            ave += data.LOG_breakInResVals[data.LOG_breakInResVals.length() - i];
        }
        ave = ave / 3.0;

        // Checking the resistance and zapping if necessary
        if (ave > 350)
        {
            emit multiclamp_zap(zapTimes[zapAttempt]);
            QThread::sleep(1);
            zapAttempt++;
            if (zapAttempt >= zapTimes.length()) // Couldn't break in with zap.  Starting over with the original break in type
            {
                // Change code here to exit break in state and go to some manual break in state (doesn't exist yet)
                qWarning() << "Couldn't break in with zap.  Retrying algorithm.";
                zapAttempt = 0;
                attempt = 0;
                firstRun();
            }
            else
            {
                emit daq_trigger();
            }
        }
        else // Proceed to cell QC
        {
            emit daq_stopTask();
            ptrResDataReady = NULL;
            int n = data.LOG_breakInResVals.length();
            qWarning() << "Resistance dropped!" << res << data.LOG_breakInResVals[n - 1] << data.LOG_breakInResVals[n - 2] << "MOhms";
            zapAttempt = 0;
            attempt = 0;
            finish();
        }
    }
    else
    {
        emit daq_trigger();
    }

}

// **************************************
//   BREAK IN ALGORITHM 1: SUCTION PULSE
// **************************************
void BreakIn::daq_resDataReadyAlg1(double)  // double is resistance value
{

}

// **************************************
//   BREAK IN ALGORITHM 2: SUCTION RAMP
// **************************************
void BreakIn::daq_resDataReadyAlg2(double)  // double is resistance value
{

}

// **************************************
//   BREAK IN ALGORITHM 3: FEEDBACK RAMP
// **************************************
void BreakIn::multiclamp_setHoldingVoltageSafeComplete()
{
    // emit multiclamp_getFastCapacitanceValue();
    emit daq_startTask();
}

void BreakIn::daq_resDataReadyAlg3(double res)
{
    if (res < 350)
    {
        emit autopatcher_stopRamp();  // Change this to direct connection?
        emit daq_stopTask();
        sampNum = 0;
        ptrResDataReady = NULL;
        int n = data.LOG_breakInResVals.length();
        qWarning() << "Resistance dropped!" << res << data.LOG_breakInResVals[n - 1] << data.LOG_breakInResVals[n - 2];
    }
    if (sampNum == 150) { // Acquiring 1.5 seconds worth of data before starting the pressure ramp.  The break in sqr wave is 100 Hz
        emit autopatcher_breakInRampFeedback(data.breakInFeedbackRampTime);

        switch (attempt) // Add a zap to make sure it breaks in when it doesn't work the first time.
        {
            case 2:
                qWarning() << "Zapping with delay!" ;
                emit multiclamp_zapWithDelay(0.000025, round(data.breakInFeedbackRampTime * 0.5)); // 25 us, Zap about 50% of the way into the suction ramp.
                break;
            case 3:
                qWarning() << "Zapping with delay!" ;
                emit multiclamp_zapWithDelay(0.000050, round(data.breakInFeedbackRampTime * 0.5)); // 50 us, Zap about 50% of the way into the suction ramp.
                break;
            case 4:
                qWarning() << "Zapping with delay!" ;
                emit multiclamp_zapWithDelay(0.000100, round(data.breakInFeedbackRampTime * 0.5)); // 100 us, Zap about 50% of the way into the suction ramp.
                break;
            default:
                // no zap on first try or after the 4th try.  4 tries is too many.
                break;
        }
    }

    data.LOG_breakInResVals.push_back(res);
    data.LOG_breakInResTime.push_back(QTime::currentTime());
    sampNum++;
    average++;
    if (average == 7)
    {
        double ave(0);
        for (int i = 0; i < 7; i++)
        {
            ave += data.LOG_breakInResVals[data.LOG_breakInResVals.length() - 8 + i];
        }
        // Since the states are in the GUI thread, plotting these points may
        // slow down this fast feedback resistance measurement loop.  Plotting
        // a single point is pretty fast though.  Raw data plotting should be
        // disabled for sure.
        emit gui_plotResData(ave / 7);
        average = 0;
    }
}

void BreakIn::autopatcher_breakInRampFinished()
{
    qWarning() << "Ramp break in finished.";
    emit daq_stopTask();
    // Break in failed (this should double check a little better although this is done in cellQC)
    qWarning() << "TEST OUTPUT FOR BREAK IN RAMP FINISHED: " << (data.LOG_breakInResVals[data.LOG_breakInResVals.length() - 1] >= 350) << data.LOG_breakInResVals[data.LOG_breakInResVals.length() - 1] << data.LOG_breakInResVals.length() - 1 << data.LOG_breakInResVals.length();
    if (data.LOG_breakInResVals[data.LOG_breakInResVals.length() - 1] >= 350)
    {
        qWarning() << "Break in attempt failed: " << attempt;
        attempt++;
        timer1.start();
    }
    else  // Successful break in
    {
        qWarning() << "Break in attempt succeeded " << attempt;
        zapAttempt = 0;
        attempt = 0;
        finish();
    }
}

void BreakIn::timer1_timeout()
{
    firstRun();  // This case could be a little more sophisticated but for now, this should work.
}

void BreakIn::finish()
{
    data.restingVoltageStateDecision = 1;  // the resting membrane voltage measurement state will go on to the quick action potential detection state afterward.
    data.quickAPDetectStateDecision = 1;  // the quick action potential detection state should go on to the wait and set vars state
    // Should this kind of logic be broken out into it's own state?  That would make it a lot more visible in the logic
    // flow code.  For now, we'll leave it here.  It should be moved later to make it more obvious.
    data.visualStimCounter = 0;             // Just in case we had to break in again, we want to re-run the visual stimulation from the beginning since the cell
    // has probably changed.
    data.prelimRheobase = 0;                // Just to make sure it's empty.
    data.prelimRheobaseSet = false;         // There can't be a rheobase estimate yet on this cell, we just broke into it.
    decision = 1;  // Going on to vc_membraneTest state
    emit stateFinished();
}
