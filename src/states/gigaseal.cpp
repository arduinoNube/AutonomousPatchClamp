#include "gigaseal.h"
#include <QDebug>
#include <cmath>

Gigaseal::Gigaseal(QObject *parent) : State(parent)
{
    name = "Gigasealing";
    description = "This state assumse a neuron has been detected but checks to see if the resistance \
drops back down to the baseline resistance measured just before the detection event.  If it stays at \
the elevated resistance value, then pressure is released and the holding voltage is ramped down \
and it continuously monitors the gigasealing resistance.  If it doesn't seal fast enough or get to \
a high enough value, it retracts the pipette.";
    timer1.setSingleShot(true);
    timer2.setSingleShot(true);
}

Gigaseal::~Gigaseal()
{

}


void Gigaseal::pauseState(bool toggled) // 1 tells the state to pause, 0 to continue
{
    if(toggled)
    {
        pauseFlag = 1;
    }
    else
    {
        pauseFlag = 0;
        emit daq_trigger();
    }
}

void Gigaseal::haltState()
{

}

void Gigaseal::daq_resDataReady(double res)
{
    if(ptrResDataReady!=NULL)
    {
        // MOVE CODE HERE THAT RUNS EVERY TIME A RESISTANCE VALUE IS ACQUIRED
        (this->*ptrResDataReady)(res);
    }
}

int Gigaseal::calculateSeconds(QTime time)
{
    // Calculating timing for gigaseal monitoring and pressure and voltage ramp control
    return ((QTime::currentTime().msecsSinceStartOfDay() - time.msecsSinceStartOfDay())/1000.0);
}

double Gigaseal::calcSlope(QVector<QTime> time,QVector<double> pts)
{
    if(time.length() == pts.length())
    {
        double aveTime(0), avePts(0), b(0),num(0),den(0);

        for(int i=0; i<pts.length(); i++)
        {
            aveTime += time[i].msecsSinceStartOfDay();
            avePts  += pts[i];
        }
        aveTime = aveTime/time.length();
        avePts  = avePts/pts.length();

        for(int i=0; i<pts.length(); i++)
        {
            num += (time[i].msecsSinceStartOfDay()-aveTime)/1000*(pts[i]-avePts);
            den += pow(time[i].msecsSinceStartOfDay()-aveTime,2)/1000000;
        }
        b = num/den;
        return b;
    }
    else
    {
        qWarning() << "error calculating the slope of the resistance trace";
        return -999999;
    }
}

// **************** PROCEDURAL CODE START *******************
// Code in this section should be very sequential and each
// method should be called after the previous.  This is the
// algorithmic portion of this state.
void Gigaseal::firstRun()
{
    ptrResDataReady = NULL;
    pauseFlag = 0;
    decision = 0;
    thisGigasealStartIndex = data.LOG_gigasealingResVals.length();
    // This state assumes the DAQ tasks are still running from the previous state
    emit daq_getTaskRunning();
    emit gui_setCurrentPageIndex("page_autopatching");
    emit autopatcher_switchBNC(1,0);

    disconnect(&timer1,SIGNAL(timeout()),this,SLOT(timer1_timeout()));
    connect(&timer1,SIGNAL(timeout()),this,SLOT(timer1_timeout()),Qt::QueuedConnection);
    disconnect(&timer2,SIGNAL(timeout()),this,SLOT(timer2_timeout()));
    connect(&timer2,SIGNAL(timeout()),this,SLOT(timer2_timeout()),Qt::QueuedConnection);
}

void Gigaseal::daq_taskRunning(int flag)
{
    if(flag == DAQWorker::TASKTYPE_RESISTANCE_CHECK)
    {
        emit gui_busy_start("Gigasealing: Motor stopped, moitoring the seal resistance");
        emit gui_pauseButtonVisible(true);
        emit gui_pauseButtonEnable(true);
        ptrResDataReady = &A;
        emit daq_trigger();
        qWarning() << "10 Second check";
    }
    else
    {
        qWarning() << "Error! DAQ tasks were not running." << name;
        decision = 0;
        emit stateFinished();
    }
}


