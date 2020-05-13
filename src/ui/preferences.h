#ifndef PREFERENCES_H
#define PREFERENCES_H

#include <QDialog>
#include <QFileDialog>

namespace Ui {
class Preferences;
}

class Preferences : public QDialog
{
    Q_OBJECT    
    QFileDialog dlg;

    QDir dataDir;
    QDir dataDirTmp;
    int dataFormat;
    int dataFormatTmp;

public:
    explicit Preferences(QWidget *parent = 0);
    ~Preferences();
    QDir getDataDir();
    void setDataDir(QDir dd);
    int  getFileFormat();
    void setFileFormat(int);
signals:
    void windowClosed();

public slots:
private slots:
    void on_pushButtonBrowseForDataDir_released();

    void on_checkBox_2_toggled(bool checked);

    void on_checkBox_toggled(bool checked);

    void dataDirChanged(QString dir);
    void on_buttonBox_accepted();

    void on_buttonBox_rejected();

private:
    Ui::Preferences *ui;
};

#endif // PREFERENCES_H
