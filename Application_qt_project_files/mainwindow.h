#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "login.h"
#include "ui_login.h"
#include "QSqlQueryModel"
#include "QSqlQuery"
#include "updatedata.h"
#include "ui_updatedata.h"
#include "deletedeal.h"
#include "ui_deletedeal.h"
#include "report.h"
#include "ui_report.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    Login * logUI;
    UpdateData * updUI;
    DeleteDeal * searchUI;
    Report * rep;

    bool isdb = false;
private slots:
    void on_actionConnect_to_BD_triggered();

    void on_pButtonMCollectData_clicked();

    void on_pButtonMUpdateData_clicked();

    void on_actionSearch_triggered();

    void on_actionreport_triggered();

private:
    Ui::MainWindow *ui;
    QSqlQueryModel *models;
};
#endif // MAINWINDOW_H
