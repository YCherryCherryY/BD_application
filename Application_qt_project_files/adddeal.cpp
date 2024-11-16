#include "adddeal.h"
#include "ui_adddeal.h"

AddDeal::AddDeal(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::AddDeal)
{
    ui->setupUi(this);
}

AddDeal::~AddDeal()
{
    delete ui;
}

void AddDeal::on_pushButton_clicked()
{
    QSqlQuery * query = new QSqlQuery();
    QMessageBox *msg = new QMessageBox();

    query->prepare("INSERT INTO Сделки(ID_мероприятия, Количество_человек, Дата_сделки) VALUES(:eve,:num,:da)");

    query->bindValue(":eve", ui->lineEdit->text());
    query->bindValue(":num", ui->lineEdit_2->text());
    query->bindValue(":da", ui->lineEdit_3->text());

    if (!query->exec())
    {
        msg->setText("Incorrect input");
        msg->show();
    }
    emit refreshTable();
    delete msg;
}

