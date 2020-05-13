#ifndef RETRACT_H
#define RETRACT_H

#include <QObject>
#include <state.h>

class Retract : public State
{
    Q_OBJECT
public:
    Retract(QObject *parent = 0);
    ~Retract();
    void firstRun();
public slots:
    void pauseState(bool toggled);
    void haltState();
    void thorLabsMotor_moveComplete();
};

#endif // RETRACT_H
