#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <vector>
#include <QVector>
#include <QTimer>
#include <QThread>
#include <QProcess>
#include <QAxWidget>
#include <QKeyEvent>
#include <qcustomplot/qcustomplot.h>
#include <workers/autopatcherworker.h>
#include <workers/scaraworker.h>
#include <workers/fillerworker.h>
#include <workers/headstageclampworker.h>
#include <workers/multiclampworker.h>
#include <workers/thorworker.h>
#include <workers/daqworker.h>
#include <workers/visualstimuliworker.h>
#include <workers/lengthmeasurementcameraworker.h>
#include <states/error.h>
#include <states/hardwareinit.h>
#include <states/loadpipettes.h>
#include <states/hardwarecalib.h>
#include <states/breakin.h>
#include <states/clogcheck.h>
#include <states/getpipette.h>
#include <states/gigaseal.h>
#include <states/ic_bridgebalanceadjust.h>
#include <states/ic_restingVoltage.h>
#include <states/ic_quickapdetect.h>
#include <states/ic_measurerheobase.h>
#include <states/ic_currentsteps.h>
#include <states/ic_BACFiring.h>
#include <states/ic_recordvisualstimulation.h>
#include <states/neuronhunt.h>
#include <states/pipetteqc.h>
#include <states/removepipette.h>
#include <states/retract.h>
#include <states/retractslowly.h>
#include <states/setbrainheight.h>
#include <states/trialinit.h>
#include <states/vc_membranetest.h>
#include <states/vc_pipettecapacitanceneutralization.h>
#include <states/wait.h>
#include <states/waitandsetvars.h>
#include <ui/autopatchersettings.h>
#include <ui/autopatchersettingswindow.h>
#include <ui/breakinsettingsramp.h>
#include <ui/breakinsettingssuction.h>
#include <ui/breakinsettingszap.h>
#include <ui/hardwaresettingswindow.h>
#include <ui/preferences.h>
//#include <gui_data.h>

// Program approximately 4200 lines of code on 6/2/2014

namespace Ui {
class MainWindow;
}



class MainWindow : public QMainWindow
{
    Q_OBJECT
private:
    Ui::MainWindow *ui;

    // ***********************************************************************************
    // ********************************** VARIABLES **************************************
    // ***********************************************************************************

    // Hardware Workers
    AutopatcherWorker *autopatcher;
    HeadstageClampWorker *headstageClamp;
    SCARAWorker *scara;
    FillerWorker *filler;
    ThorWorker *tMotor;
    MulticlampWorker *multiclamp;
    DAQWorker *daq;
    VisualStimuliWorker *visualStim;
    LengthMeasurementCameraWorker *length;

    QVector<Worker*> allWorkers;

    // Hardware Threads
    QThread autopatcherThread;
    QThread daqThread;
    QThread scaraThread;
    QThread fillerThread;
    QThread headstageClampThread;
    QThread multiclampThread;
    QThread tMotorThread;
    QThread lengthThread;

    // Algorithm States
    Error errorState;
    HardwareInit hardwareInitState;
    LoadPipettes loadPipettesState;
    HardwareCalib hardwareCalibState;
    SetBrainHeight setBrainHeightState;
    GetPipette getPipetteState;
    TrialInit trialInitState;
    PipetteQC pipetteQCState;
    ClogCheck clogCheckState;
    NeuronHunt neuronHuntState;
    Gigaseal gigasealState;
    BreakIn breakInState;
    VC_MembraneTest vc_membraneTestState;
    VC_PipetteCapacitanceNeutralization vc_pipetteCapCompState;
    IC_BridgeBalanceAdjust ic_bridgeBalanceAdjustState;
    IC_RestingVoltage ic_restingVoltageState;
    IC_QuickAPDetect ic_quickAPDetectState;
    IC_MeasureRheobase ic_measureRheobaseState;
    IC_CurrentSteps ic_currentStepsState;
    IC_BACFiring ic_BACFiringState;
    IC_RecordVisualStimulation ic_recordVisualStimulationState;
    WaitAndSetVars waitAndSetVarsState;
    Retract retractState;
    RetractSlowly retractSlowlyState;
    RemovePipette removePipetteState;

