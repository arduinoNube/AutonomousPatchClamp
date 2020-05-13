#ifndef HARDWARESETTINGSWINDOW_H
#define HARDWARESETTINGSWINDOW_H

#include <QWidget>





namespace Ui {
class HardwareSettingsWindow;
}

class HardwareSettingsWindow : public QWidget
{
    Q_OBJECT

public:
    explicit HardwareSettingsWindow(QWidget *parent = 0);
    ~HardwareSettingsWindow();
    QString a_COM;
    QString s_COM;
    QString f_COM;
    QString h_COM;
    int multiclampHeadstageNumber;
    QString multiclampPath;
    QString devName;
    int thorSerial;
    int thorSlowVel;
    int thorFastVel;
    QString visualStimIP;
    QString visualStimPort;
    int daqSampRate;

    // Autopatcher Control Box Variables
    double highP;
    double lowP;
    double highV;
    double lowV;

signals:
    void windowClosed();

private slots:
    void on_pushButtonOk_released();

    void on_pushButtonCancel_released();

private:
    Ui::HardwareSettingsWindow *ui;
    bool registerGUIValues();
};

#endif // HARDWARESETTINGSWINDOW_H
