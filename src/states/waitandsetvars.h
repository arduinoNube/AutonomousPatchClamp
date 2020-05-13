#ifndef WAITANDSETVARS_H
#define WAITANDSETVARS_H

#include <QObject>
#include <state.h>
#include <QTimer>

class WaitAndSetVars : public State
{
    Q_OBJECT
    QTimer timer1;
private slots:
    void timer1_timeout();
public:
    WaitAndSetVars(QObject *parent = 0);
    ~WaitAndSetVars();
    void firstRun();

public slots:
    void pauseState(bool toggled);
    void haltState();
};

#endif // WAITANDSETVARS_H

