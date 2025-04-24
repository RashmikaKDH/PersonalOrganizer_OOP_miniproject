#ifndef SIGNUP_H
#define SIGNUP_H

#include <QDialog>
#include <QMainWindow>
#include<QtSql>
#include<QDebug>
#include<QFileInfo>
#include<QSqlDatabase>
#include<QMessageBox>


namespace Ui {
class signup;
}

class signup : public QDialog
{
    Q_OBJECT

public:
    explicit signup(QWidget *parent = nullptr);
    ~signup();

    //close database function
    void conclose(){

        sqlitedb.close();
        sqlitedb.removeDatabase(QSqlDatabase::defaultConnection);
    }

private slots:
    void on_pushButton_register_clicked();

    void on_pushButton_back_clicked();

private:
    Ui::signup *ui;
    QSqlDatabase sqlitedb;
  //loginwindow *Loginwindow1;
};

#endif // SIGNUP_H
