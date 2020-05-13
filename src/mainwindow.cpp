// Sublime text line count search
// ^(.*)$
// C:\Users\gholst3\Dropbox\Research\Autoswapper\C++\Qt 5.4\Autopatch_5.0\src,*.cpp,*.h,-*/daqmx_libs/*,-*/libssh2-1.4.3/*,-*/qcustomplot/*,-*/qcustomplot_old/*
// VERSION 4.0 - 17268 lines
//
// VERSION 5.0
// 07/10/2015 - 9108 lines
// 07/13/2015 - 9216 lines
// 12/17/2015 - 13340 lines
// 02/10/2016 - 14109 lines

#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "daqmx_libs/NIDAQmx.h"
#include <qcustomplot/qcustomplot.h>
#include <QDebug>
#include <QVector>
#include <vector>
#include <fstream>
#include <string>
#include <ui/breakinsettingszap.h>
#include <ui/breakinsettingssuction.h>
#include <ui/breakinsettingsramp.h>
#include <cmath>
#include <QStringList>

using namespace std;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    //fix the data save directory and preferences path
    // GUI Busy Symbol
    busy.setParent(this);
    busy.setInterval(200);
    connect(&busy,SIGNAL(timeout()),this,SLOT(busyTimeout()));

    // GUI Setup
    guiInit();  // loading bitmaps, instantiating ui classes (settings windows), setting gui defaults, etc.

    // Hardware Threads
    // Assigning parent so the cleanup happens when the window is closed
    daqThread.setParent(this);
    multiclampThread.setParent(this);
    tMotorThread.setParent(this);
    autopatcherThread.setParent(this);
    scaraThread.setParent(this);
    fillerThread.setParent(this);
    headstageClampThread.setParent(this);
    lengthThread.setParent(this);

    // Initializings state variables
    stateRunning = 0;
    currentState = NULL;


    initTimer.setSingleShot(true);  // Timer used to give the GUI a chance to refresh before initializing everything else.
    connect(&initTimer,SIGNAL(timeout()),this,SLOT(init()),Qt::QueuedConnection);
    initTimer.start(1000);  // this will call init();
}

MainWindow::~MainWindow()
{
//    emit stopVstim();
    if(stateRunning && currentState != NULL) AP_Data = currentState->getData();
    if(AP_Data.trialSaved == 0)
    {        
        AP_Data.saveSettings();
        AP_Data.saveLog();
    }
    savePreferences();
    connect(this,SIGNAL(daq_stopTask()),daq,SLOT(stopTask()),Qt::QueuedConnection);
    emit daq_stopTask();
    connect(this,SIGNAL(scara_powerDown()),scara,SLOT(powerDown()),Qt::QueuedConnection);
    emit scara_powerDown();
//    connect(this,SIGNAL(autopatcher_stop()),autopatcher,SLOT(stop()),Qt::QueuedConnection);
//    emit autopatcher_stop();
//    connect(this,SIGNAL(filler_stop()),filler,SLOT(stop()),Qt::QueuedConnection);
//    emit filler_stop();
//    connect(this,SIGNAL(headstageClamp_stop()),headstageClamp,SLOT(stop()),Qt::QueuedConnection);
//    emit headstageClamp_stop();
//    connect(this,SIGNAL(scara_stop()),scara,SLOT(stop()),Qt::QueuedConnection);
//    emit scara_stop();

    QThread::msleep(500);
    connect(this,SIGNAL(closeWorkers()),autopatcher,SLOT(aboutToClose()),Qt::QueuedConnection);
    connect(this,SIGNAL(closeWorkers()),headstageClamp,SLOT(aboutToClose()),Qt::QueuedConnection);
    connect(this,SIGNAL(closeWorkers()),filler,SLOT(aboutToClose()),Qt::QueuedConnection);
    connect(this,SIGNAL(closeWorkers()),scara,SLOT(aboutToClose()),Qt::QueuedConnection);
    connect(this,SIGNAL(closeWorkers()),multiclamp,SLOT(aboutToClose()),Qt::QueuedConnection);
    connect(this,SIGNAL(closeWorkers()),tMotor,SLOT(aboutToClose()),Qt::QueuedConnection);
    connect(this,SIGNAL(closeWorkers()),length,SLOT(aboutToClose()),Qt::QueuedConnection);
    emit closeWorkers();

    autopatcherThread.quit();
    headstageClampThread.quit();
    fillerThread.quit();
    scaraThread.quit();
    daqThread.quit();
    multiclampThread.quit();
    tMotorThread.quit();
    lengthThread.quit();

    autopatcherThread.wait(3000);
    headstageClampThread.wait(3000);
    fillerThread.wait(3000);
    scaraThread.wait(3000);
    daqThread.wait(3000);
    multiclampThread.wait(3000);
    tMotorThread.wait(3000);
    lengthThread.wait(3000);

    qWarning() << autopatcherThread.isFinished();
    qWarning() << headstageClampThread.isFinished();
    qWarning() << fillerThread.isFinished();
    qWarning() << scaraThread.isFinished();
    qWarning() << daqThread.isFinished();
    qWarning() << multiclampThread.isFinished();
    qWarning() << tMotorThread.isFinished();
    qWarning() << lengthThread.isFinished();

    // Deleting the hardware workers (this should close the serial
    // ports etc. when their destructors are called)


    delete autopatcher;
    delete headstageClamp;
    delete scara;
    delete filler;
    delete tMotor;
    delete multiclamp;
    delete daq;
    delete length;
    delete ui;


    ap_win->close();
    brkRampSettings->close();
    brkSuckSettings->close();
    brkZapSettings->close();
    hw_win->close();
    pref_win->close();
    delete brkZapSettings;
    delete brkSuckSettings;
    delete brkRampSettings;
    delete ap_win;
}


void MainWindow::init()
{
    // ###########################################################################################
    // STEP 1  Setup
    // ###########################################################################################

    AP_Data.clearLogValues();
    // Hardware Workers (don't assign parents so that they can be moved to another thread)
    autopatcher     = new AutopatcherWorker();
    headstageClamp  = new HeadstageClampWorker();
    scara           = new SCARAWorker();
    filler          = new FillerWorker();
    multiclamp      = new MulticlampWorker();
    daq             = new DAQWorker();
    tMotor          = new ThorWorker();  // ActiveX Controls are slow to initialize
                                         // (that's why we let the GUI loop run first)
    visualStim      = new VisualStimuliWorker();
    length          = new LengthMeasurementCameraWorker();

    allWorkers.push_back(autopatcher);
    allWorkers.push_back(headstageClamp);
    allWorkers.push_back(scara);
    allWorkers.push_back(filler);
    allWorkers.push_back(tMotor);
    allWorkers.push_back(multiclamp);
    allWorkers.push_back(daq);
    allWorkers.push_back(visualStim);
    allWorkers.push_back(length);

    autopatcher->   moveToThread(&autopatcherThread);
    headstageClamp->moveToThread(&headstageClampThread);
    scara->         moveToThread(&scaraThread);
    filler->        moveToThread(&fillerThread);
    tMotor->        moveToThread(&tMotorThread);
    multiclamp->    moveToThread(&multiclampThread);
    daq->           moveToThread(&daqThread);
    length->        moveToThread(&lengthThread);

    // Setting up threads
    autopatcherThread.start(QThread::TimeCriticalPriority);
    daqThread.start(QThread::TimeCriticalPriority);
    scaraThread.start();
    fillerThread.start();
    headstageClampThread.start();
    multiclampThread.start(QThread::TimeCriticalPriority);
    tMotorThread.start();
    lengthThread.start();

    // ************************************
    // ********* Setup Hardware ***********
    // ************************************
    connect(this,SIGNAL(initDAQInThread()),daq,SLOT(initInThread()),Qt::QueuedConnection);
    emit initDAQInThread();
    daq->setAmplifierScaleVC(multiclamp->getCommandScale());  // is this necessary?

    connect(this,SIGNAL(initAutopatcherInThread()),autopatcher,SLOT(initInThread()),Qt::QueuedConnection);
    emit initAutopatcherInThread();

    // ************************************
    // ************ Setup Plots ***********
    // ************************************
    plotInit();
    ui->pages->setEnabled(true);
    busy_stop("You may edit the settings in drop down menu or click GO to initialize the hardware connections.");
}

