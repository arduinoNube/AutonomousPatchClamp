#include "ic_bridgebalanceadjust.h"
#include <fstream>

using namespace std;

IC_BridgeBalanceAdjust::IC_BridgeBalanceAdjust(QObject *parent) : State(parent)
{
    name = "Bridge Balance Adjust State";
    description = "This state will start a test pulse (500 pA at 150 Hz) \
and adjust the bridge balance until the steps at the transitions \
in the sawtooth wave disappear.";
    bridgeBalance = 10; // MOhms default.
}

IC_BridgeBalanceAdjust::~IC_BridgeBalanceAdjust()
{

}

void IC_BridgeBalanceAdjust::pauseState(bool) // Toggled
{

}

void IC_BridgeBalanceAdjust::haltState()
{

}

void IC_BridgeBalanceAdjust::setHardwareVals(HardwareSettingsWindow * hw_win)
{
    samplingRate = hw_win->daqSampRate;
}

void IC_BridgeBalanceAdjust::regression(QVector<double> x, QVector<double> y, double &m, double &b)
{
    int n=x.size();
    double xSum(0), ySum(0), xxSum(0), xySum(0);   // Regression variables
    if(x.size() == y.size())
    {
        for(int i=0; i<y.size(); i++)
        {
            xSum += x[i];
            ySum += y[i];
            xxSum += x[i]*x[i];
            xySum += x[i]*y[i];
        }
        m = (xySum - xSum*ySum/n)/(xxSum-xSum*xSum/n);
        b = (ySum-m*xSum)/n;
    }
    else
    {
        qWarning() << "Regression Error!";
        m = 0;
        b = 0;
    }
}

// **************** PROCEDURAL CODE START *******************
// Code in this section should be very sequential and each
// method should be called after the previous.  This is the
// algorithmic portion of this state.
void IC_BridgeBalanceAdjust::firstRun()
{
    emit gui_setCurrentPageIndex("page_cell_qc");
    // Switching to current clamp
    emit multiclamp_selectChannel(data.headstageNum);
    emit multiclamp_setMode(MCCMSG_MODE_ICLAMP);
    emit multiclamp_setHoldingIChecked(false,false);
    qWarning() << "Pipette Capacitance Compensation Value: " << data.pipetteCapacitance;
    emit multiclamp_setPipetteCapacitanceCompensation(0); // This is important that it is ZERO!  If there is pipette capacitance and there are oscillations, it will throw the algorithm off!
    emit multiclamp_enablePipetteCapacitanceCompensation(true);
    emit multiclamp_setHoldingISafe(0*pow(10,-12),true);
    emit multiclamp_setHoldingIChecked(true,true);
}

void IC_BridgeBalanceAdjust::multiclamp_holdingCurrentCheckedComplete()
{
    emit multiclamp_getBridgeBalance();
}

void IC_BridgeBalanceAdjust::multiclamp_getBridgeBalanceComplete(double valMOhms)
{
    bridgeBalance = valMOhms*pow(10,-6);
    emit daq_initTask(DAQWorker::TASKTYPE_IC_MEMBRANE_TEST);
}

void IC_BridgeBalanceAdjust::daq_initTaskReady()
{
    enabled = 1;
    f = 1;
    a = 0;
    counterGood = 0;
    counterBad = 0;
    emit daq_startTask();
}

void IC_BridgeBalanceAdjust::daq_initError()
{
    qWarning() << "DAQ Error in " << name << " state!";
    emit gui_busy_stop("DAQ Error!");
    decision = 0;
    emit stateFinished();
}

