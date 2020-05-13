#include "multiclampworker.h"
#include <QtDebug>
#include <arduino.h>
#include <QThread>
#include <QProcess>
#include <string>

using namespace std;


MulticlampWorker::MulticlampWorker() :
    QObject()
{
    error = MCCMSG_ERROR_NOERROR;
    h = MCCMSG_CreateObject(&error);
    MMCisValid = 0;

}

MulticlampWorker::~MulticlampWorker()
{
    MCCMSG_DestroyObject(h);
}

void MulticlampWorker::setPath(QString p)
{
    path = p;
}


void MulticlampWorker::check()
{
    int err = findFirstMulticlamp();
    if(!err)
    {
        MMCisValid = 1;
        emit multiclampInitReady();
    }
    else
    {
        QProcess pro;
        pro.startDetached(path);

        QThread::sleep(10);
        error = MCCMSG_ERROR_NOERROR;
        err = findFirstMulticlamp();
        if(!err)
        {
            MMCisValid = 1;
            emit multiclampInitReady();
        }
        else
        {
            DisplayErrorMsg();
            MMCisValid = 0;
            emit multiclampInitError();
        }
    }
}


void MulticlampWorker::init(int numMCPS)
{

    // find the first MultiClamp
    uModel = MCCMSG_HW_TYPE_MC700B; // Identifies MultiClamp 700A or 700B model
    uCOMPortID = 0; // COM port ID of MultiClamp 700A (1-16)
    uDeviceID = 0; // Device ID of MultiClamp 700A (1-8)
    uChannelID = 0; // Headstage channel ID

    if(MMCisValid)
    {
        for(int i=0; i<numMCPS; i++)
        {
            selectChannel(1);

            setMode(MCCMSG_MODE_VCLAMP);

            setWholeCellCapComp(false);

            setHoldingVoltage(0);

            setHoldingCurrent(0);

//            autoFastCompensation();  // Do this after getting a gigaseal
//            autoSlowCompensation();
            setHoldingVoltageChecked(1);

            setMode(MCCMSG_MODE_VCLAMP);

            selectChannel(2);

            setMode(MCCMSG_MODE_VCLAMP);

            setWholeCellCapComp(false);

            setHoldingVoltage(0);

            setHoldingCurrent(0);

//            autoFastCompensation();
//            autoSlowCompensation();
            setHoldingVoltageChecked(1);

            setMode(MCCMSG_MODE_VCLAMP);


//            int err = findNextMulticlamp();
//

//            if(err = 6000)
//            {
//                findFirstMulticlamp();
                selectChannel(2);  // Change this to change which headstage to use
                break;
//            }
        }
    }

    QThread::sleep(1);
    emit initComplete();
}

void MulticlampWorker::DisplayErrorMsg()
{
    char msg[128];
    MCCMSG_BuildErrorText(h,error,msg,128);
    qWarning() << "Error! " << error << " " << msg;
}


void MulticlampWorker::selectChannel(int id)
{
    uChannelID = id;
    // select this MultiClamp
    if( !MCCMSG_SelectMultiClamp(h, uModel, szSerialNum,
        uCOMPortID, uDeviceID, uChannelID, &error) )
    {
        DisplayErrorMsg();
    }
//    qWarning() << uChannelID << " here";
}

double MulticlampWorker::getCommandScale()
{
    return scale;
}

void MulticlampWorker::setCommandScale(double num)
{
    scale = num;
}

void MulticlampWorker::setHoldingVoltage(double volt)
{
//    qWarning() << "Setting holding voltage " << volt << "V";
    selectChannel(uChannelID);
    UINT mode;
    if(!MCCMSG_GetMode(h,&mode,&error)){DisplayErrorMsg();}
    if(mode != 0)
    {
        if(!MCCMSG_SetMode(h,MCCMSG_MODE_VCLAMP,&error)){DisplayErrorMsg();}
        if(!MCCMSG_SetHolding(h,volt,&error)){DisplayErrorMsg();}
        if(mode == 1)
        {
            if(!MCCMSG_SetMode(h,MCCMSG_MODE_ICLAMP,&error)){DisplayErrorMsg();}
        }
        else if(mode == 2)
        {
            if(!MCCMSG_SetMode(h,MCCMSG_MODE_ICLAMPZERO,&error)){DisplayErrorMsg();}
        }
    }
    else
    {
        if(!MCCMSG_SetHolding(h,volt,&error)){DisplayErrorMsg();}
    }
}

