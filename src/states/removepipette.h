#ifndef REMOVEPIPETTE_H
#define REMOVEPIPETTE_H

#include <QObject>
#include <state.h>

class RemovePipette : public State
{
    Q_OBJECT
    typedef void (RemovePipette::*PtrCommandFinished)();
    PtrCommandFinished ptrHeadCmdFinished;
    PtrCommandFinished ptrScaraCmdFinished;
    PtrCommandFinished ptrThorMoveComplete;
    bool pause;
    bool ready;
    void finish();
public:
    RemovePipette(QObject *parent = 0);
    ~RemovePipette();
    void firstRun();
public slots:
    void pauseState(bool toggled);
    void haltState();

    // Snytime slots
    void gui_actionLoadMicrofil();

    // Procedural Slots
    void scara_commandFinished()
    { if(ptrScaraCmdFinished!=NULL) (this->*ptrScaraCmdFinished)(); }
    void headstageClamp_commandFinished()
    { if(ptrHeadCmdFinished!=NULL) (this->*ptrHeadCmdFinished)(); }
    void thorLabsMotor_moveComplete()
    { if(ptrThorMoveComplete!=NULL) (this->*ptrThorMoveComplete)(); }
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
    void M();
    void O();
    void P();
    void Q();
    void R();
    void S();
    void T();
};

#endif // REMOVEPIPETTE_H
