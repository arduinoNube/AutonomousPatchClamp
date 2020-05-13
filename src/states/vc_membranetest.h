#ifndef VC_MEMBRANETEST_H
#define VC_MEMBRANETEST_H

#include <QObject>
#include <state.h>

class VC_MembraneTest : public State
{
    Q_OBJECT
    int strikes;
    int balls;
    int quit;
    double RmAve;
    double RaAve;
    double HcAve;
    double TauAve;
    double CmAve;
    int f;
    QVector<double> rawDataLog;
    int checked;
public:
    VC_MembraneTest(QObject *parent = 0);
    ~VC_MembraneTest();
    void firstRun();

public slots:
    void pauseState(bool toggled);
    void haltState();
    void multiclamp_setHoldingVoltageSafeComplete();
    void daq_initTaskReady();
    void daq_initTaskError();
    void daq_memTestValsReady(QVector<double> vals);
};

#endif // VC_MEMBRANETEST_H
