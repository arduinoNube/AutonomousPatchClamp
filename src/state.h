/* This class is designed to be inherited to create several custom states
 * that interact with the same interfaces (signals and slots) on hardware.
 *
 * The basic rules are:
 * 1. write the implementation file (.cpp) of the derived class so that the
 * code is procedural.  For example, every method is executed in turn after
 * the previous one.  This makes the event driven code much more readable
 *
 * 2. When a single SLOT is called multiple times within the state but is
 * NOT a looping type operation where one SLOT could be executed multiple
 * times, use the function pointers to reassign which function is the
 * SLOT that responds to the hardware signal.  This way, the code can still
 * seem procedural
 *
 *
 * GOOD CODE FORMATTING EXAMPLE
 *
 *  --------------
 * |   SLOT 1     |
 * |   (code)     |  (signalA is sent to the hardware.)
 * | emit signalA |
 *  --------------
 *
 *  --------------
 * |   SLOT 2     |  (the hardware reponds to signalA with a signal
 * |   (code)     |   back that triggers SLOT 2)
 * | emit signalB |  (signalB is sent to the hardware)
 *  --------------
 *
 *  SLOTS 1 AND 2 ARE WRITTEN SEQUENTIALLY.  THIS DRASTICALLY IMPROVES READABILITY AND SHOWS THE
 *  ORDER OF THE EVENTS
 *
 *  --------------
 * |   SLOT 3     |
 * |   (code)     |  (the hardware responds to signalB with a signal that triggers SLOT 3)
 * | emit signalC |  (signalC is sent to the hardware)
 *  --------------
 *
 *  --------------
 * |   SLOT 4     |  (the hardware reponds with a signal
 * |   (code)     |   back that triggers SLOT2)
 * | if(i<10)     |
 * | emit signalB |  (signalB is sent to the hardware and causes SLOT 3 to be the next slot triggered)
 * | i++          |
 * | else()       |
 * | emit signalD |  (signalD is sent to the hardware)
 *  --------------
 *
 *  SLOTS 3 AND 4 FORM A LOOPING TYPE OPERATION.  THIS IS FINE AS LONG AS IT IS WELL COMMENTED
 *  SO THAT THE STRUCTURE OF THE EVENT LOOP IS VERY OBVIOUS.  EACH SLOT SHOULD BE LABELED AS PART
 *  OF THE EVENT LOOP.  ONCE THE HARDWARE RESPONDS BACK AND TRIGGERS SLOT 5, SLOTS 3 AND 4 SHOULD
 *  NOT BE USED AGAIN IN THIS EVENT CHAIN.  THIS HELPS KEEP THE COMPLEXITY DOWN
 *
 *  BAD CODE FORMATTING
 *
 *  --------------
 * |   SLOT 5     |
 * |   (code)     |
 * | emit signalE |  (signalE is sent to the hardware.)
 *  --------------
 *
 *  --------------
 * |   SLOT 6     |  (the hardware reponds to signalE with a signal back that triggers SLOT 6)
 * | (code body)  |
 * | if(i=0)      |
 * | emit signalF |  (signalF is sent to the hardware)
 * | i++          |
 * | else(i=1)    |
 * |  (else code) |
 * | emit signalG |  (on the second time through this slot, signalG is emitted)
 *  --------------
 *
 *  --------------
 * |   SLOT 7     |  (the hardware reponds to signalF with a signal back that triggers SLOT 7)
 * |   (code)     |
 * | emit signalE |  (signalE is sent to the hardware.  This triggers SLOT 6 again)
 *  --------------
 *
 *  --------------
 * |   SLOT 8     |  (the hardware reponds to signalG with a signal back that triggers SLOT 8)
 * |   (code)     |
 * | emit signalH |  (signalH is sent to the hardware)
 *  --------------
 *
 * CONFUSED YET?  A BETTER WAY WOULD BE TO SIMPLY MOVE THE "BODY CODE" AND "ELSE CODE" STATEMENT
 * IN SLOT 6 TO A COMPLETELY NEW SLOT (SEE BELOW)
 *
 *  --------------
 * |   SLOT 5     |
 * |   (code)     |
 * | emit signalE |  (signalE is sent to the hardware.)
 *  --------------
 *
 *  --------------
 * |   SLOT 6     |  (the hardware reponds to signalE with a signal back that triggers SLOT 6)
 * | (code body)  |
 * | emit signalF |  (signalF is sent to the hardware)
 *  --------------
 *
 *  --------------
 * |   SLOT 7     |  (the hardware reponds to signalF with a signal back that triggers SLOT 7)
 * |   (code)     |
 * | emit signalE |  (signalE is sent to the hardware.  This triggerd SLOT 6 before, now it just goes to slot 8)
 *  --------------
 *
 *  --------------------
 * |   SLOT 8           |  (the hardware reponds to signalG with a signal back that triggers SLOT 8)
 * | (slot 6 body code) |
 * | (slot 6 else code) |
 * | emit signalH       |  (signalH is sent to the hardware)
 *  --------------------
 *
 *  --------------
 * |   SLOT 9     |  (this was formally slot 8) (the hardware reponds to signalH with a signal back that triggers SLOT 9)
 * |   (code)     |
 * | emit signalH |  (signalH is sent to the hardware etc. etc.)
 *  --------------
 *
 * GRANTED, THE CODE IN SLOT 6 and SLOT 8 ARE DUPLICATES, BUT BY MOVING THE BODY CODE TO AN EXTERNAL FUNCTION
 * THE FLOW OF THE EVENT STRUCTURE IS MUCH MORE SEQUENTIAL LOOKING AND READABLE AND SEPARATES FUNCTIONALITY FROM FLOW
 *
 * THE CODE WITHIN A STATE SHOULD BE MOSTLY PROCEDURAL WITH SOME LOOPING AND LOTS OF SEQUENTIALLY EXECUTED SLOTS.  IF THIS STRUCTURE BECOMES
 * CUMBERSOME LIKE WHERE THERE ARE MANY MORE IF-ELSE OR SWITCH-CASE DECISION POINTS, TRY TO SEPARATE THOSE DECISION POINTS SO THEY
 * ARE MADE BETWEEN STATES, NOT WITHIN IT.
 *
 * THE FEWER RECIRCULATING EVENT LOOPS THERE ARE WITHIN A SINGLE STATE, THE BETTER.  FOR EXAMPLE,
 * IF AT A DECISION POINT, IT COULD JUMP BACK TO EITHER SLOT 4 OR 6, OR CONTINUE TO SLOT 10.  THESE ARE FINE AS LONG AS
 * THE CODE IN THE RECEIVING SLOT DOESN'T BEHAVE ANY DIFFERENTLY THAN IT DID WHEN IT WAS TRIGGERED BEFORE.  THE MINUTE
 * THAT SWITCH-CASE STATMENTS ARE ADDED TO REDIRECT THE FLOW AND EMIT OTHER SIGNALS, IT GETS REALLY CONFUSING TO FOLLOW.
 * EACH SLOT SHOULD BE TRIGGERED AND ONLY LEAD TO A MAXIMUM OF TWO POSSIBLE SIGNAL EMISSIONS OUT (FOR SIGNALS THAT CONTROL
 * THE FLOW OF THE EVENT LOOP), AND IDEALLY ONLY ONE (FOR SIMPLE SEQUENTIAL PROGRAMMING).  THE CASE ABOVE WHERE THERE
 * ARE 3 POSSIBLE DIRECTIONS IS A DEGENERATE CASE THAT SHOULD BE USED SPARINGLY TO IMPROVE READABILITY.
 *
 *
*/
#ifndef STATE_H
#define STATE_H

