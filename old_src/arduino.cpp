#include "arduino.h"
#include <QDebug>
#include <iostream>
#include <QThread>
#include <cmath>

Arduino::Arduino(QObject *parent) :
    QObject(parent)
{
    highP = 800 *1.0; //mbar
    lowP  = 25  *1.2;  //mbar
    highV = 150 *1.2; //mbar
    lowV  = 20  *1.3;  //mbar  (1.* are fudge factors)

}

Arduino::~Arduino()
{

}

void Arduino::closeArduinoPort()
{
    qWarning() << "Arduino port closed.";
    port->close();
    delete port;
}


void Arduino::init(QString comPort)
{

    port = new QSerialPort();
    QList<QSerialPortInfo> portsInfo(QSerialPortInfo::availablePorts());
    QSerialPortInfo info;
    bool flag = 0;
    int err(999);

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
        qWarning()<< "Arduino COM Port \""<< comPort << "\" not found.";
        err = -1;
        emit arduinoInitError();
    }
    else
    {
        port->setPort(info);
        if(port->open(QIODevice::ReadWrite))
        {
            port->setBaudRate(9600);
            qWarning() << "Arduino COM port opened: " << comPort;
            err = 0;
            port->readAll();  // Clearing the buffer to start

            softwarePressure(1);
            setPressure(PRESSURE_HIGHP,highP);

            setPressure(PRESSURE_LOWP,lowP);
            setPressure(PRESSURE_LOWV,lowV);
            setPressure(PRESSURE_HIGHV,highV);
            setPressure(PRESSURE_HIGHP,highP);
            switchPressure(PRESSURE_HIGHP);
            switchPressure(PRESSURE_LOWP);
            switchPressure(PRESSURE_HIGHV);

            switchPressure(PRESSURE_LOWV);
            switchPressure(PRESSURE_ATM);
            switchBNC(1);
            softwarePressure(1);
            emit arduinoInitReady();
        }
        else
        {
            qWarning() << "Unable to open COM port: "<< comPort;
            err = -1;
            emit arduinoInitError();
        }
    }
}

void Arduino::switchBNC(bool on)
{
    if(on)
    {
        sendSerialCommand("switchBNC=1");
    }
    else
    {
        sendSerialCommand("switchBNC=0");
    }
}


void Arduino::sendSerialCommand(QString str)
{
    str.append("\n");
    port->write(str.toStdString().c_str(),str.length());
    port->flush();

    QByteArray msg, msgTmp1,msgTmp2;

    while(1)
    {
        if(port->waitForReadyRead(100))
        {

            msg.append(port->readAll());
//            qWarning() << msg;
            msgTmp1 = msg;
            msgTmp2 = msg;
            msgTmp1.chop(2);  // Chopping off the end of line characters in case there is some variation in convention
            msgTmp2.chop(1);
//            qWarning() << msg.endsWith("done") << msgTmp1.endsWith("done")<< msgTmp2.endsWith("done");
            if(msg.endsWith("done") || msgTmp1.endsWith("done")|| msgTmp2.endsWith("done"))
            {
                break;
            }
        }
    }
}


void Arduino::switchPressure(int flag)
{

    switch(flag)
    {
//        sendSerialCommand("V2 0");  // OFF = vacuum,       ON = atmospheric
//        sendSerialCommand("V3 0");  // OFF = low pressure, ON = high pressure
//        sendSerialCommand("V1 1");  // Output selector from valves 2 and 3
        case PRESSURE_HIGHP:
            sendSerialCommand("switchHighP");
            qWarning() << "Pressure switched HIGHP";
            break;

        case PRESSURE_LOWP:
            sendSerialCommand("switchLowP");
            qWarning() << "Pressure switched LOWP";
            break;

        case PRESSURE_ATM:
            sendSerialCommand("switchAtm");
            qWarning() << "Pressure switched ATM";
            break;

        case PRESSURE_HIGHV:
            sendSerialCommand("switchHighV");
            qWarning() << "Pressure switched HIGHV";
            break;

        case PRESSURE_LOWV:
            sendSerialCommand("switchLowV");
            qWarning() << "Pressure switched LOWV";
            break;

        default:
        qWarning() << "Bad pressure value";
            break;
    }
}

void Arduino::softwarePressure(bool flag)
{
    if(flag)
    {
        sendSerialCommand("knobsEnabled=0");
    }
    else
    {
        sendSerialCommand("knobsEnabled=1");
    }
}

void Arduino::setPressure(int flag, double val)
{
    switch(flag)
    {

        case (PRESSURE_HIGHP):
            highP = val;
            if((val>0) && (val<=999))
            {
                sendSerialCommand("setHighP="+QString::number(val,'f',0));
            }
            else
            {
                qWarning() << "CODE ERROR: Vacuum value is too large or too small.  It should be between 0 and 999mbar.";
            }
            break;

        case (PRESSURE_LOWP):
            lowP = val;
            if((val>0) && (val < 99.9))
            {
                sendSerialCommand("setLowP="+QString::number(val,'f',1));
            }
            else
            {
                qWarning() << "CODE ERROR: Vacuum value is too large or two small.  It should be between 0 and 99.9mbar.";
            }
            break;

        case (PRESSURE_LOWV):
            lowV = val;
            if((val>0) && (val<99.9))
            {
                sendSerialCommand("setLowV="+QString::number(val,'f',1));
            }
            else
            {
                qWarning() << "CODE ERROR: Vacuum value is too large or too small.  It should be between 0 and 99.9mbar.";
            }
            break;

        case (PRESSURE_HIGHV):
            highV = val;
            if((val >0) && (val < 999))
            {
                sendSerialCommand("setHighV="+QString::number(val,'f',0));
            }
            else
            {
                qWarning() << "CODE ERROR: Vacuum value is too large or too small.  It should be between 0 and 999mbar.";
            }
            break;
    }
}

void Arduino::breakIn(int time,int msWaitBetween,int numPulses)
{
    for(int i=0; i<numPulses; i++)
    {
     sendSerialCommand("break="+QString::number(time));
     QThread::msleep(msWaitBetween+time);
    }
     emit breakInFinished();
}

void Arduino::breakInRamp(int time , int pressure)
{
    QString timeS;
    if(pressure > 999)
    {
        pressure = 999;
    }
    if(pressure < 0)
    {
        pressure = 0;
    }

    if(time>9999)
    {
        timeS = "9999";
    }
    else if(time < 1000 && time >= 100)
    {
        timeS = "0" + QString::number(time);
    }
    else if(time < 100  && time >= 10)
    {
        timeS = "00" + QString::number(time);
    }
    else if(time<10)
    {
        timeS = "000" + QString::number(time);
    }
    else if(time<0)
    {
        timeS = "0000";
    }
    else
    {
        timeS = QString::number(time);
    }
    qWarning() << "Break in Time Ramp: " << time << timeS;
    qWarning() << "Command: " << "rampBreak="+QString::number(pressure)+","+timeS;
    sendSerialCommand("rampBreak="+QString::number(pressure)+","+timeS);
    QThread::msleep(round(time*1.2));
    emit breakInFinished();
}

