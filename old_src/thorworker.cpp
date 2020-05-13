#include "ThorWorker.h"
#include <QMessageBox>
#include <QBitArray>
#include <arduino.h>
#include <QTime>
#include <QCoreApplication>

using namespace cv;



ThorWorker::ThorWorker()
{
    hMotorSnum =  67839858;
    stageMotorSnum = 83840919;
    caroselMotorSnum = 83845558;
    mode   = 0; // initialization mode
    chanID = QVariant(0); // Usually only 1 channel (0)
    pos1   = 0;
    pos2   = 0;

    // Initialization flags


    chanID = QVariant(0);
    flag   = QVariant(true);
    err = 0;

    // Motor Position Variables
    stageMotorCurrentPosition   = 0;
    hMotorCurrentPosition       = 0;
    caroselMotorCurrentPosition = 0;
    distToBrain = 0;  // Distance between the camera height of the pipette tip and the surface of the brain
    cameraPipetteHeight = 0;


    // Aquire Pipette flags
    step2FlagA = 0;
    aquirePipetteChainMode = 0;
    hasPipette = 0;

    // Get next pipette flags
    step2FlagG = 0;
    relativeMoveLock = 0;

    QVariant err1(0);
    // Initializing ActiveX Thor Motor Controls.  These have to be initialized in the main GUI thread.
    hMotor = new QAxWidget();
    hMotor->setControl("MGMOTOR.MGMotorCtrl.1");
    hMotor->setProperty("HWSerialNum",QVariant(hMotorSnum));
    hMotor->dynamicCall("StartCtrl");

    stageMotor = new QAxWidget();
    stageMotor->setControl("MGMOTOR.MGMotorCtrl.1");
    stageMotor->setProperty("HWSerialNum",QVariant(stageMotorSnum));
    stageMotor->dynamicCall("StartCtrl");

    caroselMotor = new QAxWidget();
    caroselMotor->setControl("MGMOTOR.MGMotorCtrl.1");
    caroselMotor->setProperty("HWSerialNum",QVariant(caroselMotorSnum));
    caroselMotor->dynamicCall("StartCtrl");

    // These will be set to 1 after they are properly initialized
    hMotorInit = 0;
    stageMotorInit = 0;
    caroselMotorInit = 0;

    // Camera adjustment calibration
    calib = 0.5/640*(1.00); // The 1.11 is a scale factor to tweak the calibration factor.
}


ThorWorker::~ThorWorker()
{
    // Closing the ActiveX Controls    
    hMotor->dynamicCall("StopCtrl");
    stageMotor->dynamicCall("StopCtrl");
    caroselMotor->dynamicCall("StopCtrl");
    delete hMotor;
    delete stageMotor;
    delete caroselMotor;
    delete retryChangePipetteTimer;
    delete initCheckTimer;
}

void ThorWorker::close()
{
    returnPipette();
    hMotor->dynamicCall("StopCtrl");
    stageMotor->dynamicCall("StopCtrl");
    caroselMotor->dynamicCall("StopCtrl");
}

