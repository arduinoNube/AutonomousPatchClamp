#include "ic_restingvoltage.h"

IC_RestingVoltage::IC_RestingVoltage(QObject *parent) : State(parent)
{
    name = "Resting Membrane Voltage Measurement";
    description = "This state aquires raw data from the cell in current clamp mode and \
looks for 0.5 second intervals where the variance is less than 0.2 mV^2.  If it finds one \
it takes the average value and calls that the resting membrane potential.  If it is below \
the threshold speficied in the autopatcher settings data struct, then it continues.  Index \
0 is the \"Error\" decision, Index 3 is the \
\"Bad Resting Voltage\" decision.  This state is generally followed by a state that will check \
to see if the cell spikes.  IMPORTANT: Indexes 1 and 2 are based on a flag in the autopatcher \
settings struct called restingVoltageStateDecision.  This needs to be set before the state is \
run and can be a value of 1 or 2.  Whatever the value is before the state runs and if the cell \
has a good resting membrane potential and there are not errors (Indexes 1 and 3) then the value of the flag will be \
the decision Index of this state. (in the code it says \"decision = data.restingVoltageStateDecision\" \
and then the state finishes.)";

    // Bridge balance dialog reminder
    //dlg = new QMessageBox();
    //connect(dlg,SIGNAL(buttonClicked(QAbstractButton*)),this,SLOT(dialogClose()),Qt::QueuedConnection);
}

IC_RestingVoltage::~IC_RestingVoltage()
{
    delete dlg;
}

void IC_RestingVoltage::pauseState(bool) // Toggled
{

}

void IC_RestingVoltage::haltState()
{

}

void IC_RestingVoltage::setHardwareVals(HardwareSettingsWindow * hw_win)
{
    samplingRate = hw_win->daqSampRate;
}

// **************** PROCEDURAL CODE START *******************
// Code in this section should be very sequential and each
// method should be called after the previous.  This is the
// algorithmic portion of this state.
void IC_RestingVoltage::firstRun()
{
    emit daq_initTask(DAQWorker::TASKTYPE_CURRENT_INJECTION);  // Logging raw data to measure resting potential and action potential amplitude
}

void IC_RestingVoltage::daq_initTaskError()
{
    emit gui_busy_stop("DAQ Error!");
    qWarning() << "DAQ Error! in " << name << " state!";
    decision = 0;
    emit stateFinished();
}

void IC_RestingVoltage::daq_initTaskReady()
{
    // Switching to current clamp
    emit multiclamp_selectChannel(data.headstageNum);
    emit multiclamp_setMode(MCCMSG_MODE_ICLAMP);
    emit multiclamp_setHoldingIChecked(false);
    qWarning() << "Pipette Capacitance Compensation Value: " << data.pipetteCapacitance;
    emit multiclamp_setPipetteCapacitanceCompensation(data.pipetteCapacitance*data.capacitancePercentCompensation);
    emit multiclamp_enablePipetteCapacitanceCompensation(true);

    // Enable the next line and disable the following to automatically set the holding current so the resting membrane potential is -65mV
    //emit multiclamp_setHoldingISafe(data.LOG_holdingCurrent65*pow(10,-12),true);
    emit multiclamp_setHoldingISafe(0*pow(10,-12),true);
    emit multiclamp_setHoldingIChecked(true);
}

void IC_RestingVoltage::multiclamp_setHoldingCurrentSafeComplete()
{
    //dlg->setModal(true);
    //dlg->setText("ATTENTION!  Correct the bridge balance now!");
    //dlg->show();

    // I moved up the following from dialogClose()
    emit gui_setCurrentPageIndex("page_autopatching");
    rawDataLog.clear();
    qWarning() << "Paused";  // Waiting for the holding current check box to be checked and the mode to be switched and initialized.
    QThread::sleep(5);
    emit daq_setCurrentInjAmplitude(0);  // This state won't be injecting current
    emit daq_startTask();
    qWarning() << "Going!  Performing resting membrane potential measurement.";
}

void IC_RestingVoltage::dialogClose()
{
    //dlg->close();


}

void IC_RestingVoltage::daq_rawDataReady(QVector<double> rawData)  // Checking the resting membrane potential
{
    rawDataLog += rawData;
    double time(0.5);
    if(rawDataLog.size() > samplingRate*time)
    {
        //qWarning() << rawDataLog.length() << checked;
        // Finding the resting membrane potential
        // 1. Looking for the first 0.5 second section with a variance less than 0.2
        // 2. Average the points in this section to calculate the resting membrane voltage

        double ave(0);   // Resting membrane voltage
        double var(0);
        ave = 0;
        var = 0;
        // Calculating average for the ith 0.5 second section
        for(int j=0; j<samplingRate*time; j++)
        {
            ave += rawDataLog[j];
        }
        ave = ave/(samplingRate*time);

        // Calculating the variance
        for(int j=0; j<samplingRate*time; j++)
        {
            var += pow(rawDataLog[j] - ave,2);
        }
        var = var/(samplingRate*time);
        rawDataLog = rawDataLog.mid(samplingRate*time,rawDataLog.length()-samplingRate*time);

        qWarning() << ave << var;
        if(var < 0.2/1000)  // Calculated "0.2" by using test data in matlab.  Seemed pretty robust
        {
            // ave = restingMembraneVoltage
            data.LOG_restingMembraneVoltage.push_back(ave);
            data.LOG_restingMembraneVoltageTime.push_back(QTime::currentTime());
            qWarning() << data.restingVoltageStateDecision << " HERE";
            if(ave < data.restingVoltageThresh)  // If below the membrane voltage threshold (more negative is better)
            {
                emit gui_busy_start("Resting membrane voltage = " + QString::number(ave*1000) + " mV.  Checking for action potentials.");
                qWarning() << "Resting membrane voltage = " + QString::number(ave*1000) + " mV.  Checking for action potentials.";
                data.restingVoltagePassed = 1;
                decision = data.restingVoltageStateDecision; // go on to the next state (quick AP detect or rheobaseMeasure) it is predetermined/set by the break in state and the wait state.

                // Bad cell with a good resting voltage.  Retracting rather than trying to measure the rheobase of a bad cell
                if((data.restingVoltageStateDecision == 2) && (data.membraneTestPassed == 0))
                {
                    decision = 3;
                }
                emit stateFinished();
            }
            else
            {
                emit gui_busy_start("Resting membrane voltage = " + QString::number(ave*1000) + " mV.  Poor quality cell, test failed, flag set so the quick action potential detect (or rehobase) state will retract.");
                qWarning() << "Resting membrane voltage = " + QString::number(ave*1000) + " mV.  Poor quality cell, , test failed, flag set so the quick action potential detect (or rheobase) state will retract.";
                data.restingVoltagePassed = 0;
                //decision = 3;  // retracting.
                decision = data.restingVoltageStateDecision;  // The quickAPDetect or the rheobase state will check the "Passed" flags and retract if it doesn't pass.

                // If the next state is the rheobase measurement but we've got a bad cell (Didn't pass the membrane test or have a good resting voltage), retract
                if((data.restingVoltageStateDecision == 2) &&  (data.membraneTestPassed == 0))
                {
                    decision = 3;
                }
                emit stateFinished();
            }
        }
    }
}