void Gigaseal::A(double res)
{

    if(!pauseFlag)
    {
        emit gui_plotResData(res);
        data.LOG_gigasealingResVals.push_back(res);
        data.LOG_gigasealingResValsTime.push_back(QTime::currentTime());

        QVector<double> vals;
        for(int i=thisGigasealStartIndex; i< data.LOG_gigasealingResVals.size(); i++)
        {
            vals.push_back(data.LOG_gigasealingResVals[i]);; // just to shorten the name.  There will never be more than a couple hundered values here so it's fast.
        }
        int n = vals.size();
        // If the user specified a number less than 8, the 10 second wait won't work well so just releasing pressure and continuing
        if(data.numSampsToWaitToReleasePress < 8)
        {
            data.gigasealStartTime.start();
            qWarning() << "Gigaseal start time set: " << data.gigasealStartTime.isValid();
            qWarning() << "Skipping " << data.numSampsToWaitToReleasePress << " sample check.  Pressure released.  Going on to wait for 1000 MOhms.";
            emit autopatcher_switchPressure(AutopatcherWorker::PRESSURE_ATM,false);
            ptrResDataReady = &B;
            emit daq_trigger();
            return;
        }

        // Checking resistance after waiting for 10 samples
        if(n==data.numSampsToWaitToReleasePress)
        {
            // Comparing the first 4 samples and the last 4
            double ave1(0), ave2(0);
            for(int i=0; i<4; i++)
            {
                ave1 += vals[i];
            }
            ave1 = ave1/4;
            for(int i=n-1; i>5; i--)
            {
                ave2 += vals[i];
            }
            ave2 = ave2/4;

            // If passed 10 second check
            if(((ave2 >= data.LOG_resAveAboveBrain + data.neuronThresh)))  // If the resistance is still at least above threshold
            // and it hasn't dropped more than returnThresh unless it was a huge hit and is twice the detection threshold (add this back in if it doesn't behave properly)
            // && ((ave1-ave2) < data.returnThresh) || (ave2 > data.LOG_resAveAboveBrain + data.neuronThresh*2)))
            {
                data.gigasealStartTime.start();
                qWarning() << "Passed " << data.numSampsToWaitToReleasePress << " sample check.  Going on to wait for 1000 MOhms.";
                emit autopatcher_switchPressure(AutopatcherWorker::PRESSURE_ATM,false);
                ptrResDataReady = &B;
                emit daq_trigger();
            }
            // return to neuron hunt
            else
            {
                qWarning() << "Failed " << data.numSampsToWaitToReleasePress << " sample check.  Going back to neuron hunt";
                decision = 2; // Neuron Hunt
                emit stateFinished();
            }
        }
        else
        {
            emit daq_trigger();
        }
    }
}

// Measuring the resistance, waiting for a few seconds at atmospheric pressure, applying suction, and ramping down the voltage
void Gigaseal::B(double res)
{
    if(!pauseFlag)
    {
        emit gui_plotResData(res);
        data.LOG_gigasealingResVals.push_back(res);
        data.LOG_gigasealingResValsTime.push_back(QTime::currentTime());

        // Calculating timing for gigaseal monitoring and pressure and voltage ramp control
        qWarning() << data.gigasealStartTime.elapsed() << data.atmosphericDuration;
        if(data.gigasealStartTime.elapsed()/1000 >= data.atmosphericDuration)
        {
            emit autopatcher_switchPressure(AutopatcherWorker::PRESSURE_LOW_V,false);
            timer1.start(data.suctionDuration*1000);
            readyForRamp = 0;
            ptrResDataReady = &C;            
        }
        emit daq_trigger();
    }
}

// Just logging the values during the period during suction
void Gigaseal::C(double res)
{
    if(!pauseFlag)
    {
        emit gui_plotResData(res);
        data.LOG_gigasealingResVals.push_back(res);
        data.LOG_gigasealingResValsTime.push_back(QTime::currentTime());
        if(!readyForRamp)
        {
            emit daq_trigger();
        }
        else
        {
            emit autopatcher_switchPressure(AutopatcherWorker::PRESSURE_ATM,false);
            emit multiclamp_selectChannel(data.headstageNum);
            emit multiclamp_setHoldingVChecked(true);
            emit multiclamp_setHoldingVSafe(-0.03,false);
            holdingV = -0.03;
            ptrResDataReady = &D;
            emit gui_busy_start("Gigasealing.  Do NOT interact with multiclamp commander during the voltage ramp.");
            timer2.start(50);  // This gives time to multiclamp commander to set the holding voltage before the next resistance measurement.  Ideally, this should be event driven rather than hopeful timing.
        }
    }
}

