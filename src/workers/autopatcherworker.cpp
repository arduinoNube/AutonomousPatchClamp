#include "autopatcherworker.h"
#include "serialworker.h"
#include <QDebug>
#include <QThread>
#include <cmath>
#include <QApplication>

AutopatcherWorker::AutopatcherWorker(QObject *parent): SerialWorker(parent)
{
    highP = 800 *1.0;  //mbar
    lowP  = 20  *1.15; //mbar
    highV = 345 *1.2;  //mbar
    lowV  = 20  *1.3;  //mbar  (1.* are fudge factors that act as a calibration factor for the pressure regualtors)
    workerName = "Autopatcher";
    //qWarning() << "HereA" <<  highP << lowP << highV << lowV;

}

AutopatcherWorker::~AutopatcherWorker()
{

}

void AutopatcherWorker::setHardwareVals(HardwareSettingsWindow *win)
{
    qWarning() << "Pressure settings for the AutopatcherWorker were set...";
    highP = win->highP*1.0 ;
    lowP  = win->lowP *1.15;
    highV = win->highV*1.2 ;
    lowV  = win->lowV *1.3 ;
    if(port != NULL)
    {
        if(port->isOpen() && port->isWritable())
        {
            //qWarning() << "Here";
            setPressure(PRESSURE_HIGH_P,highP   , 0);
            setPressure(PRESSURE_LOW_P ,lowP    , 0);
            setPressure(PRESSURE_LOW_V ,lowV    , 0);
            setPressure(PRESSURE_HIGH_V,highV   , 0);
            //qWarning() << "Here2";
        }
    }
    //qWarning() << "Here" <<  highP << lowP << highV << lowV;
}

void AutopatcherWorker::initInThread()
{
    timer1 = new QTimer();    
    timer1->setSingleShot(true);
    connect(timer1,SIGNAL(timeout()),this,SLOT(timer1_timeout()),Qt::QueuedConnection);
}

void AutopatcherWorker::moveThreadBack()
{

}

void AutopatcherWorker::aboutToClose()
{
    sendSerialCommand("switchAtm",false);
    closePort();
}

void AutopatcherWorker::switchPressure(int flag ,bool sendEvent)
{
    switch(flag)
    {
//        sendSerialCommand("V2 0");  // OFF = vacuum,       ON = atmospheric
//        sendSerialCommand("V3 0");  // OFF = low pressure, ON = high pressure
//        sendSerialCommand("V1 1");  // Output selector from valves 2 and 3
        case PRESSURE_HIGH_P:
            sendSerialCommand("switchHighP", sendEvent);
            qWarning() << "Pressure switched HIGHP";
            break;

        case PRESSURE_LOW_P:
            sendSerialCommand("switchLowP", sendEvent);
            qWarning() << "Pressure switched LOWP";
            break;

        case PRESSURE_ATM:
            sendSerialCommand("switchAtm", sendEvent);
            qWarning() << "Pressure switched ATM";
            break;

        case PRESSURE_HIGH_V:
            sendSerialCommand("switchHighV", sendEvent);
            qWarning() << "Pressure switched HIGHV";
            break;

        case PRESSURE_LOW_V:
            sendSerialCommand("switchLowV", sendEvent);
            qWarning() << "Pressure switched LOWV";
            break;

        default:
        qWarning() << "Bad pressure switch value";
            break;
    }
}

void AutopatcherWorker::hardwareInit()
{
    QThread::sleep(2);
    softwarePressure(1, 0);
    softwarePressure(1, 0);
    setPressure(PRESSURE_HIGH_P,highP   , 0);
    setPressure(PRESSURE_LOW_P ,lowP    , 0);
    setPressure(PRESSURE_LOW_V ,lowV    , 0);
    setPressure(PRESSURE_HIGH_V,highV   , 0);
    setPressure(PRESSURE_HIGH_P,highP   , 0);
    //qWarning() << "Here2" <<  highP << lowP << highV << lowV;

}

void AutopatcherWorker::switchBNC(bool on,bool sendEvent)
{
    if(on)
    {
        sendSerialCommand("switchBNC=1", sendEvent);
    }
    else
    {
        sendSerialCommand("switchBNC=0", sendEvent);
    }
}

