#ifndef BREAKINSETTINGSZAP_H
#define BREAKINSETTINGSZAP_H

#include <QAbstractButton>

namespace Ui {
class BreakInSettingsZap;
}

class BreakInSettingsZap : public QWidget
{
    Q_OBJECT
    int ignore;
    QVector< QVector<int> > tableData;
public:
    explicit BreakInSettingsZap(QWidget *parent = 0);
    ~BreakInSettingsZap();

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
    Ui::BreakInSettingsZap *ui;
};

#endif // BREAKINSETTINGSZAP_H