#include <QObject>
#include <QTimer>
#include <QDebug>
#include <QThread>
#include <workers/autopatcherworker.h>
#include <workers/daqworker.h>
#include <workers/fillerworker.h>
#include <workers/headstageclampworker.h>
#include <workers/multiclampworker.h>
#include <workers/scaraworker.h>
#include <workers/thorworker.h>
#include <workers/lengthmeasurementcameraworker.h>
#include <ui/autopatchersettings.h>

class HardwareSettingsWindow;

class State : public QObject
{
    Q_OBJECT

    // STATE LOGIC CONTROL VARIABLE
    /* When the state completes all of it's procedural code, a decision is made.
     * It lets the state controller know which state to switch to after this state finishes.
     * the variable "decision" can be any number, usually 0, 1, 2, etc depending on how many
     * different outcomes the state could have.  Try to keep this number small.  In the state
     * controller, a truth table uses the value to choose between which of all the other states
     * it should switch to next.  This list is defined in the controller class and each value
     * of "decision" corresponds to a different logical outcome of the state.
     * if decision = -1, state did not reach a decision (error state)
     * if decision = 0, logical outcome 1, usually wait (however it is defined within the state)
     * if decision = 1, logical outcome 2 (however it is defined within the state)
     * etc.
     * */


    QVector<State*> nextStates;  // holds pointers to the states that follow the current state

