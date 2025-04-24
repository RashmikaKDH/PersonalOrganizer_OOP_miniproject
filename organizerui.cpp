#include "organizerui.h"
#include "ui_organizerui.h"
#include"incomeui.h"
#include"loginwindow.h"
#include"expense.h"
#include"budgetcreating.h"
#include "financialreports.h"
#include"financialreports.h"
#include"shedulemaneger.h"

#include <QApplication>
#include <QLabel>
#include <QVBoxLayout>
#include <QWidget>
#include <string>
#include<QMessageBox>
organizerui::organizerui(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::organizerui)
{
    ui->setupUi(this);
    ui->lable->setText("Welcome  "+globalUsername);
}
/*QString x="seed";
QMessageBox::information(this,"user:"+x+);*/
 //ui->QLabel->setText("value is:"+QString::fromStdString(std::to_string(x)));

organizerui::~organizerui()
{
    delete ui;
}

// logout Button
void organizerui::on_pushButton_logout_clicked()
{
    this->close();
    loginwindow *backtologin = new loginwindow;
    backtologin->show();
}





//connecting income ui to button
void organizerui::on_pushButton_income_clicked()
{
    this->close();
    Incomeui *inui =new Incomeui;
    inui->show();
}

//connecting expenseui to button
void organizerui::on_pushButton_expense_clicked()
{
    this->close();
    Expense *exui =new Expense;
    exui->show();
}


void organizerui::on_pushButton_createbudget_clicked()
{
    this->close();
    Budgetcreating *budui =new Budgetcreating;
    budui->show();
}


void organizerui::on_pushButton_financialreports_clicked()
{
    this->close();
    financialreports *fiui =new financialreports;
    fiui->show();
}


void organizerui::on_pushButton_academic_clicked()
{
    this->close();
    shedulemaneger *sheman =new shedulemaneger;
    sheman->show();
}

