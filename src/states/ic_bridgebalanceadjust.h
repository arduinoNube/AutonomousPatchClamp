#ifndef IC_BRIDGEBALANCEADJUST_H
#define IC_BRIDGEBALANCEADJUST_H

#include <state.h>

class IC_BridgeBalanceAdjust : public State
{
    Q_OBJECT
    int f;
    int a;
    bool enabled;
    double samplingRate;
    double top1Ave;
    double top2Ave;
    double bridgeBalance;
    int counterGood;
    int counterBad;
    void regression(QVector<double> x, QVector<double> y, double &m, double &b);
public:
    IC_BridgeBalanceAdjust(QObject * parent=0);
    ~IC_BridgeBalanceAdjust();

public slots:
    void haltState();
    void pauseState(bool);
    void setHardwareVals(HardwareSettingsWindow *hw_win);
    void firstRun();
    void multiclamp_holdingCurrentCheckedComplete();
    void daq_initTaskReady();
    void daq_initError();
    void daq_rawDataReady(QVector<double> data);
    void multiclamp_setBridgeBalanceComplete();
    void multiclamp_getBridgeBalanceComplete(double valMOhms);
};

#endif // IC_BRIDGEBALANCEADJUST_H
