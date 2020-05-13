#ifndef VISUALSTIM_H
#define VISUALSTIM_H

#include <QObject>
#include <QProcess>

// THIS CLASS RELIES ON THE "PLINK.EXE" EXECUTALBE TO HANDLE THE SSH PROTOCOL
// IT ALSO REQUIRES commands.txt and commands2.txt TO CONTAIN THE COMMANDS TO
// ON THE REMOTE COMPUTER TO SHOW THE VISUAL STIMULI.

class VisualStim : public QObject
{
    Q_OBJECT

    QProcess ssh1,ssh2;
    void sendStopCommand();
    void sendStartCommand();

public:
    explicit VisualStim(QObject *parent = 0);

signals:
    void visualStimuliStarted();
    void visualStimuliStopped();

public slots:
    void startVisualStimuli();
    void stopVisualStimuli();
};

#endif // VISUALSTIM_H
