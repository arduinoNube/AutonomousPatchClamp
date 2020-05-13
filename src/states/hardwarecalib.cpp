#include "hardwarecalib.h"
#include <workers/autopatcherworker.h>
#include <ui/hardwaresettingswindow.h>

HardwareCalib::HardwareCalib(QObject *parent) : State(parent)
{
    name = "Hardware Calibration";
    description = "This state calibrates the autopatcher control box pressures (cycles the valves), \
allows the user to adjust the robot arm so that it's ready to calibrate and then the user clicks \
to start the calibration of the robot arm.  This state also runs the \"home\" routine for the \
ThorLabs motor.";
    thor_serialNum = 0;
    connect(&timer1,SIGNAL(timeout()),this,SLOT(checkCalibrated()),Qt::QueuedConnection);
    ptrScaraCmdFinished     = NULL;
}

HardwareCalib::~HardwareCalib()
{

}

void HardwareCalib::pauseState(bool) // 1 tells the state to pause, 0 to continue
{

}

void HardwareCalib::haltState()
{

}

void HardwareCalib::setHardwareVals(HardwareSettingsWindow *hw_win)
{
    thor_serialNum = hw_win->thorSerial;
    thor_slowVel   = hw_win->thorSlowVel;
    thor_fastVel   = hw_win->thorFastVel;
}

// **************** PROCEDURAL CODE START *******************
// Code in this section should be very sequential and each
// method should be called after the previous.  This is the
// algorithmic portion of this state.
void HardwareCalib::firstRun()
{    
    decision    = 0;
    scaraCalib  = 0;
    thorCalib   = 0;
    ptrScaraCmdFinished = NULL;

    emit scara_powerUp();

    emit autopatcher_switchPressure(AutopatcherWorker::PRESSURE_HIGH_P,0);
    emit autopatcher_switchPressure(AutopatcherWorker::PRESSURE_LOW_P,0);
    emit autopatcher_switchPressure(AutopatcherWorker::PRESSURE_HIGH_V,0);
    emit autopatcher_switchPressure(AutopatcherWorker::PRESSURE_LOW_V,0);
    emit autopatcher_switchPressure(AutopatcherWorker::PRESSURE_ATM,0);
    emit autopatcher_switchBNC(1,0);
    emit autopatcher_softwarePressure(1,0);

    emit thorLabsMotor_calibrate();
    emit gui_enablePushButtonCalibrate(true);

    emit gui_setCurrentPageIndex("page_hardware_calib");
    emit gui_enablePages(true);
    emit gui_busy_start("Calibrating ThorLabs motor.  After adjusting the arms so they are parallel, click \"Calibrate\"");
    // execution waiting on GUI signal saying it's ok to calibrate
}

void HardwareCalib::gui_calibrateSCARA()
{
    emit scara_powerUp();
    emit scara_calibrate();
    emit gui_enablePages(false);
    emit gui_busy_start("Calibrating robot arm.");
    timer1.setSingleShot(true);
    timer1.start(200);
    ptrScaraCmdFinished = &A;
}

void HardwareCalib::A()
{
    scaraCalib = 1;
    qWarning() << "SCARA calibrated.";
}

void HardwareCalib::thorLabsMotor_calibrateFinished()
{
    thorCalib = 1;
    qWarning() << "ThorLabs motor calibrated.";
    emit gui_busy_stop("Ready.  After adjusting the arms so they are parallel, click \"Calibrate\"");
}

void HardwareCalib::checkCalibrated()
{
    if(scaraCalib && thorCalib)
    {
        ptrScaraCmdFinished = &B;
        pipetteNumberCounter = 0;
        emit scara_moveNext(true);
    }
    else
    {
        timer1.start();
        emit gui_enablePushButtonCalibrate(false);
    }
}

void HardwareCalib::B()
{
    ptrScaraCmdFinished = &C;
    C();
}

void HardwareCalib::C()
{
    pipetteNumberCounter++;
    if(data.startingPipetteNumber > pipetteNumberCounter)
    {
        emit scara_rotateCarouselNext(true);
    }
    else
    {
        finish();
    }
}

void HardwareCalib::finish()
{
    ptrScaraCmdFinished = NULL;
    emit gui_busy_stop("Ready");
    decision = 1;
    emit stateFinished();
}

