#include "autopatchersettings.h"
#include <QDebug>
#include <QObject>
#include <QStandardPaths>

using namespace std;

AutopatcherSettings::AutopatcherSettings()
{
    // ********************************************
    // ******* State flow control flags ***********
    // ********************************************
    restingVoltageStateDecision = 0;  // This flag tells the resting membrane voltage measurement state which state to go to next
    quickAPDetectStateDecision  = 0;  // This tells the quick action potential detection state which state is next
    visualStimPaused            = 0;  // This tells the visual stimulatino state whether to start a new visual stimulation or continue one
                                      // that was paused on a previous execution of this state.
    membraneTestPassed          = 0;  // This flag tells the quickAPCheckState whether the cell passed the membrane
    restingVoltagePassed        = 0;  // This flag tells the quickAPCheckState whether the cell has a good enough resting membrane potential.
    numVisualStims              = 2;  //
    cellQCInterval              = 8*60*1000; // 7 minute default.  Was 3 minutes.  In the current code, there should only be one QC event during visual stimulation.

    // ********************************************
    // ******* Autopatcher Settings Defaults ******
    // ********************************************
    // THE DEFAULT VALUES IN THE AUTOPATCHERSETTINGSWINDOW GUI WILL OVERWRITE THE VALUES BELOW THAT ARE EDITABLE IN THE GUI
    // FLAGS
    pipetteAcquired             = 0;
    pipetteUsed                 = 0;  // Pipette is considered used after neuron hunting begins
    pipetteOk                   = 0;  // Pipette has passed all diagnostics and is ready to hunt
    brainHeightSet              = 0;  // This flag is set to true when the first pipette is lowered to the surface of the brain

//    visualStimulationCounter    = 0;  // This counts how many times the visual stimulation has been show on  this cell.  Used to tell the quick action potential detection
                                      // state which state is next
    waitForRecordingStabilization= 120; // This is used whenever the "Wait" state is run and it pauses the state machine waits for
                                      // however many SECONDS are in "waitForRecordingStabilization"
    rheobaseFound               = 0;  // Flag that tells CellQC whether the rheobase has been found already or not.  If so, it starts injecting current at the rheobase
                                      // to elicit spikes
    prelimRheobase              = 0;  // A preliminary rheobase found during the first action potential detection check. It's just a guestimate that it will start from
                                      // when doing a more accurate measure of the rehobase
    prelimRheobaseSet           = 0;  // Flag that tells whether the preliminary rheobase has been set or not


    // POSITIONS
    motorPosition               = 0;  // Current motor position (absolute) in mm
    brainHeight                 = 0;  // Brain position set on the page "1"
    pipetteLengthWhenHeightSet  = 0;  // The visible length (only what shows up in the images) of the pipette that was measured when the height of the brain was set
    pipetteLengthCurrent        = 0;  // The visible length (only what shows up in the images) of the pipette for the pipette currently being inserted into the brain

    startingPipetteNumber       = 1;  // Starting position in the carousel
    currentPipetteNumber        = 1;  // Current pipette number;
    startDepth                  = 500;
    stopDepth                   = 1000;
    stepSize                    = 2;  // 2 um steps
    nPeriods                    = 10;  // number of square wave periods to average for each resistance measurment
    maxR                        = 11;
    minR                        = 3;
    numAve                      = 20;  // Number of pipette resistance check values;
    maxVar                      = 0.50;
    delayAfterDescent           = 8;   // Number of seconds to wait after descending to the startDepth
    LOG_delayAfterDescent       = delayAfterDescent;
    clogThresh                  = 0.4;
    LOG_clogThresh              = clogThresh;
    neuronThresh                = 0.35;
    LOG_neuronThresh            = neuronThresh;
    hitNoStepThresh             = neuronThresh*2;
    numSampsToWaitToReleasePress= 10;     // must be >= 8.  If less than 8, it skips the 10 second confirmation check and go's straight to atmospheric presure.
    nDetectSamps                = 3;      // number of sequential steps that must increase in resistance and have a span greather than APneuronThresh
    returnThresh                = neuronThresh; // The maximum amount the resitance can drop during the initial gigasealing with low positive pressure stage without returning to neuron hunt
    LOG_returnThresh            = returnThresh;
    breakInThresh               = 1000;   // Minimum threshold to allow break in;
    gigasealMaxWait             = 200;    // (seconds) (should be about 100) the maximum wait time before the algorithm breaks in if the resistance is greather than the minimum threshold.  If not, it changes the pipette.  This wait time should inlcude the initial moments of suction
    resCounter                  = 0;
    pipetteCapacitance          = 0;
    capacitancePercentCompensation = 0.93; // 0.95 was just a little ambitious.  It's better to be slightly more conservative.  This seemed to work well so far in vivo.
    accessResistanceThresh      = 200;    // Access resistance threshold.  < 70 is probably publishable.  The cell must have an access resistance less than this to be considered a good recording.
    holdingCurrentThresh        = 400;    // Holding current at -70mV.  It should be less than 200 pA or it's a leaky seal.
    restingVoltageThresh        = -0.040; // Resting membrane potential threshold.  It will reject cells with resting potentials above this value.
    switchControlFlag           = 1;
//    huntingFlag                 = 0;
    slowRetractFlag             = 0;
    breakInType                 = 3;      // Break In Ramps with feedback
//    overrideBreakIn             = 0;
    brokenInFlag                = 0;
    breakInFailed               = 0;
//    breakInFlag                 = 0;
    stopGigasealFlag            = 0;
    minorHitTrip                = 0;

    atmosphericDuration         = 10;  // (seconds) duration of atmospheric pressure before applying suction
    suctionDuration             = 5;  // (seconds) Duration of the pulse of suction
    rampStartTime               = 0;  // (seconds) When to start voltage ramp after releasing low positive pressure

    slowRetractStepSize         = 2;

    headstageNum                = 1;  // Default headstage value
    screenNumber                = 1;
    numCurrentStepRepeats       = 3;
    numBACCurrentInjRepeats     = 2;
    trialNum                    = 0;
    trialSaved                  = true;

    QVector<int> tmp(3);

    int dur[8] = {25,50,100,200,500,1000,1000,5000};
    int num[8] = {1 , 1,  1,  1,  1,  1,    3,   3};

    for(int i=0; i<8; i++)
    {
        tmp[0] = i+1;
        tmp[1] = dur[i];
        tmp[2] = num[i];
        breakInTableZap.push_back(tmp);
    }

    int pressures[7] = {150, 200, 250, 300, 345, 345,345};
    int times1[5]    = {150, 250, 300, 450, 500};

    QVector<int> tmp2(4);
    for(int i=0; i<5; i++)
    {
        tmp2[0] = i+1;
        tmp2[1] = pressures[i];
        tmp2[2] = times1[i];
        tmp2[3] = 1;
        breakInTableSuction.push_back(tmp2);
    }

    int times[7]     = {1000, 1000, 1000, 1000, 1000,1500,2000};

    QVector<int> tmp3(3);

    for(int i=0; i<7; i++)
    {
        tmp3[0] = i+1;
        tmp3[1] = pressures[i];
        tmp3[2] = times[i];
        breakInTableRamp.push_back(tmp3);
    }

    breakInFeedbackRampTime = 1500; // ms duration of the feedback break in ramp

    fileFormat = 2;
    LOG_experimentDateTime.setDate(QDate::currentDate());
}

