#include "BreakInSettingsZap.h"
#include "ui_breakinsettingszap.h"
#include <QDebug>
#include <QCloseEvent>

BreakInSettingsZap::BreakInSettingsZap(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::BreakInSettingsZap)
{

    ui->setupUi(this);
    ignore = 1;
    QTableWidgetItem *item = new QTableWidgetItem();
    item->setText("Attempt #");
    item->setTextAlignment(Qt::AlignCenter);
    ui->tableWidgetBreakIn->setHorizontalHeaderItem(0,item);
    item = new QTableWidgetItem();
    item->setText("Pressure (mbar)");
    item->setTextAlignment(Qt::AlignCenter);
    ui->tableWidgetBreakIn->setHorizontalHeaderItem(1,item);
    item = new QTableWidgetItem();
    item->setText("Duration (ms)");
    item->setTextAlignment(Qt::AlignCenter);
    ui->tableWidgetBreakIn->setHorizontalHeaderItem(2,item);
    item = new QTableWidgetItem();
    item->setText("Num of Pulses");
    item->setTextAlignment(Qt::AlignCenter);
    ui->tableWidgetBreakIn->setHorizontalHeaderItem(3,item);

    ui->tableWidgetBreakIn->horizontalHeader()->setVisible(true);

}

BreakInSettingsZap::~BreakInSettingsZap()
{
    delete ui;
}

void BreakInSettingsZap::on_pushButtonAddRowBreakIn_clicked()
{
    qWarning() << "Add Row: " << tableData.size();
    int rows = ui->tableWidgetBreakIn->rowCount();
    ui->tableWidgetBreakIn->setRowCount(rows+1);
    tableData.push_back(tableData[tableData.size()-1]);
    tableData[tableData.size()-1][0] = rows+1;

    updateTable();
}

void BreakInSettingsZap::on_pushButtonDeleteRowBreakIn_clicked()
{
    int rows = ui->tableWidgetBreakIn->rowCount();
    ui->tableWidgetBreakIn->setRowCount(rows-1);
    tableData.pop_back();
    updateTable();
}

void BreakInSettingsZap::updateTable()
{
    ignore = 3*(tableData.size());
    for(int i=0; i<tableData.size(); i++)
    {
        setTableValue(i,0,tableData[i][0]);
        setTableValue(i,1,tableData[i][1]);
        setTableValue(i,2,tableData[i][2]);
    }
}

void BreakInSettingsZap::on_tableWidgetBreakIn_cellChanged(int row, int column)
{
    if(column == 0)
    {
        // do nothing
        ignore--;
    }
    else
    {
        if(ignore == 0)
        {
            bool flag(0);
            int num = ui->tableWidgetBreakIn->item(row,column)->text().toInt(&flag);
            if(flag)
            {
                tableData[row][column] = num;
            }
            else
            {
                qWarning() << "Please only use numbers in the table";
            }
            updateTable();
        }
        else if(ignore >0)
        {
            ignore--;
        }
    }

}

void BreakInSettingsZap::setTableValue(int row, int col, int val)
{
    QTableWidgetItem *item = new QTableWidgetItem();
    item->setTextAlignment(Qt::AlignCenter);
    item->setText(QString::number(val));
    ui->tableWidgetBreakIn->setItem(row,col,item);
}

void BreakInSettingsZap::setTableData(QVector< QVector<int> > data)
{
    tableData = data;
    if((tableData.size() !=0) && (ui->tableWidgetBreakIn->rowCount() != tableData.size()))
    {
        ui->tableWidgetBreakIn->setRowCount(tableData.size());
    }
    updateTable();
}

QVector< QVector<int> > BreakInSettingsZap::getTable()
{
    return tableData;
}


void BreakInSettingsZap::closeEvent(QCloseEvent *e)
{
    e->accept();
    this->close();
    emit windowClosed();
}

void BreakInSettingsZap::on_pushButtonOk_clicked()
{
    qWarning() << "Load GUI values into data";
    this->close();
}

void BreakInSettingsZap::on_pushButtonCancel_clicked()
{
    qWarning() << "Closing window";
    this->close();
}

void BreakInSettingsZap::showEvent(QShowEvent *e)
{
    QWidget::showEvent(e);
    ui->pushButtonCancel->setFocus();
}