    // Function pointers (used for specific hardware callback direction)
    //typedef void (State::*DAQ_initResCheckReady_ptr)();
    //DAQ_initResCheckReady_ptr daq_initResCheckReady_ptr = NULL;

protected:
    QString type; // Used to... not implemented yet
    QString name; // Used by dialog boxes to inform the user what the state does and which state to switch to
    QString description;  // Long description of what the state does
    AutopatcherSettings data;
    int thisGigasealStartIndex;

public:

    int decision;  // Used to tell the state machine which of the states in nextStates it should go to next.

    State(QObject *parent);
    ~State();
    virtual void firstRun() = 0;
    void setNextStates(QVector<State*> sts) { nextStates = sts;}
    QVector<State *> getNextStates() { return nextStates;}
    QString getName() { return name;}
    QString getType() { return type;}
    QString getDescription() { return description;}

    virtual void setHardwareVals(HardwareSettingsWindow *){}
    AutopatcherSettings getData() const;
    void setData(const AutopatcherSettings &value);

    // PUT ALL THE METHODS ONLY USED BY ONE STATE HERE
    virtual void gui_pushbuttonGO3Released(ThorWorker *)    { qDebug() << "\"gui_pushbuttonGO3Released\" called."; }


signals:
    // PUT ALL THE METHODS USED BY MULTIPLE STATES IN THE SIGNALS AND SLOTS BELOW
    // DON'T FORGET TO ADD THEM TO THE "CONNECTSTATE" FUNCTION IN MAINWINDOW.CPP
    // ***********************************************************************************
    // **************************** SOFTWARE SIGNAL INTERFACES ***************************
    // ***********************************************************************************
    void stateFinished(); // this signals to the gui to change to the next state (nextState[decision])

    // SSH To visual stim computer
    //void vStim_start();
    //void vStim_stop();
    //void vStim_pause();

    // GUI interfaces
    void gui_busy_start(QString msg);
    void gui_busy_stop(QString msg);
    void gui_busy_stop_error(QString msg);
    void gui_setCurrentPageIndex(int i);
    void gui_setCurrentPageIndex(QString pgObjName);
    void gui_enablePages(bool flag);
    void gui_setTextStatus(QString msg);
    void gui_clearResistancePlot();
    void gui_clearRawDataPlot();
    void gui_clearMemTestPlot();
    void gui_enableActions(bool enable);
    void gui_enablePushButtonGO1(bool enable);
    void gui_pauseButtonEnable(bool enable);
    void gui_pauseButtonVisible(bool enable);
    void gui_enablePushButtonUpAdjust(bool enable);
    void gui_enablePushButtonDownAdjust(bool enable);
    void gui_enablePushButtonGO3(bool enable);
    void gui_enablePushButtonCalibrate(bool enable);
    void gui_incrementTrialNumber();
    void gui_checkedBrainHeightReset(bool checked);

    void gui_updateCurrentPosition();
    void gui_updateCurrentBrainPosition(double depth);
    void gui_plotResData(double res);
    void gui_updateMembraneTestValues(QVector<double> vals);

