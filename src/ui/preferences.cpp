#include "preferences.h"
#include "ui_preferences.h"
#include <QDebug>

Preferences::Preferences(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Preferences)
{
    ui->setupUi(this);
    connect(&dlg,SIGNAL(fileSelected(QString)),this,SLOT(dataDirChanged(QString)),Qt::QueuedConnection);
    dataFormat = 2;
    dataFormatTmp = dataFormat;
}

Preferences::~Preferences()
{
    delete ui;
}

void Preferences::on_pushButtonBrowseForDataDir_released()
{
    if(dataDir.exists()) dlg.setDirectory(dataDir.path());
    dlg.setFileMode(QFileDialog::Directory);
    dlg.show();
}

void Preferences::dataDirChanged(QString dir)
{
    ui->lineEditDataDirectory->setText(dir);
    dataDirTmp = QDir::fromNativeSeparators(dir);
}

QDir Preferences::getDataDir()
{
    return dataDir;
}

void Preferences::setDataDir(QDir dd)
{
    ui->lineEditDataDirectory->setText(dd.path());
    dataDir = dd;
    dataDirTmp = dd;
}

int Preferences::getFileFormat()
{
    return dataFormat;
}

void Preferences::setFileFormat(int flag)
{
    switch(flag)
    {
    case 1:
        ui->checkBox->setChecked(true);
        ui->checkBox_2->setChecked(false);
        dataFormat = 1;
        break;
    case 2:
        ui->checkBox->setChecked(false);
        ui->checkBox_2->setChecked(true);
        dataFormat = 2;
        break;
    case 3:
        ui->checkBox->setChecked(true);
        ui->checkBox_2->setChecked(true);
        dataFormat = 3;
        break;
    }
    dataFormatTmp = dataFormat;
}

void Preferences::on_checkBox_2_toggled(bool)  // bool is whether the box was checked or not
{
    if(ui->checkBox_2->isChecked() && ui->checkBox->isChecked())
    {
        dataFormatTmp = 3;     // Both Checked
    }
    else if(ui->checkBox_2->isChecked())
    {
        dataFormatTmp = 2;     // Matlab checked
    }
}

void Preferences::on_checkBox_toggled(bool) // bool is whether the box was checked or not
{
    if(ui->checkBox_2->isChecked() && ui->checkBox->isChecked())
    {
        dataFormatTmp = 3;     // Both checked
    }
    else if(ui->checkBox->isChecked())
    {
        dataFormatTmp = 1;     // CSV checked
    }
}

void Preferences::on_buttonBox_accepted()
{
    dataFormat = dataFormatTmp;
    dataDir = dataDirTmp;
    this->close();
    emit windowClosed();
}

void Preferences::on_buttonBox_rejected()
{
    dataFormatTmp = dataFormat;
    dataDirTmp = dataDir;

    ui->lineEditDataDirectory->setText(dataDir.path());
    if(dataFormat == 1)
    {
        ui->checkBox->setChecked(true);
        ui->checkBox_2->setChecked(false);
    }else if(dataFormat == 2)
    {
        ui->checkBox->setChecked(false);
        ui->checkBox_2->setChecked(true);
    }
    else if(dataFormat == 3)
    {
        ui->checkBox->setChecked(true);
        ui->checkBox_2->setChecked(true);
    }
    this->close();
}
