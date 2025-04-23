#ifndef ORGANIZERUI_H
#define ORGANIZERUI_H

#include <QDialog>
#include<QtSql>
#include<QDebug>
#include<QFileInfo>
#include<QSqlDatabase>
#include<QMessageBox>

namespace Ui {
class organizerui;
}

class organizerui : public QDialog
{
    Q_OBJECT

public:
    explicit organizerui(QWidget *parent = nullptr);
    ~organizerui();

private slots:
    void on_pushButton_income_clicked();

    void on_pushButton_logout_clicked();

    void on_pushButton_expense_clicked();

    void on_pushButton_createbudget_clicked();


    void on_pushButton_financialreports_clicked();

    void on_pushButton_academic_clicked();

private:
    Ui::organizerui *ui;
};

#endif // ORGANIZERUI_H
