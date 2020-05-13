#ifndef IC_QUICKAPDETECT_H
#define IC_QUICKAPDETECT_H

#include <QObject>
#include <state.h>
#include <QTimer>
#include <states/statehelperfunctions.h>

class IC_QuickAPDetect : public State, public StateHelperFunctions
{
    Q_OBJECT
    QTimer timer1;
    double currentInjectionAmplitude;
    bool enabled;
    double samplingRate;
private slots:
    void timer1_timeout();

public:
    IC_QuickAPDetect(QObject *parent=0);
    ~IC_QuickAPDetect();
    void firstRun();

public slots:
    void pauseState(bool toggled);
    void haltState();
    void multiclamp_setHoldingCurrentSafeComplete();
    void daq_initTaskReady();
    void daq_rawDataReady(QVector<double>){/* Ignoring the raw data from the DAQ*/}
    void daq_currInjDataReady(QVector<double> injData);
    void daq_initTaskError();
    void setHardwareVals(HardwareSettingsWindow *hw_win);
};

#endif // IC_QUICKAPDETECT_H
