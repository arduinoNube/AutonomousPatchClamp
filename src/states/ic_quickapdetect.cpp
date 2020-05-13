#include "ic_quickapdetect.h"

// There is some code duplication between this class and the IC_MeasureRheobase class.  The resting membrane voltage code is the same
// but is duplicated in both places.  Do we subclass it into an IC_GeneralState class or do we create a stand alone state called
// RestingMembraneVoltageMeasurement?l
IC_QuickAPDetect::IC_QuickAPDetect(QObject *parent) : State(parent)
{
    timer1.setSingleShot(true);
    timer1.setInterval(2000);
    connect(&timer1,SIGNAL(timeout()),this,SLOT(timer1_timeout()),Qt::QueuedConnection);
    name = "Quick Action Potential Detection";
    description = "This state will inject current starting at zero and increasing by 20 pA each time until \
spikes are elicited from the cell.  If there are no spikes and the average voltage during a \
current injection is greater than -20 mV, the algorithm assumes the recording is of poor quality and it use \
Index 3.  If the ";
}

IC_QuickAPDetect::~IC_QuickAPDetect()
{

}

void IC_QuickAPDetect::pauseState(bool)
{

}

void IC_QuickAPDetect::haltState()
{

}

void IC_QuickAPDetect::setHardwareVals(HardwareSettingsWindow * hw_win)
{
    samplingRate = hw_win->daqSampRate;
}





// **************** PROCEDURAL CODE START *******************
// Code in this section should be very sequential and each
// method should be called after the previous.  This is the
// algorithmic portion of this state.
void IC_QuickAPDetect::firstRun()
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
}

void IC_QuickAPDetect::multiclamp_setHoldingCurrentSafeComplete()
{
    emit gui_setCurrentPageIndex("page_autopatching");
    qWarning() << "Paused";
    QThread::sleep(5);
    emit daq_initTask(DAQWorker::TASKTYPE_CURRENT_INJECTION);  // Logging raw data to measure resting potential and action potential amplitude
}
void IC_QuickAPDetect::daq_initTaskReady()
{
    if(data.rheobaseFound)
    {
        qWarning() << "Quick detect: Rheobase Found";
        currentInjectionAmplitude = data.LOG_rheobase*1.1;
        emit daq_setCurrentInjAmplitude(data.LOG_rheobase);
    }
    else if(data.prelimRheobaseSet)
    {
        qWarning() << "Quick detect: Preliminary Rheobase";
        currentInjectionAmplitude = data.prelimRheobase*1.1;
        emit daq_setCurrentInjAmplitude(data.prelimRheobase);
    }
    else
    {
        qWarning() << "Quick detect: Start at zero";
        currentInjectionAmplitude = 0;
        emit daq_setCurrentInjAmplitude(0);
    }

    enabled = 1;
    emit daq_startTask();
    emit daq_trigger();
    qWarning() << "Going!";
}

void IC_QuickAPDetect::daq_initTaskError()
{
    emit gui_busy_stop("DAQ Error!");
    qWarning() << "DAQ Error! in " << name << " state!";
    decision = 0;
    emit stateFinished();
}

void IC_QuickAPDetect::daq_currInjDataReady(QVector<double> injData)
{
    if(enabled)
    {
    // Nuclear exit if the cell is lost.
    double mean = 0;
    for(int i=0; i<injData.size(); i++)
    {
        mean += injData[i];
    }
    mean = mean/injData.size();

    qWarning() << "Number of APs: " << countActionPotentials(injData,data,samplingRate)<< " Average Resting Voltage: " << mean*1000  << " mV.  " << data.quickAPDetectStateDecision ;
    if(mean > -0.02)  // if the resting voltage is > -20 mV. exit
    {
        emit gui_busy_start("The average voltage during the current injection was greater than -20mV.  Poor quality cell, exiting.");
        qWarning() << "The average voltage during the current injection was greater than -20mV.  Poor quality cell, exiting.";
        decision = 3; // retract pipette
        enabled = 0;
        emit stateFinished();
        return;
    }

    if(countActionPotentials(injData,data,samplingRate) > 0)  // Action potentials detected, going on to next state
    {
        // *******************************************************************************************
        // IF YOU INSERT THIS STATE IN OTHER PLACES IN THE LOGICAL FLOW BE SURE TO EDIT THIS SECTION!
        // *******************************************************************************************

        switch(data.quickAPDetectStateDecision)
        {
        case 1:  // This is the first time this state has run since break in.  Going on to the wait state

            if(data.restingVoltagePassed && data.membraneTestPassed)
            {
                qWarning() << "Going on to wait state...";
                data.prelimRheobase = currentInjectionAmplitude;
                data.prelimRheobaseSet = true;
                decision = 1;
                enabled = 0;
                emit stateFinished();
                return;
            }
            else
            {
                qWarning() << "Didn't pass a QC check... retracting";
                decision = 3;
                enabled = 0;
                emit stateFinished();
                return;
            }

            break;

        case 2: // The wait state has been run (it sets the flag to 2), as well as part of the first visual stimulation, now
                // it should continue with the visual stimulations until enough of them have been recorded.

            if(data.visualStimCounter == data.numVisualStims)  // both visual stimulations have been run by this point, we are now finished with this cell
            {
                qWarning() << "Visual stimulations complete (" << data.numVisualStims << " runs).";
                emit gui_busy_start("All the visual stimulations and cell QC checks are complete.  Retracting the pipette.");
                decision = 3;
            }
            else if(data.membraneTestPassed == 0 || data.restingVoltagePassed == 0)  // If more visual stimulations need to be run but the quality is bad, retract
            {
                qWarning() << "Cell quality was poor.  Retracting pipette.";
                emit gui_busy_start("Cell quality was poor.  Retracting pipette.");
                decision = 3;
            }
            else // If the quality is good and we need to run more visual stimulations, return to visual stim.
            {
                qWarning() << "Cell passed QC checks, returning to visual stimulation.";
                emit gui_busy_start("Cell quality is still good, returning to visual stimulation state.");
                decision = 2;
            }
            enabled = 0;
            emit stateFinished();
            return;
            break;

        default:
            emit gui_busy_stop("Problem with quickAPDetectState " + QString::number(data.quickAPDetectStateDecision));
            qWarning() << "Problem with quickAPDetectState " << QString::number(data.quickAPDetectStateDecision);
            decision = 0;
            enabled = 0;
            emit stateFinished();
            return;
        }
    }
    else
    {
        currentInjectionAmplitude += 20;
        timer1.start();
    }
    }
}

void IC_QuickAPDetect::timer1_timeout()
{
    emit daq_setCurrentInjAmplitude(currentInjectionAmplitude);  // Get an initial baseline current
    emit daq_trigger();
}