void MainWindow::initializeStates()
{
    /* Initializing State Flow/Logic Variables
     * Each state should return an integer when it reaches an exit point.
     * The following cases describe the significance of the integer
     * 0= Error.  This means the state finished without reaching a decision like if it was interrupted during execution
     * 1 = Go to the state listed at position "1" index nextStates vector in State.  (GO TO NEXT STATE, OPTION 1)
     * 2 = Go to the state listed at position "2" index nextStates vector in State.  (GO TO NEXT STATE, OPTION 2)
     * etc.
     *
     * I should probably write a GUI selector for this so that people can pick and choose which states to use
     * and when to switch between them live.  It will make debugging a lot harder depending on which route
     * the user makes the state machine go so reproducing errors will be tricky since the flow of the code
     * is changing live as the user uses it.  It should probably have a log file to trace the code flow and
     * help with debugging.
     *
     * Each state will need to declare how many decision options there are within it's code and also define
     * what logic it is using to decide betwen each state.  That way, the GUI can show the user what the state
     * is thinking when it chooses decision 1, 2, etc.
     *
     * Don't forget to add any new states to the allStates vector (see below)
     *
     *
     * The following cases are different examples of how the states are arranged and linked.  They don't all work
     * and many contain errors.  They are mainly used for debugging and hardware readjustment.  If you create a new
     * state flow case, don't forget to add a description to the comboBoxModeSelect in guiInit.  The combo box is what
     * chooses which state flow case will be used at runtime states between
     *
     * Another point, it's generally better to create new states than edit old ones when making changes to the code.
     * That way, the state flows can remain the same for old versions of the code (old experimental protocols)
     * and new ones can rely on the new states.  When editing old states, make sure it won't break the old functionality.
     * To make this easier, try to write very simple and very general states that are indepdenent from the others.
     * This is difficult especially when reusing states that change which output state is selected based on what happend
     * in another state.  One solution is to insert little states in the sequence that change which state follows another
     * state. That way, the complex state code can be reused, but the state flow can be modified using these small custom
     * states that do nothing except set a flag or set the decision variable of the next state.  The fact that they show
     * up in the state flow below highlights their importance in the execution and will make it eaiser for people to find
     * out where the decision is being made to go to a particular state.
     *
     *
     *       _____________          _____________      ________      _____________          _____________
     *      |             |        |             |    |        |    |             |        |             |
     *      |   State 1   |   ->   |   State 2   | -> | Little | -> |   State 1   |   ->   |   State 3   |
     *      |_____________|        |_____________|    |_State__|    |_____________|        |_____________|
     *
     *                                                    ^
     *                                                    |
     *                                  This little state changes a flag that
     *                                  State 1 uses to decide to go to State 3
     *                                  instead of back to State 2 again like
     *                                  it did the first time State 1 was
     *                                  executed.  This could be
     *                                  encapsulated inside State 2 but if
     *                                  you're reusing State 2 for something
     *                                  else somewhere else, then it wouldn't
     *                                  be a "general" state.  Using the flag
     *                                  helps keep State 2 reusable and is more
     *                                  readable in the state flow vectors
     *                                  (see below).
     *
     *
     *
     * I have not always follwed my own advice so watch out inside some of my states where I'm setting flags that should be
     * more visible.  Here are a couple of those important flags that shouldn't be hidden in these states, but are:
     *
     * in "BreakIn", I'm setting the "data.restingVoltageStateDecision", "data.quickAPDetectStateDecision", and
     * "data.visualStimulationCounter" flags to control the decisions of the "ic_quickAPDetectState" and
     * "ic_restingVoltageState" states.
     *
     * I am, however using the "waitAndSetVars" state as one of these little states to control flow flags.  Frankly, I think
     * it's more readable but it's still a little confusing.
     *
     *
     *
     * Another confusing thing is to have a state behave differently based on the number of times it's run.  That doesn't seem
     * very intuitive from the state machine perspective where states are supposed to be able to be inserted and moved around.  Especially
     * for a state like quickAPDetectState where all it's supposed to do is check to see if there are action potentials and give
     * a yes or no answer.  For example, when I check for APs after the second visual stimulation, even if there are APs, I
     * still want to retract because I'm done with that cell.  Therefore, the state is doing a little trickery where it's based
     * on whether there are APs or not, but also on how many times the visual stimulation has been run.  Not very intuitive so
     * I guess I'll have to add something to the description of the state.  It's amazing how fast these things change and how
     * documentation like this and in the state description go out of date almost immediately.  It's tough to keep track of
     * documentation that references changing files.
     *

*/
qWarning() << "State machine was set up with the \"" << ui->comboBoxModeSelect->currentIndex() << "\" case.";
switch (ui->comboBoxModeSelect->currentIndex())
{
case 0:  // Actual state order
    hardwareInitState               .setNextStates(QVector<State*>() << &errorState << &loadPipettesState);
    loadPipettesState               .setNextStates(QVector<State*>() << &errorState << &hardwareCalibState);
    hardwareCalibState              .setNextStates(QVector<State*>() << &errorState << &getPipetteState);
    getPipetteState                 .setNextStates(QVector<State*>() << &errorState << &trialInitState);
    trialInitState                  .setNextStates(QVector<State*>() << &errorState << &setBrainHeightState     << &pipetteQCState);
    setBrainHeightState             .setNextStates(QVector<State*>() << &errorState << &pipetteQCState);
    pipetteQCState                  .setNextStates(QVector<State*>() << &errorState << &clogCheckState          << &retractState);
    clogCheckState                  .setNextStates(QVector<State*>() << &errorState << &neuronHuntState         << &retractState                    << &gigasealState);
    neuronHuntState                 .setNextStates(QVector<State*>() << &errorState << &gigasealState           << &retractState);
    gigasealState                   .setNextStates(QVector<State*>() << &errorState << &breakInState            << &neuronHuntState                 << &retractState    << &vc_membraneTestState);
    breakInState                    .setNextStates(QVector<State*>() << &errorState << &vc_membraneTestState    << &retractState);  // This sets a couple of decision flags for ic_restingVoltageState and ic_quickAPDetectState
    vc_membraneTestState            .setNextStates(QVector<State*>() << &errorState << &breakInState            << &ic_bridgeBalanceAdjustState); //          << &retractState);
    ic_bridgeBalanceAdjustState     .setNextStates(QVector<State*>() << &errorState << &ic_restingVoltageState);
    ic_restingVoltageState          .setNextStates(QVector<State*>() << &errorState << &ic_quickAPDetectState   << &ic_measureRheobaseState         << &retractState); //          << &retractState);
    ic_quickAPDetectState           .setNextStates(QVector<State*>() << &errorState << &waitAndSetVarsState     << &ic_recordVisualStimulationState << &retractState);
    waitAndSetVarsState             .setNextStates(QVector<State*>() << &errorState << &vc_membraneTestState);  // This sets a flag used by the ic_restingVoltageState state decision
    ic_measureRheobaseState         .setNextStates(QVector<State*>() << &errorState << &ic_currentStepsState    << &retractState);
    ic_currentStepsState            .setNextStates(QVector<State*>() << &errorState << &ic_BACFiringState);
    ic_BACFiringState               .setNextStates(QVector<State*>() << &errorState << &ic_recordVisualStimulationState);
    ic_recordVisualStimulationState .setNextStates(QVector<State*>() << &errorState << &vc_membraneTestState);
    retractState                    .setNextStates(QVector<State*>() << &errorState << &removePipetteState);    // uncomment this line when actually running the code, (and commend out the next one)
    retractSlowlyState              .setNextStates(QVector<State*>() << &errorState << &removePipetteState);
    removePipetteState              .setNextStates(QVector<State*>() << &errorState << &getPipetteState);
    break;

case 1: // Just loads a single pipette and finishes
    hardwareInitState       .setNextStates(QVector<State*>() << &errorState << &loadPipettesState);
    loadPipettesState       .setNextStates(QVector<State*>() << &errorState << &hardwareCalibState);
    hardwareCalibState      .setNextStates(QVector<State*>() << &errorState << &getPipetteState);
    getPipetteState         .setNextStates(QVector<State*>() << &errorState << &errorState);
    break;

case 2:  // Cycles through pipettes for the video
    hardwareInitState       .setNextStates(QVector<State*>() << &errorState << &loadPipettesState);
    loadPipettesState       .setNextStates(QVector<State*>() << &errorState << &hardwareCalibState);
    hardwareCalibState      .setNextStates(QVector<State*>() << &errorState << &getPipetteState);
    getPipetteState         .setNextStates(QVector<State*>() << &errorState << &trialInitState);
    trialInitState          .setNextStates(QVector<State*>() << &errorState << &setBrainHeightState << &retractState);
    setBrainHeightState     .setNextStates(QVector<State*>() << &errorState << &retractState);
    retractState            .setNextStates(QVector<State*>() << &errorState << &removePipetteState);
    removePipetteState      .setNextStates(QVector<State*>() << &errorState << &getPipetteState);
    break;

case 3: // Testing resistance check code (skipping load pipettes, calib, get pipettes, retract etc.
        // This case leaves the pipette in the holder and just does resistance checks, neuron hunt, etc.
        // I should probably inclulde the option to switch to the spare headstage to make this easier to
        // debug.  The THOR motor needs to be homed using the APT User software before running this
    hardwareInitState       .setNextStates(QVector<State*>() << &errorState << &loadPipettesState);
    loadPipettesState       .setNextStates(QVector<State*>() << &errorState << &hardwareCalibState);
    hardwareCalibState      .setNextStates(QVector<State*>() << &errorState << &getPipetteState);
    getPipetteState         .setNextStates(QVector<State*>() << &errorState << &trialInitState);
    trialInitState          .setNextStates(QVector<State*>() << &errorState << &setBrainHeightState << &pipetteQCState);
    setBrainHeightState     .setNextStates(QVector<State*>() << &errorState << &pipetteQCState);
    pipetteQCState          .setNextStates(QVector<State*>() << &errorState << &retractState        << &retractState);
    retractState            .setNextStates(QVector<State*>() << &errorState << &removePipetteState);
    removePipetteState      .setNextStates(QVector<State*>() << &errorState << &getPipetteState);
    break;
case 4:

    // Before using this state, you need to edit hardware calibrate so it doesn't take so long.  That's the point of using this state anyway.
    hardwareInitState               .setNextStates(QVector<State*>() << &errorState << &hardwareCalibState);
    hardwareCalibState              .setNextStates(QVector<State*>() << &errorState << &trialInitState);
    trialInitState                  .setNextStates(QVector<State*>() << &errorState << &pipetteQCState          << &pipetteQCState);
    pipetteQCState                  .setNextStates(QVector<State*>() << &errorState << &clogCheckState          << &retractState);
    clogCheckState                  .setNextStates(QVector<State*>() << &errorState << &neuronHuntState         << &retractState                    << &gigasealState);
    neuronHuntState                 .setNextStates(QVector<State*>() << &errorState << &gigasealState           << &retractState);
    gigasealState                   .setNextStates(QVector<State*>() << &errorState << &breakInState            << &neuronHuntState                 << &retractState    << &vc_membraneTestState);
    breakInState                    .setNextStates(QVector<State*>() << &errorState << &vc_membraneTestState    << &retractState);  // This sets a couple of decision flags for ic_restingVoltageState and ic_quickAPDetectState
    vc_membraneTestState            .setNextStates(QVector<State*>() << &errorState << &breakInState            << &ic_restingVoltageState); //          << &retractState);
    ic_restingVoltageState          .setNextStates(QVector<State*>() << &errorState << &ic_quickAPDetectState   << &ic_measureRheobaseState         << &retractState);
    ic_quickAPDetectState           .setNextStates(QVector<State*>() << &errorState << &waitAndSetVarsState     << &ic_recordVisualStimulationState << &retractState);
    waitAndSetVarsState             .setNextStates(QVector<State*>() << &errorState << &vc_membraneTestState);  // This sets a flag used by the ic_restingVoltageState state decision
    ic_measureRheobaseState         .setNextStates(QVector<State*>() << &errorState << &ic_currentStepsState    << &retractState);
    ic_currentStepsState            .setNextStates(QVector<State*>() << &errorState << &ic_BACFiringState);
    ic_BACFiringState               .setNextStates(QVector<State*>() << &errorState << &ic_recordVisualStimulationState);
    ic_recordVisualStimulationState .setNextStates(QVector<State*>() << &errorState << &vc_membraneTestState);
    retractState                    .setNextStates(QVector<State*>() << &errorState << &trialInitState);

case 5:
    hardwareInitState               .setNextStates(QVector<State*>() << &errorState << &hardwareCalibState);
    hardwareCalibState              .setNextStates(QVector<State*>() << &errorState << &trialInitState);
    trialInitState                  .setNextStates(QVector<State*>() << &errorState << &ic_bridgeBalanceAdjustState    << &ic_bridgeBalanceAdjustState);
    ic_bridgeBalanceAdjustState     .setNextStates(QVector<State*>() << &errorState << &trialInitState); //          << &retractState);

    break;

  /*   GOOD SEQUENCE BACKUP FROM DECEMBER/JANUARY RECORDINGS
    hardwareInitState               .setNextStates(QVector<State*>() << &errorState << &loadPipettesState);
    loadPipettesState               .setNextStates(QVector<State*>() << &errorState << &hardwareCalibState);
    hardwareCalibState              .setNextStates(QVector<State*>() << &errorState << &getPipetteState);
    getPipetteState                 .setNextStates(QVector<State*>() << &errorState << &trialInitState);
    trialInitState                  .setNextStates(QVector<State*>() << &errorState << &setBrainHeightState     << &pipetteQCState);
    setBrainHeightState             .setNextStates(QVector<State*>() << &errorState << &pipetteQCState);
    pipetteQCState                  .setNextStates(QVector<State*>() << &errorState << &clogCheckState          << &retractState);
    clogCheckState                  .setNextStates(QVector<State*>() << &errorState << &neuronHuntState         << &retractState                    << &gigasealState);
    neuronHuntState                 .setNextStates(QVector<State*>() << &errorState << &gigasealState           << &retractState);
    gigasealState                   .setNextStates(QVector<State*>() << &errorState << &breakInState            << &neuronHuntState                 << &retractState    << &vc_membraneTestState);
    breakInState                    .setNextStates(QVector<State*>() << &errorState << &vc_membraneTestState    << &retractState);  // This sets a couple of decision flags for ic_restingVoltageState and ic_quickAPDetectState
    vc_membraneTestState            .setNextStates(QVector<State*>() << &errorState << &breakInState            << &ic_restingVoltageState); //          << &retractState);
    ic_restingVoltageState          .setNextStates(QVector<State*>() << &errorState << &ic_quickAPDetectState   << &ic_measureRheobaseState         << &retractState); //          << &retractState);
    ic_quickAPDetectState           .setNextStates(QVector<State*>() << &errorState << &waitAndSetVarsState     << &ic_recordVisualStimulationState << &retractState);
    waitAndSetVarsState             .setNextStates(QVector<State*>() << &errorState << &vc_membraneTestState);  // This sets a flag used by the ic_restingVoltageState state decision
    ic_measureRheobaseState         .setNextStates(QVector<State*>() << &errorState << &ic_currentStepsState    << &retractState);
    ic_currentStepsState            .setNextStates(QVector<State*>() << &errorState << &ic_BACFiringState);
    ic_BACFiringState               .setNextStates(QVector<State*>() << &errorState << &ic_recordVisualStimulationState);
    ic_recordVisualStimulationState .setNextStates(QVector<State*>() << &errorState << &vc_membraneTestState);
    retractState                    .setNextStates(QVector<State*>() << &errorState << &removePipetteState);
    retractSlowlyState              .setNextStates(QVector<State*>() << &errorState << &removePipetteState);
    removePipetteState              .setNextStates(QVector<State*>() << &errorState << &getPipetteState);
    */

}

    // Just a list of all states in no particular order (this is used by setHardwareVals())
    allStates = QVector<State*>() << &hardwareInitState
                                  << &loadPipettesState
                                  << &hardwareCalibState
                                  << &getPipetteState
                                  << &setBrainHeightState
                                  << &trialInitState
                                  << &pipetteQCState
                                  << &clogCheckState
                                  << &neuronHuntState
                                  << &gigasealState
                                  << &breakInState
                                  << &vc_membraneTestState
                                  << &vc_pipetteCapCompState
                                  << &ic_bridgeBalanceAdjustState
                                  << &ic_restingVoltageState
                                  << &ic_quickAPDetectState
                                  << &ic_measureRheobaseState
                                  << &ic_currentStepsState
                                  << &ic_BACFiringState
                                  << &ic_recordVisualStimulationState
                                  << &waitAndSetVarsState
                                  << &retractState
                                  << &retractSlowlyState
                                  << &removePipetteState;

    hwSettingsChanged();  // Initializing the states with the default hardware settings in the hardware window

    // If these values change with each time the state is run, add them to the "connectState" function
    updateStateValues();
}

