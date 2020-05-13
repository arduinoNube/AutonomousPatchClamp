#ifndef BREAKIN_H
#define BREAKIN_H

#include <QObject>
#include <state.h>

class BreakIn : public State
{
    Q_OBJECT
    typedef void (BreakIn::*PtrResDataReady)(double);
    PtrResDataReady ptrResDataReady;
    int average;
    int sampNum;
    int attempt;
    int zapAttempt;
    QVector<double> zapTimes;
    QTimer timer1;

    int alg0Counter;

private slots:
    void timer1_timeout();

public:
    BreakIn(QObject *parent = 0);
    ~BreakIn();

    void firstRun();
    void finish();

public slots:
    void daq_resDataReady(double res)
    { if(ptrResDataReady != NULL) (this->*ptrResDataReady)(res);}
    void pauseState(bool toggled);
    void haltState();
    void zap();
    void daq_initTaskReady();
    void daq_initTaskError();
    void daq_resDataReadyAlg0(double res);
    void daq_resDataReadyAlg1(double res);
    void daq_resDataReadyAlg2(double res);
    void daq_resDataReadyAlg3(double res);
    void multiclamp_setHoldingVoltageSafeComplete();
    void autopatcher_breakInRampFinished();
    void multiclamp_pipetteCapacitanceCompensationValue(double val);
};

#endif // BREAKIN_H
