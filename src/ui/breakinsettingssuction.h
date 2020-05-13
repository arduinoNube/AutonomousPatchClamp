#ifndef BREAKINSETTINGSSUCTION_H
#define BREAKINSETTINGSSUCTION_H

#include <QDialog>
#include <QAbstractButton>

namespace Ui {
class BreakInSettingsSuction;
}

class BreakInSettingsSuction : public QWidget
{
    Q_OBJECT
    int ignore;
    QVector< QVector<int> > tableData;
public:
    explicit BreakInSettingsSuction(QWidget *parent = 0);
    ~BreakInSettingsSuction();

    void setTableValue(int row, int col, int val);
    void setTableData(QVector< QVector<int> > data);    
    QVector< QVector<int> > getTable();

public slots:
    void on_pushButtonAddRowBreakIn_clicked();
    void on_pushButtonDeleteRowBreakIn_clicked();
    void updateTable();
    void on_tableWidgetBreakIn_cellChanged(int row, int column);
    void closeEvent(QCloseEvent *e);

    void on_pushButtonOk_clicked();

    void on_pushButtonCancel_clicked();

    void showEvent(QShowEvent *e);

signals:
    void windowClosed();

private:
    Ui::BreakInSettingsSuction *ui;
};

#endif // BREAKINSETTINGSSUCTION_H
