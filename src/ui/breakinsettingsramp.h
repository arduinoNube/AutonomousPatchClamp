#ifndef BREAKINSETTINGSRAMP_H
#define BREAKINSETTINGSRAMP_H

#include <QDialog>
#include <QAbstractButton>

namespace Ui {
class BreakInSettingsRamp;
}

class BreakInSettingsRamp : public QWidget
{
    Q_OBJECT
    int ignore;
    QVector< QVector<int> > tableData;
public:
    explicit BreakInSettingsRamp(QWidget *parent = 0);
    ~BreakInSettingsRamp();

    void setTableValue(int row, int col, int val);
    void setTableData(QVector< QVector<int> > data);
    QVector< QVector<int> > getTable();

public slots:
    void on_pushButtonAddRowBreakIn_clicked();
    void on_pushButtonDeleteRowBreakIn_clicked();
    void updateTable();
    void on_tableWidgetBreakIn_cellChanged(int row, int column);
    void keyReleaseEvent(QKeyEvent *e);
    void closeEvent(QCloseEvent *e);

    void on_pushButtonOk_clicked();

    void on_pushButtonCancel_clicked();

    void showEvent(QShowEvent *e);

signals:
    void windowClosed();

private slots:

private:
    Ui::BreakInSettingsRamp *ui;
};

#endif // BREAKINSETTINGSRAMP_H
