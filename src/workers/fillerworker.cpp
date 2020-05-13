#include "fillerworker.h"
#include <QDebug>
#include <QThread>
#include <cmath>

FillerWorker::FillerWorker(QObject *parent) : SerialWorker(parent)
{
    workerName = "Filler";
}

FillerWorker::~FillerWorker()
{

}

void FillerWorker::setHardwareVals(HardwareSettingsWindow *)
{

}


void FillerWorker::aboutToClose()
{
    closePort();
}

void FillerWorker::hardwareInit()
{
    QThread::sleep(3);
    sendSerialCommand("v0", 0);
}

void FillerWorker::aspirateVolume(float volume, bool sendEvent)
{
    // calibration factor: 2100 steps = 40 uL (roughly)
    sendSerialCommand("step00"+QString::number(round(volume*52.5)), sendEvent);
}

void FillerWorker::dispenseVolume(float volume, bool sendEvent)
{
    //qWarning() << "Here2";
    // calibration factor: 2100 steps = 40 uL (roughly)
    sendSerialCommand("step11"+QString::number(round(volume*52.5)), sendEvent);
}

void FillerWorker::enablePressureControl(bool flag, bool sendEvent)
{
    if(flag)
    {
        sendSerialCommand("v1", sendEvent);
    }
    else
    {
        sendSerialCommand("v0", sendEvent);
    }
}

