#ifndef QMYCUSTOMEVENT_H
#define QMYCUSTOMEVENT_H


class QMyCustomEvent : public QCustomEvent
{
    Q_OBJECT
public:
    QMyCustomEvent();
    double resistance;
signals:
    
public slots:
    
};

#endif // QMYCUSTOMEVENT_H
