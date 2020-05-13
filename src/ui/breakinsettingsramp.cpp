#include "breakinsettingsramp.h"
#include "ui_breakinsettingsramp.h"
#include <QDebug>
#include <QCloseEvent>


BreakInSettingsRamp::BreakInSettingsRamp(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::BreakInSettingsRamp)
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

BreakInSettingsRamp::~BreakInSettingsRamp()
{
    delete ui;
}

void BreakInSettingsRamp::on_pushButtonAddRowBreakIn_clicked()
{
    int rows = ui->tableWidgetBreakIn->rowCount();
    ui->tableWidgetBreakIn->setRowCount(rows+1);
    tableData.push_back(tableData[tableData.size()-1]);
    tableData[tableData.size()-1][0] = rows+1;

    updateTable();
    qWarning() << "Add row";
}

void BreakInSettingsRamp::on_pushButtonDeleteRowBreakIn_clicked()
{
    int rows = ui->tableWidgetBreakIn->rowCount();
    ui->tableWidgetBreakIn->setRowCount(rows-1);
    tableData.pop_back();
    updateTable();
}

void BreakInSettingsRamp::updateTable()
{
    ignore = 3*(tableData.size());
    for(int i=0; i<tableData.size(); i++)
    {
        setTableValue(i,0,tableData[i][0]);
        setTableValue(i,1,tableData[i][1]);
        setTableValue(i,2,tableData[i][2]);
    }
}

void BreakInSettingsRamp::on_tableWidgetBreakIn_cellChanged(int row, int column)
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

void BreakInSettingsRamp::setTableValue(int row, int col, int val)
{
    QTableWidgetItem *item = new QTableWidgetItem();
    item->setTextAlignment(Qt::AlignCenter);
    item->setText(QString::number(val));
    ui->tableWidgetBreakIn->setItem(row,col,item);
}

void BreakInSettingsRamp::setTableData(QVector< QVector<int> > data)
{
    tableData = data;
    if((tableData.size() !=0) && (ui->tableWidgetBreakIn->rowCount() != tableData.size()))
    {
        ui->tableWidgetBreakIn->setRowCount(tableData.size());
    }
    updateTable();
}

QVector< QVector<int> > BreakInSettingsRamp::getTable()
{
    return tableData;
}

void BreakInSettingsRamp::keyReleaseEvent(QKeyEvent* e)
{
    if(e->key() == Qt::Key_Enter || e->key() == Qt::Key_Return)
    {
        if(ui->pushButtonOk->hasFocus())
        {
            ui->pushButtonOk->animateClick(200);
            this->close();
        }
        if(ui->pushButtonCancel->hasFocus())
        {
            ui->pushButtonCancel->animateClick(200);
            this->close();
        }
    }
    else if(e->key() == Qt::Key_Escape)
    {
        this->close();
    }
}

void BreakInSettingsRamp::closeEvent(QCloseEvent *e)
{
    e->accept();
    this->close();
    emit windowClosed();
}

void BreakInSettingsRamp::on_pushButtonOk_clicked()
{
    qWarning() << "Load GUI values into data";
    this->close();
}

void BreakInSettingsRamp::on_pushButtonCancel_clicked()
{
    qWarning() << "Closing window";
    this->close();
}

void BreakInSettingsRamp::showEvent(QShowEvent *e)
{
    QWidget::showEvent(e);
    ui->pushButtonCancel->setFocus();
}

