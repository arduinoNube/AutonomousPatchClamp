#include "retract.h"
#include <QDebug>

Retract::Retract(QObject *parent) : State(parent)
{
    name = "Retract State";
}

Retract::~Retract()
{

}


void Retract::pauseState(bool) // 1 tells the state to pause, 0 to continue
{

}

void Retract::haltState()
{

}

// **************** PROCEDURAL CODE START *******************
// Code in this section should be very sequential and each
// method should be called after the previous.  This is the
// algorithmic portion of this state.
void Retract::firstRun()
{
    decision = 0;
    data.saveLog();
    data.clearLogValues();
    emit visual_stop();  // This makes sure whatever visual stimulation was running or was paused get's saved to a file.
    emit gui_enablePages(false);
    emit gui_busy_start("Retracting pipette");
    emit thorLabsMotor_moveToAbsolute(-4,2);
    emit daq_stopTask();
    //emit gui_clearMemTestPlot();
    //emit gui_clearRawDataPlot();
    //emit gui_clearResistancePlot();
}

void Retract::thorLabsMotor_moveComplete()
{
    decision = 1;
    emit stateFinished();
}
