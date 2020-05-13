#include "vc_pipettecapacitanceneutralization.h"
#include "workers/daqworker.h"

// ********************************
// THIS STATE IS NOT CURRENTLY USED
// ********************************

VC_PipetteCapacitanceNeutralization::VC_PipetteCapacitanceNeutralization(QObject *parent) : State(parent)
{
    name = "Pipette Capacitance Compensation (Voltage Clamp)";
    description = "This state will increase the capacitance compensation \
until it starts overshooting.  It will record the maximum value that doesn't \
overshoot and saves it to the data.pipetteCapacitance value. ";
}

VC_PipetteCapacitanceNeutralization::~VC_PipetteCapacitanceNeutralization()
{

}

void VC_PipetteCapacitanceNeutralization::pauseState(bool) // Toggled
{

}

void VC_PipetteCapacitanceNeutralization::haltState()
{

}

// **************** PROCEDURAL CODE START *******************
// Code in this section should be very sequential and each
// method should be called after the previous.  This is the
// algorithmic portion of this state.
void VC_PipetteCapacitanceNeutralization::firstRun()
{
    emit autopatcher_switchBNC(1,0);
    emit gui_busy_start("Finding the pipette capacitance");
    emit gui_setCurrentPageIndex("page_cell_qc");
    emit autopatcher_switchPressure(AutopatcherWorker::PRESSURE_ATM,0);
    emit multiclamp_selectChannel(data.headstageNum);
    emit multiclamp_setMode(MCCMSG_MODE_VCLAMP);
    emit multiclamp_setHoldingVSafe(-0.065,true);
    emit multiclamp_setFastCapacitanceValue(5*pow(10,-12));
}

void VC_PipetteCapacitanceNeutralization::multiclamp_setHoldingVoltageSafeComplete()
{
    emit multiclamp_autoSlowCapacitance();
    emit multiclamp_autoFastCapacitance();
}

void VC_PipetteCapacitanceNeutralization::multiclamp_autoFastCapacitanceComplete()
{
    emit multiclamp_getPipetteCapacitanceCompensation();
}

void VC_PipetteCapacitanceNeutralization::multiclamp_pipetteCapacitanceCompensationValue(double val)
{
    //capCompVal = val;
    qWarning() << "Auto fast capacitance compensation value: " << val << " pA.";
    capCompVal = val;
    emit daq_initTask(DAQWorker::TASKTYPE_MEMBRANE_TEST);
}

void VC_PipetteCapacitanceNeutralization::daq_initTaskReady()
{
    qWarning() << "Membrane test daq tasks initialized.";

    // Resetting the cell check algorithm variables
    RmAve       = 0;
    RaAve       = 0;
    HcAve       = 0;
    CmAve       = 0;
    TauAve      = 0;
    CapCompAve  = 0;
    f           = 0;
    quit        = 0;
    emit daq_startTask();
}

void VC_PipetteCapacitanceNeutralization::daq_initTaskError()
{
    qWarning() << "DAQ Error in " << name << " state!";
    emit gui_busy_stop("DAQ Error!");
    decision = 0;
    emit stateFinished();
}

void VC_PipetteCapacitanceNeutralization::daq_memTestValsReady(QVector<double> vals)
{
    emit gui_updateMembraneTestValues(vals);

    if(vals.length() == 6)
    {
        // Values from the membrane test calculations
        // These values are the result of averaging 100 values together

        double Cm       = vals[0]; // Membrane Capacitance (pF)
        double Rm       = vals[1]; // Membrane Resistance (MOhms)
        double Ra       = vals[2]; // Access Resistance (MOhms)
        double Tau      = vals[3]; // Capacitance time constant
        double Hc       = vals[4]; // Holding current
        double CapComp  = vals[5]; // Percent overshoot from too much capacitance compensation. Percentage of the flat part of the whole cell current trace. (0 means no overshoot, it's either under compensated or properly compensated)

        // Increasing the capacitance compensation until there is some overshoot
        // Averaging n values together
        if(f >= 1)  // n = 3
        {
            RmAve = RmAve/f;
            RaAve = RaAve/f;
            HcAve = HcAve/f;
            TauAve = TauAve/f;
            CmAve = CmAve/f;
            CapCompAve = CapCompAve/f;

            quit++;
            qWarning() << "CapComp: " << CapCompAve;
            // Calculate stuff
            if(CapCompAve > 12.5) // if it's more than 12.5 percent of the flat part of the test pulse
            {
                qWarning() << "With " << capCompVal << " pF of fast capacitance compensation, we're getting more than 12% overshoot";
                capCompVal= capCompVal - 0.1;  // This may need some kind of scaling depending on the input resistance of the cell
                data.pipetteCapacitance = capCompVal;
                emit multiclamp_setPipetteCapacitanceCompensation(capCompVal*pow(10,-12));
                emit multiclamp_setFastCapacitanceValue(capCompVal*pow(10,-12));
                decision = 1;
                emit daq_stopTask();
                emit stateFinished();
            }
            else
            {
                capCompVal = capCompVal + 0.1;
                emit multiclamp_setFastCapacitanceValue(capCompVal*pow(10,-12));
            }

            // Logging the cell QC values
            data.LOG_cellQCParamsTime.push_back(QTime::currentTime());
            data.LOG_accessResistance.push_back(RaAve);
            data.LOG_cellCapacitance.push_back(CmAve);
            data.LOG_cellMembraneResistance.push_back(RmAve);
            data.LOG_holdingCurrent65.push_back(HcAve);
            data.LOG_membraneTau.push_back(TauAve);
            data.LOG_pipetteCapCompOvershoot.push_back(CapCompAve);

            // Reset the values
            f           = 0;
            RmAve       = 0;
            RaAve       = 0;
            HcAve       = 0;
            TauAve      = 0;
            CmAve       = 0;
            CapCompAve  = 0;
        }
        else
        {
            f++;
            RmAve += Rm;
            RaAve += Ra;
            HcAve += Hc;
            TauAve += Tau;
            CmAve += Cm;
            CapCompAve += CapComp;
        }
        if(quit>240)  // After 240 measurements (roughly 30 seconds), stop this state.  It probably isn't properly compensated
        {
            qWarning() << "Pipette capacitance compensation not properly done (timed out).";
            decision = 1;  // ok exit.
            emit daq_stopTask();
            emit stateFinished();
        }
    }
    else
    {
        qWarning() << "Something is wrong with the membrane test data (wrong number of values)";
    }

}