void Gigaseal::timer1_timeout()  // Releasing suction and ramping down voltage
{
    readyForRamp = 1;
}

void Gigaseal::D(double res)  // Ramping down voltage -1mV/s
{
    if(!pauseFlag)
    {
        holdingV = holdingV  -0.002;
//        emit multiclamp_selectChannel(data.headstageNum);
//        emit multiclamp_setHoldingVChecked(true);
        emit multiclamp_setHoldingVRaw(holdingV);
        if(holdingV <= -0.065 || res > data.breakInThresh)
        {
//            emit multiclamp_selectChannel(data.headstageNum);
//            emit multiclamp_setHoldingVChecked(true);
            emit multiclamp_setHoldingVRaw(-0.065);
            ptrResDataReady = &E;
        }

        emit gui_busy_start("Ramping down the holding voltage.  Do NOT interact with multiclamp commander during the voltage ramp.");
        emit gui_plotResData(res);
        data.LOG_gigasealingResVals.push_back(res);
        data.LOG_gigasealingResValsTime.push_back(QTime::currentTime());

        timer2.start(37);  // Giving time for multiclamp to change the holding voltage
    }
}

void Gigaseal::timer2_timeout()
{
    emit daq_trigger(); // Don't worry if the daq is already triggered.  It will (should) ignore double triggers.
}

// Checking for a gigaseal after pressure switched and voltage is ramped down
// (and retracting if it doesn't get there fast enough, if ever)
void Gigaseal::E(double res)
{
    if(!pauseFlag)
    {
        emit gui_busy_start("Voltage ramp complete.  Watching how fast the seal is forming.");
        emit gui_plotResData(res);
        data.LOG_gigasealingResVals.push_back(res);
        data.LOG_gigasealingResValsTime.push_back(QTime::currentTime());
        int n = data.LOG_gigasealingResVals.length();

        // Calculating timing for gigaseal monitoring and pressure and voltage ramp control
        double seconds = data.gigasealStartTime.elapsed()/1000 - data.suctionDuration - data.atmosphericDuration;
        if(seconds < 0) seconds = 0;

        // If gigaseal, switch to function C;
        if(res > data.breakInThresh)  // usually 1000 MOhms
        {
            firstDerivative.clear();
            ptrResDataReady = &F; // Gigaseal was formed, now on to the monitoring stage
            qWarning() << "Gigaseal formed: " << res << " MOhms after " << seconds << " seconds.";
            emit daq_trigger();
            return;
        }

        // **********************************
        // ********* Will it seal? **********
        // **********************************
        /* This section measures the progression of the gigaseal and will
         * reject pipettes that don't seal fast enough.  There three tiers:
         *
         * 1. The resistance is below 20 MOhms after 30 seconds  (Maybe after this case fails, try more suction rather than retract. This still needs to be developed)
         * 2. The resistance is below 100 MOhms after 90 seconds
         * 3. The resistance is below 500 MOhms after 120 seconds
         * 4. The resistance is below 1000 MOhms after 180 seconds.
         *
         * If any of the above are true, it will retract the pipette
         *
         */
        if(n > 3)
        {
            double resAve = data.LOG_gigasealingResVals[n-1] + data.LOG_gigasealingResVals[n-2]+ data.LOG_gigasealingResVals[n-3];
            resAve = resAve/3.0;
            qWarning() << resAve << seconds;
            if(((resAve < 40)   && (seconds > 30)) ||
               ((resAve < 100)  && (seconds > 90)) ||
               ((resAve < 500)  && (seconds > 120))||
               ((resAve < 1000) && (seconds > 180)))
            {
                qWarning() << "Failed to form a gigaseal.  Last average resistance value (n=3): " << resAve << "MOhms after " << seconds << " seconds.";
                emit gui_busy_start("Failed to seal or was too slow to seal.");
                decision = 3;
                emit stateFinished();
            }
            else
            {
                emit daq_trigger();
            }
        }
        else
        {
            emit daq_trigger();
        }
    }
}

