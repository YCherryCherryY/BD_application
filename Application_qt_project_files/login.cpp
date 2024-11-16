#include "login.h"
#include "ui_login.h"

Login::Login(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Login)
{
    ui->setupUi(this);
    ui->lineEdLServAdr->setText("ASUS");
    ui->lineEdLPassw->setEchoMode(QLineEdit::Password);
    msg = new QMessageBox();
}

Login::~Login()
{
    delete ui;
}

void Login::on_pButtonL_clicked()
{
    db = QSqlDatabase::addDatabase("QODBC");
    db.setDatabaseName("DRIVER={SQL Server};SERVER="+ui->lineEdLServAdr->text()+";DATABASE=sweet_base;");
    db.setUserName(ui->lineEdLLogin->text());
    db.setPassword(ui->lineEdLPassw->text());
    if (db.open())
    {
        msg->setText("Connected");

    }
    else
    {
        msg->setText("Connection failed");
    }
    msg->show();
}

