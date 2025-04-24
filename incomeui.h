#ifndef INCOMEUI_H
#define INCOMEUI_H

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

namespace Ui {
class Incomeui;
}

class Incomeui : public QDialog
{
    Q_OBJECT

public:
    explicit Incomeui(QWidget *parent = nullptr);
    ~Incomeui();

    //close database function

    void conclose(){

        sqlitedb.close();
        sqlitedb.removeDatabase(QSqlDatabase::defaultConnection);
    }

private slots:
    void on_pushButton_back_clicked();

    //void on_pushButton_clicked();

    void on_pushButton_Add_clicked();

private:
    Ui::Incomeui *ui;
    //QLabel *lable;
  // Qtext
    QSqlDatabase sqlitedb;

};

#endif // INCOMEUI_H
