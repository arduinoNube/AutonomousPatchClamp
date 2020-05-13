#include "getpipette.h"
#include <QDebug>
#include <QThread>

GetPipette::GetPipette(QObject *parent) : State(parent)
{
    name        = "Get Pipette";
    description = "This state moves the robot arm to grab a pipette, move it to the filler, \
fill it, then move it to the headstage clamp, insert it into the clamp and \
o-ring, close the clamp, and then thread the silver wire into it.";

    // This pointer holds the address of the next function that should be
    // called when the commandFinished slot is called
    ptrScaraCmdFinished     = NULL;
    ptrFillerCmdFinished    = NULL;
    ptrHeadCmdFinished      = NULL;

    // volume to retract the filler to pull fluid out of the microfil tip
    // so it stays cold
    tipVolume = 7.6; // uL
    pause = 0;
}

GetPipette::~GetPipette()
{

}

void GetPipette::pauseState(bool toggled) // 1 tells the state to pause, 0 to continue
{
    if(toggled)
    {
        emit gui_pauseButtonEnable(false);
        emit gui_busy_start("The RoboPatcher will pause after inserting the pipette.");
        pause = 1;
    }
    else
    {
        if(ready)
        {
            ready = 0;
            finish();
        }
    }
}

void GetPipette::haltState()
{

}

void GetPipette::length_measurementReady(float length)
{
    data.pipetteLengthCurrent = length; // mm
}

// **************** PROCEDURAL CODE START *******************
// Code in this section should be very sequential and each
// method should be called after the previous.  This is the
// algorithmic portion of this state.
//
// This code is highly dependent on the configuration of the paths of the
// robot.  It issues "moveNext" commands to the stepper controller which
// moves the arm along the subsequent path and stops.  If the number of paths
// change or the order is somehow adjusted, every moveNext will have to be
// carefully placed to maintain the proper sequence of events.
void GetPipette::firstRun()
{
    decision = 0;
    emit gui_enablePages(false);
    emit gui_busy_start("Acquiring, filling, measuring, and inserting the pipette");
    pause = 0;
    ready = 0;
    emit gui_pauseButtonEnable(true);
    emit gui_pauseButtonVisible(true);
    ptrFillerCmdFinished    = NULL;
    ptrHeadCmdFinished      = NULL;
    ptrScaraCmdFinished     = &A;
    emit scara_openEndEffector(true);
}
void GetPipette::A()
{
    ptrScaraCmdFinished = &B;
    emit scara_moveNext(true);
}
void GetPipette::B()
{
    ptrScaraCmdFinished = &C;
    emit scara_closeEndEffector(true);
}
void GetPipette::C()
{
    ptrScaraCmdFinished = &D;
    emit filler_dispenseVolume(tipVolume,false);
    emit scara_moveNext(true);
}
void GetPipette::D()
{
    ptrScaraCmdFinished = &E;
    emit scara_partialCloseEndEffector(true);
}
void GetPipette::E()
{
    ptrScaraCmdFinished = &F;
    emit scara_fill1(true);
}
void GetPipette::F()
{
    ptrScaraCmdFinished = &G;
    emit scara_openEndEffector(true);
}
void GetPipette::G()
{
    ptrScaraCmdFinished = &H;
    emit scara_moveNext(true);
}
void GetPipette::H()
{
    ptrScaraCmdFinished = &I;
    emit filler_enablePressureControl(true,false);
    emit scara_fill2(true);
}
void GetPipette::I()
{
    ptrScaraCmdFinished = &J;
    QThread::sleep(2);  // Probably doens't need this.  It's just so I can see if the tip fills
    emit scara_dispenseHighPressure(100,true);
}
void GetPipette::J()
{
    ptrScaraCmdFinished = &K;
    QThread::sleep(1);  // Waiting for all the fluid to dispense and come to steady state
    emit filler_enablePressureControl(false,false);
    emit scara_fill3(true); // retracting microfil (lowering pipette)
}
void GetPipette::K()
{
    ptrScaraCmdFinished = &L;
    emit scara_moveNext(true);
    emit filler_aspirateVolume(tipVolume,false);
}
void GetPipette::L()
{
    ptrScaraCmdFinished = &M0;
    emit scara_closeEndEffector(true);
}