void MainWindow::startStateMachine()
{
    // On program startup
    stateRunning = 1;
    currentState = &hardwareInitState;
    connectState(currentState);    
    currentState->setData(AP_Data);
    ap_win->setVals(AP_Data);
    //updateStateValues();
    qWarning() << "State starting: " << currentState->getName();
    currentState->firstRun();
}

void MainWindow::stateFinished()
{    
    ui->pages->setEnabled(false);
    disconnectState(currentState);
    stateRunning = 0;
    qWarning() << "State finished: " << currentState->getName();

    if(currentState->decision != -1)
    {
        if((currentState->getNextStates()[currentState->decision] != NULL) &&
            (currentState->getNextStates()[currentState->decision] != &errorState) &&
             (currentState->decision < currentState->getNextStates().size()))
        {
            stateRunning = 1;
            AP_Data = currentState->getData();
            ap_win->setVals(AP_Data);
            currentState = currentState->getNextStates()[currentState->decision];
            connectState(currentState);
            currentState->setData(AP_Data);
            qWarning() << "State starting: " << currentState->getName();
            currentState->firstRun();
        }
        else
        {
            qWarning() << "State machine stopped.  NULL state, error state, or bad decision value from a state." << currentState->decision << currentState->getNextStates()[currentState->decision];
        }
        ui->pages->setEnabled(true);
    }
    else
    {
        qWarning() << "ERROR!!!  STATE FINISHED WITH A CODE -1. Something is wrong with the state code.";
        // WHAT TO DO WITH THE DATA?
    }
}

void MainWindow::updateStateValues()
{
    // Call this function whenever the values in AP_Data change
    // to propagates them down into the states
    pipetteQCState.setHeadstageNum(AP_Data.headstageNum);
    pipetteQCState.setNumAve(AP_Data.numAve);

}

void MainWindow::updateWorkerValues()
{
    daq->setNPeriods(AP_Data.nPeriods);
}