void IC_BridgeBalanceAdjust::daq_rawDataReady(QVector<double> rawData)
{

    int endBuff1 = round((rawData.size())/2.0)- round(0.00015*samplingRate);  // There is a slight delay at the beginning of the triangle wave so that's why the chopped points around the peak are not symmetric (0.00015 vs 0.00015 usec aroud the midpoint of the data)
    //int startBuff1 = 0;
    int startBuff2 = endBuff1 + round(0.00015*samplingRate);// 250 microseconds (500 microseconds was too much, 150 microseconds was about right.  This assumes cap compensation is off and it works best when the two lines are almost in the right position) This is about how long it takes for the artifact to appear and for the capacitive compensation dynamics to happen.
    //int endBuff2 = rawData.size();

//    if(f > 100)
//    {
//        // Saves data to a file.
//        ofstream fout;
//        fout.open("data_new.txt");
//        for(int i=0; i< rawData.size(); i++)
//        {
//            fout << rawData[i] << endl;
//        }
//        fout.close();
//    }

    /* This is what the waveform looks like.  The first half of the buffer is
     * looking at the ramp up, the second half is looking a the ramp down of one period.
     * The vertical jump at the peak should be missing from either buffer so that when
     * the maximums are calculated, they are a good representation of the relative heights
     * of the line endpoints are at.
     *
     *      /|        /|
     *     /  \      /  \
     *    /    \    /    \      need to increase the bridge balance
     *   /      \  /      \
     *  |        \|        \
     *
     *
     *      |\        |\
     *     /  \      /  \
     *    /    \    /    \      need to decrease the bridge balance
     *   /      \  /      \
     *  /        |/        \
     *
     *
     *      /\        /\
     *     /  \      /  \
     *    /    \    /    \      just right!
     *   /      \  /      \
     *  /        \/        \

     * Performing a linear regression on both sides of the peak and finding the height of the top endpoint.
     * The regression shouldn't use too many points because the subthreshold noise might skew the results.
     * It should also average the results from many periods.
    */

    // Number of points used in the regressions.  It doesn't use the whole line because only the part near
    // the transition is important.  If we use the whole line, we're just adding possible noise to the system

    double numPts = 0.0005*samplingRate;

    QVector<double> x;
    QVector<double> y;

    for(int i=0; i<numPts; i++)
    {
        x.push_back(i);
        y.push_back(rawData[endBuff1-numPts+i+1]);
    }

//    if(f >100)
//    {
//        // Saves data to a file.
//        ofstream fout;
//        fout.open("data_reg1.txt");
//        for(int i=0; i< x.size(); i++)
//        {
//            fout << x[i] << "," << y[i] << endl;
//        }
//        fout.close();
//    }

    double m; // slope
    double b; // intercept
    regression(x,y,m,b);

    double top1 = m*x.last()+b;
    x.clear();
    y.clear();

    // The second buffer is a descending line but by reversing the direction of the regression, it flips
    // it around the y axis and makes it the same orientation as the first buffer so we can compare the
    // constants directly.

    for(int i=0; i<numPts; i++)
    {
        x.push_back(i);
        y.push_back(rawData[startBuff2+numPts-i-1]);
    }

    if(f >100)
    {
        // Saves data to a file.
        ofstream fout;
        fout.open("data_reg2.txt");
        for(int i=0; i< x.size(); i++)
        {
            fout << x[i] << "," << y[i] << endl;
        }
        fout.close();
        f = -10000;
    }
    else
    {
        f++;
    }

    regression(x,y,m,b);

    double top2 = m*x.last()+b;

    //qWarning() << top1 << " " << top2;

    top1Ave += top1;
    top2Ave += top2;
    a++;

    if(a >= 20)
    {
        top1Ave = top1Ave/a;
        top2Ave = top2Ave/a;

        // It's accurate to about 2 decimal places (in volts) (is this statement accurate?)
        qWarning() << "Tops: " << top1Ave << " " << top2Ave;
        double dR(0);
        if(fabs(top1Ave-top2Ave) > 0.05) { dR = 2;   }
        else                             { dR = 0.2; }

        if(top1Ave-top2Ave > 0.01)
        {
            bridgeBalance += dR;
            if(enabled){ emit multiclamp_setBridgeBalance(bridgeBalance,true); enabled = 0;}
            //qWarning() << "Bridge balance is too small";
            counterBad++;
        }
        else if(top1Ave-top2Ave < -0.01)
        {
            bridgeBalance -= dR;
            if(enabled){ emit multiclamp_setBridgeBalance(bridgeBalance,true); enabled = 0;}
            //qWarning() << "Bridge balance is too high";
            counterBad++;
        }
        else
        {
            //qWarning() << "Bridge balance is good";
            counterGood++;
        }
        if(counterGood > 20 || counterBad > 150)  // if the bad counter is pretty large, it's probably because of noise in the recording.  No big deal.  It will probably get pretty close.  The access resistance is always a moving target anyway.
        {
            data.LOG_bridgeBalance.push_back(bridgeBalance);
            emit daq_stopTask();
            decision = 1;
            emit stateFinished();
        }

        qWarning() << "Bridge Balance Adjustment Counters: Good: " << counterGood << " Bad: " << counterBad;

        a = 0;
        top1Ave = 0;
        top2Ave = 0;
    }
}

void IC_BridgeBalanceAdjust::multiclamp_setBridgeBalanceComplete()
{
    enabled = 1;
}
