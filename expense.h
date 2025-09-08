#ifndef EXPENSE_H
#define EXPENSE_H
#include "UserDataTableDialog.h"

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

class Expense : public UserDataTableDialog
{
    Q_OBJECT

public:
    explicit Expense(QWidget *parent = nullptr);
    ~Expense();
    double getMonthlyExpenseSum(const QString &category);

protected:
    // Implement the pure virtual functions from the base class
    QTableView* getTableView() const override;
    QString getTableName() const override;

private slots:
    void on_pushButton_backto_clicked();

    void on_pushButton_add_clicked();

private:
    Ui::Expense *ui;

};

#endif // EXPENSE_H