void ThorWorker::init()
{
    initCheckTimer = new QTimer;
    initCheckTimer->setSingleShot(true);
    initCheckTimer->setInterval(500);
    connect(initCheckTimer,SIGNAL(timeout()),this,SLOT(initCheck()),Qt::QueuedConnection);
    connect(hMotor,SIGNAL(HomeComplete(int)),this,SLOT(moveCompleteSlot()));
    connect(hMotor,SIGNAL(MoveComplete(int)),this,SLOT(moveCompleteSlot()));
    retryChangePipetteTimer = new QTimer;
    retryChangePipetteTimer->setSingleShot(true);
    connect(retryChangePipetteTimer,SIGNAL(timeout()),this,SLOT(changePipette()),Qt::QueuedConnection);

    // Velociy Parameters
    velMin = QVariant(0.0);   // 0
    velMax = QVariant(100); // 200
    accel  = QVariant(300); // 999 works but stalls sometimes on startup
    hMotor->dynamicCall("SetVelParams(QVariant,QVariant,QVariant,QVariant)",chanID,velMin,accel,velMax);
    QList<QVariant> args;
    args.push_back(QVariant(chanID));
    args.push_back(QVariant(2400));
    args.push_back(QVariant(1200));
    args.push_back(QVariant(32767));
    args.push_back(QVariant(6500));
    args.push_back(QVariant(7));
    args.push_back(QVariant(6000));
    args.push_back(QVariant(0));
    args.push_back(QVariant(0));
    args.push_back(QVariant(6553));

    hMotor->dynamicCall("SetDCPositionLoopParams(QVariant,QVariant,QVariant,QVariant,QVariant,QVariant,QVariant,QVariant,QVariant,QVariant)",args);

    QList<QVariant> args2;
    args2.push_back(QVariant(chanID));
    args2.push_back(QVariant(20));
    args2.push_back(QVariant(80));
    args2.push_back(QVariant(20000));
    args2.push_back(QVariant(50));
    args2.push_back(QVariant(0));

    hMotor->dynamicCall("SetDCCurrentLoopParams(QVariant,QVariant,QVariant,QVariant,QVariant,QVariant,QVariant,QVariant,QVariant,QVariant)",args2);

    QList<QVariant> args3;
    args3.push_back(QVariant(chanID));
    args3.push_back(QVariant(0));
    args3.push_back(QVariant(40));
    args3.push_back(QVariant(30000));
    args3.push_back(QVariant(50));
    args3.push_back(QVariant(500));

    hMotor->dynamicCall("SetDCSettledCurrentLoopParams(QVariant,QVariant,QVariant,QVariant,QVariant,QVariant,QVariant,QVariant,QVariant,QVariant)",args3);


//    // Homing speed
//    int dir(1);
//    int swtch(1);
//    float vel(20);
//    float offset(30);
//    hMotor->dynamicCall("SetHomeParams(QVariant,QVariant,QVariant,QVariant,QVariant)",chanID,QVariant(dir),QVariant(swtch),QVariant(vel),QVariant(offset));



    float blash(0);
    stageMotor->dynamicCall("SetBLashDist(QVariant,QVariant)",chanID,blash);  // Eliminating backlash compensation (reduces accuracy but also eliminates overshoot for small steps down)
    connect(stageMotor,SIGNAL(HomeComplete(int)),this,SLOT(moveCompleteSlot()));
    connect(stageMotor,SIGNAL(MoveComplete(int)),this,SLOT(moveCompleteSlot()));

    // Homing speed
//    dir     = 2;
//    swtch   = 1;
//    vel     = 2;
//    offset  = 0.299994;
//    stageMotor->dynamicCall("SetHomeParams(QVariant,QVariant,QVariant,QVariant,QVariant)",chanID,QVariant(dir),QVariant(swtch),QVariant(vel),QVariant(offset));



    connect(caroselMotor,SIGNAL(HomeComplete(int)),this,SLOT(moveCompleteSlot()));
    connect(caroselMotor,SIGNAL(MoveComplete(int)),this,SLOT(moveCompleteSlot()));
//    // Homing speed
//    dir     = 2;
//    swtch   = 1;
//    vel     = 2;
//    offset  = 0.299994;
//    caroselMotor->dynamicCall("SetHomeParams(QVariant,QVariant,QVariant,QVariant,QVariant)",chanID,QVariant(dir),QVariant(swtch),QVariant(vel),QVariant(offset));
    initCheckTimer->start();

    cam.initCamera();
    connect(&cam,SIGNAL(move(double)),this,SLOT(stageMotorRelativeMoveFast(double)),Qt::QueuedConnection);
}

void ThorWorker::returnPipette()
{
    if(hasPipette)
    {        
        stageMotor->dynamicCall("EnableHWChannel(QVariant)",chanID);
        QThread::msleep(500);
        stageMotor->dynamicCall("SetAbsMovePos(QVariant,QVariant)",chanID,QVariant(stageDockPosition));
        stageMotor->dynamicCall("MoveAbsolute(QVariant,QVariant,QVariant)",chanID,1);
        emit retractWire();        
        caroselMotor->dynamicCall("SetAbsMovePos(QVariant,QVariant)",chanID,QVariant(caroselDockPosition));
        caroselMotor->dynamicCall("MoveAbsolute(QVariant,QVariant,QVariant)",chanID,1);
        emit unlockHorz();        
        qWarning() << "unlocked.";
        QThread::sleep(3);  // waiting for wire to retract before enabling motor.  This keeps it from overcurrenting
        hMotor->dynamicCall("EnableHWChannel(QVariant)",chanID);        
        QThread::sleep(1);  // Give it time to enable the channel
        hMotor->dynamicCall("SetAbsMovePos(QVariant,QVariant)",chanID,QVariant(hMotorDockPosition));
        hMotor->dynamicCall("MoveAbsolute(QVariant,QVariant,QVariant)",chanID,1);
        caroselMotor->dynamicCall("SetAbsMovePos(QVariant,QVariant)",chanID,QVariant(caroselReleasePosition));
        caroselMotor->dynamicCall("MoveAbsolute(QVariant,QVariant,QVariant)",chanID,1);
        hMotor->dynamicCall("SetAbsMovePos(QVariant,QVariant)",chanID,QVariant(hMotorMousePosition));
        hMotor->dynamicCall("MoveAbsolute(QVariant,QVariant,QVariant)",chanID,1);

        stageMotorCurrentPosition   = stageDockPosition;
        caroselMotorCurrentPosition = caroselReleasePosition;
        hMotorCurrentPosition       = hMotorMousePosition;
//        emit pipetteChanged();
    }
}