void MainWindow::connectState(State * state)
{
    qRegisterMetaType< QVector<double> >("QVector<double>");

    // GUI Signals
    connect(state,SIGNAL(stateFinished())                           ,this,SLOT(stateFinished())                             ,Qt::QueuedConnection);
    connect(state,SIGNAL(gui_busy_start(QString))                   ,this,SLOT(busy_start(QString))                         ,Qt::QueuedConnection);
    connect(state,SIGNAL(gui_busy_stop(QString))                    ,this,SLOT(busy_stop(QString))                          ,Qt::QueuedConnection);
    connect(state,SIGNAL(gui_busy_stop_error(QString))              ,this,SLOT(busy_stop_error(QString))                    ,Qt::QueuedConnection);
    connect(state,SIGNAL(gui_setCurrentPageIndex(int))              ,this,SLOT(setCurrentPageIndex(int))                    ,Qt::QueuedConnection);
    connect(state,SIGNAL(gui_setCurrentPageIndex(QString))          ,this,SLOT(setCurrentPageIndex(QString))                ,Qt::QueuedConnection);
    connect(state,SIGNAL(gui_enablePages(bool))                     ,this,SLOT(enablePages(bool))                           ,Qt::QueuedConnection);
    connect(state,SIGNAL(gui_setTextStatus(QString))                ,this,SLOT(setTextStatus(QString))                      ,Qt::QueuedConnection);
    connect(state,SIGNAL(gui_clearResistancePlot())                 ,this,SLOT(clearResistancePlot())                       ,Qt::QueuedConnection);
    connect(state,SIGNAL(gui_clearRawDataPlot())                    ,this,SLOT(clearRawDataPlot())                          ,Qt::QueuedConnection);
    connect(state,SIGNAL(gui_clearMemTestPlot())                    ,this,SLOT(clearMemTestPlot())                          ,Qt::QueuedConnection);
    connect(state,SIGNAL(gui_enableActions(bool))                   ,ui->actionFill_Pipette,SLOT(setEnabled(bool))          ,Qt::QueuedConnection);
    connect(state,SIGNAL(gui_enableActions(bool))                   ,ui->actionReset_Carousel,SLOT(setEnabled(bool))        ,Qt::QueuedConnection);
    connect(state,SIGNAL(gui_enableActions(bool))                   ,ui->actionLoad_microfil_20uL,SLOT(setEnabled(bool))    ,Qt::QueuedConnection);
    connect(state,SIGNAL(gui_enableActions(bool))                   ,ui->actionOpen_Headstage_Clamp,SLOT(setEnabled(bool))  ,Qt::QueuedConnection);
    connect(state,SIGNAL(gui_enableActions(bool))                   ,ui->actionClose_Headstage_Clamp,SLOT(setEnabled(bool)) ,Qt::QueuedConnection);
    connect(state,SIGNAL(gui_enableActions(bool))                   ,ui->actionRetract_Headstage_Wire,SLOT(setEnabled(bool)),Qt::QueuedConnection);
    connect(state,SIGNAL(gui_enableActions(bool))                   ,ui->actionInsert_Headstage_Wire,SLOT(setEnabled(bool)) ,Qt::QueuedConnection);
    connect(state,SIGNAL(gui_enableActions(bool))                   ,ui->actionHome_Thorlabs_Motor,SLOT(setEnabled(bool))   ,Qt::QueuedConnection);
    connect(state,SIGNAL(gui_enableActions(bool))                   ,ui->actionFinish_Visual_Stimuli,SLOT(setEnabled(bool)) ,Qt::QueuedConnection);
    connect(state,SIGNAL(gui_enableActions(bool))                   ,ui->actionReset_Brain_Height_On_New_Pipette,SLOT(setEnabled(bool)),Qt::QueuedConnection);
    connect(state,SIGNAL(gui_checkedBrainHeightReset(bool))         ,ui->actionReset_Brain_Height_On_New_Pipette,SLOT(setChecked(bool)),Qt::QueuedConnection);
    connect(state,SIGNAL(gui_enableActions(bool))                   ,ui->actionFiller_Valve_On,SLOT(setEnabled(bool)),Qt::QueuedConnection);
    connect(state,SIGNAL(gui_enableActions(bool))                   ,ui->actionFiller_Valve_Off,SLOT(setEnabled(bool)),Qt::QueuedConnection);
    connect(state,SIGNAL(gui_pauseButtonEnable(bool))               ,ui->pushButtonPause,SLOT(setEnabled(bool))             ,Qt::QueuedConnection);
    connect(state,SIGNAL(gui_pauseButtonVisible(bool))              ,ui->pushButtonPause,SLOT(setVisible(bool))             ,Qt::QueuedConnection);
    connect(state,SIGNAL(gui_plotResData(double))                   ,this,SLOT(plotResData(double))                         ,Qt::QueuedConnection);
    connect(state,SIGNAL(gui_updateCurrentPosition())               ,this,SLOT(updateCurrentPosition())                     ,Qt::QueuedConnection);
    connect(state,SIGNAL(gui_updateCurrentBrainPosition(double))    ,this,SLOT(updateCurrentBrainPosition(double))          ,Qt::QueuedConnection);

    connect(state,SIGNAL(gui_incrementTrialNumber())                ,this,SLOT(incrementTrialNumber())                      ,Qt::QueuedConnection);
    connect(state,SIGNAL(gui_updateMembraneTestValues(QVector<double>)),this,SLOT(updateMemTestVals(QVector<double>))       ,Qt::QueuedConnection);
    connect(state,SIGNAL(gui_enablePushButtonUpAdjust(bool))        ,ui->pushButtonUpAdjust,SLOT(setEnabled(bool))          ,Qt::QueuedConnection);
    connect(state,SIGNAL(gui_enablePushButtonDownAdjust(bool))      ,ui->pushButtonDownAdjust,SLOT(setEnabled(bool))        ,Qt::QueuedConnection);
    connect(state,SIGNAL(gui_enablePushButtonGO1(bool))             ,ui->pushButtonGo1,SLOT(setEnabled(bool))               ,Qt::QueuedConnection);
    connect(state,SIGNAL(gui_enablePushButtonGO3(bool))             ,ui->pushButtonGo3,SLOT(setEnabled(bool))               ,Qt::QueuedConnection);
    connect(state,SIGNAL(gui_enablePushButtonCalibrate(bool))       ,ui->pushButtonSCARACalibrate,SLOT(setEnabled(bool))    ,Qt::QueuedConnection);

    // Autopatcher Signals
    connect(state,SIGNAL(autopatcher_init(QString))                      ,autopatcher,SLOT(init(QString))                   ,Qt::QueuedConnection);
    connect(state,SIGNAL(autopatcher_switchBNC(bool, bool))              ,autopatcher,SLOT(switchBNC(bool,bool))            ,Qt::QueuedConnection);
    connect(state,SIGNAL(autopatcher_softwarePressure(bool,bool))        ,autopatcher,SLOT(softwarePressure(bool,bool))     ,Qt::QueuedConnection);
    connect(state,SIGNAL(autopatcher_switchPressure(int,bool))           ,autopatcher,SLOT(switchPressure(int,bool))        ,Qt::QueuedConnection);
    connect(state,SIGNAL(autopatcher_setPressure(int, double, bool))     ,autopatcher,SLOT(setPressure(int, double, bool))  ,Qt::QueuedConnection);
    connect(state,SIGNAL(autopatcher_breakIn(int,int,int))               ,autopatcher,SLOT(breakIn(int,int,int))            ,Qt::QueuedConnection);
    connect(state,SIGNAL(autopatcher_breakInRamp(int, int))              ,autopatcher,SLOT(breakInRamp(int, int))           ,Qt::QueuedConnection);
    connect(state,SIGNAL(autopatcher_breakInRampFeedback(int))           ,autopatcher,SLOT(breakInRampFeedback(int))        ,Qt::QueuedConnection);
    connect(state,SIGNAL(autopatcher_stopRamp())                         ,autopatcher,SLOT(stopRamp())                      ,Qt::QueuedConnection);

    // Headstage Clamp Signals
    connect(state,SIGNAL(headstageClamp_init(QString))    ,headstageClamp,SLOT(init(QString))         ,Qt::QueuedConnection);
    connect(state,SIGNAL(headstageClamp_openClamp(bool))  ,headstageClamp,SLOT(openClamp(bool))       ,Qt::QueuedConnection);
    connect(state,SIGNAL(headstageClamp_halfClamp(bool))  ,headstageClamp,SLOT(halfClamp(bool))       ,Qt::QueuedConnection);
    connect(state,SIGNAL(headstageClamp_closeClamp(bool)) ,headstageClamp,SLOT(closeClamp(bool))      ,Qt::QueuedConnection);
    connect(state,SIGNAL(headstageClamp_threadWire(bool)) ,headstageClamp,SLOT(threadWire(bool))      ,Qt::QueuedConnection);
    connect(state,SIGNAL(headstageClamp_retractWire(bool)),headstageClamp,SLOT(retractWire(bool))     ,Qt::QueuedConnection);

    // SCARA Signals
    connect(state,SIGNAL(scara_init(QString))                   ,scara,SLOT(init(QString))                  ,Qt::QueuedConnection);
    connect(state,SIGNAL(scara_rotateCarouselNext(bool))        ,scara,SLOT(carouselNextPipette(bool))      ,Qt::QueuedConnection);
    connect(state,SIGNAL(scara_calibrate())                     ,scara,SLOT(calibrate())                    ,Qt::QueuedConnection);
    connect(state,SIGNAL(scara_calibrateCarousel(bool))         ,scara,SLOT(calibrateCarousel(bool))        ,Qt::QueuedConnection);
    connect(state,SIGNAL(scara_rotateArm(int,bool,int))         ,scara,SLOT(rotateArm(int,bool,int))        ,Qt::QueuedConnection);
    connect(state,SIGNAL(scara_enableEndEffector(bool,bool))    ,scara,SLOT(enableEndEffector(bool,bool))   ,Qt::QueuedConnection);
    connect(state,SIGNAL(scara_openEndEffector(bool))           ,scara,SLOT(openEndEffector(bool))          ,Qt::QueuedConnection);
    connect(state,SIGNAL(scara_partialCloseEndEffector(bool))   ,scara,SLOT(partialCloseEndEffector(bool))  ,Qt::QueuedConnection);
    connect(state,SIGNAL(scara_closeEndEffector(bool))          ,scara,SLOT(closeEndEffector(bool))         ,Qt::QueuedConnection);
    connect(state,SIGNAL(scara_moveNext(bool))                  ,scara,SLOT(moveNext(bool))                 ,Qt::QueuedConnection);
    connect(state,SIGNAL(scara_fill1(bool))                     ,scara,SLOT(fill1(bool))                    ,Qt::QueuedConnection);
    connect(state,SIGNAL(scara_fill2(bool))                     ,scara,SLOT(fill2(bool))                    ,Qt::QueuedConnection);
    connect(state,SIGNAL(scara_fill3(bool))                     ,scara,SLOT(fill3(bool))                    ,Qt::QueuedConnection);
    connect(state,SIGNAL(scara_dispenseHighPressure(int,bool))  ,scara,SLOT(dispenseHighPressure(int,bool)) ,Qt::QueuedConnection);
    connect(state,SIGNAL(scara_powerDown())                     ,scara,SLOT(powerDown())                    ,Qt::QueuedConnection);
    connect(state,SIGNAL(scara_powerUp())                       ,scara,SLOT(powerUp())                      ,Qt::QueuedConnection);
    connect(state,SIGNAL(scara_peltier(bool))                   ,scara,SLOT(peltier(bool))                  ,Qt::QueuedConnection);
    connect(state,SIGNAL(scara_fan(bool))                       ,scara,SLOT(fan(bool))                      ,Qt::QueuedConnection);

    // Filler Signals
    connect(state,SIGNAL(filler_init(QString))                   ,filler,SLOT(init(QString))                   ,Qt::QueuedConnection);
    connect(state,SIGNAL(filler_aspirateVolume(float,bool))      ,filler,SLOT(aspirateVolume(float,bool))      ,Qt::QueuedConnection);
    connect(state,SIGNAL(filler_dispenseVolume(float,bool))      ,filler,SLOT(dispenseVolume(float,bool))      ,Qt::QueuedConnection);
    connect(state,SIGNAL(filler_enablePressureControl(bool,bool)),filler,SLOT(enablePressureControl(bool,bool)),Qt::QueuedConnection);

    // Thor Labs Motor Signals
    connect(state,SIGNAL(thorLabsMotor_init(int))                   ,tMotor,SLOT(init(int))                     ,Qt::DirectConnection);
    connect(state,SIGNAL(thorLabsMotor_calibrate())                 ,tMotor,SLOT(calibrate())                   ,Qt::QueuedConnection);
    connect(state,SIGNAL(thorLabsMotor_moveToAbsolute(float,float)) ,tMotor,SLOT(moveMotorAbsolute(float,float)),Qt::QueuedConnection);
    connect(state,SIGNAL(thorLabsMotor_moveByRelative(float,float)) ,tMotor,SLOT(moveMotorRelative(float,float)),Qt::QueuedConnection);
    connect(state,SIGNAL(thorLabsMotor_getPosition(bool))           ,tMotor,SLOT(getPosition(bool))             ,Qt::QueuedConnection);

    // Multiclamp Signals
    connect(state,SIGNAL(multiclamp_init(int, QString))                         ,multiclamp,SLOT(init(int, QString))                        ,Qt::QueuedConnection);
    connect(state,SIGNAL(multiclamp_selectChannel(int))                         ,multiclamp,SLOT(selectChannel(int))                        ,Qt::QueuedConnection);
    connect(state,SIGNAL(multiclamp_setMode(int))                               ,multiclamp,SLOT(setMode(int))                              ,Qt::QueuedConnection);
    connect(state,SIGNAL(multiclamp_setHoldingVSafe(double,bool))               ,multiclamp,SLOT(setHoldingVoltageSafe(double,bool))        ,Qt::QueuedConnection);
    connect(state,SIGNAL(multiclamp_setHoldingVRaw(double))                     ,multiclamp,SLOT(setHoldingVoltageRaw(double))              ,Qt::QueuedConnection);
    connect(state,SIGNAL(multiclamp_setHoldingISafe(double,bool))               ,multiclamp,SLOT(setHoldingCurrentSafe(double,bool))        ,Qt::QueuedConnection);
    connect(state,SIGNAL(multiclamp_setHoldingIRaw(double))                     ,multiclamp,SLOT(setHoldingCurrentRaw(double))              ,Qt::QueuedConnection);
    connect(state,SIGNAL(multiclamp_setHoldingVChecked(bool))                   ,multiclamp,SLOT(setHoldingVoltageChecked(bool))            ,Qt::QueuedConnection);
    connect(state,SIGNAL(multiclamp_setHoldingIChecked(bool,bool))              ,multiclamp,SLOT(setHoldingCurrentChecked(bool,bool))       ,Qt::QueuedConnection);
    connect(state,SIGNAL(multiclamp_autoPipetteOffset())                        ,multiclamp,SLOT(autoCorrectOffset())                       ,Qt::QueuedConnection);
    connect(state,SIGNAL(multiclamp_autoFastCapacitance())                      ,multiclamp,SLOT(autoFastCapacitance())                     ,Qt::QueuedConnection);
    connect(state,SIGNAL(multiclamp_autoSlowCapacitance())                      ,multiclamp,SLOT(autoSlowCapacitance())                     ,Qt::QueuedConnection);
    connect(state,SIGNAL(multiclamp_getFastCapacitanceValue())                  ,multiclamp,SLOT(getFastCapacitanceValue())                 ,Qt::QueuedConnection);
    connect(state,SIGNAL(multiclamp_enablePipetteCapacitanceCompensation(bool)) ,multiclamp,SLOT(enablePipetteCapacitanceCompensation(bool)),Qt::QueuedConnection);
    connect(state,SIGNAL(multiclamp_setPipetteCapacitanceCompensation(double))  ,multiclamp,SLOT(setPipetteCapacitanceCompensation(double)) ,Qt::QueuedConnection);
    connect(state,SIGNAL(multiclamp_getPipetteCapacitanceCompensation())        ,multiclamp,SLOT(getPipetteCapacitanceCompensation())       ,Qt::QueuedConnection);
    connect(state,SIGNAL(multiclamp_setFastCapacitanceValue(double))            ,multiclamp,SLOT(setFastCapacitanceValue(double))           ,Qt::QueuedConnection);
    connect(state,SIGNAL(multiclamp_setWholeCellChecked(bool))                  ,multiclamp,SLOT(setWholeCellChecked(bool))                 ,Qt::QueuedConnection);
    connect(state,SIGNAL(multiclamp_autoBridgeBalance())                        ,multiclamp,SLOT(autoBridgeBalance())                       ,Qt::QueuedConnection);
    connect(state,SIGNAL(multiclamp_getBridgeBalance())                         ,multiclamp,SLOT(getBridgeBalance())                        ,Qt::QueuedConnection);

    connect(state,SIGNAL(multiclamp_setBridgeBalance(double,bool))              ,multiclamp,SLOT(setBridgeBalance(double,bool))             ,Qt::QueuedConnection);
    connect(state,SIGNAL(multiclamp_injectSlowCurrentEnable(bool))              ,multiclamp,SLOT(injectSlowCurrentEnable(bool))             ,Qt::QueuedConnection);
    connect(state,SIGNAL(multiclamp_injectSlowCurrentSetTimeConstant(double))   ,multiclamp,SLOT(injectSlowCurrentSetTimeConstant(double))  ,Qt::QueuedConnection);
    connect(state,SIGNAL(multiclamp_injectSlowCurrentSetVoltage(double))        ,multiclamp,SLOT(injectSlowCurrentSetVoltage(double))       ,Qt::QueuedConnection);
    connect(state,SIGNAL(multiclamp_leakSubtractionChecked(bool))               ,multiclamp,SLOT(leakSubtractionChecked(bool))              ,Qt::QueuedConnection);
    connect(state,SIGNAL(multiclamp_zap(double))                                ,multiclamp,SLOT(zap(double))                               ,Qt::QueuedConnection);
    connect(state,SIGNAL(multiclamp_zapWithDelay(double,int))                   ,multiclamp,SLOT(zapWithDelay(double,int))                  ,Qt::QueuedConnection);

    // DAQ Signals
    connect(state,SIGNAL(daq_init(QString))                     ,daq,SLOT(init(QString))                    ,Qt::QueuedConnection);
    connect(state,SIGNAL(daq_initTask(int))                     ,daq,SLOT(initTask(int))                    ,Qt::QueuedConnection);
    connect(state,SIGNAL(daq_startTask())                       ,daq,SLOT(startTask())                      ,Qt::QueuedConnection);
    connect(state,SIGNAL(daq_stopTask())                        ,daq,SLOT(stopTask())                       ,Qt::QueuedConnection);
    connect(state,SIGNAL(daq_getTaskRunning())                  ,daq,SLOT(getTaskRunning())                 ,Qt::QueuedConnection);
    connect(state,SIGNAL(daq_trigger())                         ,daq,SLOT(trigger())                        ,Qt::QueuedConnection);
    connect(state,SIGNAL(daq_setCurrentInjAmplitude(double))    ,daq,SLOT(setCurrInjAmplitude(double))      ,Qt::QueuedConnection);
    connect(state,SIGNAL(daq_setBACCurrentInjAmplitude(double)) ,daq,SLOT(setBACCurrInjAmplitude(double))   ,Qt::QueuedConnection);
    connect(state,SIGNAL(daq_setBACCurrentInjFrequency(double)) ,daq,SLOT(setBACCurrInjFrequency(double))   ,Qt::QueuedConnection);

    // Visual Signals
    connect(state,SIGNAL(visual_init(QString,QString))      ,visualStim,SLOT(init(QString,QString)) ,Qt::QueuedConnection);
    connect(state,SIGNAL(visual_start(int))                 ,visualStim,SLOT(start(int))            ,Qt::QueuedConnection);
    connect(state,SIGNAL(visual_stop())                     ,visualStim,SLOT(stop())                ,Qt::QueuedConnection);
    connect(state,SIGNAL(visual_pause())                    ,visualStim,SLOT(pause())               ,Qt::QueuedConnection);
    connect(state,SIGNAL(visual_continue())                 ,visualStim,SLOT(continue_())           ,Qt::QueuedConnection);

    // Length Signals
    connect(state,SIGNAL(length_init())                     ,length,SLOT(init())            ,Qt::QueuedConnection);
    connect(state,SIGNAL(length_measure())                  ,length,SLOT(measureLength())   ,Qt::QueuedConnection);
    connect(state,SIGNAL(length_aboutToClose())             ,length,SLOT(aboutToClose())    ,Qt::QueuedConnection);

    // SLOTS
    connect(ui->pushButtonPause,SIGNAL(toggled(bool))   ,state,SLOT(pauseState(bool))   ,Qt::QueuedConnection);

    // Autopatcher Slots
    connect(autopatcher,SIGNAL(initReady())             ,state,SLOT(autopatcher_initReady())        ,Qt::QueuedConnection);
    connect(autopatcher,SIGNAL(initError())             ,state,SLOT(autopatcher_initError())        ,Qt::QueuedConnection);
    connect(autopatcher,SIGNAL(breakInFinished())       ,state,SLOT(autopatcher_breakInComplete())  ,Qt::QueuedConnection);
    connect(autopatcher,SIGNAL(breakInRampFinished())   ,state,SLOT(autopatcher_breakInRampFinished())  ,Qt::QueuedConnection);

    // Headstage Clamp Slots
    connect(headstageClamp,SIGNAL(initReady())          ,state,SLOT(headstageClamp_initReady())         ,Qt::QueuedConnection);
    connect(headstageClamp,SIGNAL(initError())          ,state,SLOT(headstageClamp_initError())         ,Qt::QueuedConnection);
    connect(headstageClamp,SIGNAL(commandFinished())    ,state,SLOT(headstageClamp_commandFinished())   ,Qt::QueuedConnection);

    // SCARA Slots
    connect(scara,SIGNAL(initReady())       ,state,SLOT(scara_initReady())          ,Qt::QueuedConnection);
    connect(scara,SIGNAL(initError())       ,state,SLOT(scara_initError())          ,Qt::QueuedConnection);
    connect(scara,SIGNAL(calibFinished())   ,state,SLOT(scara_calibrateFinished())  ,Qt::QueuedConnection);
    connect(scara,SIGNAL(commandFinished()) ,state,SLOT(scara_commandFinished())    ,Qt::QueuedConnection);

    // Filler Slots
    connect(filler,SIGNAL(initReady())      ,state,SLOT(filler_initReady())         ,Qt::QueuedConnection);
    connect(filler,SIGNAL(initError())      ,state,SLOT(filler_initError())         ,Qt::QueuedConnection);
    connect(filler,SIGNAL(commandFinished()),state,SLOT(filler_commandFinished())   ,Qt::QueuedConnection);

    // Thor Labs Motor Slots
    connect(tMotor,SIGNAL(initReady())                  ,state,SLOT(thorLabsMotor_initReady())                  ,Qt::QueuedConnection);
    connect(tMotor,SIGNAL(initError())                  ,state,SLOT(thorLabsMotor_initError())                  ,Qt::QueuedConnection);
    connect(tMotor,SIGNAL(calibFinished())              ,state,SLOT(thorLabsMotor_calibrateFinished())          ,Qt::QueuedConnection);
    connect(tMotor,SIGNAL(moveMotorFinished())          ,state,SLOT(thorLabsMotor_moveComplete())               ,Qt::QueuedConnection);
    connect(tMotor,SIGNAL(currentMotorPosition(float))  ,state,SLOT(thorLabsMotor_currentMotorPosition(float))   ,Qt::QueuedConnection);

    // Multiclamp Slots
    connect(multiclamp,SIGNAL(initReady())                          ,state,SLOT(multiclamp_initReady())                     ,Qt::QueuedConnection);
    connect(multiclamp,SIGNAL(initError())                          ,state,SLOT(multiclamp_initError())                     ,Qt::QueuedConnection);
    connect(multiclamp,SIGNAL(autoOffsetComplete())                 ,state,SLOT(multiclamp_autoPipetteOffsetComplete())     ,Qt::QueuedConnection);
    connect(multiclamp,SIGNAL(autoFastCapacitanceComplete())        ,state,SLOT(multiclamp_autoFastCapacitanceComplete())   ,Qt::QueuedConnection);
    connect(multiclamp,SIGNAL(setHoldingVoltageSafeComplete())      ,state,SLOT(multiclamp_setHoldingVoltageSafeComplete()) ,Qt::QueuedConnection);
    connect(multiclamp,SIGNAL(setHoldingCurrentSafeComplete())      ,state,SLOT(multiclamp_setHoldingCurrentSafeComplete()) ,Qt::QueuedConnection);
    connect(multiclamp,SIGNAL(pipetteCapacitanceCompensationValue(double)),state,SLOT(multiclamp_pipetteCapacitanceCompensationValue(double)) ,Qt::QueuedConnection);
    connect(multiclamp,SIGNAL(holdingCurrentCheckedComplete())      ,state,SLOT(multiclamp_holdingCurrentCheckedComplete()) ,Qt::QueuedConnection);
    connect(multiclamp,SIGNAL(setBridgeBalanceComplete())           ,state,SLOT(multiclamp_setBridgeBalanceComplete())      ,Qt::QueuedConnection);
    connect(multiclamp,SIGNAL(getBridgeBalanceComplete(double))     ,state,SLOT(multiclamp_getBridgeBalanceComplete(double)),Qt::QueuedConnection);


    // DAQ Slots
    connect(daq,SIGNAL(initReady())                         ,state,SLOT(daq_initReady())                        ,Qt::QueuedConnection);
    connect(daq,SIGNAL(initError())                         ,state,SLOT(daq_initError())                        ,Qt::QueuedConnection);
    connect(daq,SIGNAL(initTaskReady())                     ,state,SLOT(daq_initTaskReady())                    ,Qt::QueuedConnection);
    connect(daq,SIGNAL(initTaskError())                     ,state,SLOT(daq_initTaskError())                    ,Qt::QueuedConnection);

    connect(daq,SIGNAL(memTestValsReady(QVector<double>))   ,state,SLOT(daq_memTestValsReady(QVector<double>))  ,Qt::QueuedConnection);
    connect(daq,SIGNAL(resDataReady(double))                ,state,SLOT(daq_resDataReady(double))               ,Qt::QueuedConnection);
    connect(daq,SIGNAL(taskIsRunning(int))                  ,state,SLOT(daq_taskRunning(int))                   ,Qt::QueuedConnection);
    connect(daq,SIGNAL(rawDataReady(QVector<double>))       ,state,SLOT(daq_rawDataReady(QVector<double>))      ,Qt::QueuedConnection);
    connect(daq,SIGNAL(currInjDataReady(QVector<double>))   ,state,SLOT(daq_currInjDataReady(QVector<double>))  ,Qt::QueuedConnection);
    connect(daq,SIGNAL(bacCurrInjDataReady(QVector<double>)),state,SLOT(daq_bacCurrInjDataReady(QVector<double>))  ,Qt::QueuedConnection);

    // Visual Stim

    connect(visualStim,SIGNAL(initReady())  ,state,SLOT(visual_initReady())     ,Qt::QueuedConnection);
    connect(visualStim,SIGNAL(initError())  ,state,SLOT(visual_initError())     ,Qt::QueuedConnection);
    connect(visualStim,SIGNAL(started())    ,state,SLOT(visual_started())       ,Qt::QueuedConnection);
    connect(visualStim,SIGNAL(paused())     ,state,SLOT(visual_paused())        ,Qt::QueuedConnection);
    connect(visualStim,SIGNAL(finished())   ,state,SLOT(visual_finished())      ,Qt::QueuedConnection);
    connect(visualStim,SIGNAL(stopped())    ,state,SLOT(visual_stopped())       ,Qt::QueuedConnection);

    // Length Measurement
    connect(length,SIGNAL(initReady())              ,state,SLOT(length_initReady())             ,Qt::QueuedConnection);
    connect(length,SIGNAL(initError())              ,state,SLOT(length_initError())             ,Qt::QueuedConnection);
    connect(length,SIGNAL(imagesAquired())          ,state,SLOT(length_imagesAquired())         ,Qt::QueuedConnection);
    connect(length,SIGNAL(measurementReady(float))  ,state,SLOT(length_measurementReady(float)) ,Qt::QueuedConnection);

    // OTHER SIGNALS THAT HAVE TO BE REESTABLISHED BECAUSE EVERYTHING GETS DISCONNECTED IN THE "disconnectState" function
    // ADD ANY OTHER SIGNALS TO THAT FUNCTION THAT DON'T GO THROUGH State.h AND CONNECT BETWEEEN ANYTHING ELSE AND THE WORKERS.
}

