#ifndef TRIALINIT_H
#define TRIALINIT_H

#include <QObject>
#include <state.h>

class TrialInit : public State
{
    Q_OBJECT
    QTimer timer1;
public:
    TrialInit(QObject *parent = 0);
    ~TrialInit();
    void firstRun();

private slots:
    void ready();

public slots:
    void pauseState(bool toggled);
    void haltState();
    void thorLabsMotor_moveComplete();
};

#endif // TRIALINIT_H
