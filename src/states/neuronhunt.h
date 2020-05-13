#ifndef NEURONHUNT_H
#define NEURONHUNT_H

#include <QObject>
#include <state.h>

class NeuronHunt : public State
{
    Q_OBJECT
    bool detectionFlag;
    int thisHuntStartIndex;
public:
    NeuronHunt(QObject *parent = 0);
    ~NeuronHunt();
    void firstRun();
public slots:
    void pauseState(bool toggled);
    void haltState();
    void daq_resDataReady(double res);
    void thorLabsMotor_moveComplete();
    void thorLabsMotor_currentMotorPosition(float pos);
    void daq_taskRunning(int flag);
};

#endif // NEURONHUNT_H
