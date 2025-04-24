#include "financialreports.h"
#include "ui_financialreports.h"
#include"organizerui.h"
#include <QSqlQueryModel>
#include <QSqlQuery>
#include <QSqlError>
#include <QDebug>
#include <QDate>

financialreports::financialreports(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::financialreports)
{
    ui->setupUi(this);

    //connecting database for login
    sqlitedb = QSqlDatabase::addDatabase("QSQLITE");

    sqlitedb.setDatabaseName("C:/Users/Rashmika97/Music/PersonalOrganizerOOP/Db/logindatabase.db");

    //checking conectivity of database
    if(!sqlitedb.open()){
        ui->lable->setText("Failed to Open Database");
    }
    else{
        ui->lable->setText("Database Conected..");
    }
}

financialreports::~financialreports()
{
    delete ui;
}

void financialreports::on_genaratepushButton_clicked()
{

    // Get the selected date from QDateEdit
    QDate selectedDate = ui->reportdateEdit->date();
    QString selectedMonth = QString::number(selectedDate.month()).rightJustified(2, '0'); // Ensure 2-digit format
    QString selectedYear = QString::number(selectedDate.year());

    // Prepare the SQL query to get the sum of the amount column from expensedata
    QSqlQuery expenseQuery;
    expenseQuery.prepare(R"(SELECT SUM(amount) AS total FROM expensedata WHERE strftime('%m', date) = :month AND strftime('%Y', date) = :year)");

    // Bind the parameters for expensedata
    expenseQuery.bindValue(":month", selectedMonth);
    expenseQuery.bindValue(":year", selectedYear);

    // Execute the expense query
    double expenseTotal = 0.0;
    if (expenseQuery.exec()) {
        if (expenseQuery.next()) {
            // Retrieve the total from the query result
            expenseTotal = expenseQuery.value("total").toDouble();
        }
    } else {
        qDebug() << "Expense query execution failed:" << expenseQuery.lastError().text();
    }

    // Prepare the SQL query to get the sum of the amount column from incomedata
    QSqlQuery incomeQuery;
    incomeQuery.prepare(R"(SELECT SUM(amount) AS total FROM incomedata WHERE strftime('%m', date) = :month AND strftime('%Y', date) = :year)");

    // Bind the parameters for incomedata
    incomeQuery.bindValue(":month", selectedMonth);
    incomeQuery.bindValue(":year", selectedYear);

    // Execute the income query
    double incomeTotal = 0.0;
    if (incomeQuery.exec()) {
        if (incomeQuery.next()) {
            // Retrieve the total from the query result
            incomeTotal = incomeQuery.value("total").toDouble();
        }
    } else {
        qDebug() << "Income query execution failed:" << incomeQuery.lastError().text();
    }
    double monthlysaving;
    monthlysaving=incomeTotal-expenseTotal;
    // Display the results in the QLabel
    ui->totalexpenselabel->setText("Expense Total: " + QString::number(expenseTotal, 'f', 2));
    ui->totalincomelabel->setText("Income Total: " + QString::number(incomeTotal, 'f', 2));
    ui->savinglabel->setText("Your monthly saving Total: " + QString::number(monthlysaving, 'f', 2));





}


void financialreports::on_pushButton_clicked()
{
    conclose();
    this->close();
    organizerui *backtoor = new organizerui;
    backtoor->show();
}