void ThorWorker::homeMotors()
{
    mode = 0;
    hMotor->dynamicCall("EnableHWChannel(QVariant)",chanID);
    stageMotor->dynamicCall("EnableHWChannel(QVariant)",chanID);
    caroselMotor->dynamicCall("EnableHWChannel(QVariant)",chanID);
    QThread::msleep(500); // minimum 500 msecond delay for robust operation.  Anything less will
    // make the T-Cube controllers crash and then they have to be restarted

//    int homingBits = (512);
    int homedBits  = (1024);

    QList<QVariant> args;
    args.push_back(QVariant(chanID));
    args.push_back(QVariant(3));
    hMotor->dynamicCall("LLGetStatusBits(int,QVariant&)",args);
    uint val = args[1].toUInt();

//    float pos = hMotor->dynamicCall("GetPosition_Position(int)",chanID).toFloat();
    if(val & homedBits)
    {
        qWarning() << "hMotor Homed already, moving to 0.0mm";
        hMotorToMouse();
    }
    else
    {
        qWarning() << "Homing HMotor...";
        hMotor->dynamicCall("MoveHome(QVariant,QVariant)",chanID,QVariant(false));
    }
    QThread::sleep(3); // waiting for hstage to move so it doesn't clash with the carosel.

    stageMotor->dynamicCall("LLGetStatusBits(int,QVariant&)",args);
    val = args[1].toUInt();

    stageMotor->dynamicCall("SetHomeParams(QVariant,QVariant,QVariant,QVariant,QVariant)",chanID,1,4,3,0);
    stageMotor->dynamicCall("SetStageAxisInfo(QVariant,QVariant,QVariant,QVariant,QVariant,QVariant)",chanID,-25,0,1,1,0);

    if(val & homedBits)
    {
        qWarning() << "Stage Homed.  Moving to clearance position.";
        stageMotorToClearance();
    }
    else
    {
        qWarning() << "Homing Stage Motor...";
        stageMotor->dynamicCall("MoveHome(QVariant,QVariant)",chanID,QVariant(false));
    }

    caroselMotor->dynamicCall("LLGetStatusBits(int,QVariant&)",args);
    val = args[1].toUInt();

    // This should be set to the defaults that comes when the motor starts up in the APT control software.  I'm not sure
    // what values those are.  The documentation is a little murky when it comes to variable values.
//    caroseleMotor->dynamicCall("SetHomeParams(QVariant,QVariant,QVariant,QVariant,QVariant)",chanID,1,4,3,0);
    if(val & homedBits)
    {
        qWarning() << "Carosel Homed.  Moving to release position";
        caroselMotorToRelease();
    }
    else
    {
        qWarning() << "Homing Carosel Motor...";
        caroselMotor->dynamicCall("MoveHome(QVariant,QVariant)",chanID,QVariant(false));
    }

    initTimeStart = QTime::currentTime();

}


void ThorWorker::homeComplete()
{
//    static int done = 0;
    int snum = QObject::sender()->property("HWSerialNum").toInt();
    if(snum == stageMotorSnum)
    {
        stageMotorInit = 1;
    }
    if(snum == caroselMotorSnum)
    {
        caroselMotorInit = 1;
    }
    if(snum == hMotorSnum)
    {
        hMotorInit = 1;
    }
}


void ThorWorker::moveCompleteSlot()
{
    int snum = QObject::sender()->property("HWSerialNum").toInt();
    switch(mode)  // Mode: Initialization, Pipette Aquire, Pipette Change, Pipette Return
    {
        case 0:   // Initialization mode;
        {
            if(snum == hMotorSnum){ hMotorInit = 1; }
            if(snum == stageMotorSnum){ stageMotorInit = 1; }
            if(snum == caroselMotorSnum){ caroselMotorInit = 1; }

            break;
        }
        case 1:  // Aquire Pipette Mode

            aquirePipetteChain(snum);

            break;
       case 2:  // Change the pipette (currently has a pipette in the brain)

            changePipetteChain(snum);

            break;
       case 3:  // This is for basic relative moves.

//            qWarning() << "Motor Off: " << QTime::currentTime().second() << " " << QTime::currentTime().msec();
            emit stageMotorOff();
            relativeMoveLock = 0;
            break;

       case 4:

           break;
       default:

            qWarning() << "Thor motor finished move, no callback launched";
            break;
       }
}

void ThorWorker::disableStage()
{

    stageMotor->dynamicCall("DisableHWChannel(QVariant)",chanID);
}

void ThorWorker::enableStage()
{
    stageMotor->dynamicCall("EnableHWChannel(QVariant)",chanID);
    QThread::msleep(500);
}

