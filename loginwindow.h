#ifndef LOGINWINDOW_H
#define LOGINWINDOW_H

#include <QMainWindow>
#include<QtSql>
#include<QDebug>
#include<QFileInfo>
#include<QSqlDatabase>
#include<QMessageBox>
#include"signup.h"
#include"organizerui.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class loginwindow;
}
QT_END_NAMESPACE


// Global variable to store the username
extern QString globalUsername;


class loginwindow : public QMainWindow
{
    Q_OBJECT

public:
    loginwindow(QWidget *parent = nullptr);
    ~loginwindow();

        //close database function

    void conclose(){

        sqlitedb.close();
        sqlitedb.removeDatabase(QSqlDatabase::defaultConnection);
    }

private slots:


    void on_LPushButton_login_clicked();



    void on_LPushButton_signup_clicked();

    //void on_pushButton_clicked();

private:
    Ui::loginwindow *ui;
    QSqlDatabase sqlitedb;
    signup *Signup1;
    organizerui *Organizerui;


};

#endif // LOGINWINDOW_H
