#ifndef RETRACTSLOWLY_H
#define RETRACTSLOWLY_H

#include <QObject>
#include <state.h>

class RetractSlowly : public State
{
    Q_OBJECT

    typedef void (RetractSlowly::*PtrThorMoveComplete)();
    PtrThorMoveComplete ptrThorMoveComplete;
    double dist;

    void A();
    void B();
public:
    RetractSlowly(QObject *parent = 0);
    ~RetractSlowly();
    void firstRun();
public slots:
    void pauseState(bool toggled);
    void haltState();
    void daq_resDataReady(double val);
    void thorLabsMotor_moveComplete()
    { if(ptrThorMoveComplete!=NULL) (this->*ptrThorMoveComplete)(); }

};

#endif // RETRACTSLOWLY_H