void AutopatcherWorker::softwarePressure(bool flag, bool sendEvent)
{
    if(flag)
    {
        sendSerialCommand("knobsEnabled=0", sendEvent);
    }
    else
    {
        sendSerialCommand("knobsEnabled=1", sendEvent);
    }
}

void AutopatcherWorker::setPressure(int num, double val, bool sendEvent)
{
    switch(num)
    {
        case (PRESSURE_HIGH_P):
            highP = val;
            if((val>0) && (val<=999))
            {
                sendSerialCommand("setHighP="+QString::number(val,'f',0), sendEvent);
            }
            else
            {
                if(val < 0)
                {
                    sendSerialCommand("setHighP="+QString::number(0,'f',0), sendEvent);
                }
                if(val > 999)
                {
                    sendSerialCommand("setHighP="+QString::number(999,'f',0), sendEvent);
                }
                qWarning() << "CODE ERROR: Pressure value is too large or too small: " << val << " mbar. It should be between 0 and 999 mbar.";
            }
            break;

        case (PRESSURE_LOW_P):
            lowP = val;
            if((val>0) && (val <= 99.9))
            {
                sendSerialCommand("setLowP="+QString::number(val,'f',1), sendEvent);
            }
            else
            {
                if(val < 0)
                {
                    sendSerialCommand("setLowP="+QString::number(0,'f',0), sendEvent);
                }
                if(val > 99.9)
                {
                    sendSerialCommand("setLowP="+QString::number(99.9,'f',0), sendEvent);
                }
                qWarning() << "CODE ERROR: Pressure value is too large or two small: " << val << " mbar. It should be between 0 and 99.9 mbar.";
            }
            break;

        case (PRESSURE_LOW_V):
            lowV = val;
            if((val>0) && (val<=99.9))
            {
                sendSerialCommand("setLowV="+QString::number(val,'f',1), sendEvent);
            }
            else
            {
                if(val < 0)
                {
                    sendSerialCommand("setLowV="+QString::number(0,'f',0), sendEvent);
                }
                if(val > 99.9)
                {
                    sendSerialCommand("setLowV="+QString::number(99.9,'f',0), sendEvent);
                }
                qWarning() << "CODE ERROR: Vacuum value is too large or too small: " << val << " mbar. It should be between 0 and 99.9 mbar.";
            }
            break;

        case (PRESSURE_HIGH_V):
            highV = val;
            if((val >0) && (val < 999))
            {
                sendSerialCommand("setHighV="+QString::number(val,'f',0), sendEvent);
            }
            else
            {
                if(val < 0)
                {
                    sendSerialCommand("setLowV="+QString::number(0,'f',0), sendEvent);
                }
                if(val > 999)
                {
                    sendSerialCommand("setLowV="+QString::number(999,'f',0), sendEvent);
                }
                qWarning() << "CODE ERROR: Vacuum value is too large or too small: " << val << " mbar. It should be between 0 and 999 mbar.";
            }
            break;
    }
}

void AutopatcherWorker::breakIn(int time,int msWaitBetween,int numPulses)
{
    for(int i=0; i<numPulses; i++)
    {
     sendSerialCommand("break="+QString::number(time), 0);
     QThread::msleep(msWaitBetween+time);
    }
     emit breakInFinished();
}

void AutopatcherWorker::breakInRamp(int time , int pressure)
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
    sendSerialCommand("rampBreak="+QString::number(pressure)+","+timeS, 0);
    QThread::msleep(round(time*1.2));
    emit breakInFinished();
}

void AutopatcherWorker::breakInRampFeedback(int time)
{
    //setPressure(AutopatcherWorker::PRESSURE_HIGH_V,pressure,false);
    qWarning() << "Ramp break in started.";
    if(time > 9999) time = 9999;
    if(time < 0) time = 0;
    sendSerialCommand("rampFeedBreak"+QString::number(time),0);
    timer1->start(time*2);
}

void AutopatcherWorker::stopRamp()
{
    sendSerialCommand("s",0);
    timer1->stop();
    emit breakInRampFinished();
}

void AutopatcherWorker::timer1_timeout()
{
    qWarning() << "Ramp break in finished.";
    emit breakInRampFinished();
}