void MainWindow::disconnectState(State *state)
{
    // All the objects referenced in connectState need to be listed here or
    // things will get connected and not disconnected whenever the state changes.
    ui->pushButtonPause->disconnect();
    state->disconnect();
    autopatcher->disconnect();
    headstageClamp->disconnect();
    scara->disconnect();
    filler->disconnect();
    tMotor->disconnect();
    multiclamp->disconnect();
    daq->disconnect();
    visualStim->disconnect();
    length->disconnect();

    // This is not a state connection but to use the "disconnect" function, I have to restablish the connection with every other signal.
    connect(daq,SIGNAL(rawDataReady()),this,SLOT(rawDataReadySlot()),Qt::QueuedConnection);
}

void MainWindow::addStates(vector< vector<State*> > &table, State** states)
{
    table.push_back(vector<State*>(states,states+sizeof(states)/sizeof(State*)));
}

void MainWindow::pauseState(State *)
{

}

void MainWindow::resumeState(State *)
{

}

void MainWindow::busy_start(QString msg)
{
    if(!busy.isActive())
    {
        busy.start();
    }
    ui->textStatus->setText(msg);
}

void MainWindow::busy_stop(QString msg)
{
    busy.stop();
    ui->textBusy->setText("✔");
    ui->textStatus->setText(msg);
}

