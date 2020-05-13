#ifndef IC_BACFIRING_H
#define IC_BACFIRING_H

#include <QObject>
#include <state.h>
#include <QTimer>

class IC_BACFiring : public State
{
    Q_OBJECT
    QTimer timer1;
    int loopCount;
    int nRepeats;
    double bacFrequencyMax; // Hz
    double bacFrequencyMin; // Hz
    double bacFrequencyStepSize; // Hz
    double freq; // Hz
public:
    IC_BACFiring(QObject *parent = 0);
    ~IC_BACFiring();
    void firstRun();

public slots:
    void pauseState(bool toggled);
    void haltState();
    void multiclamp_setHoldingCurrentSafeComplete();
    void daq_initTaskReady();
    void daq_initTaskError();
    void daq_bacCurrInjDataReady(QVector<double>);
private slots:
    void timer1_timeout();
};

#endif // IC_BACFIRING_H

