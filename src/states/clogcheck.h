#ifndef CLOGCHECK_H
#define CLOGCHECK_H

#include <QObject>
#include <state.h>
#include <QTimer>

class ClogCheck : public State
{
    Q_OBJECT
    typedef void (ClogCheck::*PtrTimeout)();
    PtrTimeout ptrTimer1Timeout;
    typedef void (ClogCheck::*PtrResDataReady)(double res);
    PtrResDataReady ptrResDataReady;

    QTimer timer1;

private slots:
    void timer1_timeout();
    void daq_resDataReady(double res)
    { if(ptrResDataReady != NULL) (this->*ptrResDataReady)(res); }


    void A(double res);
    void B();
    void C(double res);
public:
    ClogCheck(QObject *parent = 0);
    ~ClogCheck();
    void firstRun();

public slots:
    void pauseState(bool toggled);
    void haltState();
    void thorLabsMotor_moveComplete();
    void daq_taskRunning(int flag);
};

#endif // CLOGCHECK_H
