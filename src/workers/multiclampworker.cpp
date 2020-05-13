#include "multiclampworker.h"
#include <QtDebug>
#include <QThread>
#include <QProcess>
#include <string>
#include <QDir>

using namespace std;


MulticlampWorker::MulticlampWorker() : Worker()
{
    error = MCCMSG_ERROR_NOERROR;
    h = MCCMSG_CreateObject(&error);
    MMCisValid = 0;
    scaleVC = 0.02; // (mV/V) External Command Sensitivity
    scaleIC = 400;  // (pA/V) External Command Sensitivity
}

MulticlampWorker::~MulticlampWorker()
{
    MCCMSG_DestroyObject(h);
}


void MulticlampWorker::setHardwareVals(HardwareSettingsWindow *)
{

}

void MulticlampWorker::aboutToClose()
{

}

void MulticlampWorker::setPath(QString p)
{
    path = p;
}

void MulticlampWorker::init(int, QString path)
// the "int" is numMPCS (number of multiclamp headstages) and can be used to specify which headstage you want to use.
// Right now it just takes the first one it finds.
{
    MulticlampWorker::path = path;
//    path.replace("\\","\\\\");
    path.append("\"");
    path.prepend("\"");

    int err = findFirstMulticlamp();
    if(!err)
    {
        MMCisValid = 1;
        emit initReady();
    }
    else
    {        
        qWarning() << "Running multiclamp: " << QDir::toNativeSeparators(path);
        QProcess pro;
        if(!pro.startDetached(QDir::toNativeSeparators(path)))
        {
            qWarning() << "Multiclamp commander couldn't start.  Check the path.";
        }

        QThread::sleep(10);
        error = MCCMSG_ERROR_NOERROR;
        err = findFirstMulticlamp();
        if(!err)
        {
            MMCisValid = 1;
            emit initReady();
        }
        else
        {
            DisplayErrorMsg();
            MMCisValid = 0;
            emit initError();
        }
    }
}


//void MulticlampWorker::init(int numMCPS)
//{
//    // find the first MultiClamp
//    uModel = MCCMSG_HW_TYPE_MC700B; // Identifies MultiClamp 700A or 700B model
//    uCOMPortID = 0; // COM port ID of MultiClamp 700A (1-16)
//    uDeviceID = 0; // Device ID of MultiClamp 700A (1-8)
//    uChannelID = 0; // Headstage channel ID

//    if(MMCisValid)
//    {
//        for(int i=0; i<numMCPS; i++)
//        {
//            selectChannel(1);

//            setMode(MCCMSG_MODE_VCLAMP);

//            setWholeCellCapComp(false);

//            setHoldingVoltage(0);

//            setHoldingCurrent(0);

////            autoFastCompensation();  // Do this after getting a gigaseal
////            autoSlowCompensation();
//            setHoldingVoltageChecked(1);

//            setMode(MCCMSG_MODE_VCLAMP);

//            selectChannel(2);

//            setMode(MCCMSG_MODE_VCLAMP);

//            setWholeCellCapComp(false);

//            setHoldingVoltage(0);

//            setHoldingCurrent(0);

////            autoFastCompensation();
////            autoSlowCompensation();
//            setHoldingVoltageChecked(1);

//            setMode(MCCMSG_MODE_VCLAMP);


////            int err = findNextMulticlamp();
////

////            if(err = 6000)
////            {
////                findFirstMulticlamp();
//                selectChannel(2);  // Change this to change which headstage to use
//                break;
////            }
//        }
//    }

//    QThread::sleep(1);
//    emit initReady();
//}

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
    QThread::msleep(10);
//    qWarning() << uChannelID << " here";
}

double MulticlampWorker::getCommandScale()
{
    return scaleVC;
}

void MulticlampWorker::setCommandScale(double num)
{
    scaleVC = num;
}

void MulticlampWorker::setHoldingVoltageSafe(double volt,bool sendEvent)
{
//    qWarning() << "Setting holding voltage " << volt << "V";
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
    if(sendEvent)
    {
        emit setHoldingVoltageSafeComplete();
    }
}

void MulticlampWorker::setHoldingVoltageRaw(double volt)
{
    if(!MCCMSG_SetHolding(h,volt,&error)){DisplayErrorMsg();}
}

void MulticlampWorker::setHoldingCurrentRaw(double curr)
{
    if(!MCCMSG_SetHolding(h,curr,&error)){DisplayErrorMsg();}
}

void MulticlampWorker::setHoldingCurrentSafe(double curr,bool sendEvent)
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
    if(sendEvent)
    {
        emit setHoldingCurrentSafeComplete();
    }
}


void MulticlampWorker::setHoldingVoltageChecked(bool flag)
{
    setMode(MCCMSG_MODE_VCLAMP);
    if(!MCCMSG_SetHoldingEnable(h, flag, &error)){DisplayErrorMsg();}
}

void MulticlampWorker::setHoldingCurrentChecked(bool flag, bool sendEvent)
{
    setMode(MCCMSG_MODE_ICLAMP);
    if(!MCCMSG_SetHoldingEnable(h, flag, &error)){DisplayErrorMsg();}
    if(sendEvent){ emit holdingCurrentCheckedComplete();}
}


void MulticlampWorker::autoCorrectOffset()
{
    if(!MCCMSG_AutoPipetteOffset(h, &error)){DisplayErrorMsg();}
    qWarning() << "Auto correcting pipette offset.";
    emit autoOffsetComplete();
}


void MulticlampWorker::autoFastCapacitance()
{
    if(!MCCMSG_AutoFastComp(h,&error)){DisplayErrorMsg();}
    emit autoFastCapacitanceComplete();
}

