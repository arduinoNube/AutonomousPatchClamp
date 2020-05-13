#ifndef DAQTHREAD_H
#define DAQTHREAD_H

#include <QThread>

class DAQThread : public QThread
{
    Q_OBJECT
public:
    explicit DAQThread(QObject *parent = 0);
    void run();
signals:
    
public slots:
    
};

#endif // DAQTHREAD_H