void MulticlampWorker::setHoldingCurrent(double curr)
{
    UINT mode;
//    qWarning() << "Setting the holding current to " << curr << "pA";
    if(!MCCMSG_GetMode(h,&mode,&error)){DisplayErrorMsg();}
    if(mode != 1)
    {
        if(!MCCMSG_SetMode(h,MCCMSG_MODE_ICLAMP,&error)){DisplayErrorMsg();}
        if(!MCCMSG_SetHolding(h,curr,&error)){DisplayErrorMsg();}
        if(mode == 0)
        {
            if(!MCCMSG_SetMode(h,MCCMSG_MODE_VCLAMP,&error)){DisplayErrorMsg();}
        }
        else if(mode == 2)
        {
            if(!MCCMSG_SetMode(h,MCCMSG_MODE_ICLAMPZERO,&error)){DisplayErrorMsg();}
        }
    }
    else
    {
        if(!MCCMSG_SetHolding(h,curr,&error)){DisplayErrorMsg();}
    }
}


void MulticlampWorker::setHoldingVoltageChecked(bool flag)
{

    if(!MCCMSG_SetHoldingEnable(h, flag, &error)){DisplayErrorMsg();}
}


void MulticlampWorker::autoCorrectOffset()
{
    if(!MCCMSG_AutoPipetteOffset(h, &error)){DisplayErrorMsg();}
    emit autoOffsetComplete();
}


void MulticlampWorker::autoFastCompensation()
{
    if(!MCCMSG_AutoFastComp(h,&error)){DisplayErrorMsg();}
}


void MulticlampWorker::autoSlowCompensation()
{
    if(!MCCMSG_AutoSlowComp(h,&error)){DisplayErrorMsg();}
}


void MulticlampWorker::setMode(int mode)
{
    // MCCMSG_MODE_VCLAMP
    // MCCMSG_MODE_ICLAMP
    // MCCMSG_MODE_ICLAMPZERO
    if(!MCCMSG_SetMode(h, mode, &error)){DisplayErrorMsg();}
}


int MulticlampWorker::findFirstMulticlamp()
{
//    qWarning() << "Finding first multiclamp..." << &h;
    if( !MCCMSG_FindFirstMultiClamp(h, &uModel, szSerialNum,
          sizeof(szSerialNum), &uCOMPortID,
          &uDeviceID, &uChannelID, &error) )
    {

    }
//    qWarning() << "First muilticlamp found " << error - MCCMSG_ERROR_NOERROR;
    return(error - MCCMSG_ERROR_NOERROR);
}

int MulticlampWorker::findNextMulticlamp()
{
    if(!MCCMSG_FindNextMultiClamp(h, &uModel, szSerialNum,
                                  sizeof(szSerialNum), &uCOMPortID,
                                  &uDeviceID, &uChannelID, &error)){DisplayErrorMsg(); return error;}
    return -1;
}

void MulticlampWorker::zap(double time)
{
    emit switchPressure(Arduino::PRESSURE_LOWV);
    QThread::msleep(1000);
//    qWarning() << "Zapping! " << time << "us";
    selectChannel(uChannelID);
    if(!MCCMSG_SetZapDuration(h,time,&error)){DisplayErrorMsg();}
    if(!MCCMSG_Zap(h,&error)){DisplayErrorMsg();}
    emit switchPressure(Arduino::PRESSURE_ATM);
    QThread::msleep(200);
    emit zapped();
}

void MulticlampWorker::setWholeCellCapComp(bool flag)
{
    if(!MCCMSG_SetWholeCellCompEnable(h,flag,&error)){DisplayErrorMsg();}
}
