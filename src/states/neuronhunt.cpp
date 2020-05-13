#include "neuronhunt.h"
#include <QDebug>

NeuronHunt::NeuronHunt(QObject *parent) : State(parent)
{
    name = "Neuron Hunt";
    description = "This state searches for neurons by moving the pipette down into the tissue in 2 micron steps \
and measuring the resistance at each step.  When the resistance increases over 3 subsequent steps and the total \
resistance increase over those three steps is greater than a specified threshold, the motor stops and the robot \
switches to the next state.  If the pipette becomes unresponsive, detected by a very low resistance variation, \
or if the average resistance drifts from the baseline resistance by more than 0.5 megaohms, the pipette is deemed clogged \
and is retracted.  Some of these algorithms are still under development.";
}

NeuronHunt::~NeuronHunt()
{

}

void NeuronHunt::pauseState(bool) // 1 tells the state to pause, 0 to continue
{

}

void NeuronHunt::haltState()
{

}

// **************** PROCEDURAL CODE START *******************
// Code in this section should be very sequential and each
// method should be called after the previous.  This is the
// algorithmic portion of this state.
void NeuronHunt::firstRun()
{
    detectionFlag = 0;
    // This state assumes the DAQ tasks are still running from the previous state
    emit daq_getTaskRunning();
    emit gui_setCurrentPageIndex("page_autopatching");
    emit autopatcher_switchBNC(1,0);
}

void NeuronHunt::daq_taskRunning(int flag)
{
    if(flag == 0)
    {
        emit gui_busy_start("Hunting for neurons");
        thisHuntStartIndex = data.LOG_huntingResVals.size();
        emit daq_trigger();  // Doing a quick resistance check for a broken pipette
    }
    else
    {
        qWarning() << "Error! DAQ tasks were not running." << name;
        decision = 0;
        emit stateFinished();
    }
}

/* This section loops between reading a resistance and moving the motor until one of
 * 4 conditions are met.
 *
 * 1. The resistance values trigger the neuron detection algorithms and it continues to the next state.
 * 2. The motor reaches the end of the hunt distance without triggering the detection algorithm.  It retracts the pipette.
 * 3. The resistance values drift more than a specified amount over a long distance.  The pipette is retracted
 * 4. The resistance of the pipette doesn't have enough variation.  The pipette is retracted
 */

