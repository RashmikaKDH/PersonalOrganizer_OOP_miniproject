#include "budgetcreating.h"
#include "DatabaseManager.h"
#include "expense.h"
#include "ui_expense.h"
#include "organizerui.h"
#include"loginwindow.h"
#include"string"
#include "AppUtils.h"
Expense::Expense(QWidget *parent)
    : UserDataTableDialog(parent)
    , ui(new Ui::Expense)
{
    ui->setupUi(this);
    ui->dateEdit_expense->setDate(QDate::currentDate());



//connecting database for login
    if(!DatabaseManager::instance().getDatabase().isOpen()){
        qDebug() << "Failed to Open Database";
    }
    else{
        qDebug() << "Database Connected..";
    }
    refreshTable();
    checkAllCategoryBudgets(); // Check budgets when the window is first opened.
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


            // --- THE BUDGET CHECKING LOGIC , BEFORE a new expense is saved ---
            double budget = Budgetcreating::getBudgetForCategory(expensecategory);
            // A budget of -1 means no budget was set for this category, so we can skip the check.
            if (budget >= 0) {
                double currentExpenses = Budgetcreating::getCurrentExpensesForCategory(expensecategory, exdate);
                if ((currentExpenses + amountdouble) > budget) {
                    // The new expense will exceed the budget. Warn the user.
                     /*AppUtils::showMessage(this, "Budget Warning",
                                          QString("Adding this expense of %1 will exceed your monthly budget of %2 for %3.\n\n"
                                                  "Current Spending: %4")
                                              .arg(amountdouble).arg(budget).arg(expensecategory).arg(currentExpenses));*/
                    // If the check is true, show the detailed warning message to the user.
                   /* QMessageBox::StandardButton reply;
                    reply = QMessageBox::question(this, "Budget Warning",
                                                  QString("Adding this expense of %1 will exceed your monthly budget of %2 for %3.\n\n"
                                                          "Current Spending: %4\n\n"
                                                          "Do you want to add this expense anyway?")
                                                      .arg(amountdouble).arg(budget).arg(expensecategory).arg(currentExpenses),
                                                  QMessageBox::Yes|QMessageBox::No);


                    if (reply == QMessageBox::No) {
                        return; // Stop if the user clicks "No".
                    }*/
                    QString question = QString("Adding this expense of %1 will exceed your monthly budget of %2 for %3.\n\n"
                                               "Current Spending: %4\n\n"
                                               "Do you want to add this expense anyway?")
                                           .arg(amountdouble).arg(budget).arg(expensecategory).arg(currentExpenses);

                    // 2. Call our new utility function to ask the question.
                    //    The '!' at the beginning means "if the user did NOT click Yes".
                    if (!AppUtils::askQuestion(this, "Budget Warning", question)) {
                        AppUtils::showToastred("New Expense Adding Stop by user...!!!", this);
                        return; // Stop and do not save the expense.
                    }
                }
            }
            // --- END of new budget checking logic ---



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
                    //ui->lable->setText("Registration Sucsusfull...");
                    AppUtils::showToast("New Expense Adding Sucsusfull...", this);

                    refreshTable();

                }else{
                    //ui->lable->setText("Registration Uncsusfull...!!!");
                    AppUtils::showToastred("New Expense Adding Failed...!!!", this);

                    refreshTable();



                }











 }



double Expense::getMonthlyExpenseSum(const QString &category) {

    QSqlQuery getMonthlyExpenseSum;
    getMonthlyExpenseSum.prepare("SELECT SUM(amount) AS total FROM expensedata WHERE strftime('%m', date) = strftime('%m', 'now', 'localtime') AND category =:category");
    getMonthlyExpenseSum.bindValue(":category",category);

    if (!getMonthlyExpenseSum.exec()) {
        //qWarning() << "Failed to execute query:" << getMonthlyExpenseSum.lastError().text();
        qDebug() << "Failed to execute query:" << getMonthlyExpenseSum.lastError().text();
        return 0.0; // Return 0.0 if query execution fails
    }

    double total = 0.0;
    if (getMonthlyExpenseSum.next()) {
        total = getMonthlyExpenseSum.value("total").toDouble(); // Fetch the total from the result
    }
    return total;
}

// --- NEW FUNCTION TO THE BOTTOM of expense.cpp ---
void Expense::checkAllCategoryBudgets()
{   QDate currentDate = QDate::currentDate();
    // Loop through every category in the dropdown list.
    for (int i = 0; i < ui->comboBox_category->count(); ++i) {
        QString category = ui->comboBox_category->itemText(i);
        double budget = Budgetcreating::getBudgetForCategory(category);

        // If a budget is set for this category (i.e., not -1)
        if (budget >= 0) {
            double currentExpenses = Budgetcreating::getCurrentExpensesForCategory(category, currentDate);
            if (currentExpenses > budget) {
                // This category is already over budget. Show a warning.
                AppUtils::showMessage(this, "Budget Alert",
                                      QString("You are currently over budget for %1.\n\n"
                                              "Budget: %2\n"
                                              "Spent: %3")
                                          .arg(category).arg(budget).arg(currentExpenses));
            }
        }
    }
}

void Expense::on_deleteOldRecordsButton_clicked()
{
    // 1. Ask the user to confirm this dangerous action.
    bool confirmed = AppUtils::askQuestion(this, "Confirm Deletion",
                                           "Are you sure you want to permanently delete all expense records from previous months?\n\nThis action cannot be undone.");

    // 2. If the user clicks "No", stop right here.
    if (!confirmed) {
        return;
    }

    // 3. Prepare the SQL query to delete records for the current user
    //    where the date is less than the first day of the current month.
    QSqlQuery query(DatabaseManager::instance().getDatabase());
    query.prepare("DELETE FROM expensedata WHERE username = :username AND date < date('now', 'start of month')");
    query.bindValue(":username", globalUsername);

    // 4. Execute the query and show a success or failure message.
    if (query.exec()) {
        AppUtils::showMessage(this, "Success", "Old expense records have been deleted.");
    } else {
        qWarning() << "Failed to delete old expense records:" << query.lastError().text();
        AppUtils::showMessage(this, "Database Error", "Could not delete old records.");
    }

    // 5. Refresh the table view to show that the old records are gone.
    refreshTable();
}