void AutopatcherSettings::setWindowTitle(QString title)
{
    dataDir = QStandardPaths::standardLocations(QStandardPaths::HomeLocation).at(0) + "/" + title + "/data/";
}

void AutopatcherSettings::clearLogValues()
{
    LOG_neuronThresh        = neuronThresh;
    LOG_clogThresh          = clogThresh;
    LOG_delayAfterDescent   = delayAfterDescent;
    LOG_returnThresh        = returnThresh;
    LOG_trialStartDateTime  = QDateTime();
    LOG_resAveAboveBrain    = -1;
    LOG_resVarAboveBrain    = -1;
    LOG_pipetteCheckResVals.clear();
    LOG_pipetteCheckResTime.clear();
    LOG_pipetteClogCheckVal = -1;
    LOG_pipetteClogCheckTime = QTime();
    LOG_pipetteClogCheckDepth = -1;
    LOG_huntingResVals.clear();
    LOG_huntingResValsDepth.clear();
    LOG_huntingResValsTime.clear();
    LOG_pipetteHitSize.clear();
    LOG_pipetteHitTime.clear();
    LOG_pipetteHitDepth.clear();
    LOG_pipetteMaxSeal = -1;
    LOG_pipetteMaxSealTime = QTime();
    LOG_gigasealingResVals.clear();
    LOG_gigasealingResValsTime.clear();
    LOG_breakInType.clear();
    LOG_breakInTime.clear();
    LOG_breakInResVals.clear();
    LOG_breakInResTime.clear();
    LOG_actionPotentialAmplitude.clear();
    LOG_restingMembraneVoltage.clear();
    LOG_restingMembraneVoltageTime.clear();
    LOG_holdingCurrent65.clear();
    LOG_membraneTau.clear();
    LOG_pipetteCapCompOvershoot.clear();
    LOG_accessResistance.clear();
    LOG_cellCapacitance.clear();
    LOG_cellMembraneResistance.clear();
    LOG_cellQCParamsTime.clear();
    LOG_rheobase = 0;
    LOG_injectedCurrentMaxAmplitude = 0;
    LOG_bridgeBalance.clear();
    LOG_bridgeBalanceTime.clear();
    LOG_retractionResVals.clear();
    LOG_retractionResTime.clear();
    LOG_retractionResDepth.clear();

    qWarning() << "Log Data CLEARED.";
}

