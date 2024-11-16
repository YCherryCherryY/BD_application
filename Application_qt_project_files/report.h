#ifndef REPORT_H
#define REPORT_H

#include <QWidget>
#include <QAxObject>
#include <QSqlQuery>
#include <QFileDialog>
#include <QFile>
#include <QTextStream>

namespace Ui {
class Report;
}

class Report : public QWidget
{
    Q_OBJECT

public:
    explicit Report(QWidget *parent = nullptr);
    ~Report();

private slots:
    void on_pushButton_clicked();

    void on_toolButton_clicked();

private:
    Ui::Report *ui;
};

#endif // REPORT_H