    State *currentState;
    QVector<State*> allStates;
    bool stateRunning;

    // Autopatcher Variables
    AutopatcherSettings AP_Data;

    // Data Logging Variables
    QDate experimentDate;



    // GUI Window Handles
    AutopatcherSettingsWindow *ap_win;

    BreakInSettingsZap *brkZapSettings;

    BreakInSettingsSuction *brkSuckSettings;

    BreakInSettingsRamp *brkRampSettings;

    HardwareSettingsWindow *hw_win;

    Preferences *pref_win;

    // Decoration Variables
    bool stopBusy;  // Busy symbol stop flag
    QTimer busy;
    QPixmap imgLEDon,imgLEDoff,imgScara; // LED image for the motor moving GUI.

    // Plotting variables
    int rawPlotBuffSize;
    QCPDataMap rawPlotData; // Raw current trace data plot
    QCPDataMap resPlotData; // Resistance value data plot
    QVector<double> raw;    // Raw data from daq.  The data is copied from the DAQ buffer into this variable in the GUI thread

    // QTimer
    QTimer initTimer;  // This timer allows the mainwindow to load before starting hardware

    // GUI VARIABLES
    int numStepsScaraAdjust;
    int microfilFillVolumeAdjust;
    int pipetteAdjustDistance;

    // ***********************************************************************************
    // ********************************** FUNCTIONS **************************************
    // ***********************************************************************************
    // Autopatcher data used by states
    void updateStateValues();

    // Autopatcher data use by workers
    void updateWorkerValues();

    // State Machine Methods
    void connectState(State*);
    void disconnectState(State*);
    void goToState(State*);
    void addStates(std::vector< std::vector<State*> > &table, State** states);
    void pauseState(State*);
    void resumeState(State*);

    // ?? REMOVE THESE TO STATES
    void patchStart();
    void isBrokenIn(std::vector<double> resVals);

    // GUI FUNCTIONS
    void guiInit();
    void loadPreferences();
    void savePreferences();
    void plotInit();
    void keyReleaseEvent(QKeyEvent *event);
//    void keyPressEvent(QKeyEvent *event);
    void plotRawData();

    // GUI Data Logging
    void savePlot(QString filename,QCustomPlot *plot);
    void initializeStates();
public slots:
    // PushButton Slots
    void on_pushButtonGo1_released();
//    void pushButtonDownAdjust();
//    void pushButtonUpAdjust();
//    void on_pushButtonGo2_clicked();
    void on_pushButtonGo3_released();
//    bool registerAutopatcherSettings();

    // Thread Slots
    void rawMemTestDataReady(QVector<double> buffer);
    void plotResData(double res);
//    void updateMemTestVals(QVector<double> vals);

    void apSettingsChanged();
    void breakInSettingsChangedZap();
    void breakInSettingsChangedSuction();
    void breakInSettingsChangedRamp();
    void hwSettingsChanged();
    void preferencesWindowClosed();    
    void updateMemTestVals(QVector<double> vals);    
    void updateCurrentBrainPosition(double depth);

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

signals:
    void pushButtonUpAdjustSignal();
    void closeWorkers();
    void initDAQInThread();
    void initAutopatcherInThread();
    void daq_stopTask();
    void autopatcher_stop();
    void filler_stop();
    void headstageClamp_stop();
    void scara_stop();
    void scara_powerDown();
    void visual_stop();

private slots:

    void init(); // done
    void startStateMachine(); // done    
    void stateFinished();
    void busy_start(QString msg); // done
    void busy_stop(QString msg); // done
    void busy_stop_error(QString msg); // done    
    void busyTimeout(); // done
    void setCurrentPageIndex(int i); // done
    void setCurrentPageIndex(QString pgObjName);
    void enablePages(bool flag); // done
    void setTextStatus(QString msg); // done
    void clearResistancePlot(); // done
    void clearRawDataPlot(); // done
    void clearMemTestPlot(); // done
    void enableActionFillPipette(bool);
    void enableActionResetCarousel(bool flag);
    void enableActionLoadMicrofil(bool flag);
    void updateCurrentPosition();

