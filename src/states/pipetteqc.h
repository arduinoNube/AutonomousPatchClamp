#ifndef PIPETTEQC_H
#define PIPETTEQC_H

#include <QObject>
#include <state.h>
#include <QTimer>

class PipetteQC : public State
{
    Q_OBJECT
    int headstageNum;
    int numAve;
    int numResVals;
    QVector<double> resVals;
    QTimer timer1;

    bool checkResVals();

    typedef void (PipetteQC::*PtrMulticlampFinished)();
    PtrMulticlampFinished ptrMulticlampFinished;
public:
    PipetteQC(QObject *parent = 0);
    ~PipetteQC();
    void firstRun();
    int  getHeadstageNum() { return headstageNum;}
    void setHeadstageNum(int n) { headstageNum = n;}
    void setNumAve(int val) {numAve = val;}

public slots:
    void pauseState(bool toggled);
    void haltState();
    void daq_initTaskReady();
    void daq_initTaskError();
    void multiclamp_autoPipetteOffsetComplete()
    { if(ptrMulticlampFinished!=NULL) (this->*ptrMulticlampFinished)(); }
    void A();
    void daq_resDataReady(double res);
    void B();
    void thorLabsMotor_moveComplete();
private slots:
    void finish();
};

#endif // PIPETTEQC_H
