#include "incomeui.h"
#include "ui_incomeui.h"
#include"organizerui.h"
#include"loginwindow.h"

Incomeui::Incomeui(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Incomeui)
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

    QSqlTableModel *tablemodel = new QSqlTableModel(this, sqlitedb);
    tablemodel->setTable("incomedata");
    tablemodel->setFilter(QString("username = '%1'").arg(globalUsername));
    tablemodel->select();

    ui->tableView->setModel(tablemodel);
    ui->tableView->show();

}

Incomeui::~Incomeui()
{
    delete ui;
}


//Back button
void Incomeui::on_pushButton_back_clicked()
{
    conclose();
    this->close();
    organizerui *backorga = new organizerui;
    backorga->show();

}


//Add button click
void Incomeui::on_pushButton_Add_clicked()
{


// retreive data from input fields

    if(!sqlitedb.open()){


        QMessageBox::information(this,"Not Connected","Database Not Ci=onnected");
    }
    else{

        //getting input from lineEdites

        QString incomesource = ui->comboBox_income_source->currentText();

        QDate selectdate = ui->QDate->date();
        //QString datestring = selectdate.toString("yyyy-MM-dd");

        QString description = ui->textEdit_Description->toPlainText();

        QString Amount = ui->lineEdit_Amount->text();
        double Amountfloat = Amount.toDouble();



        //define qury to insert data to data base

        QSqlQuery qryadd;

        qryadd.prepare("INSERT INTO incomedata(Income_Source,Description,Amount,Date,username)""VALUES (:incomesource,:description,:Amountfloat,:selectdate,:username)");

        qryadd.bindValue(":incomesource",incomesource);
        qryadd.bindValue(":selectdate",selectdate);
        qryadd.bindValue(":description",description);
        qryadd.bindValue(":Amountfloat",Amountfloat);
        qryadd.bindValue(":username",globalUsername);

        if(qryadd.exec()){
            ui->lable->setText("Registration Sucsusfull...");

            QSqlTableModel *tablemodel = new QSqlTableModel(this, sqlitedb);
            tablemodel->setTable("incomedata");
            tablemodel->setFilter(QString("username = '%1'").arg(globalUsername));
            tablemodel->select();

            ui->tableView->setModel(tablemodel);
            ui->tableView->show();

        }else{
            ui->lable->setText("Registration Uncsusfull...!!!");
        }


    }

}

