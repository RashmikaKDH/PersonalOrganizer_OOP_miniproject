
#ifndef BUDGETCREATING_H
#define BUDGETCREATING_H

#include <QMainWindow>
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
#include<QSqlTableModel>

namespace Ui {
class Budgetcreating;
}

class Budgetcreating : public QMainWindow
{
    Q_OBJECT

public:
    explicit Budgetcreating(QWidget *parent = nullptr);
    ~Budgetcreating();

    //close database function

    void conclose(){

        sqlitedb.close();
        sqlitedb.removeDatabase(QSqlDatabase::defaultConnection);
    }




private slots:
    void on_pushButton_back_clicked();

    void on_pushButton_addbudget_clicked();
   // void on_pushButton_update_clicked();


    void on_pushButton_tableview_clicked();

private:
    Ui::Budgetcreating *ui;
    QSqlDatabase sqlitedb;

};

#endif // BUDGETCREATING_H