// AFTER ADDING THE LENGTH MEASUREMENT MODULE, THE CODE BELOW NEEDS TO CHANGE

// No, the code below is not very consice, but it is VERY readable!
void GetPipette::M0()
{
    ptrScaraCmdFinished = &M1;
    emit scara_moveNext(true);  // Moving to length measurement station
}
void GetPipette::M1()
{
    ptrScaraCmdFinished = &M2;
    emit scara_moveNext(true);  // Final approach to length measurement station
}
void GetPipette::M2()
{
    ptrScaraCmdFinished = &M3;
    emit scara_openEndEffector(true);
}
void GetPipette::M3()
{
    ptrScaraCmdFinished = &M4;
    emit scara_moveNext(true);  // Shifting arm slightly so it's not touching the pipette
}
void GetPipette::M4()
{
    ptrScaraCmdFinished = NULL;
    emit gui_busy_start("Please wait, measuring the length of the pipette (~10 sec).");
    emit length_measure();      // Measuring the length of the pipette
}
void GetPipette::length_imagesAquired()
{
    emit gui_busy_start("Acquiring, filling, measuring, and inserting the pipette");
    ptrScaraCmdFinished = &M5;
    emit scara_moveNext(true);  // Shifting arm slightly so it's back touching the pipette
}
void GetPipette::M5()
{
    ptrScaraCmdFinished = &M6;
    emit scara_closeEndEffector(true);
}
void GetPipette::M6()
{
    ptrScaraCmdFinished = &N;
    emit scara_moveNext(true);  // Moving to arm transition point
}
void GetPipette::N()
{
    ptrScaraCmdFinished = &O;
    emit scara_moveNext(true);  // Moving pipette close to clamp
}
void GetPipette::O()
{
    ptrScaraCmdFinished = &P;
    emit scara_moveNext(true);  // Pipette in the headstage clamp
}
void GetPipette::P()
{
    ptrScaraCmdFinished = NULL;
    ptrHeadCmdFinished = &Q;
    emit headstageClamp_halfClamp(true);
}
void GetPipette::Q()
{
    ptrHeadCmdFinished = NULL;
    emit thorLabsMotor_moveToAbsolute(-4,2);
}
void GetPipette::thorLabsMotor_moveComplete()
{
    ptrHeadCmdFinished = &S;
    emit headstageClamp_closeClamp(true);
    emit headstageClamp_threadWire(false);
    emit gui_updateCurrentPosition();  // This is so the gui label is updated for the setbrainheight state
}
void GetPipette::S()
{
    ptrHeadCmdFinished = NULL;
    ptrScaraCmdFinished = &T;
    emit scara_openEndEffector(true);    
    emit scara_enableEndEffector(false,false);
}
void GetPipette::T()
{
    ptrScaraCmdFinished = &U;
    emit scara_moveNext(true);  // Moving arm away from pipette
}
void GetPipette::U()
{
    ptrScaraCmdFinished = &V;
    emit scara_moveNext(true);  // Folding arm away
}
void GetPipette::V()
{
    QThread::msleep(500);
    emit scara_powerDown();
    // Emitting a signal here might not make it to the worker
    // because it's about to get disconnected when the state
    // changes

    //emit headstageClamp_powerDown();
    //emit
    ready = 1;
    emit gui_pauseButtonEnable(true);
    if(!pause)
    {
        finish();
    }
}

void GetPipette::finish()
{
    ptrScaraCmdFinished = NULL;
    emit gui_busy_stop("Pipette Ready.");
    emit gui_pauseButtonVisible(false);
    decision = 1;
    QThread::msleep(500);  // without this delay for some reason the decision variable doesn't have time to get set before the state finishes... ?
    emit stateFinished();
}

