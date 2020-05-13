#include "ic_measurerheobase.h"

IC_MeasureRheobase::IC_MeasureRheobase(QObject *parent) : State(parent)
{
    name = "Rheobase Measurement";
    description = "This state measures the rheobase of a cell by injecing current starting at 0 pA (or starting at \
50% of the preliminary rheobase value if found previously) and increasing by 20 pA for each step.  Once spikes are \
found on three consecutive current injections with the same amount of injected current, we call that the rheobase. \
Index 0 is the \"Error State\", Index 1 is the \"Rheobase Found\" decision, and Index 2 is the \"Bad Cell\" decision \
where the average voltage during the current injection was above -20 mV and the cell didn't spike up to this point with \
all the current injections.";
    timer1.setSingleShot(true);
    timer1.setInterval(2000);
    connect(&timer1,SIGNAL(timeout()),this,SLOT(timer1_timeout()),Qt::QueuedConnection);
}

IC_MeasureRheobase::~IC_MeasureRheobase()
{

}

void IC_MeasureRheobase::pauseState(bool) // Toggled
{

}

void IC_MeasureRheobase::haltState()
{

}

void IC_MeasureRheobase::setHardwareVals(HardwareSettingsWindow * hw_win)
{
    samplingRate = hw_win->daqSampRate;
}

// **************** PROCEDURAL CODE START *******************
// Code in this section should be very sequential and each
// method should be called after the previous.  This is the
// algorithmic portion of this state.
void IC_MeasureRheobase::firstRun()
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
    emit multiclamp_setHoldingISafe(0*pow(10,-12),true);
    emit multiclamp_setHoldingIChecked(true);
    logicFlag = 0;
}

void IC_MeasureRheobase::multiclamp_setHoldingCurrentSafeComplete()
{
    emit gui_setCurrentPageIndex("page_autopatching");
    qWarning() << "Paused";
    QThread::sleep(5);
    qWarning() << "Going!";
    emit daq_initTask(DAQWorker::TASKTYPE_CURRENT_INJECTION);  // Logging raw data to measure resting potential and action potential amplitude
}
void IC_MeasureRheobase::daq_initTaskReady()
{
    if(data.prelimRheobaseSet)
    {
        currentInjectionAmplitude = data.prelimRheobase*0.5;
        emit daq_setCurrentInjAmplitude(currentInjectionAmplitude);
    }
    else
    {
        currentInjectionAmplitude = 0;
        emit daq_setCurrentInjAmplitude(0);
    }

    emit daq_startTask();
    emit daq_trigger();
}


void IC_MeasureRheobase::daq_initTaskError()
{
    emit gui_busy_stop("DAQ Error!");
    qWarning() << "DAQ Error! in " << name << " state!";
    decision = 0;
    emit stateFinished();
}


void IC_MeasureRheobase::daq_currInjDataReady(QVector<double> injData)
{
    // Nuclear exit if the cell is lost or won't spike.
    double mean = 0;
    for(int i=0; i<injData.size(); i++)
    {
        mean += injData[i];
    }
    mean = mean/injData.size();

    if(mean > -0.02)  // if the resting voltage is > -20 mV. exit
    {
        emit gui_busy_start("The average voltage during the current injection was greater than -20 mV.  Poor quality cell, exiting.");
        qWarning() << "The average voltage during the current injection was greater than -20mV.  Poor quality cell, exiting.";
        decision = 2; // Bad Cell
        emit stateFinished();
    }

    // Finding the rheobase
    // 1. Check for and count action potentials.
    // 2. Check to see if there are action potentials every time
    // this amount of current is injected.
    if(countActionPotentials(injData,data,samplingRate) > 0)
    {
        // Injecting the same amount of current to see if it spikes every time
        qWarning() << "Action potential found at " << currentInjectionAmplitude << " pA.";
        logicFlag++;

        if(logicFlag == 3)  // It passed the three trials.  It spiked during every injection.
        {
            data.LOG_rheobase = currentInjectionAmplitude;
            data.rheobaseFound = true;
            qWarning() << "All three current injections caused action potentials.  Continuing to the next state.";
            data.restingVoltageStateDecision = 1;
            decision = 1;
            emit stateFinished();

        }
        else // Don't have 3 consecutive current injections with spikes yet, injecting the same amout of current and trying again.
        {
            timer1.start();
        }
    }
    else // No spikes so increasing the injection current and try again
    {
        logicFlag = 0;  // didn't spike so reset to zero
        currentInjectionAmplitude += 20;
        timer1.start();
    }

}

void IC_MeasureRheobase::timer1_timeout()
{
    emit daq_setCurrentInjAmplitude(currentInjectionAmplitude);  // Get an initial baseline current
    emit daq_trigger();
}
