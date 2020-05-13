#ifndef AUTOPATCHERSETTINGSWINDOW_H
#define AUTOPATCHERSETTINGSWINDOW_H

#include <QDialog>
#include <ui/autopatchersettings.h>

namespace Ui {
class AutopatcherSettingsWindow;
}

class AutopatcherSettingsWindow : public QWidget
{
    Q_OBJECT

    QVector<QString> errs;
public:
    explicit AutopatcherSettingsWindow(QWidget *parent = 0);
    ~AutopatcherSettingsWindow();

    bool registerGuiValues();
    void setVals(AutopatcherSettings vals);

    AutopatcherSettings ap_data;
    void closeEvent(QCloseEvent *e);
    AutopatcherSettings getVals();

private:
    Ui::AutopatcherSettingsWindow *ui;
    void keyReleaseEvent(QKeyEvent* e);

signals:
    void windowClosed();
private slots:
    void on_pushButtonOk_clicked();
    void on_pushButtonCancel_clicked();
    void showEvent(QShowEvent *e);
//    bool eventFilter(QObject *target,QEvent *e);
    void on_lineEditNumSampsToWaitReleasePress_textChanged(const QString &arg1);
};

#endif // AUTOPATCHERSETTINGSWINDOW_H
