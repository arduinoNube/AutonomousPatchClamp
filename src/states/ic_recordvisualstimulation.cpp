#include "ic_recordvisualstimulation.h"

IC_RecordVisualStimulation::IC_RecordVisualStimulation(QObject *parent) : State(parent)
{
    name = "Visual Stimulation Recording State";
    description="This state puts the system in current clamp mode and starts the visual \
stimulation on the remote computer.  It doesn't pause to check the recording during the \
visual stimulation in this version but that can be easily added.  ";

    timer1.setInterval(data.cellQCInterval);
    timer1.setSingleShot(true);
    connect(&timer1,SIGNAL(timeout()),this,SLOT(timer1_timeout()),Qt::QueuedConnection);
}

IC_RecordVisualStimulation::~IC_RecordVisualStimulation()
{

}

void IC_RecordVisualStimulation::pauseState(bool) // Toggled
{

}

void IC_RecordVisualStimulation::haltState()
{

}

// **************** PROCEDURAL CODE START *******************
// Code in this section should be very sequential and each
// method should be called after the previous.  This is the
// algorithmic portion of this state.
void IC_RecordVisualStimulation::firstRun()
{
    emit daq_stopTask();
    emit gui_busy_start("Visual stimulation running, please wait...");
    if(data.visualStimPaused)
    {
        qWarning() << "Continuing a previously started visual stimulation.";
        emit visual_continue();
        emit timer1.start();
    }
    else
    {
        qWarning() << "Starting a new visual stimulation session.";
        emit visual_start(data.screenNumber);
        timer1.start();
    }
}

void IC_RecordVisualStimulation::timer1_timeout()
{
    emit visual_pause();
    emit gui_busy_start("Visual stimulation paused for a quality control check.  It will resume shortly.");
}

void IC_RecordVisualStimulation::visual_paused()
{
    qWarning() << "Visual stimulation paused.";
    data.visualStimPaused = 1;
    finish();
}

void IC_RecordVisualStimulation::visual_finished()
{
    qWarning() << "Visual stimulation finished.";
    data.visualStimPaused = 0;
    data.visualStimCounter++;
    finish();
}

void IC_RecordVisualStimulation::finish()
{    
    timer1.stop();
    decision = 1;
    emit stateFinished();
}


