#include "updatedata.h"
#include "ui_updatedata.h"

UpdateData::UpdateData(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::UpdateData)
{
    ui->setupUi(this);
}

UpdateData::~UpdateData()
{
    delete ui;
}

void UpdateData::on_pButtonUAdd_clicked()
{
    addD = new AddDeal();
    connect(addD, SIGNAL(refreshTable()), this, SLOT(obrRefTable()));
    addD->show();
}

void UpdateData::obrRefTable()
{
    on_pushButton_clicked();
}


void UpdateData::on_pushButton_clicked()
{
    models = new QSqlTableModel();
    models->setTable("Сделки");
    models->select();
    models->setHeaderData(0, Qt::Horizontal, "Номер сделки");
    models->setHeaderData(1, Qt::Horizontal, "Номер мероприятия");
    models->setHeaderData(2, Qt::Horizontal, "Количество человек");
    models->setHeaderData(3, Qt::Horizontal, "Дата сделки");
    ui->tableView->setModel(models);
    ui->tableView->resizeColumnsToContents();
    ui->tableView->show();
}



void UpdateData::on_tableView_clicked(const QModelIndex &index)
{
    int PK = ui->tableView->model()->data(ui->tableView->model()->index(index.row(), 0)).toInt();
    ui->lineEdit->setText(QString::number(PK));
}


void UpdateData::on_pButtonUDelete_clicked()
{
    QSqlQuery* query = new QSqlQuery();
    query->prepare("DELETE FROM Сделки Where ID_сделки=?");
    query->bindValue(0, ui->lineEdit->text());
    query->exec();
    on_pushButton_clicked();
}

