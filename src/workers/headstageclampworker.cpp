#include "headstageclampworker.h"
#include <QDebug>
#include <QThread>

HeadstageClampWorker::HeadstageClampWorker(QObject *parent) : SerialWorker(parent)
{
    openClampCommand = "o";
    closeClampCommand = "c";
    partialCloseClampCommand = "i";
    //threadWireCommand = "f1400";
    //retractWireCommand = "b1350";
    threadWireCommand = "f1425";
    retractWireCommand = "b1325";
    threaded = -1;
    workerName = "Headstage Clamp";
}

HeadstageClampWorker::~HeadstageClampWorker()
{

}

void HeadstageClampWorker::setHardwareVals(HardwareSettingsWindow *)
{

}

void HeadstageClampWorker::aboutToClose()
{
   closePort();
}

void HeadstageClampWorker::openClamp(bool sendEvent)
{
    sendSerialCommand(openClampCommand, sendEvent);
}

void HeadstageClampWorker::halfClamp(bool sendEvent)
{
    sendSerialCommand(partialCloseClampCommand, sendEvent);
}

void HeadstageClampWorker::closeClamp(bool sendEvent)
{
    sendSerialCommand(closeClampCommand,sendEvent);
}

void HeadstageClampWorker::hardwareInit()
{
    QThread::sleep(3);
    sendSerialCommand(openClampCommand, 0);
}

void HeadstageClampWorker::threadWire(bool sendEvent)
{
    if((threaded == 0) || (threaded == -1))
    {
        sendSerialCommand(threadWireCommand, sendEvent);
        threaded = 1;
    }
}

void HeadstageClampWorker::retractWire(bool sendEvent)
{
    if((threaded == 1) || (threaded == -1))
    {
        sendSerialCommand(retractWireCommand, sendEvent);
        threaded = 0;
    }
}
