#ifndef VC_PIPETTECAPACITANCENEUTRALIZATION_H
#define VC_PIPETTECAPACITANCENEUTRALIZATION_H

#include <QObject>
#include <state.h>

class VC_PipetteCapacitanceNeutralization : public State
{
    Q_OBJECT
    double RmAve;
    double RaAve;
    double HcAve;
    double TauAve;
    double CmAve;
    double CapCompAve;
    int f;
    int quit;
    double capCompVal;
public:
    VC_PipetteCapacitanceNeutralization(QObject *parent = 0);
    ~VC_PipetteCapacitanceNeutralization();
public slots:
    void pauseState(bool);
    void haltState();
    void firstRun();
    void multiclamp_setHoldingVoltageSafeComplete();
    void daq_initTaskReady();
    void daq_initTaskError();
    void daq_memTestValsReady(QVector<double> vals);
    void multiclamp_autoFastCapacitanceComplete();
    void multiclamp_pipetteCapacitanceCompensationValue(double val);
};

#endif // VC_PIPETTECAPACITANCENEUTRALIZATION_H