void AutopatcherSettings::saveLogSingleFile(QString fname, int fileType)
{
    /* DATA FILE EXPORT FORMAT
     * 1 = CSV file, human readable, excel readable
     * 2 = matlab file, human readable
     * 3 = ini file, human semireadable (under construction)
*/


    qWarning() << "Log fname: " << fname;
    switch(fileType+1)
    {
    case 1: // This section still needs some work.  I added some variables that need to be exported here
    {
        fname = fname + ".csv";
        ofstream fout;
        fout.open(fname.toStdString().c_str(),ios_base::app); // Appending data to the log file
        if(fout.is_open())
        {
            fout << "Trial Number: ,"           << QString::number(trialNum).toStdString() << "\n\r";
            fout << "Trial Start Date: ,"       << LOG_trialStartDateTime.date().toString("yyyy-MM-dd").toStdString() << "\n\r";
            fout << "Trial Start Time: ,"       << LOG_trialStartDateTime.time().toString("HH:mm:ss").toStdString() << "\n\r";
            fout << "R ave above brain: ,"      << LOG_resAveAboveBrain << "\n\r";
            fout << "R var above brain: ,"      << LOG_resVarAboveBrain << "\n\r";
            fout << "R at clog check: ,"        << LOG_pipetteClogCheckVal << "\n\r";
            fout << "R detection threshold: ,"  << neuronThresh << "\n\r";
            fout << "R change at detection: ,"  << LOG_pipetteHitSize.last() << "\n\r";
            fout << "Max seal R: ,"             << LOG_pipetteMaxSeal << "\n\r";
            fout << "Detection Depth: ,"        << LOG_pipetteHitDepth.last() << "\n\r";

            fout << "Resting membrane voltages: ,";
            for(int i=0; i< LOG_restingMembraneVoltage.size(); i++)
            {
                fout << LOG_restingMembraneVoltage.at(i) << ", ";
            }
            fout << "\n\r";

            fout << "Pipette check resistance values: ,";
            for(int i=0; i< LOG_pipetteCheckResVals.size(); i++)
            {
                fout << LOG_pipetteCheckResVals.at(i) << ", ";
            }
            fout << "\n\r";


            fout << "Neuron hunting resistance values: ,";
            for(int i=0; i< LOG_huntingResVals.size(); i++)
            {
                fout << LOG_huntingResVals.at(i) << ", ";
            }
            fout << "\n\r";


            fout << "Gigasealing resistance values: ,";
            for(int i=0; i< LOG_gigasealingResVals.size(); i++)
            {
                fout << LOG_gigasealingResVals.at(i) << ", ";
            }
            fout << "\n\r";

            fout << "Action Potential Amplitudes: ,";
            for(int i=0; i< LOG_actionPotentialAmplitude.size(); i++)
            {
                fout << LOG_actionPotentialAmplitude.at(i) << ", ";
            }
            fout << "\n\r";


            fout << "Retraction resistance values: ,";
            for(int i=0; i< LOG_retractionResVals.size(); i++)
            {
                fout << LOG_retractionResVals.at(i) << ", ";
            }
            fout << "\n\r";
            fout.close();
            qWarning() << "Write successfull." << fname;
        }
        {
            qWarning() << "Write failed.  Could not open the file: " << fname;
        }
        break;
    }

    case 2: // Matlab file.  This section is up to date.
    {
        fname = fname + ".m";
        bool flag(0);
        QFile tmp(fname);
        if(!tmp.exists()) flag = 1;
        ofstream fout;
        fout.open(fname.toStdString().c_str(),ios_base::app); // Appending data to the log file
        if(fout.is_open())
        {
            if(flag) // Adding the first line
            {
            fout << "trial = struct(\
'StartTime',[],\
'StartDate',[],\
'PipetteResistanceSaline',[],\
'PipetteResistanceSalineTime',[],\
'PipetteResistanceTissue',[],\
'PipetteRessitanceTissueTime',[],\
'PipetteResistanceTissueDepth',[],\
'NeuronHuntTrace',[],\
'NeuronHuntTraceDepth',[],\
'NeuronHuntTraceTime',[],\
'NeuronHuntHitSize',[],\
'NeuronHuntHitTime',[],\
'NeuronHuntHitDepth',[],\
'GigasealTrace',[],\
'GigasealTraceTime',[],\
'BreakInType',[],\
'BreakInTime',[],\
'BreakInResistanceTrace',[],\
'BreakInResistanceTraceTime',[],\
'RestingMembranePotential',[],\
'AccessResistance',[],\
'CellCapacitance',[],\
'MembraneResistance',[],\
'HoldingCurrent65',[],\
'MembraneTau',[],\
'PipetteCapCompOvershoot',[],\
'CellQCParamsTime',[],\
'ActionPotentialAmplitude',[],\
'InjectedCurrentMaxValue',[],\
'Rheobase',[],\
'BridgeBalance',[],\
'BridgeBalanceTime',[],\
'RetractionTrace',[],\
'RetractionTime',[]);"<< "\n\r";
            }
            string n = QString::number(trialNum).toStdString();
            fout << "trial(" << n << ").StartDateTime = ";
            timeArgs(fout,LOG_trialStartDateTime.date(),LOG_trialStartDateTime.time());
            fout << ";\n";
            fout << "trial(" << n << ").PipetteResistanceSaline = [";
            for(int i=0; i<LOG_pipetteCheckResVals.length(); i++)
            {
                fout << LOG_pipetteCheckResVals[i] << " ";
            }
            fout << "]; \n";
            fout << "trial(" << n << ").PipetteResistanceSalineTime = [";
            for(int i=0; i<LOG_pipetteCheckResTime.length(); i++)
            {
                timeArgs(fout,LOG_trialStartDateTime.date(),LOG_pipetteCheckResTime[i]) ;
                fout << " ";
            }
            fout << "]; \n";
            fout << "trial(" << n << ").ClogThreshold = " << LOG_clogThresh << ";" << "\n";
            fout << "trial(" << n << ").PipetteResistanceTissue = " << LOG_pipetteClogCheckVal << ";" << "\n";
            fout << "trial(" << n << ").PipetteResistanceTissueTime = ";
            timeArgs(fout,LOG_trialStartDateTime.date(),LOG_pipetteClogCheckTime);
            fout << ";" << "\n";
            fout << "trial(" << n << ").PipetteResistanceTissueDepth = " << LOG_pipetteClogCheckDepth << ";" << "\n";

            // Neuron Hunting
            fout << "trial(" << n << ").NeuronHuntTrace = [";
            for(int i=0; i<LOG_huntingResVals.length(); i++)
            {
                fout << LOG_huntingResVals[i] << " ";
            }
            fout << "]; \n";
            fout << "trial(" << n << ").NeuronHuntTraceDepth = [";
            for(int i=0; i<LOG_huntingResValsDepth.length(); i++)
            {
                fout << LOG_huntingResValsDepth[i] << " ";
            }
            fout << "]; \n";
            fout << "trial(" << n << ").NeuronHuntTraceTime = [";
            for(int i=0; i<LOG_huntingResValsTime.length(); i++)
            {
                timeArgs(fout,LOG_trialStartDateTime.date(),LOG_huntingResValsTime[i]);
                fout << " ";
            }
            fout << "]; \n";

            // Neuron Detection Events
            fout << "trial(" << n << ").NeuronDetectionThreshold = " << LOG_neuronThresh << ";" << "\n";
            fout << "trial(" << n << ").NeuronDetectionResistance = [";
            for(int i=0; i<LOG_pipetteHitSize.length(); i++)
            {
                fout << LOG_pipetteHitSize[i] << " ";
            }
            fout << "]; \n";
            fout << "trial(" << n << ").NeuronDetectionTime = [";
            for(int i=0; i<LOG_pipetteHitTime.length(); i++)
            {
                timeArgs(fout,LOG_trialStartDateTime.date(),LOG_pipetteHitTime[i]);
                fout << " ";
            }
            fout << "]; \n";
            fout << "trial(" << n << ").NeuronDetectionDepth = [";
            for(int i=0; i<LOG_pipetteHitDepth.length(); i++)
            {
                fout << LOG_pipetteHitDepth[i];
                fout << " ";
            }
            fout << "]; \n";

            // Gigasealing
            fout << "trial(" << n << ").ReturnToNeuronHuntThreshold = " << LOG_returnThresh << ";" << "\n";
            fout << "trial(" << n << ").GigasealTrace = [";
            for(int i=0; i<LOG_gigasealingResVals.length(); i++)
            {
                fout << LOG_gigasealingResVals[i] << " ";
            }
            fout << "]; \n";
            fout << "trial(" << n << ").GigasealTraceTime = [";
            for(int i=0; i<LOG_gigasealingResValsTime.length(); i++)
            {
                timeArgs(fout,LOG_trialStartDateTime.date(),LOG_gigasealingResValsTime[i]);
                fout << " ";
            }
            fout << "]; \n";

            // Break In Events
            fout << "trial(" << n << ").BreakInType = [";
            for(int i=0; i<LOG_breakInType.length(); i++)
            {
                fout << LOG_breakInType[i] << " ";
            }
            fout << "]; \n";
            fout << "trial(" << n << ").BreakInTime = [";
            for(int i=0; i<LOG_breakInTime.length(); i++)
            {
                timeArgs(fout,LOG_trialStartDateTime.date(),LOG_breakInTime[i]);
                fout<< " ";
            }
            fout << "]; \n";

            // Break In Resistance values
            fout << "trial(" << n << ").BreakInResistanceTrace = [";
            for(int i=0; i<LOG_breakInResVals.length(); i++)
            {
                fout << LOG_breakInResVals[i] << " ";
            }
            fout << "]; \n";
            fout << "trial(" << n << ").BreakInResistanceTraceTime = [";
            for(int i=0; i<LOG_breakInResTime.length(); i++)
            {
                timeArgs(fout,LOG_trialStartDateTime.date(),LOG_breakInResTime[i]);
                fout<< " ";
            }
            fout << "]; \n";

            fout << "trial(" << n << ").RestingMembranePotential = [";
            for(int i=0; i<LOG_restingMembraneVoltage.length(); i++)
            {
                fout << LOG_restingMembraneVoltage[i] << " ";
            }
            fout << "]; \n";

            fout << "trial(" << n << ").RestingMembranePotentialTime = [";
            for(int i=0; i<LOG_restingMembraneVoltageTime.length(); i++)
            {
                timeArgs(fout, LOG_trialStartDateTime.date(),LOG_restingMembraneVoltageTime[i]);
                fout<< " ";
            }
            fout << "]; \n";

            fout << "trial(" << n << ").AccessResistance = [";
            for(int i=0; i<LOG_accessResistance.length(); i++)
            {
                fout << LOG_accessResistance[i] << " ";
            }
            fout << "]; \n";

            fout << "trial(" << n << ").CellCapacitance = [";
            for(int i=0; i<LOG_cellCapacitance.length(); i++)
            {
                fout << LOG_cellCapacitance[i] << " ";
            }
            fout << "]; \n";

            fout << "trial(" << n << ").MembraneResistance = [";
            for(int i=0; i<LOG_cellMembraneResistance.length(); i++)
            {
                fout << LOG_cellMembraneResistance[i] << " ";
            }
            fout << "]; \n";

            fout << "trial(" << n << ").HoldingCurrent65 = [";
            for(int i=0; i<LOG_holdingCurrent65.length(); i++)
            {
                fout << LOG_holdingCurrent65[i] << " ";
            }
            fout << "]; \n";

            fout << "trial(" << n << ").MembraneTau = [";
            for(int i=0; i<LOG_membraneTau.length(); i++)
            {
                fout << LOG_membraneTau[i] << " ";
            }
            fout << "]; \n";

            fout << "trial(" << n << ").PipetteCapCompOvershoot = [";
            for(int i=0; i<LOG_pipetteCapCompOvershoot.length(); i++)
            {
                fout << LOG_pipetteCapCompOvershoot[i] << " ";
            }
            fout << "]; \n";

            fout << "trial(" << n << ").CellQCParamsTime = [";
            for(int i=0; i<LOG_cellQCParamsTime.length(); i++)
            {
                timeArgs(fout, LOG_trialStartDateTime.date(),LOG_cellQCParamsTime[i]);
                fout<< " ";
            }
            fout << "]; \n";

            fout << "trial(" << n << ").ActionPotentialAmplitude = [";
            for(int i=0; i<LOG_actionPotentialAmplitude.length(); i++)
            {
                fout << LOG_actionPotentialAmplitude[i] << " ";
            }
            fout << "]; \n";

            fout << "trial(" << n << ").InjectedCurrentMaxValue = " << LOG_injectedCurrentMaxAmplitude << ";\n";
            fout << "trial(" << n << ").Rheobase = " << LOG_rheobase << ";\n";

            // Bridge Balance Values
            // Retraction
            fout << "trial(" << n << ").BridgeBalance = [";
            for(int i=0; i<LOG_bridgeBalance.length(); i++)
            {
                fout << LOG_bridgeBalance[i] << " ";
            }
            fout << "]; \n";
            fout << "trial(" << n << ").BridgeBalanceTime = [";
            for(int i=0; i<LOG_bridgeBalanceTime.length(); i++)
            {
                timeArgs(fout, LOG_trialStartDateTime.date(),LOG_bridgeBalanceTime[i]);
                fout << " ";
            }
            fout << "]; \n";

            // Retraction
            fout << "trial(" << n << ").RetractionTrace = [";
            for(int i=0; i<LOG_retractionResVals.length(); i++)
            {
                fout << LOG_retractionResVals[i] << " ";
            }
            fout << "]; \n";
            fout << "trial(" << n << ").RetractionTraceTime = [";
            for(int i=0; i<LOG_retractionResTime.length(); i++)
            {
                timeArgs(fout, LOG_trialStartDateTime.date(),LOG_retractionResTime[i]);
                fout << " ";
            }
            fout << "]; \n";
            fout << "trial(" << n << ").RetractionTraceDepth = [";
            for(int i=0; i<LOG_retractionResDepth.length(); i++)
            {
                fout << LOG_retractionResDepth[i] << " ";
            }
            fout << "]; \n";
            qWarning() << "Write Successful." << fname;

        }
        else
        {
            qWarning() << "Write failed.  Could not open the file: " << fname;
        }

        break;
    }
    case 3:
        qWarning() << "File export type under construction. No data file exported.";
        break;
    }
}

