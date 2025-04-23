#ifndef FINANCIALREPORTS_H
#define FINANCIALREPORTS_H
#include <QDialog>
#include <QApplication>
#include <QCalendarWidget>
#include <QDate>
#include <QSqlDatabase>
#include <QSqlQuery>

#include<QtSql>
#include<QDebug>
#include<QFileInfo>
#include<QMessageBox>


#include <QDialog>

namespace Ui {
class financialreports;
}

class financialreports : public QDialog
{
    Q_OBJECT

public:
    explicit financialreports(QWidget *parent = nullptr);
    ~financialreports();


    //close database function

    void conclose(){

        sqlitedb.close();
        sqlitedb.removeDatabase(QSqlDatabase::defaultConnection);
    }
private slots:
    void on_genaratepushButton_clicked();

    void on_pushButton_clicked();

private:
    Ui::financialreports *ui;
    QSqlDatabase sqlitedb;
};

#endif // FINANCIALREPORTS_H
