#include "states/WaitAndSetVars.h"
#include "QTime"

WaitAndSetVars::WaitAndSetVars(QObject *parent) : State(parent)
{
    name = "Wait and Set Variable State";
    description = "This state waits for the amount of time specified in the waitForRecordingStabilization \
variable.  It also sets the \"quickAPDetectStateDecision\" and the \"restingVoltageStateDecision\" flags \
for use by later states.";
    timer1.setSingleShot(true);
    connect(&timer1,SIGNAL(timeout()),this,SLOT(timer1_timeout()), Qt::QueuedConnection);
}

WaitAndSetVars::~WaitAndSetVars()
{

}

void WaitAndSetVars::pauseState(bool) // Toggled
{

}

void WaitAndSetVars::haltState()
{

}

// **************** PROCEDURAL CODE START *******************
// Code in this section should be very sequential and each
// method should be called after the previous.  This is the
// algorithmic portion of this state.
/*
 * This wait state is specific for the experimental protocol for
 * this particular experiment.  Feel free to copy it and insert
 * the new state into the state machine flow.  It does a couple
 * more things that just wait.  It changes a flag that will
 * change which state comes after the quickAPDetect state.
 * Unfortunately, these details make it both a wait state and
 * a logical flow switch modifying state.
 * */

void WaitAndSetVars::firstRun()
{
    emit gui_busy_start("Waiting " + QString::number(data.waitForRecordingStabilization/60.0) +  " minutes for the recording to stabilize");
    timer1.setInterval(data.waitForRecordingStabilization*1000);
    timer1.start();
}


void WaitAndSetVars::timer1_timeout()
{
    data.quickAPDetectStateDecision = 2;  // This controls the decision of the ic_quickAPDetect state.  This is the "VarSet" portion of the class title.
    data.restingVoltageStateDecision = 2; // This controls the decision of the ic_restingMembrane state.
    decision = 1;
    qWarning() << decision << "Waiting state finished";
    emit stateFinished();
}
