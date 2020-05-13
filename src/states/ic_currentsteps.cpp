#include "ic_currentsteps.h"

IC_CurrentSteps::IC_CurrentSteps(QObject *parent) : State(parent)
{
    name = "Current Injection";
    description = "This state injects current steps to record the intrinsic parameters of the cell. \
It uses the rheobase value and injects current between -1/2*rheobase/2 to 1.5*rheobase in steps of 20 pA.";
    currentInjectionAmplitude = 0;
    timer1.setSingleShot(true);
    timer1.setInterval(2000);
    connect(&timer1,SIGNAL(timeout()),this,SLOT(timer1_timeout()),Qt::QueuedConnection);
    numSteps = 20; // pA

}

IC_CurrentSteps::~IC_CurrentSteps()
{

}

void IC_CurrentSteps::pauseState(bool) // Toggled
{

}

void IC_CurrentSteps::haltState()
{

}

// **************** PROCEDURAL CODE START *******************
// Code in this section should be very sequential and each
// method should be called after the previous.  This is the
// algorithmic portion of this state.
void IC_CurrentSteps::firstRun()
{
    // Switching to current clamp
    emit multiclamp_selectChannel(data.headstageNum);
    emit multiclamp_setMode(MCCMSG_MODE_ICLAMP);
    emit multiclamp_setHoldingIChecked(false);
    qWarning() << "Pipette Capacitance Compensation Value: " << data.pipetteCapacitance;
    emit multiclamp_setPipetteCapacitanceCompensation(data.pipetteCapacitance*data.capacitancePercentCompensation);
    emit multiclamp_enablePipetteCapacitanceCompensation(true);
    //emit multiclamp_autoBridgeBalance();
    //emit multiclamp_injectSlowCurrentEnable(false);
    //emit multiclamp_injectSlowCurrentSetVoltage(-0.065);
    //emit multiclamp_injectSlowCurrentSetTimeConstant(5);
    //emit multiclamp_injectSlowCurrentEnable(true);
    //qWarning() << "Holding current: " << data.LOG_holdingCurrent65 << "pA" << data.LOG_holdingCurrent65*pow(10,-12);

    // Enable the next line and disable the following to automatically set the holding current so the resting membrane potential is -65mV
    //emit multiclamp_setHoldingISafe(data.LOG_holdingCurrent65*pow(10,-12),true);
    emit multiclamp_setHoldingISafe(0,true);
    emit multiclamp_setHoldingIChecked(true);
}

void IC_CurrentSteps::multiclamp_setHoldingCurrentSafeComplete()
{
    emit gui_setCurrentPageIndex("page_autopatching");
    qWarning() << "Paused";
    QThread::sleep(5);
    qWarning() << "Going!";
    emit daq_initTask(DAQWorker::TASKTYPE_CURRENT_INJECTION);  // Logging raw data to measure resting potential and action potential amplitude
}
void IC_CurrentSteps::daq_initTaskReady()
{
    maxCurrent =  data.LOG_rheobase*1.5; // *2 was TOO MUCH!!! It was destroying seals and killing cells.
    minCurrent = -data.LOG_rheobase*0.5;
    loopCount = 1;
    nRepeats = 0;

    emit daq_setCurrentInjAmplitude(minCurrent);
    emit daq_startTask();
    emit daq_trigger();
}

void IC_CurrentSteps::daq_initTaskError()
{

    emit gui_busy_stop("DAQ Error!");
    qWarning() << "DAQ Error! in " << name << " state!";
    decision = 0;
    emit stateFinished();}


void IC_CurrentSteps::daq_currInjDataReady(QVector<double>) // Don't really care what the raw data looks like, just that the current was injected.
{
    currentInjectionAmplitude = minCurrent + (maxCurrent-minCurrent)*loopCount*1.0/numSteps;
    loopCount++;
    if(currentInjectionAmplitude >= maxCurrent)
    {
        nRepeats++;
        loopCount = 1;
        currentInjectionAmplitude = minCurrent;
        if(nRepeats == data.numCurrentStepRepeats)
        {
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


void IC_CurrentSteps::timer1_timeout()
{
    emit daq_setCurrentInjAmplitude(currentInjectionAmplitude);
    emit daq_trigger();
}
