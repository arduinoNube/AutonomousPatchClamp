#ifndef GETPIPETTE_H
#define GETPIPETTE_H

#include <QObject>
#include <state.h>

class GetPipette : public State
{
    Q_OBJECT
    typedef void (GetPipette::*PtrCommandFinished)();
    PtrCommandFinished ptrScaraCmdFinished;
    PtrCommandFinished ptrFillerCmdFinished;
    PtrCommandFinished ptrHeadCmdFinished;

    float tipVolume;
    bool pause;
    bool ready;
    void finish();
public:
    GetPipette(QObject *parent = 0);
    ~GetPipette();
    void firstRun();

public slots:
    void pauseState(bool toggled);
    void haltState();
    void length_measurementReady(float length);

    void scara_commandFinished()
    { if(ptrScaraCmdFinished!=NULL) (this->*ptrScaraCmdFinished)(); }
    void filler_commandFinished()
    { if(ptrFillerCmdFinished!=NULL) (this->*ptrFillerCmdFinished)(); }
    void headstageClamp_commandFinished()
    { if(ptrHeadCmdFinished!=NULL) (this->*ptrHeadCmdFinished)(); }
    void A();
    void B();
    void C();
    void D();
    void E();
    void F();
    void G();
    void H();
    void I();
    void J();
    void K();
    void L();
    void M0();
    void M1();
    void M2();
    void M3();
    void M4();
    void length_imagesAquired();
    void M5();
    void M6();
    void N();
    void O();
    void P();
    void Q();
    void thorLabsMotor_moveComplete();
    void S();
    void T();
    void U();
    void V();
};

#endif // GETPIPETTE_H
