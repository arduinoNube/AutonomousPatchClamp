#include "retractslowly.h"
#include <QDebug>

RetractSlowly::RetractSlowly(QObject *parent) : State(parent)
{

}

RetractSlowly::~RetractSlowly()
{

}



void RetractSlowly::pauseState(bool) // 1 tells the state to pause, 0 to continue
{

}

void RetractSlowly::haltState()
{

}

void RetractSlowly::firstRun()
{
    emit gui_enablePages(false);
    decision = 0;
    dist = 0;
    emit gui_enablePages(false);
    emit gui_busy_start("Retracting pipette slowly to attempt reseal");
    emit multiclamp_setMode(MCCMSG_MODE_VCLAMP);
    emit multiclamp_setHoldingVRaw(-0.065);
    emit multiclamp_setHoldingVChecked(true);
    emit autopatcher_switchBNC(true,false);
    emit daq_initTask(DAQWorker::TASKTYPE_RESISTANCE_CHECK);
    emit daq_startTask();
    ptrThorMoveComplete = &A;
    emit daq_trigger();
}

void RetractSlowly::daq_resDataReady(double val)
{
    data.LOG_retractionResVals.push_back(val);
    data.LOG_retractionResDepth.push_back(dist);
    data.LOG_retractionResTime.push_back(QTime::currentTime());
    emit gui_plotResData(val);
    if(val > 1000)
    {
        qWarning() << "Gigaseal on retraction achieved";
        emit gui_busy_start("Gigaseal on retraction achieved!");
    }
    dist += data.slowRetractStepSize/1000.0;
    if(dist < 0.200)
    {
        emit thorLabsMotor_moveByRelative(data.slowRetractStepSize/1000.0,2);
    }
    else
    {        
        data.saveLog();
        data.clearLogValues();
        emit daq_stopTask();
        ptrThorMoveComplete = &B;
        emit thorLabsMotor_moveToAbsolute(-4,2);
    }
}

void RetractSlowly::A()
{
    emit daq_trigger();
}

void RetractSlowly::B()
{
    ptrThorMoveComplete = NULL;
    decision = 1;
    emit stateFinished();
}