void ThorWorker::initCheck()
{
    if((hMotorInit == 1) && (stageMotorInit == 1) && (caroselMotorInit == 1))
    {
        emit motorsReady();
        mode = -1;
    }
    else if(((hMotorInit != 1) || (stageMotorInit != 1) || (caroselMotorInit != 1)) && (initTimeStart.msecsTo(QTime::currentTime()) > 20*1000))  // 20 second timeout
    {
        emit motorInitError();
        mode = -1;
    }
    else
    {
        initCheckTimer->start();
    }
}


void ThorWorker::aquirePipette()
{
    mode = 1;
    aquirePipetteChainMode = 0;
    aquirePipetteChain(0);
}


void ThorWorker::aquirePipetteChain(int snum)
{
    mode = 1;
//    qWarning() << snum << aquirePipetteChainMode;
    // modes 0-7 are used to get the first pipette
    // modes 8-9 are used when the pipette is not visible to the camera to change the pipette.
    // If this is the case, it returns the pipette and picks up the next one
    switch(aquirePipetteChainMode)
    {
    case 0:
        emit switchPressure(Arduino::PRESSURE_ATM);
        hMotor->dynamicCall("EnableHWChannel(QVariant)",chanID);
        stageMotor->dynamicCall("EnableHWChannel(QVariant)",chanID);
        caroselMotor->dynamicCall("EnableHWChannel(QVariant)",chanID);
        QThread::msleep(500); // minimum 500 msecond delay for robust operation.  Anything less will
        // make the T-Cube controllers crash and then they have to be restarted

        // Release the Mbed lock on the h stage
        emit unlockHorz();
        emit retractWire();

        aquirePipetteChainMode = 1;
        stageMotorToDock();
        caroselMotorToRelease();
        break;

    case 1:
        static bool sReady(0),cReady(0);
        if(snum == stageMotorSnum){ sReady = 1;}
        if(snum == caroselMotorSnum){ cReady = 1;}
        if(sReady && cReady)
        {
            hMotorToDock();
            aquirePipetteChainMode = 2;
        }
        break;

    case 2:
        if(snum == hMotorSnum)
        {
            caroselMotorToDock();
            hasPipette = 1;
            aquirePipetteChainMode = 3;
        }else{ qWarning() << "Thor motor sequence/chain crossover!!! Unexpected behavior will follow!  Add controls to prevent simultaneous sequence or chain operation";}
        break;

    case 3:
        if(snum == caroselMotorSnum)
        {
            hasPipette = 1;
            hMotorToCamera();
//            QThread::sleep(2);
            aquirePipetteChainMode = 4;
        }else{ qWarning() << "Thor motor sequence/chain crossover!!! Unexpected behavior will follow!  Add controls to prevent simultaneous sequence or chain operation";}
        break;

    case 4:
        if(snum == hMotorSnum)
        {
            hasPipette = 1;
            qWarning() << "Stage Motor Camera Position Going..." << stageCameraPosition;
            stageMotorToCamera();
            aquirePipetteChainMode = 5;
        }else{ qWarning() << "Thor motor sequence/chain crossover!!! Unexpected behavior will follow!  Add controls to prevent simultaneous sequence or chain operation";}
        break;

    case 5:
        if(snum == stageMotorSnum)
        {
            hasPipette = 1;
            if(adjustPipetteHeight())
            {
                hasPipette = 1;
                emit insertWire();
                aquirePipetteChainMode = 6;
                hMotorToMouse();
            }
            else
            {
                QCoreApplication::removePostedEvents(this);
                stageMotorToDock();
                aquirePipetteChainMode = 51;
            }
            mode = 1;  // the relative moves in adjustPipetteHeight change the mode.  This changes it back
        }else{ qWarning() << "Thor motor sequence/chain crossover!!! Unexpected behavior will follow!  Add controls to prevent simultaneous sequence or chain operation";}
        break;

    case 51:  // think of this as step 5.1, between 5 and 5.2.
        if(snum == stageMotorSnum)
        {
            hasPipette = 1;
            hMotorToDock();
            aquirePipetteChainMode = 52;
        }else{ qWarning() << "Thor motor sequence/chain crossover!!! Unexpected behavior will follow!  Add controls to prevent simultaneous sequence or chain operation";}
        break;

    case 52:  // think of this as step 5.2, between 5.1 and 6.
        if(snum == hMotorSnum)
        {
            hasPipette = 1;
            caroselMotorToRelease();
            aquirePipetteChainMode = 53;  // Back on the main chain of events
        }else{ qWarning() << "Thor motor sequence/chain crossover!!! Unexpected behavior will follow!  Add controls to prevent simultaneous sequence or chain operation";}
        break;

    case 53:
        if(snum == caroselMotorSnum)
        {
            hasPipette = 1;
            rotateToNextPipette();
            emit incrementPipetteNumber();
            QThread::sleep(3);
            caroselMotorToDock();
            aquirePipetteChainMode = 3;  // Back on the main chain of events
        }else{ qWarning() << "Thor motor sequence/chain crossover!!! Unexpected behavior will follow!  Add controls to prevent simultaneous sequence or chain operation";}
        break;

    case 6:
        if(snum == hMotorSnum)
        {
            hasPipette = 1;
            hMotor->dynamicCall("DisableHWChannel(QVariant)",chanID);
            emit lockHoriz();
            QThread::sleep(1);  // Waiting for it to lock the hmotor
            emit switchPressure(Arduino::PRESSURE_HIGHP);
            emit pipetteAquired();
            aquirePipetteChainMode = 7;
            mode = -1;
        }
        break;

    case 7:

        break;
    default:
        break;
    }
}

