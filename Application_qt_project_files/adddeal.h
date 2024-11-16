#ifndef ADDDEAL_H
#define ADDDEAL_H

#include <QWidget>
#include <QMessageBox>
#include <QSqlQuery>

namespace Ui {
class AddDeal;
}

class AddDeal : public QWidget
{
    Q_OBJECT

public:
    explicit AddDeal(QWidget *parent = nullptr);
    ~AddDeal();

private slots:
    void on_pushButton_clicked();
signals:
    void refreshTable();

private:
    Ui::AddDeal *ui;
};

#endif // ADDDEAL_H