void MainWindow::busy_stop_error(QString msg)
{
    busy.stop();
    ui->textBusy->setText("X");
    ui->textStatus->setText(msg);
}

void MainWindow::setCurrentPageIndex(int i)
{
    ui->pages->setCurrentIndex(i);
}

void MainWindow::setCurrentPageIndex(QString pgObjName)
{
    for(int i=0; i<ui->pages->count(); i++)
    {
        if(ui->pages->widget(i)->objectName() == pgObjName)
        {
            ui->pages->setCurrentIndex(i);
            break;
        }
    }
}

void MainWindow::enablePages(bool flag)
{
    ui->pages->setEnabled(flag);
}

void MainWindow::setTextStatus(QString msg)
{
    ui->textStatus->setText(msg);
}

void MainWindow::clearResistancePlot()
{
    ui->resistancePlot->graph(0)->clearData();;
    resPlotData.clear();
    ui->resistancePlot->replot();
}

void MainWindow::clearRawDataPlot()
{
    ui->rawPlot->graph(0)->clearData();
    rawPlotData.clear();
    ui->rawPlot->replot();
}

void MainWindow::clearMemTestPlot()
{
    ui->membraneTestPlot->graph(0)->clearData();
    ui->membraneTestPlot->replot();
}

void MainWindow::enableActionFillPipette(bool flag)
{
    ui->actionFill_Pipette->setEnabled(flag);
}

void MainWindow::enableActionResetCarousel(bool flag)
{
    ui->actionReset_Carousel->setEnabled(flag);
}

void MainWindow::enableActionLoadMicrofil(bool flag)
{
    ui->actionLoad_microfil_20uL->setEnabled(flag);
}

void MainWindow::updateCurrentPosition()
{
    ui->label_CurrentPosition->setText(QString::number(tMotor->getPosition()*1000));
}

void MainWindow::updateCurrentBrainPosition(double depth)
{
    ui->label_BrainPosition->setText(QString::number(depth));
}

void MainWindow::guiInit()
{
    ui->setupUi(this);
    QThread::currentThread()->setPriority(QThread::TimeCriticalPriority);
    busy_start("Initializing...");
    ui->pages->setCurrentIndex(0);
    ui->pages->setEnabled(false);
    ui->pushButtonGo1->setEnabled(true);
    ui->pushButtonHALT->setVisible(false);
    ui->actionFill_Pipette->setEnabled(false);    
    ui->actionReset_Carousel->setEnabled(false);
    ui->actionLoad_microfil_20uL->setEnabled(false);
    ui->actionHome_Thorlabs_Motor->setEnabled(false);
    ui->actionRetract_Headstage_Wire->setEnabled(false);
    ui->actionInsert_Headstage_Wire->setEnabled(false);
    ui->actionOpen_Headstage_Clamp->setEnabled(false);
    ui->actionClose_Headstage_Clamp->setEnabled(false);
    ui->actionFinish_Visual_Stimuli->setEnabled(false);
    ui->actionReset_Brain_Height_On_New_Pipette->setEnabled(false);
    ui->actionFiller_Valve_On->setEnabled(false);
    ui->actionFiller_Valve_Off->setEnabled(false);

    ui->checkBoxPauseOnRemoval->setVisible(false);
    ui->pushButtonPause->setVisible(false);

    imgLEDon    = QPixmap("../img/LED_on.png");
    imgLEDoff   = QPixmap("../img/LED_off.png");
//    imgScara    = QPixmap("../img/scara_adjust_view.png");
//    ui->LED->setPixmap(imgLEDoff);
//    ui->label_scara_adjust_view->setPixmap(imgScara);
//    ui->label_scara_adjust_view->setScaledContents(true);

    ap_win = new AutopatcherSettingsWindow();
    connect(ap_win,SIGNAL(windowClosed()),this,SLOT(apSettingsChanged()),Qt::QueuedConnection);
    AP_Data = ap_win->getVals();
    AP_Data.setWindowTitle(this->windowTitle());
    AP_Data.LOG_experimentDateTime.setDate(QDate::currentDate());

    brkZapSettings = new BreakInSettingsZap();
    connect(brkZapSettings,SIGNAL(windowClosed()),this,SLOT(breakInSettingsChangedZap()),Qt::QueuedConnection);

    brkSuckSettings = new BreakInSettingsSuction();
    connect(brkSuckSettings,SIGNAL(windowClosed()),this,SLOT(breakInSettingsChangedSuction()),Qt::QueuedConnection);

    brkRampSettings = new BreakInSettingsRamp();
    connect(brkRampSettings,SIGNAL(windowClosed()),this,SLOT(breakInSettingsChangedRamp()),Qt::QueuedConnection);

    hw_win = new HardwareSettingsWindow();    
    connect(hw_win,SIGNAL(windowClosed()),this,SLOT(hwSettingsChanged()),Qt::QueuedConnection);

    pref_win = new Preferences();
    connect(pref_win,SIGNAL(windowClosed()),this,SLOT(preferencesWindowClosed()),Qt::QueuedConnection);
    loadPreferences();

    // GUI VARIABLES
    if(ui->radioButton->isChecked())   numStepsScaraAdjust      = ui->radioButton->text().split(QRegExp("([^0-9])+"))[0].toInt();
    if(ui->radioButton_2->isChecked()) numStepsScaraAdjust      = ui->radioButton_2->text().split(QRegExp("([^0-9])+"))[0].toInt();
    if(ui->radioButton_3->isChecked()) numStepsScaraAdjust      = ui->radioButton_3->text().split(QRegExp("([^0-9])+"))[0].toInt();
    if(ui->radioButton_4->isChecked()) microfilFillVolumeAdjust = ui->radioButton_4->text().split(QRegExp("([^0-9])+"))[0].toInt();
    if(ui->radioButton_5->isChecked()) microfilFillVolumeAdjust = ui->radioButton_5->text().split(QRegExp("([^0-9])+"))[0].toInt();
    if(ui->radioButton_6->isChecked()) microfilFillVolumeAdjust = ui->radioButton_6->text().split(QRegExp("([^0-9])+"))[0].toInt();

    if(ui->radioButton_7->isChecked())  pipetteAdjustDistance = ui->radioButton_7->text().split(QRegExp("([^0-9])+"))[0].toInt();
    if(ui->radioButton_8->isChecked())  pipetteAdjustDistance = ui->radioButton_8->text().split(QRegExp("([^0-9])+"))[0].toInt();
    if(ui->radioButton_9->isChecked())  pipetteAdjustDistance = ui->radioButton_9->text().split(QRegExp("([^0-9])+"))[0].toInt();
    if(ui->radioButton_10->isChecked()) pipetteAdjustDistance = ui->radioButton_10->text().split(QRegExp("([^0-9])+"))[0].toInt();

    // This selects the state execution mode (see initializeStates)
    ui->comboBoxModeSelect->addItem("Autopatch");
    ui->comboBoxModeSelect->addItem("Load 1 Pipette");
    ui->comboBoxModeSelect->addItem("Continuous Pipette Cycle");
    ui->comboBoxModeSelect->addItem("Continuous Resistance Checks");
    ui->comboBoxModeSelect->addItem("Test the new algorithms");
    ui->comboBoxModeSelect->addItem("Test");

}

void MainWindow::loadPreferences()
{
    // Name value pairs
    QStringList names;
    names << "data directory" << "experiment date" << "trial number" << "output file format";
    QVector<bool> flags(names.size(),false);

    QString trialNum;

    qWarning() << "Loading preferences file";
    ifstream fin;
    QDir path = QStandardPaths::standardLocations(QStandardPaths::AppDataLocation).at(0) + "/" + this->windowTitle() + "/";
    QString fullPath = path.path() + "/preferences.txt";
    fin.open(fullPath.toStdString().c_str());
    if(fin.is_open())
    {

        string str;
        QString tmp;
        int i(0);
        while(getline(fin,str))
        {
            i++;
            tmp = QString::fromStdString(str);
            QString name  = tmp.split(QRegExp("(=)+"))[0];
            QString value = tmp.split(QRegExp("(=)+"))[1];

            int flag(0);
            if     (name.contains(names[0],Qt::CaseInsensitive)){     flag = 1;}
            else if(name.contains(names[1],Qt::CaseInsensitive)){    flag = 2;}
            else if(name.contains(names[2],Qt::CaseInsensitive)){       flag = 3;}
            else if(name.contains(names[3],Qt::CaseInsensitive)){ flag = 4;}
            else flag = 0;

            switch (flag)
            {
            case 1: // Data Directory
            {
                QDir tmp2(value);
                if(tmp2.exists())
                {
                    pref_win->setDataDir(QDir(value));
                    flags[1] = true;
                }
                else
                {
                    tmp2.mkpath(tmp2.path());
                    pref_win->setDataDir(QDir(value));
                    flags[1] = true;
                }
                break;
            }
            case 2:  // experiment date (but this should be based on the clock, not the file
            {
//                QStringList tmp3 = value.split(QRegExp("(-)+"));
//                AP_Data.LOG_experimentDateTime.setDate(QDate(tmp3[0].toInt(),tmp3[1].toInt(),tmp3[2].toInt()));
//                if(AP_Data.LOG_experimentDateTime.date().isValid()) flags[2] = true;
//                else

//                if(AP_Data.LOG_experimentDateTime != QDateTime::currentDateTime())
                AP_Data.LOG_experimentDateTime = QDateTime::currentDateTime();
                break;
            }
            case 3: // trial number
                // waiting to process the trial number until all the lines have been read. this is done in the error checking
                // section next
                trialNum = value;
                break;

            case 4: // Output file format
            {
                bool ok(0);
                AP_Data.fileFormat = value.toInt(&ok);
                pref_win->setFileFormat(value.toInt(&ok));
                if(!ok) flags[4] = false;
                else    flags[4] = true;
                break;
            }
            case 0:
            {
                qWarning() << "Bad line in preferences file: " << QString::number(i);
            }
            }
        }


        fin.close();
    }
    else // If file wasn't opened
    {
        qWarning() << "Preferences file not opened.";
    }

    // Error checking
    for(int i=0; i<flags.size(); i++)
    {
        if(!flags[i])
        {
            switch(i)
            {
            case 1:
            {
                qWarning() << "data directory error in preferences file.  Using default.";
                QDir dataDir = QStandardPaths::standardLocations(QStandardPaths::HomeLocation).at(0) + "/" + this->windowTitle() + "/data/";
                pref_win->setDataDir(dataDir);
                if(!dataDir.exists()) dataDir.mkpath(dataDir.path());
            }
                break;
            case 2:
            {
                qWarning() << "experiment date error in preferences file.  Using default.";
                AP_Data.LOG_experimentDateTime.setDate(QDate::currentDate());
                break;
            }
            case 3:
            {
                if(AP_Data.LOG_experimentDateTime.date() == QDate::currentDate())
                {
                    bool ok(0);
                    AP_Data.trialNum = trialNum.toInt(&ok);
                    if(!ok)
                    {
                        AP_Data.trialNum = 0;
                    }
                }
                else  // new day, start the trial number from zero
                {
                    AP_Data.trialNum = 0;
                }
                break;
            }
            case 4:
                AP_Data.fileFormat = 2;
                pref_win->setFileFormat(AP_Data.fileFormat);
                break;
            }
        }
    }


}