void NeuronHunt::daq_resDataReady(double res)
{
    emit gui_plotResData(res);
    data.LOG_huntingResVals.push_back(res);
    data.LOG_huntingResValsTime.push_back(QTime::currentTime());
    data.LOG_huntingResValsDepth.push_back(data.LOG_huntingResVals.size()*data.stepSize+data.LOG_pipetteClogCheckDepth);
    QVector<double> vals;
    for(int i=thisHuntStartIndex; i< data.LOG_huntingResVals.size(); i++)
    {
        vals.push_back(data.LOG_huntingResVals[i]);; // just to shorten the name.  There will never be more than a couple hundered values here so it's fast.
    }
    int n = vals.size();


    // Basic Stepwise Neuron Detection Algorithm
    if(n>2)
    {
        // If it meets the normal criteria for a neuron detection
        bool flag(1);
        for(int i=n-1; i>n-1-data.nDetectSamps+1; i--)
        {
            if(vals[i] > vals[i-1]){}
            else { flag = 0; break;};
        }
        if(flag && (vals[n-1] - vals[n-3]) > data.neuronThresh)
        {
            data.LOG_pipetteHitSize.push_back(vals[n-1]-vals[n-3]);
            data.LOG_pipetteHitTime.push_back(QTime::currentTime());
            data.LOG_pipetteHitDepth.push_back(data.LOG_huntingResValsDepth.last());
            qWarning() << "Basic neuron detection triggered!" << vals[n-3] << vals[n-2] << vals[n-1];
            if(n>6)
            {
                qWarning() << "Performing the advanced check (n>6).";
                // Double checking against an average resistance value
                // Averaging the first 4 of the last 6 resistance values
                double ave(0);
                int j(0);
                for(int i=n-3; i>=n-6; i--)
                {
                    j++;
                    ave += vals[i];
                }
                ave = ave/j;
                if((vals[n-1] - ave) > data.neuronThresh)
                {
                    qWarning() << "Advanced neuron detection check passed!" << ave << vals[n-1];
                    detectionFlag = 1;
                }
                else
                {
                    qWarning() << "Advanced neuron detection check FAILED! (continuing anyway)" << ave << vals[n-1];
                    detectionFlag = 1;
                }
            }
            else
            {
                detectionFlag = 1;
            }
        }
        // If it was a "huge" resistance change (this doesn't require the sequential increase constraint)
        // Then go ahead and seal onto it.  No need to take an extra step.  *** UNVERIFIED AS HELPFUL
        else if((vals[n-1] - vals[n-3]) > data.hitNoStepThresh)
        {
            detectionFlag = 1;
        }
    }

    // If the first step has a very large resistance change, stop neuron hunt and continue
    if(n==2)
    {
        if( vals[n-1] - vals[n-2] > data.neuronThresh*3)
        {
            detectionFlag = 1;
        }
    }

    // NEURON DETECTED!  Getting the motor position and finishing
    if(detectionFlag)
    {
        emit thorLabsMotor_getPosition(true);
    }
    else
    {
        // Checking for severe resistance drift (> 1 MOhm)
        if(n >= 12)
        {
            double ave(0);
            int j(0);
            for(int i=n-3; i>=n-12; i--)
            {
                j++;
                ave += vals[i];
            }
            ave = ave/j;

            if(ave > data.LOG_resAveAboveBrain + 2)
            {
                qWarning() << "Pipette drift detected > 2 MOhms.  Retracting.";
                emit gui_busy_start("Pipette drift detected > 2 MOhms.  Retracting.");
                decision = 2;
                emit stateFinished();
                return;
            }
        }

        if(data.LOG_huntingResValsDepth.last() > data.stopDepth)
        {
            qWarning() << "Neuron hunt stop depth reached.  Retracting";
            emit gui_busy_start("Neuron hunt stop depth reached.  Retracting");
            decision = 2;
            emit stateFinished();
            return;
        }

        // Checking for zero variation (non-responsive electrode)  This doesn't happen very often.
        int numCheck(40);  // The number of values to check the variation over.
        double thresh(0.025);  // MOhm variation threshold below which the pipette is considered "unresponsive"
        if(n >= numCheck)
        {
            double max(0),min(9999);

            for(int i=n-3; i>=n-numCheck; i--)
            {
                if(vals[i] < min) min = vals[i];
                if(vals[i] > max) max = vals[i];
            }

            if((max-min) < thresh)
            {
                qWarning() << "Pipette resistance unresponsive (variation < " << QString::number(thresh) << " MOhms). Retracting.";
                emit gui_busy_start("Pipette resistance unresponsive (variation < " + QString::number(thresh) + " MOhms). Retracting.");
                decision = 2;
                emit stateFinished();
                return;
            }
        }

        // If the pipette passes all the checks above, take another step.
        emit thorLabsMotor_moveByRelative(-data.stepSize/1000,0.2);
        emit gui_updateCurrentBrainPosition(data.LOG_huntingResValsDepth.last());
    }
}


void NeuronHunt::thorLabsMotor_moveComplete()
{
    emit daq_trigger();
}

void NeuronHunt::thorLabsMotor_currentMotorPosition(float)
{
    // Something is wrong with the position value.  It's already stored in in the LOG variable by the
    // prevous function so this is really not necessary.
    //  data.LOG_pipetteHitDepth.push_back(-(pos - data.brainHeight));
    decision = 1;
    emit stateFinished();
}
