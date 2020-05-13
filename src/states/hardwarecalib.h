#ifndef HARDWARECALIB_H
#define HARDWARECALIB_H

#include <QObject>
#include <state.h>
#include <QTimer>

class HardwareCalib : public State
{
    Q_OBJECT
    int thor_serialNum;
    int thor_slowVel;
    int thor_fastVel;
    QTimer timer1;
    bool scaraCalib;
    bool thorCalib;
    typedef void (HardwareCalib::*PtrCommandFinished)();
    PtrCommandFinished ptrScaraCmdFinished;
    int pipetteNumberCounter;
public:
    HardwareCalib(QObject *parent = 0);
    ~HardwareCalib();
    void setHardwareVals(HardwareSettingsWindow *hw_win);
    void firstRun();

public slots:
    void pauseState(bool toggled);
    void haltState();
    void gui_calibrateSCARA();
    void scara_commandFinished()
    { if(ptrScaraCmdFinished!=NULL) (this->*ptrScaraCmdFinished)(); }
    void thorLabsMotor_calibrateFinished();
private slots:
    void checkCalibrated();
    void A();
    void B();
    void C();
    void finish();
};

#endif // HARDWARECALIB_H
