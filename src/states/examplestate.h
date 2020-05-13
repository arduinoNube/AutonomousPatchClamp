#ifndef EXAMPLESTATE_H
#define EXAMPLESTATE_H

#include <QObject>
#include <state.h>

class ExampleState : public State
{
    Q_OBJECT
public:
    ExampleState(QObject *parent = 0);
    ~ExampleState();
    void firstRun();

public slots:
    void pauseState(bool toggled);
    void haltState();
};

#endif // EXAMPLESTATE_H