void ThorWorker::changePipette()
{
    changePipetteChainMode = 0;
    changePipetteChain(0);
}

void ThorWorker::changePipetteChain(int snum)
{
    mode = 2;
    switch(changePipetteChainMode)
    {
    case 0:  // Starting the chain, retracting the stage and raising the carosel

        if(!relativeMoveLock)
        {
            qWarning() << "Changing the pipette";
            mode = 2;
            changePipetteChainMode = 1;
            stageMotor->dynamicCall("EnableHWChannel(QVariant)",chanID);
            caroselMotor->dynamicCall("EnableHWChannel(QVariant)",chanID);
            QThread::msleep(1000); // minimum 500 msecond delay for robust operation.  Anything less will
            // make the T-Cube controllers crash and then they have to be restarted

            if(stageMotorCurrentPosition < distToBrain + cameraPipetteHeight)  // Do a slow retract to surface, then
            {
                stageMotorToBrainSlow();
                changePipetteChainMode = 95;  // think of this as step 0.5 in between 0 and 1 for this case
            }
            else  // do a fast retract
            {
                stageMotorToDock();
                caroselMotorToDock();
                changePipetteChainMode = 1;
            }
        }
        else
        {
            // starting a retry timer to retry after the relativeMoveLock has been released
            qWarning() << "Retrying...";
            retryChangePipetteTimer->start(1000);
        }

        break;

    case 95:
        if(snum == stageMotorSnum)
        {
            stageMotorToDock();
            caroselMotorToDock();
            changePipetteChainMode = 1;
        }
        break;

    case 1:  // retracting the wire, unlocking the hMotor, moving the hMotor
    {
        static bool sReady(0), cReady(0);
        if(snum == stageMotorSnum)  sReady = 1;
        if(snum == caroselMotorSnum) cReady = 1;

        if(sReady && cReady)
        {
           sReady = 0;
           cReady = 0;

           // Release the Mbed lock on the h stage
           emit unlockHorz();
           emit retractWire();
           emit switchPressure(Arduino::PRESSURE_ATM);
           QThread::sleep(3.5);
           hMotor->dynamicCall("EnableHWChannel(QVariant)",chanID);
           QThread::msleep(1000);  // Give it time to enable the channel
           hMotorToDock();
           changePipetteChainMode = 2;
        }
        break;
    }
    case 2:
        if(snum == hMotorSnum)
        {
            caroselMotorToRelease();
            changePipetteChainMode = 3;
        }else{ qWarning() << "Thor motor sequence/chain crossover!!! Unexpected behavior will follow!  Add controls to prevent simultaneous sequence or chain operation";}
        break;

    case 3:
        if(snum == caroselMotorSnum)
        {
            emit rotateToNextPipette();
            emit incrementPipetteNumber();
            QThread::sleep(3);  // Change this back to 2 when not skipping a pipette dock because the magnets are too big.
            caroselMotorToDock();
            hasPipette = 1;
            changePipetteChainMode = 4;
        }else{ qWarning() << "Thor motor sequence/chain crossover!!! Unexpected behavior will follow!  Add controls to prevent simultaneous sequence or chain operation";}
        break;
    case 4:
        if(snum == caroselMotorSnum)
        {
            hMotorToCamera();
            changePipetteChainMode = 5;
        }
        else{ qWarning() << "Thor motor sequence/chain crossover!!! Unexpected behavior will follow!  Add controls to prevent simultaneous sequence or chain operation";}
        break;
    case 5:
        if(snum == hMotorSnum)
        {
            stageMotorToCamera();
            changePipetteChainMode = 6;
        }else{ qWarning() << "Thor motor sequence/chain crossover!!! Unexpected behavior will follow!  Add controls to prevent simultaneous sequence or chain operation";}
        break;
    case 6:
        if(snum == stageMotorSnum)
        {
            if(adjustPipetteHeight())   // This function moves the stage motor several times.  Ignore these move events
            {
                emit insertWire();
                hMotorToMouse();
                changePipetteChainMode = 7;
            }
            else  // if the pipette is not visible, put it back and get the next one
            {
                QCoreApplication::removePostedEvents(this);
                stageMotorToDock();
                changePipetteChainMode = 61;
            }
            mode = 2;
        }else{ }
        break;

    case 61:  // step after mode 6
        if(snum == stageMotorSnum)
        {
            hMotorToDock();
            changePipetteChainMode = 2;
        }
        break;

    case 7:
        if(snum == hMotorSnum )
        {
            hMotor->dynamicCall("DisableHWChannel(QVariant)",chanID);
            emit lockHoriz();
            QThread::sleep(4);  // Waiting for it to lock the hmotor
            emit switchPressure(Arduino::PRESSURE_HIGHP);

            // Lowering to the surface of the brain;
            stageMotorToBrainFast();
            changePipetteChainMode = 8;
        }else{ }

        break;
    case 8:
        if(snum == stageMotorSnum)
        {
            emit pipetteChanged();
            changePipetteChainMode = -1;
            mode = -1;
        }
        break;
    default:
        qWarning() << "Unrecognized value in the Change Pipette Chain";
        break;
    }


}


