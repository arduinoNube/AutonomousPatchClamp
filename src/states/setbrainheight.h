#ifndef SETBRAINHEIGHT_H
#define SETBRAINHEIGHT_H

#include <QObject>
#include <state.h>

class ThorWorker;

class SetBrainHeight : public State
{
    Q_OBJECT
public:
    SetBrainHeight(QObject *parent = 0);
    ~SetBrainHeight();
    void firstRun();
public slots:
    void pauseState(bool toggled);
    void haltState();
    void gui_downAdjustBtn(int dist);
    void gui_upAdjustBtn(int dist);
    void thorLabsMotor_moveComplete();
    void gui_pushbuttonGO3Released(ThorWorker *t);
};

#endif // SETBRAINHEIGHT_H
