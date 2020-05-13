#include "wait.h"
#include "QTime"

Wait::Wait(QObject *parent) : State(parent)
{
    timer1.setSingleShot(true);
    connect(&timer1,SIGNAL(timeout()),this,SLOT(timer1_timeout()), Qt::QueuedConnection);
}

Wait::~Wait()
{

}

void Wait::pauseState(bool) // Toggled
{

}

void Wait::haltState()
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
 * change which state comes after the membrane test state.
 * Unfortunately, these details make it a wait and logical
 * flow switch state.
 * */

void Wait::firstRun()
{
    emit gui_busy_start("Waiting " + QString::number(data.waitForRecordingStabilization/60) +  " minutes for the recording to stabilize");
    timer1.setInterval(data.waitForRecordingStabilization*1000);
    timer1.start();
}

void Wait::timer1_timeout()
{
    decision = 1;
    emit stateFinished();
}
