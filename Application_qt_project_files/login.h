#ifndef LOGIN_H
#define LOGIN_H

#include <QWidget>
#include <QSqlDatabase>
#include <QMessageBox>

namespace Ui {
class Login;
}

class Login : public QWidget
{
    Q_OBJECT

public:
    explicit Login(QWidget *parent = nullptr);
    ~Login();

    QMessageBox * msg;

private slots:
    void on_pButtonL_clicked();

private:
    Ui::Login *ui;
    QSqlDatabase db;
};

#endif // LOGIN_H
