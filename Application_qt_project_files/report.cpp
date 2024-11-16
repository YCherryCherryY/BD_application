#include "report.h"
#include "ui_report.h"

Report::Report(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Report)
{
    ui->setupUi(this);
}

Report::~Report()
{
    delete ui;
}

void Report::on_pushButton_clicked()
{
    QFile * file = new QFile();
    file->setFileName(ui->lineEdit->text());
    file->open(QIODevice::WriteOnly);

    QTextStream in(file);

    in<< "<html><head></head><body><center>"+QString("Отчёт по сделкам");
    in<<"<table border = 2><tr>";
    in<<"<td>"+QString("Номер сделки")+"</td>";
    in<<"<td>"+QString("Название мероприятия")+"</td>";
    in<<"<td>"+QString("Количество человек")+"</td>";
    in<<"<td>"+QString("Дата сделки")+"</td>";
    in<<"<td>"+QString("Сумма")+"</td></tr>";

    QSqlQuery* query = new QSqlQuery();
    query->prepare("SELECT Сделки.ID_Сделки,Список_мероприятий.Название_мероприятия, "
                   "Сделки.Количество_человек, Сделки.Дата_сделки, "
                   "sum(Список_мероприятий.Стоимость * Сделки.Количество_человек) AS Сумма "
                   "FROM Сделки, Список_мероприятий "
                   "Where Сделки.ID_мероприятия = Список_мероприятий.ID_мероприятия "
                   "Group by Сделки.ID_Сделки, Список_мероприятий.Название_мероприятия, "
                   "Сделки.Количество_человек, Сделки.Дата_сделки");
    query->exec();

    while (query->next()) {
        in<< "<tr><td>";
        in<<query->value(0).toString();
        in<< "</td><td>";
        in<<query->value(1).toString();
        in<< "</td><td>";
        in<<query->value(2).toString();
        in<< "</td><td>";
        in<<query->value(3).toString();
        in<< "</td><td>";
        in<<query->value(4).toString();
        in<< "</td></tr>";
    }

    in<<"</table></center></body></html>";
    file->close();

    QAxObject *word = new QAxObject("Word.Application",this);
    word->setProperty("DisplayAlerts",false);
    word->setProperty("Visible",true);
    QAxObject* doc = word->querySubObject("Documents");
    doc->dynamicCall("Open(QVariant)", ui->lineEdit->text());
}


void Report::on_toolButton_clicked()
{
    ui->lineEdit->setText(QFileDialog::getOpenFileName(0, "Выберите файл", "./", "*.html"));
}

