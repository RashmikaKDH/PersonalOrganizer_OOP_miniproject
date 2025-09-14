#include "DatabaseManager.h"
#include "incomeui.h"
#include "ui_incomeui.h"
#include"organizerui.h"
#include"loginwindow.h"
#include "AppUtils.h"

Incomeui::Incomeui(QWidget *parent)
    : UserDataTableDialog(parent)
    , ui(new Ui::Incomeui)
{
    ui->setupUi(this);
    ui->QDate->setDate(QDate::currentDate());

    if(!DatabaseManager::instance().getDatabase().isOpen()){
        qDebug() << "Failed to Open Database";
    }
    else{
        qDebug() << "Database Connected..";
    }
    refreshTable();

}

Incomeui::~Incomeui()
{
    delete ui;
}
//++++++++

QTableView* Incomeui::getTableView() const {
    return ui->tableView;
}

QString Incomeui::getTableName() const {
    return "incomedata";
}

//+++++++

//Back button
void Incomeui::on_pushButton_back_clicked()
{
    this->close();
    organizerui *backorga = new organizerui;
    backorga->show();

}


//Add button click
void Incomeui::on_pushButton_Add_clicked()
{



        //getting input from lineEdites

        QString incomesource = ui->comboBox_income_source->currentText();

        QDate selectdate = ui->QDate->date();
        //QString datestring = selectdate.toString("yyyy-MM-dd");

        QString description = ui->textEdit_Description->toPlainText();

        QString Amount = ui->lineEdit_Amount->text();
        double Amountfloat = Amount.toDouble();



        //define qury to insert data to data base

        QSqlQuery qryadd(DatabaseManager::instance().getDatabase());

        qryadd.prepare("INSERT INTO incomedata(Income_Source,Description,Amount,Date,username)""VALUES (:incomesource,:description,:Amountfloat,:selectdate,:username)");

        qryadd.bindValue(":incomesource",incomesource);
        qryadd.bindValue(":selectdate",selectdate);
        qryadd.bindValue(":description",description);
        qryadd.bindValue(":Amountfloat",Amountfloat);
        qryadd.bindValue(":username",globalUsername);

        if(qryadd.exec()){
            //ui->lable->setText("Registration Sucsusfull...");
            //QMessageBox::information(this, "Success", "Registration Susfull.");
            AppUtils::showToast("New Income Adding Successful.", this);


           refreshTable();

        }else{
           // ui->lable->setText("Registration Uncsusfull...!!!");
            //QMessageBox::information(this, "Unsuccess", "Registration Uncsusfull..");
            AppUtils::showToastred("New Income Adding Failed..", this);


         }


   // }

}

void Incomeui::on_deleteOldRecordsButton_clicked()
{
    // 1. Ask the user to confirm this dangerous action.
    bool confirmed = AppUtils::askQuestion(this, "Confirm Deletion",
                                           "Are you sure you want to permanently delete all income records from previous months?\n\nThis action cannot be undone.");

    // 2. If the user clicks "No", stop right here.
    if (!confirmed) {
        return;
    }

    // 3. Prepare the SQL query to delete records for the current user
    //    where the date is less than the first day of the current month.
    QSqlQuery query(DatabaseManager::instance().getDatabase());
    query.prepare("DELETE FROM incomedata WHERE username = :username AND date < date('now', 'start of month')");
    query.bindValue(":username", globalUsername);

    // 4. Execute the query and show a success or failure message.
    if (query.exec()) {
        AppUtils::showMessage(this, "Success", "Old income records have been deleted.");
    } else {
        qWarning() << "Failed to delete old income records:" << query.lastError().text();
        AppUtils::showMessage(this, "Database Error", "Could not delete old records.");
    }

    // 5. Refresh the table view to show that the old records are gone.
    refreshTable();
}
