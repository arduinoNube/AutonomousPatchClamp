#include "hardwareinit.h"
#include <QDebug>

HardwareInit::HardwareInit(QObject *parent) : State(parent)
{

    timer1.setSingleShot(false);
    timer1.setInterval(200);
    connect(&timer1,SIGNAL(timeout()), this,SLOT(checkInit()));

    a_COM = "";
    s_COM = "";
    f_COM = "";
    h_COM = "";
    multiclampHeadstageNumber = 1;
    multiclampPath = "";
    devName = "Dev1";
    thorSerial = 0;

    visualStimIP = "";
    visualStimPort = "";

    decision = 0;

    name        = "Hardware Initialization";
    description = "This state initializes all the serial COM port connections, \
connects with Multiclamp Commander, and makes sure the DAQ is connected and runs \
a self check on it.";
}

HardwareInit::~HardwareInit()
{

}

// **************** GENERAL SLOTS/FUNCTIONS *******************
void HardwareInit::setHardwareVals(HardwareSettingsWindow *hw_win)
{
    a_COM        = hw_win->a_COM;
    s_COM        = hw_win->s_COM;
    f_COM        = hw_win->f_COM;
    h_COM        = hw_win->h_COM;
    multiclampHeadstageNumber = hw_win->multiclampHeadstageNumber;
    multiclampPath            = hw_win->multiclampPath;
    devName      = hw_win->devName;
    thorSerial   = hw_win->thorSerial;
    thorSlowVel  = hw_win->thorSlowVel;
    thorFastVel  = hw_win->thorFastVel;
    visualStimIP = hw_win->visualStimIP;
    visualStimPort = hw_win->visualStimPort;
}

void HardwareInit::pauseState(bool) // 1 tells the state to pause, 0 to continue
{

}

void HardwareInit::haltState()
{

}

// **************** PROCEDURAL CODE START *******************
// Code in this section should be very sequential and each
// method should be called after the previous.  This is the
// algorithmic portion of this state.
void HardwareInit::firstRun()
{
    decision = 0;

    // Initialization Flags
    autopatcherInit = 0;
    scaraInit = 0;
    fillerInit = 0;
    headstageClampInit = 0;
    multiclampInit = 0;
    thorInit = 0;
    daqInit = 0;
    visualInit = 0;
    lengthInit = 0;

    emit gui_setCurrentPageIndex("page_hardware_init");
    emit gui_enablePages(false);
    emit gui_busy_start("Setting up hardware connections.");

    emit autopatcher_init(a_COM);
    emit scara_init(s_COM);
    emit filler_init(f_COM);
    emit headstageClamp_init(h_COM);
    emit multiclamp_init(multiclampHeadstageNumber,multiclampPath);
    emit daq_init(devName);
    emit thorLabsMotor_init(thorSerial);
    emit visual_init(visualStimIP,visualStimPort);
    emit length_init();

    timer1.start();  // This times out and runs checkInit() repeatably until all the workers respond;
}

// ALL THE SIGNALS EMITTED IN firstRun() RESPOND WITH EITHER A 1 or -1;
// ONCE THEY ARE ALL FINISHED, checkInit() FINISHES THE STATE.  timer1
// CONTINUOUSLY CALLS checkInit().

void HardwareInit::checkInit()
{
    // This function will stop the busy timer if certain conditions are met.
    // It is important that the variables used in the conditions aren't changed
    // by another check function executed after this one in the busyTimeout
    // function.  Otherwise, unpredicted behavior could result.  These "check"
    // functions also change the text of the textStatus and textBusy labels
    // to display messages about the current execution loop.

    // if thorInit, or daqInit are still 0, their respective
    // initialization thread is still running.  1 means that the thread
    // emitted a successful initialization signal.  If it's -1, it emitted
    // a failed initialization signal.

    // If everything initialized properly
    if(autopatcherInit      == 1 &&
       headstageClampInit   == 1 &&
       scaraInit            == 1 &&
       fillerInit           == 1 &&
       thorInit             == 1 &&
       multiclampInit       == 1 &&
       daqInit              == 1 &&
       visualInit           == 1 &&
       lengthInit           == 1)
    {
        timer1.stop();
        emit gui_busy_stop("Ready.");
        emit gui_enableActions(true);
        emit scara_enableEndEffector(true,false);
        emit scara_openEndEffector(false);
        decision = 1;
        emit stateFinished();
        qWarning() << "Initialization completed successfully.";
    }

    // If all the threads finished but at least one failed initialization
    else if((autopatcherInit    != 0) &&
            (headstageClampInit != 0) &&
            (scaraInit          != 0) &&
            (fillerInit         != 0) &&
            (thorInit           != 0) &&
            (multiclampInit     != 0) &&
            (daqInit            != 0) &&
            (visualInit         != 0) &&
            (lengthInit         != 0))
    {
        timer1.stop();
        QString msg = "Hardware initialization failed:  ";

        if(autopatcherInit == -1)
        {
            msg = msg + "Autopatcher error.  (check the serial port name or cable) ";
        }
        if(headstageClampInit == -1)
        {
            msg = msg + "Headstage clamp error.  (check the serial port name or cable) ";
        }
        if(scaraInit == -1)
        {
            msg = msg + "SCARA error.  (check the serial port name or cable) ";
        }
        if(fillerInit == -1)
        {
            msg = msg + "Filler error.  (check the serial port name or cable) ";
        }
        if(thorInit == -1)
        {
            msg = msg + "Thor motor error. ";
        }
        if(multiclampInit == -1)
        {
            msg = msg + "Multiclamp Commander is not running and we couldn't launch it.  Check the path in hardware settings. ";
        }
        if(daqInit == -1)
        {
            msg = msg + "DAQ error. (check the device name or usb cable). Current device name is: " + devName + " ";
        }
        if(visualInit == -1)
        {
            msg = msg + "Visual stimulation computer connection error. (check the IP address and port on the stimulus computer, or the network connection of both comptuers). Current IP: " + visualStimIP + " Port: " + visualStimPort + ".  ";
        }
        if(lengthInit == -1)
        {
            msg = msg + "Length measurement module error. (check to make sure the cameras are connected to the computer and the camera is not being used by another program.";
        }
        msg = msg + "Click GO to retry.";
        emit gui_busy_stop_error(msg);
        emit gui_enablePages(true);
        emit gui_enablePushButtonGO1(true);
        emit gui_setCurrentPageIndex("page_hardware_init");
        emit scara_enableEndEffector(true,false);
        emit scara_openEndEffector(false);
        decision = 0;
        emit stateFinished();
    }
}

// 1. set BNC switch to true
// 2. multiclamp.setPath("\"C:\\Axon\\MultiClamp 700B Commander\\MC700B.exe\"");
