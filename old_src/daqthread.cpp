#include "daqthread.h"

DAQThread::DAQThread(QObject *parent) :
    QThread(parent)
{

}

void DAQThread::run()
{
    exec();
}
