#ifndef WAIT_H
#define WAIT_H

#include <QObject>
#include <state.h>
#include <QTimer>

class Wait : public State
{
    Q_OBJECT
    QTimer timer1;
private slots:
    void timer1_timeout();
public:
    Wait(QObject *parent = 0);
    ~Wait();
    void firstRun();

public slots:
    void pauseState(bool toggled);
    void haltState();
};

#endif // WAIT_H
