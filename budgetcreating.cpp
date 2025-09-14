#include "DatabaseManager.h"
#include "budgetcreating.h"
#include "ui_budgetcreating.h"
#include "organizerui.h"
#include"loginwindow.h"
#include "AppUtils.h"

Budgetcreating::Budgetcreating(QWidget *parent)
    : UserDataTableDialog(parent)
    , ui(new Ui::Budgetcreating)
{
    ui->setupUi(this);

//connecting database for login
    if(!DatabaseManager::instance().getDatabase().isOpen()){
        qDebug() << "Failed to Open Database";
    }
    else{
        qDebug() << "Database Connected..";
    }
//----------------table view for budget
        refreshTable();


}

    Budgetcreating::~Budgetcreating()
{
    delete ui;
}
//++++++++

QTableView* Budgetcreating::getTableView() const {
    return ui->tableView;
}

QString Budgetcreating::getTableName() const {
    return "budget";
}

//+++++++


//back button------------------------------------------------
void Budgetcreating::on_pushButton_back_clicked()
{
    this->close();
    organizerui *backtoor = new organizerui;
    backtoor->show();
}

//Add budget button------------------------------------------------
void Budgetcreating::on_pushButton_addbudget_clicked()
{
    if(!DatabaseManager::instance().getDatabase().isOpen()){

        //QMessageBox::information(this,"Not Connected","Database Not Ci=onnected");
        AppUtils::showToastred("Database is Not connected...", this);



    }
    else{

//getting infro from lineedit and combobox

        QString budgetcategory = ui->comboBox_category->currentText();

        QString budgetamount = ui->lineEdit_budgetamount->text();
        double budgetamountdouble = budgetamount.toDouble();


        //create qury  insert data


        QSqlQuery qry(DatabaseManager::instance().getDatabase());

        if(qry.exec("select * from budget where username='"+globalUsername+"'and category='"+budgetcategory+"'"))
        {
            int countt=0;
            while (qry.next())
            {
                countt++;
            }
            if(countt==1){
                qDebug() << "Budget category found for user, preparing update.";


                //------------------------ write to update qury
                QSqlQuery qryup(DatabaseManager::instance().getDatabase());
                qryup.prepare("UPDATE budget SET budgetamount = :budgetamount WHERE category = :category AND username = :username");
                qryup.bindValue(":budgetamount", budgetamountdouble);
                qryup.bindValue(":category", budgetcategory);
                qryup.bindValue(":username", globalUsername);
               // QSqlQuery qryup(DatabaseManager::instance().getDatabase());

                //qryup.prepare("UPDATE budget SET budgetamount='"+budgetamountdouble+"'  WHERE category='"+budgetcategory+"' and username='"+globalUsername+"'");
                qryup.exec();

                if(qryup.exec()){

                    //QMessageBox::information(this, "Success", "Budget update successful.");
                    AppUtils::showToast("Budget update successful..", this);

                }else{
                    //QMessageBox::information(this, "failed", "Budget update failed.");
                    AppUtils::showToastred("Budget update failed..", this);
                }



            }
            if(countt>1)
                QMessageBox::warning(this, "Warning", "Duplicated category");

            if(countt<1){
                //QMessageBox::warning(this, "Warning", "No value to seleectl...");
                //AppUtils::showToastred("This catogary is haven't budget yet", this);





                //--------------write insert qury
               QSqlQuery qryaddbud(DatabaseManager::instance().getDatabase());

                qryaddbud.prepare("INSERT INTO budget(category,budgetamount,username)""VALUES(:budgetcategory,:budgetamountdouble,:username)");


            //binding values

                qryaddbud.bindValue(":budgetamountdouble",budgetamount);
                qryaddbud.bindValue(":budgetcategory",budgetcategory);
                qryaddbud.bindValue(":username",globalUsername);


                if(qryaddbud.exec()){
                    //ui->lable->setText("Registration Sucsusfull...");
                   // QMessageBox::information(this, "Success", "Budget update successful.");
                    AppUtils::showToast("Budget Add successful.", this);



                }else{
                    //ui->lable->setText("Registration failed..." );
                    //QMessageBox::information(this, "Failed", "Budget update Unsuccessful.");
                    AppUtils::showToastred("Budget Add Failed.", this);

               }
            }
        }

        //=============== refresh table view-----------
        refreshTable();


    }



}

void Budgetcreating::on_pushButton_tableview_clicked()
{
    //----------------table view for budget
    refreshTable();

}

// --- ADD THE FOLLOWING CODE TO THE BOTTOM OF budgetcreating.cpp ---

/**
 * @brief Retrieves the budget amount set for a specific category for the current user.
 * @param category The category to check (e.g., "Food").
 * @return The budget amount, or -1.0 if no budget is set for that category.
 */
double Budgetcreating::getBudgetForCategory(const QString &category)
{
    QSqlQuery query(DatabaseManager::instance().getDatabase());
    query.prepare("SELECT budgetamount FROM budget WHERE username = :username AND category = :category");
    query.bindValue(":username", globalUsername);
    query.bindValue(":category", category);

    // --- REVISED LOGIC START ---
    if (!query.exec()) {
        // First, check if the query itself failed to execute.
        qWarning() << "Failed to query for budget:" << query.lastError().text();
        return -1.0; // Return -1 to indicate an error or no budget.
    }

    if (query.next()) {
        // If query.next() is true, a row was found, so a budget exists.
        return query.value(0).toDouble();
    } else {
        // If query.next() is false, no row was found. This means no budget has been set
        // for this category by the user. This is not an error.
        qDebug() << "No budget set for category:" << category;
        return -1.0;
    }
    // --- REVISED LOGIC END ---
}

/**
 * @brief Calculates the total expenses for a given category within the current calendar month.
 * @param category The category to sum up (e.g., "Food").
 * @return The total amount of expenses for the month.
 */
double Budgetcreating::getCurrentExpensesForCategory(const QString &category, const QDate &expenseDate)
{
    QSqlQuery query(DatabaseManager::instance().getDatabase());
    query.prepare("SELECT SUM(amount) FROM expensedata "
                  "WHERE username = :username AND category = :category "
                  "AND strftime('%Y-%m', date) = :expenseMonth");
   // QString currentMonth = QDate::currentDate().toString("yyyy-MM");
    query.bindValue(":username", globalUsername);
    query.bindValue(":category", category);
    // --- BIND the new value for the month ---
    query.bindValue(":expenseMonth", expenseDate.toString("yyyy-MM"));

    // --- NEW: Detailed Debugging ---
    qDebug() << "---------------------------------";
    qDebug() << "Checking expenses for Category:" << category;
    qDebug() << "Filtering for User:" << globalUsername;
    qDebug() << "Filtering for Month:" << expenseDate.toString("yyyy-MM");
    qDebug() << "---------------------------------";


    if (query.exec()) {
        if (query.next()) {
            QVariant result = query.value(0);
            qDebug() << "Query successful. Result for SUM(amount) is:" << result.toString();
            return result.toDouble(); // Correctly returns 0.0 if result is NULL
        } else {
            // This case is unlikely for a SUM query but good to have.
            qDebug() << "Query executed but returned no rows.";
        }
    } else {
        qWarning() << "Expense sum query FAILED:" << query.lastError().text();
    }

    return 0.0;
}

