#ifndef AUTOPATCHERSETTINGS_H
#define AUTOPATCHERSETTINGS_H
#include <QTime>
#include <QVector>
#include <vector>
#include <fstream>
#include <QDir>

class AutopatcherSettings
{
public:
    // State control variables
    int     restingVoltageStateDecision;// This tells the resting membrane voltage measurement state which state is next
    int     quickAPDetectStateDecision; // This tells the quick action potential detection state which state is next
    int     visualStimPaused;           // This tells the visual stimulatino state whether to start a new visual stimulation or continue one
                                        // that was paused on a previous execution of this state.
    int     membraneTestPassed;         // This flag tells the quickAPCheckState whether the cell passed the membrane test
    int     restingVoltagePassed;       // This flag tells the quickAPCheckState whether the cell has a good enough resting membrane potential.
    int     visualStimCounter;          // This flag tesll quickAPDetect how many times the visual stimulation has run and if it has run enough
                                        // times it will retract.
    int     numVisualStims;             // The number of visual stimulations that will be run on a good cell (fewer if the cell isn't a stable one)



    // Autopatcher Stuff
    bool    pipetteAcquired;
    bool    pipetteUsed;                // Pipette is considered used after neuron hunting begins
    bool    pipetteOk;                  // Pipette has passed all diagnostics and is ready to hunt
    bool    brainHeightSet;             // When the pipette height is set on page "1"

    int     cellQCRunNum; // DELETE THIS
    int     waitForRecordingStabilization; // How long, in seconds, the "WaitAndSetVars" state will pause whenever it's run.
    bool    rheobaseFound;              // Flag that tells whether it can use the rheobase value for action
                                        // potential detection or not to elicit spikes
    double  prelimRheobase;             // Preliminary rheobase use as a starting point for later measuring the
                                        // rheobase more accurately
    bool    prelimRheobaseSet;          // Flag for whether the preliminary rheobase has been set

    double  motorPosition;
    double  brainHeight;
    double  pipetteLengthWhenHeightSet;
    double  pipetteLengthCurrent;
    int     startingPipetteNumber;
    int     currentPipetteNumber;
    float   startDepth;
    float   stopDepth;
    float   stepSize;
    int     nPeriods;
    double  maxR;
    double  minR;
    double  maxVar;
    int     numAve;
    double  delayAfterDescent;
    double  LOG_delayAfterDescent;
    double  clogThresh;
    double  LOG_clogThresh;
    double  neuronThresh;
    double  LOG_neuronThresh;
    double  hitNoStepThresh;
    int     nDetectSamps;
    double  returnThresh;
    double  LOG_returnThresh;
    int     numSampsToWaitToReleasePress;
    double  atmosphericDuration;
    double  suctionDuration;
    double  rampStartTime;
    int     breakInThresh;
    int     breakInType;
    int     gigasealMaxWait;
    QTime   gigasealStartTime;
    double  pipetteCapacitance;
    double  capacitancePercentCompensation;
    double  accessResistanceThresh;
    double  holdingCurrentThresh;
    double  restingVoltageThresh;
    bool    huntingFlag;
    bool    singleStepFlag;

    double  slowRetractStepSize;
    bool    slowRetractFlag;
    bool    switchControlFlag;
    bool    brokenInFlag;
    bool    breakInFailed;

    QVector< QVector<int> > breakInTableSuction;
    QVector< QVector<int> > breakInTableZap;
    QVector< QVector<int> > breakInTableRamp;
    int breakInFeedbackRampTime; // ms (0-9999) over which the pressure is ramped down to the high vacuum pressure

    bool    overrideBreakIn;  // Overrides the break in process
    bool    breakInFlag;
    bool    stopGigasealFlag;
    int     cellQCInterval;  // msec between cell qc checks during recording

    QDateTime       LOG_experimentDateTime;
    QDateTime       LOG_trialStartDateTime;
    double          LOG_resAveAboveBrain;
    double          LOG_resVarAboveBrain;
    QVector<double> LOG_pipetteCheckResVals;
    QVector<QTime>  LOG_pipetteCheckResTime;
    double          LOG_pipetteClogCheckVal;
    QTime           LOG_pipetteClogCheckTime;
    double          LOG_pipetteClogCheckDepth;
    QVector<double> LOG_huntingResVals;
    QVector<double> LOG_huntingResValsDepth;
    QVector<QTime>  LOG_huntingResValsTime;
    QVector<double> LOG_pipetteHitSize;
    QVector<QTime>  LOG_pipetteHitTime;
    QVector<double> LOG_pipetteHitDepth;
    double          LOG_pipetteMaxSeal;
    QTime           LOG_pipetteMaxSealTime;
    QVector<double> LOG_gigasealingResVals;
    QVector<QTime>  LOG_gigasealingResValsTime;
    QVector<int>    LOG_breakInType;
    QVector<QTime>  LOG_breakInTime;
    QVector<int>    LOG_breakInResVals;
    QVector<QTime>  LOG_breakInResTime;
    QVector<double> LOG_restingMembraneVoltage;
    QVector<QTime>  LOG_restingMembraneVoltageTime;
    QVector<double> LOG_actionPotentialAmplitude;
    QVector<double> LOG_holdingCurrent65;
    QVector<double> LOG_membraneTau;
    QVector<double> LOG_pipetteCapCompOvershoot;
    QVector<double> LOG_accessResistance;
    QVector<double> LOG_cellCapacitance;
    QVector<double> LOG_cellMembraneResistance;
    QVector<QTime>  LOG_cellQCParamsTime;
    double          LOG_rheobase;
    double          LOG_injectedCurrentMaxAmplitude;
    QVector<double> LOG_bridgeBalance;
    QVector<QTime> LOG_bridgeBalanceTime;
    QVector<double> LOG_retractionResVals;
    QVector<QTime>  LOG_retractionResTime;
    QVector<double> LOG_retractionResDepth;

    int                 minorHitTrip;
    int                 resCounter;              // A counter used for the first resistance check on the pipette
    QVector<double>     resistanceValues;
    std::vector<double> resVals;      // The values for the first resistance check on the pipette.


    // Other variables

    int headstageNum;
    int screenNumber;
    int numCurrentStepRepeats;
    int numBACCurrentInjRepeats;
    int trialNum;
    bool trialSaved;

    AutopatcherSettings();
    void clearLogValues();
    enum {  FILETYPE_CSV,
            FILETYPE_MATLAB,
            FILETYPE_INI,};
    int fileFormat;
    QDir dataDir;
    void saveLogValues(QString fname,int fileType);
    void saveSettingsSingleFile(QString fname,int fileType);
    void saveLogSingleFile(QString fname,int fileType);
    void setWindowTitle(QString title);
    void saveSettings();
    void saveLog(QString fname, int fileType);

public slots:
    void saveLog();

private:
    void timeArgs(std::ofstream &fout,QDate date, QTime time);
};

#endif // AUTOPATCHERSETTINGS_H