    // ***********************************************************************************
    // **************************** HARDWARE SIGNAL INTERFACES ***************************
    // ***********************************************************************************
    // Autopatcher Arduino
    void autopatcher_init(QString port);
    void autopatcher_switchBNC(bool flag, bool sendEvent = 0);
    void autopatcher_softwarePressure(bool flag,bool sendEvent = 0);
    void autopatcher_switchPressure(int flag,bool sendEvent = 0);
    void autopatcher_setPressure(int num, double val, bool sendEvent = 0);
    void autopatcher_breakIn(int time,int msWatiBetween,int numPulses);
    void autopatcher_breakInRamp(int time , int pressure);
    void autopatcher_breakInRampFeedback(int time);
    void autopatcher_stopRamp();

    // Headstage Clamp Arduino
    void headstageClamp_init(QString port);
    void headstageClamp_retractWire(bool sendEvent = 0);
    void headstageClamp_threadWire(bool sendEvent = 0);
    void headstageClamp_openClamp(bool sendEvent = 0);
    void headstageClamp_closeClamp(bool sendEvent = 0);
    void headstageClamp_halfClamp(bool sendEvent = 0);

    // SCARA Arduino
    void scara_init(QString port);
    void scara_rotateCarouselNext(bool sendEvent);
    void scara_enableEndEffector(bool enable,bool sendEvent = 0);
    void scara_openEndEffector(bool sendEvent);
    void scara_partialCloseEndEffector(bool sendEvent = 0);
    void scara_closeEndEffector(bool sendEvent = 0);
    void scara_moveNext(bool sendEvent = 0);
    void scara_fill1(bool sendEvent = 0);
    void scara_fill2(bool sendEvent = 0);
    void scara_fill3(bool sendEvent = 0);
    void scara_dispenseHighPressure(int msec,bool sendEvent = 0);
    void scara_closePort();
    void scara_calibrate();
    void scara_calibrateCarousel(bool);
    void scara_rotateArm(int,bool,int);
    void scara_powerDown();
    void scara_powerUp();
    void scara_peltier(bool on);
    void scara_fan(bool on);

    // Filler Arduino
    void filler_init(QString port);
//    void filler_switchValve(bool);
//    void filler_stepPump(int steps);
    void filler_closePort();
    void filler_aspirateVolume(float volume, bool sendEvent = 0);
    void filler_dispenseVolume(float volume, bool sendEvent = 0);
    void filler_enablePressureControl(bool enabled, bool sendEvent = 0);
    void filler_valveOn(bool on);

    // Thor Labs Motors
    void thorLabsMotor_init(int serial);
    void thorLabsMotor_calibrate();
    void thorLabsMotor_enable();
    void thorLabsMotor_disable();
    void thorLabsMotor_moveToAbsolute(float pos, float vel);
    void thorLabsMotor_moveByRelative(float dist, float vel);
    void thorLabsMotor_haltMotor();
    void thorLabsMotor_getPosition(bool sendEvent);

    // Multiclamp Commander
    void multiclamp_init(int num,QString path);
    void multiclamp_selectChannel(int);
    void multiclamp_autoPipetteOffset();
    void multiclamp_autoFastCapacitance();
    void multiclamp_autoSlowCapacitance();
    void multiclamp_getFastCapacitanceValue();
    void multiclamp_getPipetteCapacitanceCompensation();
    void multiclamp_enablePipetteCapacitanceCompensation(bool enabled);
    void multiclamp_setPipetteCapacitanceCompensation(double val);
    void multiclamp_setFastCapacitanceValue(double val);
    void multiclamp_setWholeCellChecked(bool flag);

    void multiclamp_autoBridgeBalance();  // isn't that accurate.  Use the ic_bridgeBalanceAdjustState instead.
    void multiclamp_setBridgeBalance(double resMOhms, bool sendEvent = 0);
    void multiclamp_injectSlowCurrentEnable(bool flag);
    void multiclamp_injectSlowCurrentSetTimeConstant(double time);
    void multiclamp_injectSlowCurrentSetVoltage(double volt);
    void multiclamp_leakSubtractionChecked(bool checked);

