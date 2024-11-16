#ifndef UPDATEDATA_H
#define UPDATEDATA_H

#include <QWidget>
#include "adddeal.h"
#include "ui_adddeal.h"
#include "QSqlTableModel"

namespace Ui {
class UpdateData;
}

class UpdateData : public QWidget
{
    Q_OBJECT

public:
    explicit UpdateData(QWidget *parent = nullptr);
    ~UpdateData();
    int table = 0;

private slots:
    void on_pButtonUAdd_clicked();

    void obrRefTable();

    void on_pushButton_clicked();

    void on_tableView_clicked(const QModelIndex &index);

    void on_pButtonUDelete_clicked();

private:
    Ui::UpdateData *ui;
    AddDeal *addD;
    QSqlTableModel *models;
};

#endif // UPDATEDATA_H
