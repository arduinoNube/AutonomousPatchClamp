#ifndef IC_MEASURERHEOBASE_H
#define IC_MEASURERHEOBASE_H

#include <QObject>
#include <state.h>
#include <QTimer>
#include <states/statehelperfunctions.h>

class IC_MeasureRheobase : public State, public StateHelperFunctions
{
    Q_OBJECT
    int logicFlag;
    double currentInjectionAmplitude;
    QTimer timer1;
    double samplingRate;
public:
    IC_MeasureRheobase(QObject *parent = 0);
    ~IC_MeasureRheobase();
    void firstRun();

public slots:
    void pauseState(bool toggled);
    void haltState();
    void multiclamp_setHoldingCurrentSafeComplete();
    void daq_initTaskReady();
    void daq_initTaskError();
    void daq_currInjDataReady(QVector<double> injData);
    void setHardwareVals(HardwareSettingsWindow *hw_win);
private slots:
    void timer1_timeout();
};

#endif // IC_MEASURERHEOBASE_H