void AutopatcherSettings::timeArgs(ofstream &fout, QDate date, QTime time)
{
    fout << "datetime(" << date.year()
    << ","
    << date.month()
    << ","
    << date.day()
    << ","
    << time.hour()
    << ","
    << time.minute()
    << ","
    << time.second() << ")";
}


void AutopatcherSettings::saveSettingsSingleFile(QString fname, int fileType)
{
    //qWarning() << "Settings fname: " << fname;

    switch(fileType+1)
    {
    case 1: // This section still needs some work.  I added some variables that need to be exported here
    {
        fname = fname + ".csv";
        ofstream fout;
        fout.open(fname.toStdString().c_str(),ios_base::app); // Appending data to the log file
        if(fout.is_open())
        {


        }
        break;
    }

    case 2: // Matlab file.  This section is up to date.
    {
        fname = fname + ".m";
        ofstream fout;
        fout.open(fname.toStdString().c_str(),ios_base::app); // Appending data to the log file
        if(fout.is_open())
        {

        }
        break;
    }

    case 3: // INI file.  Under construction
    {
        // INI file.  Under construction
    }
    }
}

void AutopatcherSettings::saveSettings()
{
    // UNDER CONSTRUCTION
    /*
     *
     * 1. fix the filename
     * 2. add code to saveSettingsSingleFile to actually save the settings
     * 3. add a function to load settings from a file
     * 4. do we want to save the settings used from every trial?  What happens if the settigns change mid trial?
     * 5. ???
     *
    if(!dataDir.exists()) dataDir.mkpath(dataDir.path());
    QString fname = dataDir.path()+ "/autopatcher_data_" + LOG_experimentDateTime.date().toString("yyyy-MM-dd").replace("-","_");
    switch(fileFormat)
    {
    case 1:
        saveSettingsSingleFile(fname,AutopatcherSettings::FILETYPE_CSV);
        break;

    case 2:
        saveSettingsSingleFile(fname,AutopatcherSettings::FILETYPE_MATLAB);
        break;

    case 3:
        saveSettingsSingleFile(fname,AutopatcherSettings::FILETYPE_CSV);
        saveSettingsSingleFile(fname,AutopatcherSettings::FILETYPE_MATLAB);
        break;
    }
    */
}


void AutopatcherSettings::saveLog()
{
    trialSaved = true;
    if(!dataDir.exists()) dataDir.mkpath(dataDir.path());
    QString fname = dataDir.path()+ "/autopatcher_data_" + LOG_experimentDateTime.date().toString("yyyy-MM-dd").replace("-","_");
    switch(fileFormat)
    {
    case 1:
        saveLogSingleFile(fname,AutopatcherSettings::FILETYPE_CSV);
        break;

    case 2:
        saveLogSingleFile(fname,AutopatcherSettings::FILETYPE_MATLAB);
        break;

    case 3:
        saveLogSingleFile(fname,AutopatcherSettings::FILETYPE_CSV);
        saveLogSingleFile(fname,AutopatcherSettings::FILETYPE_MATLAB);
        break;
    }
}