    /*
    void on_pushButtonRestart_clicked();
    void incrementPipetteNumber();

    void busyTimeout();  // Busy symbol decoration timeout

    // Algorithm 1 timer callbacks
S    void atmosphericTimerTimeout();
S    void rampTimerTimeout();
S    void suctionTimerTimeout();
S    void startWaitTimer1_Timeout();
S    void startWaitTimer3_Timeout();
S    void startWaitTimer4_Timeout();
S    void breakInTimerTimeout();
S    void onePingTimerTimeout();
S    void restartTimerTimeout();
S    void gigasealAtmTimerTimeout();
S    void retractTimerTimeout();

    // Algorithm 2 timer callbacks
//    void alg2WaitTimer1Timeout();
//    void alg2WaitTimer2Timeout();
//    void alg2WaitTimer3Timeout();
//    void alg2WaitTimer4Timeout();
//    void alg2WaitTimer5Timeout();

    void restartCase3CompleteSlot();

##    void rotationFinished();
##    void breakInCallback();
##    void checkWholeCell();
*/
    void on_pushButtonHALT_clicked();
    void on_actionBreakInSuctionWindow_triggered();
    void on_actionBreakInZapWindow_triggered();
    void on_actionBreakInRampWindow_triggered();
    void on_actionAutopatcher_Settings_triggered();
    void on_actionHardware_Settings_triggered();
    void closeEvent(QCloseEvent *e);
//    void on_pushButtonJogMotor_clicked();
    void on_checkBoxPauseOnRemoval_stateChanged(int arg1);

    void on_pushButtonSCARACalibrate_released();
    void on_pushButtonArm1Clockwise_released();
    void on_pushButtonArm1Counterclockwise_released();
    void on_pushButtonArm2Counterclockwise_released();
    void on_pushButtonArm2Clockwise_released();
    void on_radioButton_toggled(bool checked);
    void on_radioButton_2_toggled(bool checked);
    void on_radioButton_3_toggled(bool checked);
    void on_radioButton_4_toggled(bool checked);
    void on_radioButton_5_toggled(bool checked);
    void on_radioButton_6_toggled(bool checked);
    void on_pushButtonDispenseLoadPipettes_released();
    void on_pushButtonAspirateLoadPipettes_released();
    void on_pushButtonNextLoadPipettes_released();
    void on_actionReset_Carousel_triggered();
    void on_actionFill_Pipette_triggered();
    void rawDataReadySlot();
    void on_radioButton_7_toggled(bool checked);
    void on_radioButton_8_toggled(bool checked);
    void on_radioButton_9_toggled(bool checked);
    void on_radioButton_10_toggled(bool checked);
    void on_pushButtonUpAdjust_released();
    void on_pushButtonDownAdjust_released();
    void on_actionLoad_microfil_20uL_triggered();
    void on_actionHome_Thorlabs_Motor_triggered();
    void on_actionOpen_Headstage_Clamp_triggered();
    void on_actionRetract_Headstage_Wire_triggered();
    void on_pushButtonPause_toggled(bool checked);
    void on_actionPreferences_triggered();
    void incrementTrialNumber();
    void on_actionClose_Headstage_Clamp_triggered();
    void on_actionInsert_Headstage_Wire_triggered();
    void on_actionFinish_Visual_Stimuli_triggered();
    void on_actionReset_Brain_Height_On_New_Pipette_triggered();
    void on_actionReset_Brain_Height_On_New_Pipette_toggled(bool arg1);
    void on_actionFiller_Valve_On_triggered();
    void on_actionFiller_Valve_Off_triggered();
};

#endif // MAINWINDOW_H
