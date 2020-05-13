#include "serialworker.h"
#include <QDebug>
#include <QThread>
#include <QTime>

void SerialWorker::sendSerialCommand(QString str,bool sendEvent)
{
    //if(!QString::compare(workerName,"SCARA",Qt::CaseInsensitive))qWarning() << idle << str << workerName;
    if(port->isOpen())
    {
        pendingCommands.push_back(str);
        pendingCommandsResponseFlags.push_back(sendEvent);
        if(idle)
        {
            //qWarning() << "Sending command: " << str << pendingCommands.first();
            sendNextCommand(pendingCommands.first());
        }
        else
        {
            //qWarning() << "Pending commands: " << pendingCommands.length() << str;
        }
    }
    else
    {
        qWarning() << "Serial command was sent by the application to a closed COM port: " + port->portName();
    }
}

void SerialWorker::sendNextCommand(QString str)
{
    str.append("\n");
    port->write(str.toStdString().c_str(),str.length());
    port->flush();
    idle = 0;
    //qWarning() << "Here2 " << str << " " << str.toStdString().c_str() << workerName;
}

void SerialWorker::checkCommandFinished()
{
    //if(!QString::compare(workerName,"SCARA",Qt::CaseInsensitive)) qWarning() << "Checking..." << workerName;
    QByteArray msgTmp1,msgTmp2;
    msg.append(port->readAll());
    msgTmp1 = msg;
    msgTmp2 = msg;
    msgTmp1.chop(2);  // Chopping off the end of line characters in case there is some variation in convention
    msgTmp2.chop(1);
    //if(!QString::compare(workerName,"SCARA",Qt::CaseInsensitive)) qWarning() << msg << workerName;
    QString msgStr(msg);
    if(msgStr.contains("Arm",Qt::CaseInsensitive) && msgStr.contains("done",Qt::CaseInsensitive)) qWarning() << msg;
    if((idle == 0) && (msg.endsWith("done") || msgTmp1.endsWith("done")|| msgTmp2.endsWith("done")))
    {
        //if(!QString::compare(workerName,"Filler",Qt::CaseInsensitive))qWarning() << msg << "DONE" << workerName;
        if(pendingCommandsResponseFlags.first())
        {
            emit commandFinished();
        }
        pendingCommands.pop_front();
        pendingCommandsResponseFlags.pop_front();
        msg.clear();
        if(pendingCommands.size() > 0)
        {
            sendNextCommand(pendingCommands.first());
        }
        else
        {
            idle = 1;
        }
    }
}

void SerialWorker::closePort()
{
    if(port != NULL)
    {
        port->close();
        //qWarning() << port->portName() << " closed.";
        delete port;
        port = NULL;
    }
}

SerialWorker::SerialWorker(QObject *parent) : Worker(parent)
{
    workerName              = "generic serial worker";
    port                    = NULL;
    idle = 1;
}

SerialWorker::~SerialWorker()
{
    if(port != NULL)
    {
        port->close();
        delete port;
    }
}

void SerialWorker::init(QString comPort)
{
    if(port == NULL)
    {
        port = new QSerialPort(this);
    }
    connect(port,SIGNAL(readyRead()),this,SLOT(checkCommandFinished()),Qt::QueuedConnection);
    QList<QSerialPortInfo> portsInfo(QSerialPortInfo::availablePorts());
    QSerialPortInfo info;
    bool flag = 0;

    if(port->isOpen() && (port->portName() == comPort))
    {
        hardwareInit();
        emit initReady();
    }
    else
    {

        for(int i=0; i<portsInfo.length(); i++)
        {
            if(portsInfo[i].portName() == comPort)
            {
                info = portsInfo[i];
                flag = 1;
                break;
            }
        }
        if(flag == 0)
        {
            qWarning()<< workerName << " COM Port \""<< comPort << "\" not found.";
            emit initError();
        }
        else
        {
            port->setPort(info);

            port->setBaudRate(9600);
            port->setFlowControl(QSerialPort::SoftwareControl);   //XON/XOFF
            if(port->open(QIODevice::ReadWrite))
            {
                qWarning() << workerName << " COM port opened: " << comPort;
                hardwareInit();
                emit initReady();
            }
            else
            {
                qWarning() << "Unable to open COM port: "<< comPort;
                emit initError();
            }
        }
    }
}


