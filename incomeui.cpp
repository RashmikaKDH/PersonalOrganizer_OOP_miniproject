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