// Waiting for the seal to stabilize (it has already hit 1 GOhm)
void Gigaseal::F(double res)
{
    if(!pauseFlag)
    {
        emit gui_plotResData(res);
        emit gui_busy_start("Gigaseal formed.  Waiting for seal to stabilize.");
        data.LOG_gigasealingResVals.push_back(res);
        data.LOG_gigasealingResValsTime.push_back(QTime::currentTime());
        QVector<double> vals;
        for(int i=thisGigasealStartIndex; i< data.LOG_gigasealingResVals.size(); i++)
        {
            vals.push_back(data.LOG_gigasealingResVals[i]);; // just to shorten the name.  There will never be more than a couple hundered values here so it's fast.
        }
        int n = vals.size();

        // Performing a local regression to calculate the derivatives
        int nPointsRegression1(30);
        int nPointsRegression2(5);

        // If there are enough points to calculate the derivatives
        double secondDerivative(0);
        if(n > nPointsRegression1)
        {
            // Calculating the first derivative
            firstDerivative.push_back(calcSlope(data.LOG_gigasealingResValsTime.mid(data.LOG_gigasealingResValsTime.length()-nPointsRegression1,nPointsRegression1)
                                                ,vals.mid(vals.length()-nPointsRegression1,nPointsRegression1)));

            // Calculating the maximum slope
            double firstDMax(0);
            for(int i=0; i<firstDerivative.length(); i++)
            {
                if(firstDerivative[i] > firstDMax) firstDMax = firstDerivative[i];
            }

            // Calculating the second derivative
            // (it was supposed to calculate the 2nd derivative like the algorithm in gigasealProcessNew.m
            // but I forgot to take the second derivative in this code before I ran all the experiments so
            // it ran with the algorithm as it stands.
            if(firstDerivative.length() > nPointsRegression2)
            {
                secondDerivative = calcSlope(data.LOG_gigasealingResValsTime.mid(n-nPointsRegression2,-1),vals.mid(n-nPointsRegression2,-1));

                // ********************* Gigaseal Stabilization THRESHOLDS *********************
                double gigaseal(data.breakInThresh);    // Should already be gigasealed but just in case;
                double firstDerivativeThresh(50);       // the first derivative should be less than this value to trigger break in
                double secondDerivativeThresh(1);       // second derivative must be less than this value to trigger break in
                double percentageThreshold(0.5);        // The percentage drop from the maximum first derivative in order to trigger break in
                                                        // (this is only used for cases where the maximum slope value from this trace was
                                                        // below the firstDerivativeThreshold, meaning that for slow sealing cells,
                                                        // (where the slope < firstDerivativeThreshold at all points) it will wait until the
                                                        // slope has dropped by percentThreshold percent.

                qWarning() << "Gigaseal stabilization data: " << res << firstDerivative.last() << secondDerivative << (firstDMax-firstDerivative.last())/firstDMax;
                if((res > gigaseal) &&
                   (firstDerivative.last() < firstDerivativeThresh) &&
                   (secondDerivative < secondDerivativeThresh) &&
                   ((firstDMax-firstDerivative.last())/firstDMax > percentageThreshold))
                {
                    decision = 1;
                    stateFinished();
                    return;
                }

                // If the maximum wait time has expired
                if(data.gigasealStartTime.elapsed()/1000 > data.gigasealMaxWait)
                {
                    qWarning() << "The maximum gigaseal wait time expired.  Proceeding to break in.";
                    decision = 1;
                    stateFinished();
                    return;
                }

                // Seal resistance dropped (spontaneous break in or lost cell)
                int minSealThresh(500);
                double resAve = vals[n-1] + vals[n-2]+ vals[n-3];
                resAve = resAve/3;

                if(resAve < minSealThresh)  // this code worked well on one cell so far.
                {
                    qWarning() << "Seal resistance dropped below " << QString::number(minSealThresh) << " MOhms.  Could have broken in spontaneously. Proceeding to cell QC.";
                    gui_busy_start("Seal resistance dropped.  Checking for spontaneous break in.");
                    decision = 4;
                    stateFinished();
                    return;
                }
            }
        }
        emit daq_trigger();
    }
}


