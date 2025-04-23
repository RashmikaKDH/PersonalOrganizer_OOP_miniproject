#ifndef EXPENSE_H
#define EXPENSE_H

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
class Expense;
}

class Expense : public QDialog
{
    Q_OBJECT

public:
    explicit Expense(QWidget *parent = nullptr);
    ~Expense();
    double getMonthlyExpenseSum(const QString &category);


//close database function

    void conclose(){

    sqlitedb.close();
    sqlitedb.removeDatabase(QSqlDatabase::defaultConnection);
    }

private slots:
    void on_pushButton_backto_clicked();

    void on_pushButton_add_clicked();

private:
    Ui::Expense *ui;
    QSqlDatabase sqlitedb;

};

#endif // EXPENSE_H
