
#ifndef BUDGETCREATING_H
#define BUDGETCREATING_H

#include "UserDataTableDialog.h"

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
#include<QSqlError>
#include<QSqlTableModel>

namespace Ui {
class Budgetcreating;
}

class Budgetcreating : public UserDataTableDialog
{
    Q_OBJECT

public:
    explicit Budgetcreating(QWidget *parent = nullptr);
    ~Budgetcreating();

    // This function will get the budget amount for a specific category.
   // static double getBudgetForCategory(const QString &category);
    // This function will get the total expenses for a category in the current month.
    //static double getCurrentExpensesForCategory(const QString &category);
    // --- MODIFY this function declaration to accept a QDate ---
    static double getCurrentExpensesForCategory(const QString &category, const QDate &expenseDate);

    static double getBudgetForCategory(const QString &category);


protected:
    // Implement the pure virtual functions from the base class
    QTableView* getTableView() const override;
    QString getTableName() const override;


private slots:
    void on_pushButton_back_clicked();

    void on_pushButton_addbudget_clicked();
   // void on_pushButton_update_clicked();


    void on_pushButton_tableview_clicked();

private:
    Ui::Budgetcreating *ui;
    //++QSqlDatabase sqlitedb;

};

#endif // BUDGETCREATING_H