void ThorWorker::setBrainHeight()
{
    distToBrain = stageMotorCurrentPosition - cameraPipetteHeight;
}


void ThorWorker::descendToDepth(float depth)  // Below the brain position.  The surface of the brain or "brain height" is effectively zero depth.
{
    emit switchPressure(Arduino::PRESSURE_HIGHP);  // ONLY HAVE HIGH PRESSURE ON FOR A SHORT PERIOD.  IF IT'S ON FOR TOO LONG THE FLUID FLOW WILL EVENTUALLY CLOG THE PIPETTE
    QThread::msleep(2000);

    qWarning() << "Stage motor position: " << stageMotorCurrentPosition << " lower to position: " << distToBrain + cameraPipetteHeight - depth/1000-0.02;
    stageMotorCurrentPosition   = distToBrain + cameraPipetteHeight - depth/1000;

    stageMotor->dynamicCall("SetVelParams(QVariant,QVariant,QVariant,QVariant,)",chanID,0,2,2);
//    stageMotor->dynamicCall("SetAbsMovePos(QVariant,QVariant)",chanID,QVariant(stageMotorCurrentPosition-0.02));
    // The extra 0.02 in depth is so that it can pull back on the next move a little bit so that the tissue doesn't clog the pipette as often.

    emit stageMotorOn();

//    stageMotor->dynamicCall("MoveAbsolute(QVariant,QVariant,QVariant)",chanID,1);
//    qWarning() << "Stage motor position: " << stageMotorCurrentPosition << " lower to position: " << distToBrain + cameraPipetteHeight - depth/1000;

    stageMotor->dynamicCall("SetAbsMovePos(QVariant,QVariant)",chanID,QVariant(stageMotorCurrentPosition));
    stageMotor->dynamicCall("MoveAbsolute(QVariant,QVariant,QVariant)",chanID,1);
    QThread::msleep(1000);
    emit switchPressure(Arduino::PRESSURE_ATM);
    QThread::msleep(100);
    emit switchPressure(Arduino::PRESSURE_LOWP);
    QThread::msleep(1000);
    emit stageMotorOff();
    emit atDepth();    
}


void ThorWorker::setInitialSettings(vector<double> args)
{
    velMax = (args)[0];
    velMin = (args)[1];
    accel  = (args)[2];

    setCaroselDockPosition          ((args)[3]);
    setCaroselReleasePosition       ((args)[4]);
    setHMotorMousePosition          ((args)[5]);
    setHMotorCameraPosition         ((args)[6]);
    setHMotorDockPosition           ((args)[7]);
    setstageCameraPosition     ((args)[8]);
    setstageDockPosition       ((args)[9]);
    setStageMotorClearancePosition  ((args)[10]);

    hMotor->dynamicCall("SetVelParams(QVariant,QVariant,QVariant,QVariant)",chanID,velMin,accel,velMax);
}


void ThorWorker::setVelocityMax(double num)
{
    velMax = QVariant(num);    
    hMotor->dynamicCall("SetVelParams(QVariant,QVariant,QVariant,QVariant)",chanID,velMin,accel,velMax);
}


void ThorWorker::setVelocityMin(double num)
{
    velMin = QVariant(num);    
    hMotor->dynamicCall("SetVelParams(QVariant,QVariant,QVariant,QVariant)",chanID,velMin,accel,velMax);
}


void ThorWorker::setAccel(double num)
{
    accel = QVariant(num);    
    hMotor->dynamicCall("SetVelParams(QVariant,QVariant,QVariant,QVariant)",chanID,velMin,accel,velMax);
}