void MainWindow::savePreferences()
{
    QDir path = QStandardPaths::standardLocations(QStandardPaths::AppDataLocation).at(0) + "/" + this->windowTitle() + "/";
    if(!path.exists()){path.mkpath(path.path());}
    QString fullPath = path.path() + "/preferences.txt";
    qWarning() << "Saving preferences file." << fullPath;
    ofstream fout;
    fout.open(fullPath.toStdString().c_str());
    if(fout.is_open())
    {
        fout << "data directory = "  << AP_Data.dataDir.path().toStdString() << "\n";
        fout << "experiment date = " << QDate::currentDate().toString("yyyy-MM-dd").toStdString() << "\n";
        fout << "output file format = " << AP_Data.fileFormat << "\n";
        fout << "trial number = "    << QString::number(AP_Data.trialNum).toStdString() << "\n";;
        fout.close();
    }
    else
    {
        qWarning() << "Preferences file could not be saved.";
    }
}

void MainWindow::plotInit()
{
    rawPlotBuffSize = 5*daq->getSamplingRate();

    ui->rawPlot->addGraph();
    QPen my_pen = QPen(Qt::blue);
    my_pen.setWidthF(0.5);
    ui->rawPlot->graph(0)->setPen(my_pen);
    ui->rawPlot->xAxis->setRange(0,rawPlotBuffSize);
    ui->rawPlot->xAxis->setVisible(false);
    ui->rawPlot->graph(0)->setAntialiased(false);
    ui->rawPlot->setNoAntialiasingOnDrag(true);
    ui->rawPlot->graph(0)->setAdaptiveSampling(true);

    ui->resistancePlot->addGraph();
    ui->resistancePlot->graph(0)->setScatterStyle(QCPScatterStyle(QCPScatterStyle::ssCircle, Qt::blue, Qt::white, 4));
    ui->resistancePlot->graph(0)->setAntialiased(false);
    ui->resistancePlot->graph(0)->setLineStyle(QCPGraph::lsNone);
    ui->resistancePlot->replot();
    ui->resistancePlot->xAxis->setVisible(false);
    ui->resistancePlot->setNoAntialiasingOnDrag(true);
    ui->resistancePlot->graph(0)->setAdaptiveSampling(true);

    ui->membraneTestPlot->addGraph();
    ui->membraneTestPlot->graph(0)->setPen(my_pen);
    ui->membraneTestPlot->xAxis->setRange(0,200);
    ui->membraneTestPlot->xAxis->setVisible(false);
    ui->membraneTestPlot->graph(0)->setAntialiased(0);
    ui->membraneTestPlot->setNoAntialiasingOnDrag(true);
    ui->membraneTestPlot->graph(0)->setAdaptiveSampling(true);
}

// DAQ slots
void MainWindow::rawDataReadySlot()
{
    daq->getRawData(&raw);
    if(ui->pages->currentWidget()->objectName() == "page_autopatching")  plotRawData();  // this will plot "raw"
    if(ui->pages->currentWidget()->objectName() == "page_cell_qc")  rawMemTestDataReady(raw);
}


void MainWindow::rawMemTestDataReady(QVector<double> buffer)
{
    QVector<double> keys(buffer.size());
    for(int i=0; i<buffer.size(); i++)
    {
        keys[i] = i;
    }
    ui->membraneTestPlot->graph(0)->setData(keys,buffer);
    ui->membraneTestPlot->yAxis->rescale();
    ui->membraneTestPlot->replot();
}

void MainWindow::updateMemTestVals(QVector<double> vals)
{
    ofstream cout;
    cout << "Trial Number: " << AP_Data.trialNum << "Cell parameters: ";
    for(int i=0; i<vals.size(); i++)
    {
       cout << vals[i] << " " ;
    }
    cout << endl;
    ui->lineEditCm->setText(QString::number(vals[0],'g',3));  // Cm Membrane Capacitance
    ui->lineEditRm->setText(QString::number(vals[1],'g',3));  // Rm Membrane Resistance
    ui->lineEditRa->setText(QString::number(vals[2],'g',3));  // Ra Access Resistance
    ui->lineEditTau->setText(QString::number(vals[3],'g',3)); // Tau RC time constant
    ui->lineEditHold->setText(QString::number(vals[4],'g',4));// Holding holding current
}

void MainWindow::busyTimeout()
{
    static int num(0);
    switch(num)
    {
    case 0:
        ui->textBusy->setText("--");
        num = 1;
        break;
    case 1:
        ui->textBusy->setText("\\");
        num = 2;
        break;
    case 2:
        ui->textBusy->setText("|");
        num = 3;
        break;
    case 3:
        ui->textBusy->setText("/");
        num = 0;
        break;
    }
}


// *********************
// Page 0 CBs
// *********************
void MainWindow::on_pushButtonGo1_released()
{
    ui->pushButtonGo1->setEnabled(false);
    ui->pages->setEnabled(false);

    initializeStates();

    if(!stateRunning)
    {
        currentState = &hardwareInitState;
        startStateMachine();
    }
}

// *********************
// Page 1 CBs
// *********************
void MainWindow::on_pushButtonGo3_released()
{
    // This is simpler than using the signals and slots
    setBrainHeightState.gui_pushbuttonGO3Released(tMotor);
    ui->label_CurrentPosition->setText(QString::number(tMotor->getPosition()*1000));
}

// *********************
// Page 2 CBs
// *********************
void MainWindow::plotRawData()
{
    QTime profile;
    profile = profile.currentTime();
    // Loading the QCPData structure with new data
    static int indexMarker(0);  // Marks the key where the last data point was added to the plot
    int length = rawPlotData.size();
    // Filling the buffer if it isn't full.  Once it' wraps around the end of the buffer, it sets the indexMarker and all
    // subsequent data is handled in the wrapping buffer fashion.
    if(rawPlotData.size() < rawPlotBuffSize)
    {
        if(length+raw.size() < rawPlotBuffSize)
        {
            int j=0;
            for(int i=length; i<raw.size()+length; i++)
            {
                rawPlotData.insert(i,QCPData(i,raw.at(j)));
                j++;
            }
        }
        else
        {
            int j=0;
            for(int i=length; i<rawPlotBuffSize; i++)
            {
                rawPlotData.insert(i,QCPData(i,raw.at(j)));
                j++;
            }
            int tmp = j;
            for(int i=0; i<raw.size()-tmp; i++)
            {
                rawPlotData.insert(i,QCPData(i,raw.at(j)));
                j++;
                indexMarker = j-tmp;
            }
        }
    }

    // If the data has wrapped around the buffer once already, this gives it the o-scope behavior
    else if(length == rawPlotBuffSize)
    {
        // If the new data won't wrap around the end of the buffer
        if(indexMarker+raw.size()<rawPlotBuffSize)
        {

            int j=0;
            for(int i=indexMarker; i<raw.size()+indexMarker; i++)
            {
                rawPlotData.insert(i,QCPData(i,raw.at(j)));
                j++;
            }
            indexMarker = raw.size() + indexMarker;
        }

        // If the new data will wrap around
        else if(indexMarker+raw.size() >= rawPlotBuffSize)
        {
            int j=0;
            for(int i=indexMarker; i<rawPlotBuffSize; i++)
            {
                rawPlotData.insert(i,QCPData(i,raw.at(j)));
                j++;
            }
            int tmp = j;
            for(int i=0; i<raw.size()-tmp; i++)
            {
                rawPlotData.insert(i,QCPData(i,raw.at(j)));
                j++;
            }
            indexMarker = j-tmp;
        }
    }

    // Plotting
    ui->rawPlot->graph(0)->setData(&rawPlotData,true);
    ui->rawPlot->yAxis->rescale();
    ui->rawPlot->replot();

    //qWarning() << "Raw Plot data size: " << ui->rawPlot->graph(0)->data()->size();
    //qWarning() << "Raw plot profiler" << profile.msec() << profile.currentTime().msec() - profile.msec() << profile.currentTime().msec();
}


void MainWindow::plotResData(double res)
{
    // This function adds the resistance value to the resistance plot
    // and overwrites the raw current traces with the new data

    if(resPlotData.size()<70)
    {
//        qWarning() << resPlotData.size() << " " << resPlotData.keys().value(resPlotData.size()-1);
        resPlotData.insert(resPlotData.size(),QCPData(resPlotData.size(),res));
        ui->resistancePlot->graph(0)->clearData();
        ui->resistancePlot->graph(0)->addData(resPlotData);
    }
    else
    {
//        qWarning() << "Removing... " << resPlotData.keys().value(0);
//        qWarning() << "Adding..... " << resPlotData.keys().value(resPlotData.size()-1)+1;
        resPlotData.remove(resPlotData.keys().value(0));
        resPlotData.insert(resPlotData.keys().value(resPlotData.size()-1)+1,QCPData(resPlotData.keys().value(resPlotData.size()-1)+1,res));
        ui->resistancePlot->graph(0)->clearData();
        ui->resistancePlot->graph(0)->addData(resPlotData);
    }

    // There usually aren't very many resistance values (<200) so code optimization here is unnecessary.
    QList<QCPData> vals = resPlotData.values();
    double resMax = vals.at(0).value;
    double resMin = vals.at(0).value;
    for(int i=0; i<vals.size()-1; i++)
    {
        if(vals.at(i+1).value>resMax)
        {
            resMax = vals.at(i+1).value;
        }
        if(vals.at(i+1).value<resMin)
        {
            resMin = vals.at(i+1).value;
        }
    }

    ui->resistancePlot->yAxis->setRange(resMin-resMax*0.05,resMax+0.05*resMax);
    double start = resPlotData.keys()[0]-1;
    double end   = resPlotData.keys()[resPlotData.keys().size()-1]+1;
    ui->resistancePlot->xAxis->setRange(start,end);
    ui->resistancePlot->replot();
}

// *********************
// General CBs
// *********************
void MainWindow::keyReleaseEvent(QKeyEvent *event)
{
    if(event->isAccepted())
    {
        switch(event->key())
        {
        case Qt::Key_Down:
            event->accept();
            if(ui->pages->widget(ui->pages->currentIndex())->objectName() == "page_brain_height_adjustment")  ui->pushButtonDownAdjust->animateClick(500);
            break;

        case Qt::Key_Up:
            event->accept();
            if(ui->pages->widget(ui->pages->currentIndex())->objectName() == "page_brain_height_adjustment")  ui->pushButtonUpAdjust->animateClick(500);
            break;

        case Qt::Key_Enter:
            event->accept();
            if(ui->pages->widget(ui->pages->currentIndex())->objectName() == "page_hardware_init")  ui->pushButtonGo1->animateClick(100);
            else if(ui->pages->widget(ui->pages->currentIndex())->objectName() == "page_hardware_init")  ui->pushButtonGo3->animateClick(100);
            break;

        case Qt::Key_Return:
            event->accept();
            if(ui->pages->widget(ui->pages->currentIndex())->objectName() == "page_hardware_init")  ui->pushButtonGo1->animateClick(100);
            else if(ui->pages->widget(ui->pages->currentIndex())->objectName() == "page_brain_height_adjustment")  ui->pushButtonGo3->animateClick(100);
            break;

        default:
            event->ignore();
            break;
        }
    }
}

void MainWindow::on_pushButtonHALT_clicked()
{
    qWarning() << "Halt clicked.  ADD CODE FOR INTERRUPTING STATES";
}

