#include "trialinit.h"
#include <QDebug>

TrialInit::TrialInit(QObject *parent) : State(parent)
{
    name        = "Trial initialization";
    description = "This state switches the BNC relay, switches the pipette to high \
pressure, and moves the pipette to the surface of the brain (or switches to the \
\"set brain height\" state so the user can adjust the pipette until it's in position).";


    timer1.setInterval(200);
    timer1.setSingleShot(true);
    connect(&timer1,SIGNAL(timeout()),this,SLOT(ready()),Qt::QueuedConnection);
}

TrialInit::~TrialInit()
{

}


void TrialInit::pauseState(bool) // 1 tells the state to pause, 0 to continue
{

}

void TrialInit::haltState()
{

}

// **************** PROCEDURAL CODE START *******************
// Code in this section should be very sequential and each
// method should be called after the previous.  This is the
// algorithmic portion of this state.
void TrialInit::firstRun()
{
    decision = 0;
    emit gui_busy_start("Initializing hardware for patching trial.");
    emit gui_clearMemTestPlot();
    emit gui_clearRawDataPlot();
    emit gui_clearResistancePlot();

    emit autopatcher_switchBNC(true, 0);
    emit autopatcher_switchPressure(AutopatcherWorker::PRESSURE_HIGH_P, 0);


    // Initializing the hunting variables just before starting the hunting state
    // They can't be cleared within neuron hunt because gigaseal can return to neuron
    // hunt and the values, depth, and times shouldn't be cleared.

    data.clearLogValues();

    timer1.start();


    // Initializing Logic flow flags
    /*
     * These are critical logic flow control flags that sare used in various subsequent states.
     * They are initialized here just in case something crashed or went weird on the last trial.
     */
    data.visualStimPaused  = 0;
    data.visualStimCounter = 0;
}

void TrialInit::ready()
{
    if(data.brainHeightSet)
    {
        decision = 2;  // Go straight to pipette QC
        double diff = data.pipetteLengthCurrent-data.pipetteLengthWhenHeightSet;
        thorLabsMotor_moveToAbsolute(data.brainHeight+diff,2);
        qWarning() << "Pipette lengths: Original " << data.pipetteLengthWhenHeightSet << " Current " << data.pipetteLengthCurrent;
    }
    else
    {
        decision = 1;  // Go to "set pipette height" state
        emit stateFinished();
    }
}

void TrialInit::thorLabsMotor_moveComplete()
{
    emit stateFinished();
}

