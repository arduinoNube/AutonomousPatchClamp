#ifndef LOADPIPETTES_H
#define LOADPIPETTES_H

#include <QObject>
#include <state.h>

class LoadPipettes : public State
{
    Q_OBJECT
public:
    LoadPipettes(QObject *parent = 0);
    ~LoadPipettes();
    void firstRun();

public slots:
    void pauseState(bool toggled);
    void haltState();

    void gui_pushbuttonNextLoadPipettesReleased();
};

#endif // LOADPIPETTES_H
