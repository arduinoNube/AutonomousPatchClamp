#include "setbrainheight.h"
#include <QDebug>

SetBrainHeight::SetBrainHeight(QObject *parent) : State(parent)
{
    name        = "Set brain height";
    description = "This state allows the user to adjust the Thorlabs motor until the tip of the \
pipette is 20-30 microns above the surface of the brain.  The state records this position for use \
in subsequent states.  It also sets a flag (AutopatcherSettings brainHeightSet) saying that for \
this run of the application, the brain height has been set and this state can be skipped if needed.";
}

SetBrainHeight::~SetBrainHeight()
{

}


void SetBrainHeight::pauseState(bool) // 1 tells the state to pause, 0 to continue
{

}

void SetBrainHeight::haltState()
{

}

// **************** PROCEDURAL CODE START *******************
// Code in this section should be very sequential and each
// method should be called after the previous.  This is the
// algorithmic portion of this state.
void SetBrainHeight::firstRun()
{
    emit gui_busy_stop("Ready.  Adjust the height of the pipette until it is 20 to 30 micrometers above the surface of the brain.");
    emit gui_setCurrentPageIndex("page_brain_height_adjustment");
}

void SetBrainHeight::gui_downAdjustBtn(int dist)
{
    emit gui_enablePushButtonUpAdjust(false);
    emit gui_enablePushButtonDownAdjust(false);
    emit gui_enablePushButtonGO3(false);
    emit thorLabsMotor_moveByRelative(-dist/1000.0,2);
}

void SetBrainHeight::gui_upAdjustBtn(int dist)
{
    emit gui_enablePushButtonUpAdjust(false);
    emit gui_enablePushButtonDownAdjust(false);
    emit gui_enablePushButtonGO3(false);
    emit thorLabsMotor_moveByRelative(dist/1000.0,2);

}

void SetBrainHeight::thorLabsMotor_moveComplete()
{
    emit gui_updateCurrentPosition();
    emit gui_enablePushButtonUpAdjust(true);
    emit gui_enablePushButtonDownAdjust(true);
    emit gui_enablePushButtonGO3(true);
}

void SetBrainHeight::gui_pushbuttonGO3Released(ThorWorker *t)
{
    data.brainHeight = t->getPosition();    
    data.brainHeightSet = true;
    data.pipetteLengthWhenHeightSet = data.pipetteLengthCurrent;
    emit gui_checkedBrainHeightReset(false);
    decision = 1;
    emit stateFinished();
}
