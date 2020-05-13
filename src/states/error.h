#ifndef ERROR_H
#define ERROR_H

#include <QObject>
#include <state.h>

class Error : public State
{
    Q_OBJECT
public:
    Error(QObject *parent = 0);
    ~Error();
    void firstRun();

public slots:
    void pauseState(bool toggled);
    void haltState();
};

#endif // ERROR_H
