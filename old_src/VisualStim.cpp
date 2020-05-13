#include "VisualStim.h"
#include <QDebug>
#include <QThread>

VisualStim::VisualStim(QObject *parent) :
    QObject(parent)
{
}

void VisualStim::sendStartCommand()
{
    QString program("plink.exe");
    QStringList commands;
    commands << "-ssh" << "192.168.1.1" << "-l" << "test" << "-pw" << "phsycopy00&" << "-m" << "command_file.txt";
    ssh1.start(program,commands);
    qWarning() << "Command Sent";
}

void VisualStim::sendStopCommand()
{
    QString program("plink.exe");
    QStringList commands;
    commands << "-ssh" << "192.168.1.1" << "-l" << "test" << "-pw" << "phsycopy00&" << "-m" << "command_file2.txt";
    ssh2.start(program,commands);
    qWarning() << "Command Sent";
    ssh1.terminate();
    ssh2.terminate();
    QThread::sleep(10);
}

void VisualStim::startVisualStimuli()
{
    sendStartCommand();
    emit visualStimuliStarted();
}

void VisualStim::stopVisualStimuli()
{
    sendStopCommand();
    emit visualStimuliStopped();
}
