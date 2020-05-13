#include "vc_membranetest.h"

VC_MembraneTest::VC_MembraneTest(QObject *parent) : State(parent)
{
    name = "Membrane Test Cell Quality Check (Voltage Clamp)";
    description = "This state checks to see if the cell is of sufficient quality \
to continue recording.  It is supposed to be followed by a resting membrane voltage \
check state.  Index 0 is the ErrorState, Index 1 is the \"Not Broken In\" decision, Index 2 is the \"Good Cell\" decision, Index 3 \
is the \"Bad Cell\" decision.  The quality thresholds are set in the autopatcher data struct.";
}

VC_MembraneTest::~VC_MembraneTest()
{

}

void VC_MembraneTest::pauseState(bool) // Toggled
{

}

void VC_MembraneTest::haltState()
{

}

// **************** PROCEDURAL CODE START *******************
// Code in this section should be very sequential and each
// method should be called after the previous.  This is the
// algorithmic portion of this state.
void VC_MembraneTest::firstRun()
{
    emit autopatcher_switchBNC(1,0);
    emit gui_busy_start("Monitoring the quality of the recording");
    emit gui_setCurrentPageIndex("page_cell_qc");
    emit autopatcher_switchPressure(AutopatcherWorker::PRESSURE_ATM,0);
    emit multiclamp_selectChannel(data.headstageNum);
    emit multiclamp_setWholeCellChecked(false);
    emit multiclamp_setMode(MCCMSG_MODE_VCLAMP);
    emit multiclamp_setHoldingVSafe(-0.065,true);
}

void VC_MembraneTest::multiclamp_setHoldingVoltageSafeComplete()
{
    emit daq_initTask(DAQWorker::TASKTYPE_MEMBRANE_TEST);
}

void VC_MembraneTest::daq_initTaskReady()
{
    qWarning() << "Membrane test daq tasks initialized.";

    // Resetting the cell check algorithm variables
    strikes = 0;
    balls   = 0;
    quit    = 0;
    CmAve   = 0;
    RmAve   = 0;
    RaAve   = 0;
    HcAve   = 0;
    TauAve  = 0;
    f       = 0;
    checked = 0;
    emit daq_startTask();
}

void VC_MembraneTest::daq_initTaskError()
{
    qWarning() << "DAQ Error in " << name << " state!";
    emit gui_busy_stop("DAQ Error!");
    decision = 0;
    emit stateFinished();
}

void VC_MembraneTest::daq_memTestValsReady(QVector<double> vals)
{
    // THE VALUES ARE CALCULATED IN THE DAQ WORKER

    emit gui_updateMembraneTestValues(vals);

    if(vals.length() == 6)
    {
        // Values from the membrane test calculations
        // These values are the result of averaging 100 values together

        double Cm  = vals[0];    // Membrane Capacitance (pF)
        double Rm  = vals[1];    // Membrane Resistance (MOhms)
        double Ra  = vals[2];    // Access Resistance (MOhms)
        double Tau = vals[3];    // Capacitance time constant
        double Hc  = vals[4];    // Holding current

        //double CapComp = vals[5]; // Overshoot from too much capacitance compensation. (0 means no overshoot, it's either under compensated or properly compensated)

        // Checking membrane parameters

        quit++;

        // Averaging n values together
        if(f >= 3)  // n = 3
        {

            CmAve = CmAve/f;
            RmAve = RmAve/f;
            RaAve = RaAve/f;
            HcAve = HcAve/f;
            TauAve = TauAve/f;
            f = 0;

            // Logging the cell QC values            
            data.LOG_cellQCParamsTime.push_back(QTime::currentTime());
            data.LOG_cellCapacitance.push_back(CmAve);
            data.LOG_accessResistance.push_back(RaAve);
            data.LOG_cellMembraneResistance.push_back(RmAve);
            data.LOG_holdingCurrent65.push_back(HcAve);
            data.LOG_membraneTau.push_back(TauAve);

            bool good1(0),good2(0);

            // Checking the membrane resistance.  If too high, return to break in
            if(RmAve > 500)
            {
                decision = 1;  // Go back to break in
                emit daq_stopTask();
                emit stateFinished();
                qWarning() << "Membrane resistance was > 500 MOhms.  Returning to break in.";
            }
            else
            {
                // Checking Access Resistance
                if(RaAve < data.accessResistanceThresh){ good1 =1;}
                else { qWarning() << "Cell access resistance (" << QString::number(RaAve) << ") is larger than the threshold of " << data.accessResistanceThresh << " MOhms. ";  }

                if(fabs(HcAve) < data.holdingCurrentThresh){ good2 =1; }
                else { qWarning() << "Cell holding current fabs(" << QString::number(HcAve) << ") is larger than the threshold of " << data.holdingCurrentThresh << "MOhms.";  }

                if(!good1 || !good2) // If one of the two are bad, then give it a strike
                {
                    balls = 0;
                    strikes++;
                    qWarning() << "Strikes " << QString::number(strikes);
                }
                if(good1&&good2)   // If both check out, erase the strikes and give it a ball.
                {
                    strikes = 0;
                    balls++;
                    qWarning() << "Ball " << QString::number(balls);
                }
                if(balls > 2)  // After 3 balls (sequential good cell measurements), begin recording
                {
                    qWarning() << "Cell checks out: Ra = " << QString::number(RaAve) << "Mohms,  Holding = " << QString::number(HcAve) << "pA.";
                    emit daq_stopTask();
                    data.membraneTestPassed = 1;
                    decision = 2;  // Good Cell
                    emit stateFinished();
                }

                if(strikes > 9)  // If the cell fails to meet the requirements after 10 sequential measurements, change the pipette.
                {
                    qWarning() << "Cell quality was bad.  Ra: " + QString::number(RaAve) + " holding: " + QString::number(HcAve) + "pA";
                    //decision = 4;  // Bad Cell
                    data.membraneTestPassed = 0;
                    decision = 2;  // the quick action potential detect or the rheobase state will use the "Passed" flag and retract.
                    emit daq_stopTask();
                    emit stateFinished();
                }
            }

            CmAve = 0;
            RmAve = 0;
            RaAve = 0;
            HcAve = 0;
            TauAve = 0;
        }
        else
        {
            f++;
            CmAve += Cm;
            RmAve += Rm;
            RaAve += Ra;
            HcAve += Hc;
            TauAve += Tau;
        }
        if(quit>120)  // After 120 measurements (roughly 15 seconds), stop trying and call it a bad cell
        {
            qWarning() << "Exceeded the maximum number of allowable membrane measurements.  Measurement will probably not stabilize.  Retracting";
            decision = 4;  // Bad cell
            emit daq_stopTask();
            emit stateFinished();
        }
    }
    else
    {
        qWarning() << "Something is wrong with the membrane test data (wrong number of values) " << vals.length();
    }

}
