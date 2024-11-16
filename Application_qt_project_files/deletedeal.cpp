#include "deletedeal.h"
#include "ui_deletedeal.h"

DeleteDeal::DeleteDeal(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::DeleteDeal)
{
    ui->setupUi(this);
}

DeleteDeal::~DeleteDeal()
{
    delete ui;
}

void DeleteDeal::on_pushButton_clicked()
{
    QSqlQuery* query = new QSqlQuery();
    QMessageBox * msg = new QMessageBox();


    if (ui->comboBox->currentIndex() == 0)
    {
        query->prepare("SELECT Сделки.ID_Сделки, Сделки.ID_мероприятия, "
                       "Список_мероприятий.Название_мероприятия, Сделки.Количество_человек, "
                       "Сделки.Дата_сделки FROM Сделки, Список_мероприятий Where Сделки.ID_сделки"
                       " = " + ui->lineEdit->text()+ "AND Сделки.ID_мероприятия = "
                       "Список_мероприятий.ID_мероприятия");
    } else if (ui->comboBox->currentIndex() == 1)
    {
        query->prepare("SELECT Сделки.ID_Сделки, Сделки.ID_мероприятия, "
                       "Список_мероприятий.Название_мероприятия, Сделки.Количество_человек, "
                       "Сделки.Дата_сделки FROM Сделки, Список_мероприятий Where "
                       "Список_мероприятий.ID_мероприятия = " + ui->lineEdit->text()+
                       "AND Сделки.ID_мероприятия = Список_мероприятий.ID_мероприятия");
    } else if (ui->comboBox->currentIndex() == 2)
    {
        query->prepare("SELECT Сделки.ID_Сделки, Сделки.ID_мероприятия, "
                       "Список_мероприятий.Название_мероприятия, Сделки.Количество_человек, "
                       "Сделки.Дата_сделки FROM Сделки, Список_мероприятий Where "
                       "Сделки.Количество_человек = " + ui->lineEdit->text()+
                       "AND Сделки.ID_мероприятия = Список_мероприятий.ID_мероприятия");
    } else if (ui->comboBox->currentIndex() == 3)
    {
        query->prepare("SELECT Сделки.ID_Сделки, Сделки.ID_мероприятия, "
                       "Список_мероприятий.Название_мероприятия, Сделки.Количество_человек, "
                       "Сделки.Дата_сделки FROM Сделки, Список_мероприятий Where "
                       "Сделки.Дата_сделки = " + ui->lineEdit->text()+
                       "AND Сделки.ID_мероприятия = Список_мероприятий.ID_мероприятия");
    }
    //query->prepare("SELECT Сделки.ID_Сделки, Сделки.ID_мероприятия, Список_мероприятий.Название_мероприятия, Сделки.Количество_человек, Сделки.Дата_сделки FROM Сделки, Список_мероприятий Where Список_мероприятий.ID_мероприятия = 1 AND Сделки.ID_мероприятия = Список_мероприятий.ID_мероприятия");
    model = new QSqlQueryModel();

    if(!query->exec())
    {
        msg->setText("Error");
        msg->show();
    }
    model->setQuery(query->lastQuery());
    model->setHeaderData(0, Qt::Horizontal, "Номер сделки");
    model->setHeaderData(1, Qt::Horizontal, "Номер мероприятия");
    model->setHeaderData(2, Qt::Horizontal, "Название мероприятия");
    model->setHeaderData(3, Qt::Horizontal, "Количество человек");
    model->setHeaderData(4, Qt::Horizontal, "Дата сделки");
    ui->tableView->setModel(model);
    ui->tableView->resizeColumnsToContents();
    ui->tableView->show();
}
