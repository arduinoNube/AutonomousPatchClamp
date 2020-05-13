#include "clogcheck.h"
#include <QDebug>
#include <workers/autopatcherworker.h>
#include <cmath>

ClogCheck::ClogCheck(QObject *parent) : State(parent)
{
    name = "Clog Check";
    description = "This state takes one resistance measurement at the desired starting \
depth to see if the pipette is clogged.  If it's not, it continues to neuron hunting.";
    timer1.setSingleShot(true);
    ptrTimer1Timeout = NULL;
}

ClogCheck::~ClogCheck()
{

}

void ClogCheck::timer1_timeout()
{
    if(ptrTimer1Timeout != NULL)
    {
        (this->*ptrTimer1Timeout)();
    }
}

void ClogCheck::pauseState(bool) // 1 tells the state to pause, 0 to continue
{

}

void ClogCheck::haltState()
{

}

// **************** PROCEDURAL CODE START *******************
// Code in this section should be very sequential and each
// method should be called after the previous.  This is the
// algorithmic portion of this state.
void ClogCheck::firstRun()
{
    // The DAQ tasks should be running so the raw data plot is updated during the wait period
    decision = 0; // error state default

    // The state machine messes with the connections so they have to be initialized every time the states switch
    // or just before they are needed in each state like this:
    disconnect(&timer1,SIGNAL(timeout()),this,SLOT(timer1_timeout()));
    connect(&timer1,SIGNAL(timeout()),this,SLOT(timer1_timeout()),Qt::QueuedConnection);

    emit gui_setCurrentPageIndex("page_autopatching");
    emit gui_busy_start("Clog Check: Waiting " + QString::number(data.delayAfterDescent) + " seconds and then checking the resistance to see if the pipette is clogged.");
    //emit autopatcher_switchPressure(AutopatcherWorker::PRESSURE_LOW_P,0); // Moved after the resistance check so that it get's about 1 second at high pressure before dropping it.
    emit daq_getTaskRunning();
    emit autopatcher_switchBNC(1,0);
}

void ClogCheck::daq_taskRunning(int flag)
{
    if(flag == DAQWorker::TASKTYPE_RESISTANCE_CHECK)
    {
        ptrResDataReady = &A;
        emit daq_trigger();  // Doing a quick resistance check for a broken pipette
    }
    else
    {
        qWarning() << "Error! DAQ tasks were not running." << name;
        decision = 0;
        emit stateFinished();
    }
}


void ClogCheck::A(double res)
{
    data.LOG_pipetteClogCheckVal = res;
    data.LOG_pipetteClogCheckTime = QTime::currentTime();
    data.LOG_pipetteClogCheckDepth = data.startDepth;

    // Check for broken pipette
    if(res < (data.LOG_resAveAboveBrain - 3 * data.clogThresh))
    {
        // emergency pressure release and retract
        emit autopatcher_switchPressure(AutopatcherWorker::PRESSURE_ATM,0);
        emit thorLabsMotor_moveToAbsolute(-4,2);   // Moving 2mm above the surface of the brain
        emit gui_busy_stop("Pipette broken!  Emergency pressure release and retract");
        return;
    }
    else
    {
        qWarning() << "Pipette not broken";
    }
    ptrResDataReady = NULL;
    ptrTimer1Timeout = &B;
    qWarning() << "delay: " << fabs(data.delayAfterDescent-1)*1000;
//    timer1.start(fabs(data.delayAfterDescent-1)*1000);
    emit autopatcher_switchPressure(AutopatcherWorker::PRESSURE_LOW_P,0);
    timer1.start(fabs(data.delayAfterDescent-1)*1000);
}

void ClogCheck::thorLabsMotor_moveComplete()
{
    // Pipette was broken
    decision = 2;
    emit stateFinished();
}

void ClogCheck::B()
{
    ptrTimer1Timeout = NULL;
    ptrResDataReady = &C;
    gui_busy_start("Measuring resistance");
    emit daq_trigger();
}

void ClogCheck::C(double res)
{
    data.LOG_pipetteClogCheckVal = res;
    data.LOG_pipetteClogCheckTime = QTime::currentTime();
    data.LOG_pipetteClogCheckDepth = data.startDepth;
    emit gui_plotResData(res);

    // Pipette is ok
    qWarning() << "Clog check: " << res << data.LOG_resAveAboveBrain << fabs(res - data.LOG_resAveAboveBrain) << fabs(res - data.LOG_pipetteCheckResVals.last()) << data.clogThresh;
    if((fabs(res - data.LOG_resAveAboveBrain) < data.clogThresh) || (fabs(res - data.LOG_pipetteCheckResVals.last()) < data.clogThresh))
    {
        emit gui_busy_stop("Pipette not clogged or broken.");
        qWarning() << "Pipette not clogged or broken.";
        decision = 1;
        emit stateFinished();
    }
    // Pipette is clogged or became unclogged.  Either way, it's a weird one.
    else if ((res - data.LOG_resAveAboveBrain) < -data.clogThresh)
    {
        emit gui_busy_stop("Pipette became unclogged ( R_diff < -(clog threshold)).  Discarding.");
        qWarning() << "Pipette became unclogged.  Discarding." << res << data.LOG_resAveAboveBrain << data.clogThresh;
        decision = 2;
        emit stateFinished();
    }
    else if((res - data.LOG_resAveAboveBrain) > 3)
    {
        //qWarning() << "Pipette is blocked by something.  It could be a cell.  Attempting a gigaseal. Hit size: " << res - data.LOG_resAveAboveBrain;
        //decision = 3;
        qWarning() << "Pipette is clogged.  Discarding.";
        decision = 2;
        emit stateFinished();
    }
    else if((res - data.LOG_resAveAboveBrain) > 0)
    {
        qWarning() << "Pipette is clogged.  Discarding.";
        decision = 2;
        emit stateFinished();
    }
}
