#ifndef DELETEDEAL_H
#define DELETEDEAL_H

#include <QWidget>
#include "QSqlQuery"
#include "QSqlQueryModel"
#include <QMessageBox>

namespace Ui {
class DeleteDeal;
}

class DeleteDeal : public QWidget
{
    Q_OBJECT

public:
    explicit DeleteDeal(QWidget *parent = nullptr);
    ~DeleteDeal();

private slots:
    void on_pushButton_clicked();

private:
    Ui::DeleteDeal *ui;
    QSqlQueryModel * model;
};

#endif // DELETEDEAL_H