    void multiclamp_setMode(int s);
    void multiclamp_setHoldingVSafe(double volts,bool sendEvent = 0);
    void multiclamp_setHoldingISafe(double amps ,bool sendEvent = 0);
    void multiclamp_setHoldingVRaw(double);
    void multiclamp_setHoldingIRaw(double);
    void multiclamp_setHoldingVChecked(bool);
    void multiclamp_setHoldingIChecked(bool, bool sendEvent = 0);
    void multiclamp_zap(double zapTimeSec);
    void multiclamp_zapWithDelay(double zapTimeSec, int delayTimeMs);

    void multiclamp_getBridgeBalance();

    // DAQ
    void daq_init(QString devName);

    void daq_initTask(int);
    void daq_startTask();
    void daq_stopTask();
    void daq_getTaskRunning();
    void daq_trigger();
    void daq_guiUpdateMemTestVals(QVector<double> vals);
    void daq_setCurrentInjAmplitude(double currrentPA);
    void daq_setBACCurrentInjAmplitude(double currentPA);
    void daq_setBACCurrentInjFrequency(double freq);

    // Visual Stimulation
    void visual_init(QString ipAddress, QString port);
    void visual_start(int screenNumber);
    void visual_stop();
    void visual_pause();
    void visual_continue();

    // Length Measurement
    void length_init();
    void length_measure();
    void length_aboutToClose();

public slots:
    // THESE SLOTS ARE THE EXTERNAL INTERFACE.  WHEN INHERITING FROM THIS CLASS,
    // USE THE FUNCTION POINTERS TO REDIRECT THE SLOT FUNCTION AS NECESSARY
    // RATHER THAN USING THESE DIRECTLY TO HELP MAKE THE IMPLEMENTATION FILE
    // MORE READABLE AND SEQUENTIAL.  IF THE SLOTS ARE ONLY USED ONCE, DON'T
    // BOTHER.  JUST REIMPLEMENT THE SLOT IN YOUR SUBCLASS IN THE ORDER THAT
    // THEY ARE USED.
    // ***********************************************************************************
    // ***************************** SOFTWARE SLOT INTERFACES ****************************
    // ***********************************************************************************
    // STATE FLOW CONTROL SLOTS
    virtual void pauseState(bool toggled) = 0;
    virtual void haltState() = 0;

    // GUI Slots
    virtual void gui_upAdjustBtn(int dist)              { qDebug() << "\"gui_upAdjustBtn\" called. " << dist << " mm.";}
    virtual void gui_downAdjustBtn(int dist)            { qDebug() << "\"gui_downAdjustBtn\" called. " << dist << " mm.";}
    virtual void gui_onCheckBoxkLowV_stateChanged(int arg1)         { qDebug() << "\"gui_onCheckBoxkLowV_stateChanged\" called. " << arg1;}
    virtual void gui_onCheckBoxRampOverride_stateChanged(int arg1)  { qDebug() << "\"gui_onCheckBoxRampOverride_stateChanged\" called. " << arg1;}
    virtual void gui_rotateSCARA(int armNumber, bool direction, int numSteps)
    {
        qDebug() << "\"gui_rotateSCARA\" called.  Emitting default signal to SCARA worker...";
        emit scara_rotateArm(armNumber,direction,numSteps);
    }
    virtual void gui_pushbuttonNextLoadPipettesReleased()   { qDebug() << "\"gui_pushbuttonNextLoadPipettesReleased\" called."; }
    virtual void gui_dispenseVolumeFiller(int volume, bool sendEvent)       { qDebug() << "\"gui_dispenseVolumeFiller\" called."; emit filler_dispenseVolume(volume, sendEvent); }
    virtual void gui_aspirateVolumeFiller(int volume, bool sendEvent)       { qDebug() << "\"gui_aspirateVolumeFiller\" called."; emit filler_aspirateVolume(volume, sendEvent); }
    virtual void gui_Load20uLInMicrofil(bool sendEvent)
    {
        qDebug() << "\"gui_Load20uLInMicrofil\" called.";
        emit gui_busy_start("Get ready to put the tip of the microfil into the fluid.");
        emit filler_dispenseVolume(7.6,sendEvent);
        QThread::sleep(5);
        emit gui_busy_start("Insert the tip of the microfil into the fluid.");
        QThread::sleep(0);
        emit filler_aspirateVolume(80, sendEvent);
        QThread::sleep(15);
        emit filler_dispenseVolume(40, sendEvent);
        emit gui_busy_start("Remove the tip of the microfil from the fluid.");
        QThread::sleep(3);
        emit filler_aspirateVolume(7.6,sendEvent);
    }


