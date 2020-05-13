#include "visualstimuliworker.h"
#include <QNetworkInterface>
#include <QHostAddress>
#include <QThread>

VisualStimuliWorker::VisualStimuliWorker(QObject *parent) : Worker(parent)
{
    socket = new QTcpSocket(this);
    connect(socket, SIGNAL(disconnected()),this,SLOT(on_disconnected()),Qt::QueuedConnection);
    connect(socket,SIGNAL(readyRead()),this,SLOT(on_readyRead()),Qt::QueuedConnection);
    connect(socket,SIGNAL(connected()),this,SLOT(sessionOpened()),Qt::QueuedConnection);
    timer1.setSingleShot(true);
    timer1.setInterval(10000);
    connect(&timer1,SIGNAL(timeout()),this,SLOT(timer1_timeout()),Qt::QueuedConnection);
}

VisualStimuliWorker::~VisualStimuliWorker()
{
    stop();
    socket->close();
    delete socket;
}

void VisualStimuliWorker::setHardwareVals(HardwareSettingsWindow *)
{

}

void VisualStimuliWorker::init(QString address, QString port)
{
    qWarning() << "Initializing visual stimulation connection";
    QHostAddress add;
    if(add.setAddress(address))
    {
        bool ok(0);
        quint16 pt = port.toInt(&ok);
        if(ok)
        {
            socket->close();
            socket->connectToHost(add,pt);
            timer1.start();
        }
        else
        {
            qWarning() << "Bad port number";
            emit initError();
        }
    }
    else
    {
        qWarning() << "Bad IP address";
        emit initError();
    }

}

void VisualStimuliWorker::start(int screenNum)
{

    QString msg("Start1");
    if(screenNum == 2)
    {
        msg = "Start2";
    }
    qWarning() << "Visual stimuli \"" << msg << "\" sent";

    QByteArray data;
    data.append(msg);
    socket->write(data);
    socket->flush();
    emit started();
}

void VisualStimuliWorker::stop()
{
    qWarning() << "Visual stimuli \"Stop\" sent";
    QString msg("Stop");
    QByteArray data;
    data.append(msg);
    socket->write(data);
    socket->flush();
}

void VisualStimuliWorker::pause()
{
    qWarning() << "Visual stimuli \"Pause\" sent";
    QString msg("Pause");
    QByteArray data;
    data.append(msg);
    socket->write(data);
    socket->flush();
    QThread::sleep(2);
    emit paused();
}

void VisualStimuliWorker::continue_()
{
    qWarning() << "Visual stimuli \"Continue\" sent";
    QString msg("Continue");
    QByteArray data;
    data.append(msg);
    qWarning() << "Data sent? " << socket->write(data);
    socket->flush();
}

void VisualStimuliWorker::sessionOpened()
{
    timer1.stop();
    emit initReady();
}

void VisualStimuliWorker::on_readyRead()
{
    qWarning() << "Data received!";
    QString msg;
    while(socket->bytesAvailable() > 0)
    {
        QByteArray ba = socket->readAll();
        msg.append(ba);
    }
    qWarning() << "Response from visual server: " << msg;

    int flag(0);

    if      (!msg.compare("Finished"      ,Qt::CaseInsensitive))      flag = 0;
    else if (!msg.compare("Stopped"         ,Qt::CaseInsensitive))    flag = 1;

    switch(flag)
    {
    case 0:
        emit finished();
        break;
    case 1:
        emit stopped();
        break;
    }
}

void VisualStimuliWorker::on_disconnected()
{
    qWarning() << "vstim disconnected";
}

void VisualStimuliWorker::write(QString)
{

}

void VisualStimuliWorker::timer1_timeout()
{
    qWarning() << "Visual stimulation connection timed out after 10 seconds.";
    emit initError();
}
