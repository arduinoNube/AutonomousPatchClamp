#include "ic_bacfiring.h"

IC_BACFiring::IC_BACFiring(QObject *parent) : State(parent)
{
    name = "BAC Firing Induced by Current Injection";
    description = "This state injects 3 current pulses at a time to induce calcium currents in the dendritic tufts of neurons.  \
it sweeps the frequency of the pulses (50 to 200 Hz) to find the critical frequency at which the dendritic spikes become \
significant.";
    // The point here is to find the critical frequency of the cell.  To do so, we'll inject a current pulse train:
    // 2 ms pulse
    // 50 Hz to 200 Hz with a 10 Hz step size
    // 3 pulses total
    // how big?

    bacFrequencyMax = 200; // Hz
    bacFrequencyMin = 50;  // Hz
    bacFrequencyStepSize = 10; // Hz
    timer1.setInterval(1500);
    timer1.setSingleShot(true);
    connect(&timer1,SIGNAL(timeout()),this,SLOT(timer1_timeout()),Qt::QueuedConnection);
}

IC_BACFiring::~IC_BACFiring()
{

}

void IC_BACFiring::pauseState(bool) // Toggled
{

}

void IC_BACFiring::haltState()
{

}

// **************** PROCEDURAL CODE START *******************
// Code in this section should be very sequential and each
// method should be called after the previous.  This is the
// algorithmic portion of this state.
void IC_BACFiring::firstRun()
{
    // Switching to current clamp
    emit multiclamp_selectChannel(data.headstageNum);
    emit multiclamp_setMode(MCCMSG_MODE_ICLAMP);
    emit multiclamp_setHoldingIChecked(false);
    qWarning() << "Pipette Capacitance Compensation Value: " << data.pipetteCapacitance;
    emit multiclamp_setPipetteCapacitanceCompensation(data.pipetteCapacitance*data.capacitancePercentCompensation);
    emit multiclamp_enablePipetteCapacitanceCompensation(false);
    //emit multiclamp_autoBridgeBalance();
    //emit multiclamp_injectSlowCurrentEnable(false);
    //emit multiclamp_injectSlowCurrentSetVoltage(-0.065);
    //emit multiclamp_injectSlowCurrentSetTimeConstant(5);
    //emit multiclamp_injectSlowCurrentEnable(true);
    //qWarning() << "Holding current: " << data.LOG_holdingCurrent65 << "pA" << data.LOG_holdingCurrent65*pow(10,-12);

    // Enable the next line and disable the following to automatically set the holding current so the resting membrane potential is -65mV
    //emit multiclamp_setHoldingISafe(data.LOG_holdingCurrent65*pow(10,-12),true);
    emit multiclamp_setHoldingISafe(0,true);  // MUST HAVE THIS TO CONTINUE THE PROCEDURAL CODE
    emit multiclamp_setHoldingIChecked(true);
    emit autopatcher_switchBNC(1,0);  // Enabling autopatcher control

}

void IC_BACFiring::multiclamp_setHoldingCurrentSafeComplete()
{
    emit gui_setCurrentPageIndex("page_autopatching");
    qWarning() << "Paused";
    QThread::sleep(5);
    qWarning() << "Going!";
    emit daq_initTask(DAQWorker::TASKTYPE_BAC_CURRENT_INJECTION);  // Logging raw data to measure resting potential and action potential amplitude
}
void IC_BACFiring::daq_initTaskReady()
{
    loopCount = 1;
    nRepeats = 0;
    freq = 0; // Hz

    if(data.numBACCurrentInjRepeats > 0)
    {
        emit daq_startTask();
        freq = bacFrequencyMin;
        timer1_timeout();
    }
    else
    {
        decision = 1;
        emit stateFinished();
    }
}

void IC_BACFiring::daq_initTaskError()
{
    emit gui_busy_stop("DAQ Error!");
    qWarning() << "DAQ Error! in " << name << " state!";
    decision = 0;
    emit stateFinished();
}

void IC_BACFiring::daq_bacCurrInjDataReady(QVector<double>) // I don't really care what the raw data looks like, just that the current was injected.
{
    freq = bacFrequencyMin +  loopCount*1.0*bacFrequencyStepSize;

    loopCount++;
    if(freq > bacFrequencyMax)
    {
        nRepeats++;
        loopCount = 1;
        freq = bacFrequencyMin;

        if(nRepeats == data.numBACCurrentInjRepeats)
        {
            emit multiclamp_enablePipetteCapacitanceCompensation(false);

            decision = 1;
            emit stateFinished();
        }
        else
        {
            timer1.start();
        }
    }
    else
    {
        timer1.start();
    }
}

void IC_BACFiring::timer1_timeout()
{
    qWarning() << "BAC Firing Test: " << freq << " Hz. ";
    if(data.rheobaseFound == 1)
    {
        emit daq_setBACCurrentInjAmplitude(data.LOG_rheobase*10);  // 1 nA according to the Larkum 1999 paper, I found it to be too much for some cells 500 pA wasn't enough for other cells.  10x the rheobase seemed to work on one cell.  I'll keep trying that.
    }
    else
    {
        emit daq_setBACCurrentInjAmplitude(500);
    }
    emit daq_setBACCurrentInjFrequency(freq);
    emit daq_trigger();
}