void MainWindow::savePlot(QString fname, QCustomPlot *plot)
{
    QString desktopDir = QStandardPaths::standardLocations(QStandardPaths::DesktopLocation).at(0);
    QString ffname = "trial " + QString::number(AP_Data.trialNum) + " " +fname+ ".png";
    QString date  = QDate::currentDate().toString("M-d");
    QString fullpath = desktopDir + "/" + date + "/trial " + ffname;

    plot->savePng(fullpath,800,600);
}

void MainWindow::incrementTrialNumber()
{
    if(stateRunning && currentState != NULL) AP_Data = currentState->getData();
    savePreferences();
    ui->label_trialNumber->setText("Trial Number: " + QString::number(AP_Data.trialNum));
}

void MainWindow::apSettingsChanged()
{
    qWarning() << "Autopatcher settings window closed.  Any data changed during this state up to this point will be lost.";
    AP_Data = ap_win->getVals();
    if(currentState != NULL) currentState->setData(AP_Data);
    AP_Data.saveSettings();
}

void MainWindow::breakInSettingsChangedZap()
{
    qWarning() << "Break in settings changed ";
    AP_Data.breakInTableZap = brkZapSettings->getTable();
    if(currentState != NULL) currentState->setData(AP_Data);
}

void MainWindow::breakInSettingsChangedSuction()
{
    qWarning() << "Break in settings changed Suction";
    AP_Data.breakInTableSuction = brkSuckSettings->getTable();
    if(currentState != NULL) currentState->setData(AP_Data);
}

void MainWindow::breakInSettingsChangedRamp()
{
    qWarning() << "Break in settings changed Ramp";
    AP_Data.breakInTableRamp = brkRampSettings->getTable();
    if(currentState != NULL) currentState->setData(AP_Data);
}

void MainWindow::hwSettingsChanged()
{
    qWarning() << "Hardware settings window closed, values updated";
    for(int i=0; i<allStates.size(); i++)
    {
        allStates[i]->setHardwareVals(hw_win);
    }
    for(int i=0; i<allWorkers.size(); i++)
    {
        allWorkers[i]->setHardwareVals(hw_win);
    }
}

void MainWindow::preferencesWindowClosed()
{
    AP_Data.dataDir     = pref_win->getDataDir();
    AP_Data.fileFormat  = pref_win->getFileFormat();
    qWarning() << "FileFormat: " << AP_Data.fileFormat;
    savePreferences();
}

void MainWindow::on_actionBreakInSuctionWindow_triggered()
{
    brkSuckSettings->setTableData(AP_Data.breakInTableSuction);
    brkSuckSettings->show();
}

void MainWindow::on_actionBreakInZapWindow_triggered()
{
    brkZapSettings->setTableData(AP_Data.breakInTableZap);
    brkZapSettings->show();
}

void MainWindow::on_actionBreakInRampWindow_triggered()
{
    brkRampSettings->setTableData(AP_Data.breakInTableRamp);
    brkRampSettings->show();
}

void MainWindow::on_actionAutopatcher_Settings_triggered()
{
    if(stateRunning && currentState != NULL) AP_Data = currentState->getData();
    ap_win->setVals(AP_Data);
    ap_win->show();
    qWarning() << "AP settings window launched";
}

void MainWindow::on_actionHardware_Settings_triggered()
{
    hw_win->show();
    qWarning() << "HW settings window launched.";
}

void MainWindow::closeEvent(QCloseEvent *e)
{
    QMainWindow::closeEvent(e);
    if(ap_win->isVisible()) ap_win->close();
    if(brkRampSettings->isVisible()) brkRampSettings->close();
    if(brkSuckSettings->isVisible()) brkSuckSettings->close();
    if(brkZapSettings->isVisible()) brkZapSettings->close();
}

void MainWindow::on_checkBoxPauseOnRemoval_stateChanged(int)
{

}

void MainWindow::on_pushButtonSCARACalibrate_released()
{
    hardwareCalibState.gui_calibrateSCARA();
}

void MainWindow::on_pushButtonArm1Clockwise_released()
{
    currentState->gui_rotateSCARA(1,1,numStepsScaraAdjust);
}

void MainWindow::on_pushButtonArm1Counterclockwise_released()
{
    currentState->gui_rotateSCARA(1,0,numStepsScaraAdjust);
}

void MainWindow::on_pushButtonArm2Counterclockwise_released()
{
    currentState->gui_rotateSCARA(2,0,numStepsScaraAdjust);
}

void MainWindow::on_pushButtonArm2Clockwise_released()
{
    currentState->gui_rotateSCARA(2,1,numStepsScaraAdjust);
}

void MainWindow::on_radioButton_toggled(bool checked)
{
    if(checked)
    {
        numStepsScaraAdjust = ui->radioButton->text().split(QRegExp("([^0-9])+"))[0].toInt();
    }
}

void MainWindow::on_radioButton_2_toggled(bool checked)
{
    if(checked)
    {
        numStepsScaraAdjust = ui->radioButton_2->text().split(QRegExp("([^0-9])+"))[0].toInt();
    }
}

void MainWindow::on_radioButton_3_toggled(bool checked)
{
    if(checked)
    {
        numStepsScaraAdjust = ui->radioButton_3->text().split(QRegExp("([^0-9])+"))[0].toInt();
    }
}

void MainWindow::on_radioButton_4_toggled(bool checked)
{
    if(checked)
    {
        microfilFillVolumeAdjust = ui->radioButton_4->text().split(QRegExp("([^0-9])+"))[0].toInt();
    }
}
void MainWindow::on_radioButton_5_toggled(bool checked)
{
    if(checked)
    {
        microfilFillVolumeAdjust = ui->radioButton_5->text().split(QRegExp("([^0-9])+"))[0].toInt();
    }
}
void MainWindow::on_radioButton_6_toggled(bool checked)
{
    if(checked)
    {
        microfilFillVolumeAdjust = ui->radioButton_6->text().split(QRegExp("([^0-9])+"))[0].toInt();
    }
}
void MainWindow::on_pushButtonDispenseLoadPipettes_released()
{
    if(currentState != NULL)
        currentState->gui_dispenseVolumeFiller(microfilFillVolumeAdjust,false);
}
void MainWindow::on_pushButtonAspirateLoadPipettes_released()
{
    if(currentState != NULL)
        currentState->gui_aspirateVolumeFiller(microfilFillVolumeAdjust,false);
}
void MainWindow::on_pushButtonNextLoadPipettes_released()
{
    if(currentState != NULL)
        currentState->gui_pushbuttonNextLoadPipettesReleased();
}
void MainWindow::on_actionReset_Carousel_triggered()
{
    scara->resetCarousel();
}
void MainWindow::on_actionFill_Pipette_triggered()
{
    disconnectState(currentState);
    QMetaObject::invokeMethod(scara,"fill1",Qt::QueuedConnection,Q_ARG(bool,false));
    QMetaObject::invokeMethod(filler,"enablePressureControl",Qt::QueuedConnection,Q_ARG(bool,true),Q_ARG(bool,false));
    QMetaObject::invokeMethod(scara,"fill2",Qt::QueuedConnection,Q_ARG(bool,false));
    QThread::sleep(2);
    QMetaObject::invokeMethod(scara,"dispenseHighPressure",Qt::QueuedConnection,Q_ARG(int,100),Q_ARG(bool,false));
    QThread::sleep(1);
    QMetaObject::invokeMethod(filler,"enablePressureControl",Qt::QueuedConnection,Q_ARG(bool,false));
    QMetaObject::invokeMethod(scara,"fill3",Qt::QueuedConnection,Q_ARG(bool,false));
    connectState(currentState);
}


void MainWindow::on_radioButton_7_toggled(bool checked)
{
    if(checked)
    {
        pipetteAdjustDistance = ui->radioButton_7->text().split(QRegExp("([^0-9])+"))[0].toInt();
    }
}
void MainWindow::on_radioButton_8_toggled(bool checked)
{
    if(checked)
    {
        pipetteAdjustDistance = ui->radioButton_8->text().split(QRegExp("([^0-9])+"))[0].toInt();
        qWarning() << pipetteAdjustDistance << ui->radioButton_8->text().split(QRegExp("([^0-9])+"))[0] ;
    }
}
void MainWindow::on_radioButton_9_toggled(bool checked)
{
    if(checked)
    {
        pipetteAdjustDistance = ui->radioButton_9->text().split(QRegExp("([^0-9])+"))[0].toInt();
    }
}
void MainWindow::on_radioButton_10_toggled(bool checked)
{
    if(checked)
    {
        pipetteAdjustDistance = ui->radioButton_10->text().split(QRegExp("([^0-9])+"))[0].toInt();
    }
}
void MainWindow::on_pushButtonUpAdjust_released()
{
    if(currentState != NULL)
        currentState->gui_upAdjustBtn(pipetteAdjustDistance);
}
void MainWindow::on_pushButtonDownAdjust_released()
{
    if(currentState != NULL)
        currentState->gui_downAdjustBtn(pipetteAdjustDistance);
}

void MainWindow::on_actionLoad_microfil_20uL_triggered()
{
    if(currentState != NULL)
        currentState->gui_Load20uLInMicrofil(false);
}

void MainWindow::on_actionHome_Thorlabs_Motor_triggered()
{
    tMotor->calibrate();
}

void MainWindow::on_actionOpen_Headstage_Clamp_triggered()
{
    headstageClamp->openClamp(false);
}

void MainWindow::on_actionRetract_Headstage_Wire_triggered()
{
    headstageClamp->retractWire(false);
}

void MainWindow::on_pushButtonPause_toggled(bool checked)
{
    if(checked)
    {
        ui->pushButtonPause->setText("Resume");
    }
    else
    {
        ui->pushButtonPause->setText("Pause");
    }
}

void MainWindow::on_actionPreferences_triggered()
{
    pref_win->setFileFormat(AP_Data.fileFormat);
    pref_win->setDataDir(AP_Data.dataDir);
    pref_win->show();
}

void MainWindow::on_actionClose_Headstage_Clamp_triggered()
{
    headstageClamp->closeClamp(false);
}

void MainWindow::on_actionInsert_Headstage_Wire_triggered()
{
    headstageClamp->threadWire(false);
}

void MainWindow::on_actionFinish_Visual_Stimuli_triggered()
{
    if(currentState != NULL)
    {
        currentState->visual_finished();
    }
}

void MainWindow::on_actionReset_Brain_Height_On_New_Pipette_triggered()
{

}

void MainWindow::on_actionReset_Brain_Height_On_New_Pipette_toggled(bool toggled)
{
    if(toggled)
    {
        qWarning() << "Brain height will be readjusted the next time a trial is started";
        busy_start("Brain height will be readjusted when a new trial starts.");
        if(currentState !=NULL)
        {
            AutopatcherSettings tmp = currentState->getData();
            tmp.brainHeightSet = 0;
            currentState->setData(tmp);
        }
    }
    else
    {
        AutopatcherSettings tmp = currentState->getData();
        if(tmp.brainHeightSet == 0)
        {
            if(currentState !=NULL && tmp.brainHeight != 0)
            {
                tmp.brainHeightSet = 1;
                currentState->setData(tmp);
            }
        }
    }
}

void MainWindow::on_actionFiller_Valve_On_triggered()
{
    QMetaObject::invokeMethod(filler,"enablePressureControl",Qt::QueuedConnection,Q_ARG(bool,true),Q_ARG(bool,false));
}

void MainWindow::on_actionFiller_Valve_Off_triggered()
{
    QMetaObject::invokeMethod(filler,"enablePressureControl",Qt::QueuedConnection,Q_ARG(bool,false),Q_ARG(bool,false));
}
