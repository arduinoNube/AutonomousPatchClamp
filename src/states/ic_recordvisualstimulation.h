#ifndef IC_RECORDVISUALSTIMULATION_H
#define IC_RECORDVISUALSTIMULATION_H

#include <QObject>
#include <state.h>
#include <QTimer>

class IC_RecordVisualStimulation : public State
{
    Q_OBJECT
    QTimer timer1;

    void finish();

public:
    IC_RecordVisualStimulation(QObject *parent = 0);
    ~IC_RecordVisualStimulation();
    void firstRun();

public slots:
    void pauseState(bool toggled);
    void haltState();
    void visual_paused();
    void visual_finished();
private slots:
    void timer1_timeout();
};

#endif // IC_RECORDVISUALSTIMULATION_H