void ThorWorker::stageMotorRelativeMoveSlow(double dist)
{
    relativeMoveLock = 1;
    mode = 3;
//    qWarning() << "Relative move started...";
    qWarning() << "Moving " << dist/1000;
    stageMotorCurrentPosition = dist/1000 + stageMotorCurrentPosition;
    stageMotor->dynamicCall("SetVelParams(QVariant,QVariant,QVariant,QVariant,)",chanID,0,.02,.02);
    stageMotor->dynamicCall("SetRelMoveDist(QVariant,QVariant)",chanID,QVariant(dist/1000));

//    qWarning() << "Motor On: "  << QTime::currentTime().second() << " " << QTime::currentTime().msec();
    emit stageMotorOn();
    stageMotor->dynamicCall("MoveRelative(QVariant,QVariant)",chanID,1);
    relativeMoveLock = 0;
}


void ThorWorker::stageMotorRelativeMoveFast(double dist)
{
    relativeMoveLock = 1;
    mode = 3;
//    qWarning() << "Relative move started...";
    qWarning() << "Moving " << dist/1000;
    stageMotorCurrentPosition = dist/1000 + stageMotorCurrentPosition;
    stageMotor->dynamicCall("SetVelParams(QVariant,QVariant,QVariant,QVariant,)",chanID,0,2,2);
    stageMotor->dynamicCall("SetRelMoveDist(QVariant,QVariant)",chanID,QVariant(dist/1000));
    emit stageMotorOn();
    stageMotor->dynamicCall("MoveRelative(QVariant,QVariant)",chanID,1);
    QThread::msleep(500);
    relativeMoveLock = 0;
}


void ThorWorker::hMotorToDock()
{
    hMotorCurrentPosition = hMotorDockPosition;
    hMotor->dynamicCall("SetAbsMovePos(QVariant,QVariant)",chanID,QVariant(hMotorDockPosition));
    hMotor->dynamicCall("MoveAbsolute(QVariant,QVariant,QVariant)",chanID,0);
}


void ThorWorker::hMotorToCamera()
{
    hMotorCurrentPosition = hMotorCameraPosition;
    hMotor->dynamicCall("SetAbsMovePos(QVariant,QVariant)",chanID,QVariant(hMotorCameraPosition));
    hMotor->dynamicCall("MoveAbsolute(QVariant,QVariant,QVariant)",chanID,0);
}


void ThorWorker::hMotorToMouse()
{
    hMotorCurrentPosition = hMotorMousePosition;
    hMotor->dynamicCall("SetAbsMovePos(QVariant,QVariant)",chanID,QVariant(hMotorMousePosition));
    hMotor->dynamicCall("MoveAbsolute(QVariant,QVariant,QVariant)",chanID,0);
}


void ThorWorker::caroselMotorToDock()
{
    caroselMotorCurrentPosition = caroselDockPosition;
    caroselMotor->dynamicCall("SetAbsMovePos(QVariant,QVariant)",chanID,QVariant(caroselDockPosition));
    caroselMotor->dynamicCall("MoveAbsolute(QVariant,QVariant,QVariant)",chanID,0);

}


void ThorWorker::caroselMotorToRelease()
{
    caroselMotorCurrentPosition = caroselReleasePosition;
    caroselMotor->dynamicCall("SetAbsMovePos(QVariant,QVariant)",chanID,QVariant(caroselReleasePosition));
    caroselMotor->dynamicCall("MoveAbsolute(QVariant,QVariant,QVariant)",chanID,0);
}


void ThorWorker::stageMotorToDock()
{
    stageMotorCurrentPosition   = stageDockPosition;
    stageMotor->dynamicCall("SetVelParams(QVariant,QVariant,QVariant,QVariant,)",chanID,0,2,2);
    stageMotor->dynamicCall("SetAbsMovePos(QVariant,QVariant)",chanID,QVariant(stageDockPosition));
    stageMotor->dynamicCall("MoveAbsolute(QVariant,QVariant,QVariant)",chanID,0);
}


void ThorWorker::stageMotorToClearance()
{
    stageMotorCurrentPosition   = stageClearancePosition;
    stageMotor->dynamicCall("SetVelParams(QVariant,QVariant,QVariant,QVariant,)",chanID,0,2,2);
    stageMotor->dynamicCall("SetAbsMovePos(QVariant,QVariant)",chanID,QVariant(stageClearancePosition));
    stageMotor->dynamicCall("MoveAbsolute(QVariant,QVariant,QVariant)",chanID,0);
}


void ThorWorker::stageMotorToCamera()
{
    stageMotorCurrentPosition   = stageCameraPosition;
    stageMotor->dynamicCall("SetVelParams(QVariant,QVariant,QVariant,QVariant,)",chanID,0,2,2);
    stageMotor->dynamicCall("SetAbsMovePos(QVariant,QVariant)",chanID,QVariant(stageCameraPosition));
    stageMotor->dynamicCall("MoveAbsolute(QVariant,QVariant,QVariant)",chanID,0);
}


