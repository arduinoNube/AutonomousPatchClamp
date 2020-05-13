#include "removepipette.h"
#include <QDebug>
#include <QThread>

RemovePipette::RemovePipette(QObject *parent) : State(parent)
{
    name = "Remove Pipette";
    description = "This state retracts the silver wire, opens the headstage clamp, and extracts the \
pipette using the SCARA robot arm.  It finishes by discarding the pipette and moving the end effector \
until it is next to the carosel ready to get the nex pipette";
    ptrHeadCmdFinished  = NULL;
    ptrScaraCmdFinished = NULL;
    ptrThorMoveComplete = NULL;
}

RemovePipette::~RemovePipette()
{

}

void RemovePipette::haltState()
{

}

void RemovePipette::pauseState(bool toggled) // 1 tells the state to pause, 0 to continue
{
    qWarning() << "Remove pipette pause state toggled: " << toggled;
    if(toggled)
    {
        emit gui_pauseButtonEnable(false);
        pause = 1;
    }
    else
    {
        qWarning() << "ready? " << ready;
        if(ready)
        {
            ready = 0;
            finish();
        }
    }
}

void RemovePipette::gui_actionLoadMicrofil()
{

}

// **************** PROCEDURAL CODE START *******************
// Code in this section should be very sequential and each
// method should be called after the previous.  This is the
// algorithmic portion of this state.
void RemovePipette::firstRun()
{
    ptrThorMoveComplete = &A;
    ptrScaraCmdFinished = NULL;
    ptrHeadCmdFinished  = NULL;
    // The motor should already be there but just to be safe:
    emit thorLabsMotor_moveToAbsolute(-4,2);
    emit gui_enablePages(false);
    pause = 0;
    ready = 0;
    emit gui_pauseButtonEnable(true);
    emit gui_pauseButtonVisible(true);
}

void RemovePipette::A()
{
    ptrThorMoveComplete = NULL;
    emit headstageClamp_retractWire(false);
    ptrScaraCmdFinished = &B;
    emit scara_moveNext(true);  // Unfold the robot arm
}

void RemovePipette::B()
{    
    ptrScaraCmdFinished = &C;
    emit scara_openEndEffector(true);  // Should already be open, but just in case;
}

void RemovePipette::C()
{
    ptrScaraCmdFinished = &D;
    emit scara_moveNext(true); // Moving slowly in next to the pipette
}

void RemovePipette::D()
{
    ptrScaraCmdFinished = &E;
    emit scara_closeEndEffector(true);
}

void RemovePipette::E()
{
    ptrScaraCmdFinished = NULL;
    ptrHeadCmdFinished = &F;
    emit headstageClamp_openClamp(true);
    emit autopatcher_switchPressure(AutopatcherWorker::PRESSURE_ATM,0);
}

void RemovePipette::F()
{
    QThread::sleep(2);  // This locks up the GUI so a timer should be added later to perform this delay.
    ptrHeadCmdFinished = NULL;
    ptrThorMoveComplete = &G;
    emit thorLabsMotor_moveToAbsolute(0,2);
}

void RemovePipette::G()
{
    ptrThorMoveComplete = NULL;
    ptrScaraCmdFinished = &H;
    emit scara_moveNext(true); // Moving the pipette out of the clamp
}

void RemovePipette::H()
{
    ptrScaraCmdFinished = &I;
    emit scara_moveNext(true); // Moving to parallel configuration
}

void RemovePipette::I()
{
    ptrScaraCmdFinished = &J; // Normal paths flag            <-----------  Change this pointer to
    //ptrScaraCmdFinished = &O;   // Infinite paths algorithm     <-----------  route the execution below
    emit scara_moveNext(true); // Moving to trash position
}


// ************************************
// ****** EXECUTION PATH 1 ************
// ************************************
void RemovePipette::J()
{
    ptrScaraCmdFinished = &K;
    emit scara_openEndEffector(true); // Dropping in the trash
}

void RemovePipette::K()
{
    ptrScaraCmdFinished = &L;
    emit scara_rotateCarouselNext(true);
}

void RemovePipette::L()
{
    ptrScaraCmdFinished = &M;
    emit scara_moveNext(true); // Moving next to carousel to pick up the next pipette
}

void RemovePipette::M()
{
    ptrScaraCmdFinished = NULL;
    ptrThorMoveComplete = NULL;
    ptrHeadCmdFinished  = NULL;
    ready = 1;

    if(!pause)
    {
        finish();
    }
    emit gui_pauseButtonEnable(true);
}

void RemovePipette::finish()
{
    emit gui_busy_stop("Pipette Removed.");
    emit gui_pauseButtonVisible(false);
    decision = 1;
    QThread::msleep(500);  // without this delay for some reason the decision variable doesn't have time to get set before the state finishes... ?
    emit stateFinished();
}


// ************************************
// ****** EXECUTION PATH 2 ************
// ************************************
// This execution path assumes that the user is just testing the pipette filler.
// It also assumes the code on the Arduino is set up to use this number of paths
// as well as just move the pipettes back and forth between the carousel and the
// filler.  Currently, this path is disabled and should only be enabled with
// caution and consideration for the aforementioned interactions.

void RemovePipette::O()
{
    ptrScaraCmdFinished = &P;
    emit scara_moveNext(true);  // Moving next to the carousel
}

void RemovePipette::P()
{
    ptrScaraCmdFinished = &Q;
    emit scara_moveNext(true);  // Moving into the carousel clip
}

void RemovePipette::Q()
{
    ptrScaraCmdFinished = &R;
    emit scara_openEndEffector(true);  // Dropping the pipette off
}

void RemovePipette::R()
{
    ptrScaraCmdFinished = &S;
    emit scara_moveNext(true);  // Moving EE away from the carousel
}

void RemovePipette::S()
{
    ptrScaraCmdFinished = &T;
    emit scara_rotateCarouselNext(true);  // Rotate the carousel to the next pipette
}

void RemovePipette::T()
{
    ptrScaraCmdFinished = NULL;
    ptrThorMoveComplete = NULL;
    ptrHeadCmdFinished  = NULL;
    decision = 1;
    emit stateFinished();
}
