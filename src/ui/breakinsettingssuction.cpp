#include "breakinsettingssuction.h"
#include "ui_breakinsettingssuction.h"
#include <QDebug>
#include <QCloseEvent>

BreakInSettingsSuction::BreakInSettingsSuction(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::BreakInSettingsSuction)
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

BreakInSettingsSuction::~BreakInSettingsSuction()
{
    delete ui;
}

void BreakInSettingsSuction::on_pushButtonAddRowBreakIn_clicked()
{
    int rows = ui->tableWidgetBreakIn->rowCount();
    ui->tableWidgetBreakIn->setRowCount(rows+1);
    tableData.push_back(tableData[tableData.size()-1]);
    tableData[tableData.size()-1][0] = rows+1;

    updateTable();
}

void BreakInSettingsSuction::on_pushButtonDeleteRowBreakIn_clicked()
{
    int rows = ui->tableWidgetBreakIn->rowCount();
    ui->tableWidgetBreakIn->setRowCount(rows-1);
    tableData.pop_back();
    updateTable();
}

void BreakInSettingsSuction::updateTable()
{
    ignore = 4*(tableData.size());
    for(int i=0; i<tableData.size(); i++)
    {
        setTableValue(i,0,tableData[i][0]);
        setTableValue(i,1,tableData[i][1]);
        setTableValue(i,2,tableData[i][2]);
        setTableValue(i,3,tableData[i][3]);
    }
}

void BreakInSettingsSuction::on_tableWidgetBreakIn_cellChanged(int row, int column)
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

void BreakInSettingsSuction::setTableValue(int row, int col, int val)
{
    QTableWidgetItem *item = new QTableWidgetItem();
    item->setTextAlignment(Qt::AlignCenter);
    item->setText(QString::number(val));
    ui->tableWidgetBreakIn->setItem(row,col,item);
}

void BreakInSettingsSuction::setTableData(QVector< QVector<int> > data)
{
    tableData = data;
    if((tableData.size() !=0) && (ui->tableWidgetBreakIn->rowCount() != tableData.size()))
    {
        ui->tableWidgetBreakIn->setRowCount(tableData.size());
    }
    updateTable();
}

QVector< QVector<int> > BreakInSettingsSuction::getTable()
{
    return tableData;
}


void BreakInSettingsSuction::closeEvent(QCloseEvent *e)
{
    e->accept();
    this->close();
    emit windowClosed();
}

void BreakInSettingsSuction::on_pushButtonOk_clicked()
{
    qWarning() << "Load GUI values into data";
    this->close();
}

void BreakInSettingsSuction::on_pushButtonCancel_clicked()
{
    qWarning() << "Closing window Suction";
    this->close();
}

void BreakInSettingsSuction::showEvent(QShowEvent *e)
{
    QWidget::showEvent(e);
    ui->pushButtonCancel->setFocus();
}
