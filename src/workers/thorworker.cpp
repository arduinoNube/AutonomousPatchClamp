#include "thorworker.h"
#include <QDebug>
#include <QThread>

ThorWorker::ThorWorker(QObject *parent) : Worker(parent)
{
    chanID = QVariant(0); // Usually only 1 channel (0)
    serialNum = 83840919;
    motor = NULL;
    motorPosition = 0;
}
ThorWorker::~ThorWorker()
{
    moveMotorAbsolute(0,2);
    motor->dynamicCall("StopCtrl");
    delete motor;
}

void ThorWorker::setHardwareVals(HardwareSettingsWindow *hw_win)
{
    fastVel = hw_win->thorFastVel;
    slowVel = hw_win->thorSlowVel;
}

void ThorWorker::aboutToClose()
{

}

void ThorWorker::init(int serial)
{
    if(motor != NULL)
    {
        delete motor;
    }
    serialNum = serial;
    motor = new QAxWidget();  // Has to be created in the GUI thread
    motor->setControl("MGMOTOR.MGMotorCtrl.1");  // This has to happen in the GUI thread too
    motor->setProperty("HWSerialNum",QVariant(serialNum));
    motor->dynamicCall("StartCtrl");
    bool flag(0);
    QList<QVariant> args;
    args.push_back(QVariant(flag));
    motor->dynamicCall("GetHWCommsOK(QVariant&)",args);
    if(args[0].toBool())
    {
        emit initReady();
    }
    else
    {
        emit initError();
    }
}
void ThorWorker::calibrate()
{
    qWarning() << "Calibrating ThorLabs motor (worker)";
    motor->dynamicCall("StartCtrl");
    QThread::msleep(500);

    connect(motor,SIGNAL(HomeComplete(int)),this,SLOT(homeFinished(int)));
    connect(motor,SIGNAL(MoveComplete(int)),this,SLOT(moveFinished(int)));

    motor->dynamicCall("EnableHWChannel(QVariant)",chanID);
    QThread::msleep(500); // minimum 500 msecond delay for robust operation.  Anything less will
                          // make the T-Cube controllers crash and then they have to be restarted

    motor->dynamicCall("SetHomeParams(QVariant,QVariant,QVariant,QVariant,QVariant)",chanID,1,4,3,0);
    motor->dynamicCall("SetStageAxisInfo(QVariant,QVariant,QVariant,QVariant,QVariant,QVariant)",chanID,-25,0,1,1,0);

    motor->dynamicCall("SetBLashDist(QVariant,QVariant)",chanID,0);  // Eliminating backlash compensation (reduces accuracy but also eliminates overshoot for small steps down)

    // Homing the motor
    int homedBits  = (1024);
    QList<QVariant> args;
    args.push_back(QVariant(chanID));
    args.push_back(QVariant(3));
    motor->dynamicCall("LLGetStatusBits(int,QVariant&)",args);
    uint val = args[1].toUInt();

    if(val & homedBits)
    {
        qWarning() << "ThorLabs motor already homed, moving to 0.0mm";
        moveMotorAbsoluteWait(0,true);
        emit calibFinished();
    }
    else
    {
        qWarning() << "Homing ThorLabs motor...";
        motor->dynamicCall("MoveHome(QVariant,QVariant)",chanID,QVariant(true));
    }
    motorPosition = 0;
}
void ThorWorker::moveMotorAbsolute(float pos, float vel)
{
    qWarning() << "Moving motor absolute: " << pos;
    motorPosition = pos;  // Units in milimeters
    motor->dynamicCall("SetVelParams(QVariant,QVariant,QVariant,QVariant,)",chanID,0,2,QVariant(vel));
    motor->dynamicCall("SetAbsMovePos(QVariant,QVariant)",chanID,QVariant(pos));
    enableMotor();
    motor->dynamicCall("MoveAbsolute(QVariant,QVariant)",chanID,0);
}
void ThorWorker::moveMotorAbsoluteWait(float pos, float vel)
{
    qWarning() << "Moving motor absolute: " << pos;
    motorPosition = pos;  // Units in milimeters
    motor->dynamicCall("SetVelParams(QVariant,QVariant,QVariant,QVariant,)",chanID,0,2,QVariant(vel));
    motor->dynamicCall("SetAbsMovePos(QVariant,QVariant)",chanID,QVariant(pos));
    enableMotor();
    motor->dynamicCall("MoveAbsolute(QVariant,QVariant)",chanID,1);
}
void ThorWorker::moveMotorRelative(float dist, float vel)
{
    motorPosition = dist + motorPosition;  // Units in milimeters
    qWarning() << "Moving motor relative: " << dist << motorPosition << vel;
    motor->dynamicCall("SetVelParams(QVariant,QVariant,QVariant,QVariant,)",chanID,0,2,QVariant(vel));
    motor->dynamicCall("SetRelMoveDist(QVariant,QVariant)",chanID,QVariant(dist));
    enableMotor();
    motor->dynamicCall("MoveRelative(QVariant,QVariant)",chanID,0);
}
void ThorWorker::homeFinished(int)
{
    motor->dynamicCall("SetVelParams(QVariant,QVariant,QVariant,QVariant,)",chanID,0,2,2);
    emit calibFinished();
}
void ThorWorker::moveFinished(int)
{
    emit moveMotorFinished();
}
void ThorWorker::enableMotor()
{
    motor->dynamicCall("EnableHWChannel(QVariant)",chanID);
    QThread::msleep(500);
}
float ThorWorker::getPosition() const
{
    return motorPosition;
}
void ThorWorker::getPosition(bool sendEvent)
{
    if(sendEvent)
    {
        emit currentMotorPosition(motorPosition);
    }
}
void ThorWorker::haltMotor()
{
    motor->dynamicCall("StopProfiled(QVariant)",chanID);
}