    // SSH to visual stim computer
    virtual void vStim_stopped()                { qDebug() << "\"vStim_stopped\" called.";}
    virtual void vStim_started()                { qDebug() << "\"vStim_started\" called.";}
    virtual void vStim_paused()                 { qDebug() << "\"vStim_paused\" called.";}

    // ***********************************************************************************
    // ***************************** HARDWARE SLOT INTERFACES ****************************
    // ***********************************************************************************
    // Autopatcher Arduino
    virtual void autopatcher_initReady()        { qDebug() << "\"autopatcher_initReady\" called.";}
    virtual void autopatcher_initError()        { qDebug() << "\"autopatcher_initError\" called.";}
    virtual void autopatcher_breakInComplete()  { qDebug() << "\"autopatcher_breakInComplete\" called.";}
    virtual void autopatcher_breakInRampFinished() { qDebug() << "\"autopatcher_breakInRampFinished\" called.";}

    // Headstage Clamp Arduino
    virtual void headstageClamp_initReady()     { qDebug() << "\"headstageClamp_initReady\" called.";}
    virtual void headstageClamp_initError()     { qDebug() << "\"headstageClamp_initError\" called.";}
    //virtual void headstageClamp_wireRetracted() { qDebug() << "\"headstageClamp_wireRetracted\" called.";}
    //virtual void headstageClamp_wireExtended()  { qDebug() << "\"headstageClamp_wireExtended\" called.";}
    //virtual void headstageClamp_clampOpened()   { qDebug() << "\"headstageClamp_clampOpened\" called.";}
    //virtual void headstageClamp_clampClosed()   { qDebug() << "\"headstageClamp_clampClosed\" called.";}
    //virtual void headstageClamp_clampHalfClosed(){qDebug() << "\"headstageClamp_clampHalfClosed\" called.";}
    virtual void headstageClamp_commandFinished(){ qDebug() << "\"headstageClamp_commandFinished\" called.";}

    // SCARA Arduino
    virtual void scara_initReady()              { qDebug() << "\"scara_initReady\" called.";}
    virtual void scara_initError()              { qDebug() << "\"scara_initError\" called.";}
    virtual void scara_calibrateFinished()      { qDebug() << "\"scara_calibrateFinished\" called.";}
    virtual void scara_commandFinished()        { qDebug() << "\"scara_commandFinished\" called.";}

    // Filler Arduino
    virtual void filler_initReady()             { qDebug() << "\"filler_initReady\" called.";}
    virtual void filler_initError()             { qDebug() << "\"filler_initError\" called.";}
    virtual void filler_commandFinished()       { qDebug() << "\"filler_commandFinished\" called.";}

    // Thor Labs Motors
    virtual void thorLabsMotor_initReady()                  { qDebug() << "\"thorLabsMotor_initReady\" called.";}
    virtual void thorLabsMotor_initError()                  { qDebug() << "\"thorLabsMotor_initError\" called.";}
    virtual void thorLabsMotor_calibrateFinished()          { qDebug() << "\"thorLabsMotor_calibrateFinished\" called.";}
    virtual void thorLabsMotor_moveComplete()               { qDebug() << "\"thorLabsMotor_moveComplete\" called.";}
    virtual void thorLabsMotor_enabled()                    { qDebug() << "\"thorLabsMotor_enabled\" called.";}
    virtual void throLabsMotor_disabled()                   { qDebug() << "\"throLabsMotor_disabled\" called.";}
    virtual void thorLabsMotor_currentMotorPosition(float)  { qDebug() << "\"throLabsMotor_currentMotorPosition\" called.";}

