#include "scaraworker.h"
#include <QDebug>
#include <QThread>
#include <QTime>

SCARAWorker::SCARAWorker(QObject *parent) : SerialWorker(parent)
{
    workerName = "SCARA";
}

SCARAWorker::~SCARAWorker()
{

}

void SCARAWorker::setHardwareVals(HardwareSettingsWindow *)
{

}

void SCARAWorker::aboutToClose()
{
    port->close();
    port->open(QIODevice::ReadWrite);   // stops the robot mid path with a hard reset
    sendNextCommand("off");
    QThread::msleep(500);  // Give time for the command to be sent before closing the port.
    closePort();
}

void SCARAWorker::hardwareInit()
{
    // Don't put commands here.  For some reason, it needs to return to the main
    // GUI loop to open the port properly.
    QThread::sleep(10);
}

void SCARAWorker::rotateArm(int armNumber, bool direction, int numSteps)
{
    if(((armNumber == 1) || (armNumber == 2)) &&
       ((numSteps > 0) && (numSteps < 20000)))
    {
        sendSerialCommand("step" + QString::number(direction)+QString::number(armNumber)+QString::number(numSteps),0);
    }
}

void SCARAWorker::calibrate()
{
    qWarning() << "Calibrating SCARA";
    sendSerialCommand("calib", 1);
}

void SCARAWorker::enableEndEffector(bool enable, bool sendEvent)
{
    if(enable)
    {
        sendSerialCommand("c_on", sendEvent);
    }
    else
    {
        sendSerialCommand("c_off", sendEvent);
    }
}

void SCARAWorker::calibrateCarousel(bool sendEvent)
{
    qWarning() << "Calibrating carousel";
    sendSerialCommand("reset_carousel", sendEvent);
}

void SCARAWorker::powerUp()
{
    qWarning() << "Powering up SCARA";
    sendSerialCommand("on",false);
}

void SCARAWorker::powerDown()
{
    qWarning() << "Powering down SCARA";
    sendSerialCommand("off",false);
}


void SCARAWorker::openEndEffector(bool sendEvent)
{
    sendSerialCommand("c_open", sendEvent);
}

void SCARAWorker::partialCloseEndEffector(bool sendEvent)
{
    sendSerialCommand("c_light", sendEvent);
}

void SCARAWorker::closeEndEffector(bool sendEvent)
{
    sendSerialCommand("c_close", sendEvent);
}

void SCARAWorker::moveNext(bool sendEvent)
{
    sendSerialCommand("g", sendEvent);
}

void SCARAWorker::fill1(bool sendEvent)
{
    sendSerialCommand("fill1", sendEvent);
}

void SCARAWorker::fill2(bool sendEvent)
{
    sendSerialCommand("fill2", sendEvent);
}

void SCARAWorker::fill3(bool sendEvent)
{
    sendSerialCommand("fill3", sendEvent);
}

void SCARAWorker::dispenseHighPressure(int msec,bool sendEvent)
{
    sendSerialCommand("HPpulse" + QString::number(msec),sendEvent);
}

void SCARAWorker::resetCarousel()
{
    // We don't want to trigger a "done" event for a different command if
    // it's already processing one.  Using this is still dangeous if
    // because the state will receive the "commandFinished" command
    // whenever this is called from the GUI.  Be prepared for that in
    // your states.
    sendSerialCommand("reset_carousel",0);
}

void SCARAWorker::carouselNextPipette(bool sendEvent)
{
    sendSerialCommand("npipette", sendEvent);
}

void SCARAWorker::peltier(bool on)
{
    if(on)
    {
        sendSerialCommand("p_on",false);
    }
    else
    {
        sendSerialCommand("p_off",false);
    }
}

void SCARAWorker::fan(bool on)
{
    if(on)
    {
        sendSerialCommand("f_on",false);
    }
    else
    {
        sendSerialCommand("f_off",false);
    }
}
