#ifndef VISUALSTIMULIWORKER_H
#define VISUALSTIMULIWORKER_H

#include <QObject>
#include <QTcpSocket>
#include <QTimer>
#include "worker.h"

class VisualStimuliWorker : public Worker
{
    Q_OBJECT
    QTimer timer1;
public:
    explicit VisualStimuliWorker(QObject *parent = 0);
    ~VisualStimuliWorker();

signals:
    void initReady();
    void initError();
    void started();
    void paused();
    void finished();
    void stopped();
public slots:
    void init(QString,QString);
    void start(int screebNum);
    void stop();
    void pause();
    void continue_();
    void setHardwareVals(HardwareSettingsWindow *hw_win);

private slots:
    void sessionOpened();
    void on_readyRead();
    void on_disconnected();
    void write(QString);
    void timer1_timeout();

private:
    QTcpSocket *socket;
};

#endif // VISUALSTIMULIWORKER_H