    // Multiclamp Commander
    virtual void multiclamp_initReady()                     { qDebug() << "\"multiclamp_initReady\" called.";}
    virtual void multiclamp_initError()                     { qDebug() << "\"multiclamp_initError\" called.";}
    virtual void multiclamp_autoPipetteOffsetComplete()     { qDebug() << "\"multiclamp_autoPipetteOffsetComplete\" called.";}
    virtual void multiclamp_autoFastCapacitanceComplete()     { qDebug() << "\"multiclamp_autoFastCapacitanceComplete\" called.";}
    virtual void multiclamp_zapComplete()                   { qDebug() << "\"multiclamp_zapComplete\" called.";}
    virtual void multiclamp_setHoldingVoltageSafeComplete() { qDebug() << "\"multiclamp_setHoldingVoltageSafeComplete\" called.";}
    virtual void multiclamp_setHoldingCurrentSafeComplete() { qDebug() << "\"multiclamp_setHoldingCurrentSafeComplete\" called.";}
    virtual void multiclamp_pipetteCapacitanceCompensationValue(double) { qDebug() << "\"multiclamp_pipetteCapacitanceCompensationValue\" called.";}
    virtual void multiclamp_holdingCurrentCheckedComplete() { qDebug() << "\"multiclamp_holdingCurrentCheckedComplete\" called.";}
    virtual void multiclamp_setBridgeBalanceComplete()      { qDebug() << "\"multiclamp_setBridgeBalanceComplete\" called.";}
    virtual void multiclamp_getBridgeBalanceComplete(double) {qDebug() << "\"multiclamp_getBridgeBalanceComplete\" called.";}


    // DAQ
    virtual void daq_initReady()                        { qDebug() << "\"daq_initReady\" called.";}
    virtual void daq_initError()                        { qDebug() << "\"daq_initError\" called.";}
    virtual void daq_initTaskReady()                    { qDebug() << "\"daq_initTaskReady\" called.";}
    virtual void daq_initTaskError()                    { qDebug() << "\"daq_initTaskError\" called.";}
    virtual void daq_resDataReady(double)               { /*qDebug() << "\"daq_resDataReady(double)\" called.";*/}
    virtual void daq_rawDataReady()                     { qDebug() << "\"daq_rawDataReady\" called.";}
    virtual void daq_rawDataReady(QVector<double>)      { /*qDebug() << "\"daq_rawDataReady(QVector<double>)\" called.";*/}
    virtual void daq_memTestValsReady(QVector<double>)  { qDebug() << "\"daq_memTestValsReady\" called.";}
    virtual void daq_rawMemTestDataReady()              { qDebug() << "\"daq_rawMemTestDataReady\" called.";}
    virtual void daq_taskRunning(int)                   { qDebug() << "\"daq_taskRunning(int)\" called.";}
    virtual void daq_currInjDataReady(QVector<double>)  { qDebug() << "\"daq_currInjDataReady\" called.";}
    virtual void daq_bacCurrInjDataReady(QVector<double>)  { qDebug() << "\"daq_bacCurrInjDataReady\" called.";}

    // Visual stimulus
    virtual void visual_initReady() {}
    virtual void visual_initError() {}
    virtual void visual_started() {}
    virtual void visual_paused() {}
    virtual void visual_finished() {}
    virtual void visual_stopped() {}

    // Length Measurement
    virtual void length_initReady()                     {qDebug() << "\"length_initReady\" called.";}
    virtual void length_initError()                     {qDebug() << "\"length_initError\" called.";}
    virtual void length_imagesAquired()                 {qDebug() << "\"length_imagesAquired\" called.";}
    virtual void length_measurementReady(float length)  {qDebug() << "\"length_measurementReady\" called. " << length << " mm";}


private slots:
    //virtual void timer1_timeout(){ qDebug() << "\"timer1_timeout\" called.";}
    //virtual void timer2_timeout(){ qDebug() << "\"timer2_timeout\" called.";}

};

#endif // STATE_H
