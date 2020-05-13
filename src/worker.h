#ifndef WORKER_H
#define WORKER_H

#include <QObject>
#include "ui/hardwaresettingswindow.h"

class Worker : public QObject
{
    Q_OBJECT
public:
    explicit Worker(QObject *parent = 0);
    ~Worker();

signals:

public slots:
    virtual void setHardwareVals(HardwareSettingsWindow *) = 0;
};

#endif // WORKER_H
