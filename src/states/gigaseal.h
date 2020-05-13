#ifndef GIGASEAL_H
#define GIGASEAL_H

#include <QObject>
#include <state.h>
#include <QTime>

class Gigaseal : public State
{
    Q_OBJECT
    bool pauseFlag;
    bool readyForRamp;
    typedef void (Gigaseal::*PtrResDataReady)(double res);
    PtrResDataReady ptrResDataReady;
    QTimer timer1;
    QTimer timer2;
    double holdingV;
    QVector<double> firstDerivative;

    int calculateSeconds(QTime time);
    double calcSlope(QVector<QTime> time, QVector<double> pts);
public:
    Gigaseal(QObject *parent = 0);
    ~Gigaseal();
    void firstRun();

public slots:
    void daq_taskRunning(int flag);
    void pauseState(bool toggled);
    void haltState();
    void daq_resDataReady(double res);


    void A(double res);
    void B(double res);
    void C(double res);
    void D(double res);
    void E(double res);
    void F(double res);

private slots:
    void timer1_timeout();
    void timer2_timeout();
};

#endif // GIGASEAL_H
