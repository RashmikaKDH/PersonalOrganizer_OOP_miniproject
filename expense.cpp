#include "DatabaseManager.h"
#include "expense.h"
#include "ui_expense.h"
#include "organizerui.h"
#include"loginwindow.h"
#include"string"
Expense::Expense(QWidget *parent)
    : UserDataTableDialog(parent)
    , ui(new Ui::Expense)
{
    ui->setupUi(this);



//connecting database for login
    if(!DatabaseManager::instance().getDatabase().isOpen()){
        qDebug() << "Failed to Open Database";
    }
    else{
        qDebug() << "Database Connected..";
    }
    refreshTable();
    //ui->label->setText(QString::number(getMonthlyExpenseSum("Food")));

}

Expense::~Expense()
{
    delete ui;
}

//+++++++++++++++
QTableView* Expense::getTableView() const {
    return ui->tableView;
}

QString Expense::getTableName() const {
    return "expensedata";
}
//++++++++++++++


//Back button
void Expense::on_pushButton_backto_clicked()
{
    this->close();
    organizerui *backtoor = new organizerui;
    backtoor->show();

}


void Expense::on_pushButton_add_clicked()
{
            QString expensecategory = ui->comboBox_category->currentText();

            QDate exdate = ui->dateEdit_expense->date();

            QString description = ui->lineEdit_description->text();

            QString amount = ui->lineEdit_amount->text();
            double amountdouble = amount.toDouble();


//qury to insert data to database

                QSqlQuery qryadd(DatabaseManager::instance().getDatabase());
                //--

                qryadd.prepare("INSERT INTO expensedata(category,description,date,amount,username)""VALUES(:expensecategory,:description,:date,:amount,:username)");
            //binding values

                qryadd.bindValue(":expensecategory",expensecategory);
                qryadd.bindValue(":description",description);
                qryadd.bindValue(":date",exdate);
                qryadd.bindValue(":amount",amountdouble);
                //--
                qryadd.bindValue(":username",globalUsername);



                if(qryadd.exec()){
                    ui->lable->setText("Registration Sucsusfull...");
                    refreshTable();

                }else{
                    ui->lable->setText("Registration Uncsusfull...!!!");
                    refreshTable();



                }











 }



double Expense::getMonthlyExpenseSum(const QString &category) {

    QSqlQuery getMonthlyExpenseSum;
    getMonthlyExpenseSum.prepare("SELECT SUM(amount) AS total FROM expensedata WHERE strftime('%m', date) = strftime('%m', 'now', 'localtime') AND category =:category");
    getMonthlyExpenseSum.bindValue(":category",category);

    if (!getMonthlyExpenseSum.exec()) {
        qWarning() << "Failed to execute query:" << getMonthlyExpenseSum.lastError().text();
        return 0.0; // Return 0.0 if query execution fails
    }

    double total = 0.0;
    if (getMonthlyExpenseSum.next()) {
        total = getMonthlyExpenseSum.value("total").toDouble(); // Fetch the total from the result
    }
    return total;
}