void ThorWorker::stageMotorToBrainFast()
{
    stageMotorCurrentPosition   = distToBrain + cameraPipetteHeight;
    stageMotor->dynamicCall("SetVelParams(QVariant,QVariant,QVariant,QVariant,)",chanID,0,2,2);
    stageMotor->dynamicCall("SetAbsMovePos(QVariant,QVariant)",chanID,QVariant(stageMotorCurrentPosition));
    stageMotor->dynamicCall("MoveAbsolute(QVariant,QVariant,QVariant)",chanID,0);
    qWarning() << "Lowering to the surface of the brain " << stageMotorCurrentPosition;
}


void ThorWorker::stageMotorToBrainSlow()
{
    stageMotorCurrentPosition   = distToBrain + cameraPipetteHeight;
    stageMotor->dynamicCall("SetVelParams(QVariant,QVariant,QVariant,QVariant,)",chanID,0,.2,.2);
    stageMotor->dynamicCall("SetAbsMovePos(QVariant,QVariant)",chanID,QVariant(stageMotorCurrentPosition));
    stageMotor->dynamicCall("MoveAbsolute(QVariant,QVariant,QVariant)",chanID,0);
    qWarning() << "Lowering to the surface of the brain " << stageMotorCurrentPosition;
}


void ThorWorker::stageMotorToDepth(float depth)
{
    emit switchPressure(Arduino::PRESSURE_HIGHP);  // ONLY HAVE HIGH PRESSURE ON FOR A SHORT PERIOD.  IF IT'S ON FOR TOO LONG THE FLUID FLOW WILL EVENTUALLY CLOG THE PIPETTE
    QThread::msleep(2000);

    qWarning() << "Stage motor position: " << stageMotorCurrentPosition << " lower to position: " << distToBrain + cameraPipetteHeight - depth/1000-0.02;
    stageMotorCurrentPosition   = distToBrain + cameraPipetteHeight - depth/1000;

    stageMotor->dynamicCall("SetVelParams(QVariant,QVariant,QVariant,QVariant,)",chanID,0,2,2); // going fast because the piezo motor does.  previous values were 0.3 and 0.2
//    stageMotor->dynamicCall("SetAbsMovePos(QVariant,QVariant)",chanID,QVariant(stageMotorCurrentPosition-0.02));
    // The extra 0.02 in depth is so that it can pull back on the next move a little bit so that the tissue doesn't clog the pipette as often.

    emit stageMotorOn();

//    stageMotor->dynamicCall("MoveAbsolute(QVariant,QVariant,QVariant)",chanID,1);
//    qWarning() << "Stage motor position: " << stageMotorCurrentPosition << " lower to position: " << distToBrain + cameraPipetteHeight - depth/1000;

    stageMotor->dynamicCall("SetAbsMovePos(QVariant,QVariant)",chanID,QVariant(stageMotorCurrentPosition));
    stageMotor->dynamicCall("MoveAbsolute(QVariant,QVariant,QVariant)",chanID,1);
    QThread::msleep(1000);
    emit switchPressure(Arduino::PRESSURE_ATM);
    QThread::msleep(100);
    emit switchPressure(Arduino::PRESSURE_LOWP);
    QThread::msleep(1000);
    emit stageMotorOff();
    emit atDepth();
}

bool ThorWorker::adjustPipetteHeight()
{
    Mat img;
    float h_current;
    int allowable_error = 5; // Allowable error in pixels.  This is the stop band condition.

    int diff(0);
    cam.my_cam >> img; // clearing a bad image;
    if(cam.pipetteDetected())
    {
        int count(20);

        while(count > 0)
        {
            cam.my_cam >> img;
            h_current = cam.getPipetteHeight();
            diff = cam.pipetteHeight - h_current;
            qWarning() << diff;

            if(h_current == -1)
            {
                break;
            }
            else if(abs(diff)<allowable_error)
            {
                qWarning() << "Pipette calibrated.";
                break;
            }
    //        qWarning() << scaleFactor;
            if(diff < 0)
            {
                // Move up by 30 micrometers
                qWarning() << "Move up";
                stageMotorRelativeMoveFast(-diff*calib*1000);
                QThread::msleep(500);
            }
            else if(diff > 0)
            {
                // Move down by 30 microns
                qWarning() << "Move down";
                stageMotorRelativeMoveFast(-diff*calib*1000);
                QThread::msleep(500);
            }
            else
            {
                break;
            }

            count--;
        }
        qWarning() << "Pipette detected, height adjusted";
        cameraPipetteHeight = stageMotor->dynamicCall("GetPosition_Position(int)",chanID).toFloat();

        qWarning() << "Stage motor position after camera adjustment: " << cameraPipetteHeight;

        return 1;
    }
    else
    {
        qWarning() << "Pipette not visible.  Going to next pipette.";
        return 0;
    }
}

