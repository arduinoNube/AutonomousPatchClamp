#ifndef IC_CURRENTSTEPS_H
#define IC_CURRENTSTEPS_H

#include <QObject>
#include <state.h>
#include <QTimer>

class IC_CurrentSteps : public State
{
    Q_OBJECT
    double currentInjectionAmplitude;
    QTimer timer1;
    int numSteps;
    int loopCount;
    double minCurrent;
    double maxCurrent;
    int nRepeats;

public:
    IC_CurrentSteps(QObject *parent = 0);
    ~IC_CurrentSteps();
    void firstRun();

public slots:
    void pauseState(bool toggled);
    void haltState();
    void multiclamp_setHoldingCurrentSafeComplete();
    void daq_initTaskReady();
    void daq_initTaskError();
    void daq_currInjDataReady(QVector<double> injData);
private slots:
    void timer1_timeout();
};

#endif // IC_CURRENTSTEPS_H