double MulticlampWorker::getFastCapacitanceValue()
{
    // The fast capacitance value should NOT be used as the
    // capacitance compensation value in current clamp according
    // to this article
    // http://mdc.custhelp.com/app/answers/detail/a_id/18716/~/correcting-for-pipette-capacitance-using-a-multiclamp%E2%84%A2-amplifier
    // "In practice, this means that one cannot take the value for Cp Fast
    // compensation done in VC mode and enter it as the Pipette Capacitance
    // Neutralization in IC mode. Pipette Capacitance elimination needs to
    // be independently in VC and IC modes."
    //
    // However, I'm going to allow it anyway and simply undercompensate a bit
    double val(0);
    if(!MCCMSG_GetFastCompCap(h,&val,&error)){DisplayErrorMsg();}
    val = val*pow(10,12);
    qWarning() << "Cp Fast: " << val;
    if(val < 0.0001) val = 0;
    return val;
}

void MulticlampWorker::setFastCapacitanceValue(double val)
{
    if(!MCCMSG_SetFastCompCap(h,val,&error)){DisplayErrorMsg();}
}

void MulticlampWorker::getPipetteCapacitanceCompensation()
{
    double val = getFastCapacitanceValue();
    qWarning() << "Fast Capacitance Value : " << val << " pF";;
    emit pipetteCapacitanceCompensationValue(val);
}

void MulticlampWorker::setPipetteCapacitanceCompensation(double val_pA)
{
    if(!MCCMSG_SetNeutralizationCap(h,val_pA*pow(10,-12),&error)){DisplayErrorMsg();}
}

void MulticlampWorker::enablePipetteCapacitanceCompensation(bool flag)
{
    if(!MCCMSG_SetNeutralizationEnable(h,flag,&error)){DisplayErrorMsg();}
}

void MulticlampWorker::autoSlowCapacitance()
{
    if(!MCCMSG_AutoSlowComp(h,&error)){DisplayErrorMsg();}
}

void MulticlampWorker::autoBridgeBalance()
{
    if(!MCCMSG_AutoBridgeBal(h,&error)){DisplayErrorMsg();}
}

void MulticlampWorker::setBridgeBalance(double resMOhms, bool sendEvent)
{
    if(!MCCMSG_SetBridgeBalEnable(h,1,&error)){DisplayErrorMsg();}
    if(!MCCMSG_SetBridgeBalResist(h,resMOhms*pow(10,6),&error)){DisplayErrorMsg();}
    if(sendEvent){ emit setBridgeBalanceComplete();}
}

void MulticlampWorker::getBridgeBalance()
{
    double val(0);
    if(!MCCMSG_GetBridgeBalResist(h,&val,&error)){DisplayErrorMsg();}
    emit getBridgeBalanceComplete(val);
}

void MulticlampWorker::setMode(int mode)
{
    if(mode == 0)
    {
        if(!MCCMSG_SetMode(h, MCCMSG_MODE_VCLAMP, &error)){DisplayErrorMsg();}
    }
    else if(mode == 1)
    {
        if(!MCCMSG_SetMode(h, MCCMSG_MODE_ICLAMP, &error)){DisplayErrorMsg();}
    }
    else if(mode == 2)
    {
        if(!MCCMSG_SetMode(h, MCCMSG_MODE_ICLAMPZERO, &error)){DisplayErrorMsg();}
    }
    // MCCMSG_MODE_VCLAMP
    // MCCMSG_MODE_ICLAMP
    // MCCMSG_MODE_ICLAMPZERO
    //if(!MCCMSG_SetMode(h, mode, &error)){DisplayErrorMsg();}
}

void MulticlampWorker::injectSlowCurrentEnable(bool flag)
{
    if(flag)
    {
        if(!MCCMSG_SetSlowCurrentInjEnable(h,1,&error)){DisplayErrorMsg();}
    }
    else
    {
        if(!MCCMSG_SetSlowCurrentInjEnable(h,0,&error)){DisplayErrorMsg();}
    }
}

void MulticlampWorker::injectSlowCurrentSetTimeConstant(double time)
{
    if(!MCCMSG_SetSlowCurrentInjSettlingTime(h,time,&error)){DisplayErrorMsg();}
}

void MulticlampWorker::injectSlowCurrentSetVoltage(double volt)
{
    if(!MCCMSG_SetSlowCurrentInjLevel(h,volt,&error)){DisplayErrorMsg();}
}

void MulticlampWorker::leakSubtractionChecked(bool checked)
{
    if(!MCCMSG_SetLeakSubEnable(h,checked,&error)){DisplayErrorMsg();}
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

void MulticlampWorker::zap(double timeSec)
{
    selectChannel(uChannelID);
    if(!MCCMSG_SetZapDuration(h,timeSec,&error)){DisplayErrorMsg();}
    if(!MCCMSG_Zap(h,&error)){DisplayErrorMsg();}
}

void MulticlampWorker::zapWithDelay(double zapTimeSec, int delayTimeMs)
{
    qWarning() << "(multiclamp) Zapping with delay!" ;
    selectChannel(uChannelID);
    if(!MCCMSG_SetZapDuration(h,zapTimeSec,&error)){DisplayErrorMsg();}
    QThread::msleep(delayTimeMs);
    if(!MCCMSG_Zap(h,&error)){DisplayErrorMsg();}
    qWarning() << "(multiclamp) Zapped!" ;

}

void MulticlampWorker::setWholeCellChecked(bool flag)
{
    if(!MCCMSG_SetWholeCellCompEnable(h,flag,&error)){DisplayErrorMsg();}
}
