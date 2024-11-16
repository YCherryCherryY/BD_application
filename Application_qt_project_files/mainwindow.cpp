#include "mainwindow.h"
#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_actionConnect_to_BD_triggered()
{
    logUI = new Login();
    logUI->show();
}


void MainWindow::on_pButtonMCollectData_clicked()
{
    models = new QSqlQueryModel();
    QSqlQuery* query = new QSqlQuery();
    if (ui->rButtonMDeals->isChecked())
    {
        query->prepare("SELECT Сделки.ID_Сделки,Список_мероприятий.Название_мероприятия, "
                       "Сделки.Количество_человек, Сделки.Дата_сделки, "
                       "sum(Список_мероприятий.Стоимость * Сделки.Количество_человек) AS Сумма "
                       "FROM Сделки, Список_мероприятий "
                       "Where Сделки.ID_мероприятия = Список_мероприятий.ID_мероприятия "
                       "Group by Сделки.ID_Сделки, Список_мероприятий.Название_мероприятия, "
                       "Сделки.Количество_человек, Сделки.Дата_сделки");
        //query->exec();
        models->setQuery(query->lastQuery());
        models->setHeaderData(0, Qt::Horizontal, "Номер сделки");
        models->setHeaderData(1, Qt::Horizontal, "Название мероприятия");
        models->setHeaderData(2, Qt::Horizontal, "Количество человек");
        models->setHeaderData(3, Qt::Horizontal, "Дата сделки");
    } else if (ui->rButtonMStoarge->isChecked())
    {
        query->prepare("SELECT Продукты_на_складе.ID_продукта, Продукты_на_складе.Наименование, "
                       "Продукты_на_складе.Количество, Продукты_на_складе.Цена "
                       "FROM Продукты_на_складе ");
        //query->exec();
        models->setQuery(query->lastQuery());
        models->setHeaderData(0, Qt::Horizontal, "Номер продукта");
        models->setHeaderData(1, Qt::Horizontal, "Название продукта");
        models->setHeaderData(2, Qt::Horizontal, "Количество");
        models->setHeaderData(3, Qt::Horizontal, "Цена");
    }

    ui->tableView->setModel(models);
    ui->tableView->resizeColumnsToContents();
    ui->tableView->show();
}


void MainWindow::on_pButtonMUpdateData_clicked()
{
    updUI = new UpdateData();
    if (ui->rButtonMDeals->isChecked())
    {
        updUI->table = 0;
    } else if (ui->rButtonMStoarge->isChecked())
    {
        updUI->table = 1;
    }
    updUI->show();
    //updUI->ui->tableView->show();
}


void MainWindow::on_actionSearch_triggered()
{
    searchUI = new DeleteDeal();
    searchUI->show();
}


void MainWindow::on_actionreport_triggered()
{
    rep = new Report();
    rep->show();
}

