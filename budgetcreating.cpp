#include "budgetcreating.h"
#include "ui_budgetcreating.h"
#include "organizerui.h"
#include"loginwindow.h"

Budgetcreating::Budgetcreating(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Budgetcreating)
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
        ui->lable->setText("Database Conected.."+globalUsername);
//----------------table view for budget
        QSqlTableModel *tablemodel = new QSqlTableModel(this, sqlitedb);

        tablemodel->setTable("budget");
        tablemodel->setFilter(QString("username = '%1'").arg(globalUsername));
        tablemodel->select();

        ui->tableView->setModel(tablemodel);
        ui->tableView->show();

    }
}

    Budgetcreating::~Budgetcreating()
{
    delete ui;
}

//back button------------------------------------------------
void Budgetcreating::on_pushButton_back_clicked()
{
    conclose();
    this->close();
    organizerui *backtoor = new organizerui;
    backtoor->show();
}

//Add budget button------------------------------------------------
void Budgetcreating::on_pushButton_addbudget_clicked()
{
    if(!sqlitedb.open()){

        QMessageBox::information(this,"Not Connected","Database Not Ci=onnected");


    }
    else{

//getting infro from lineedit and combobox

        QString budgetcategory = ui->comboBox_category->currentText();

        QString budgetamount = ui->lineEdit_budgetamount->text();
        double budgetamountdouble = budgetamount.toDouble();


        //create qury  insert data


        QSqlQuery qry;

        if(qry.exec("select * from budget where username='"+globalUsername+"'and category='"+budgetcategory+"'"))
        {
            int countt=0;
            while (qry.next())
            {
                countt++;
            }
            if(countt==1){
                ui->lable->setText("select Sucsusfull...");


                //------------------------ write to update qury
                QSqlQuery qryup;
                qryup.prepare("UPDATE budget SET budgetamount = :budgetamount WHERE category = :category AND username = :username");
                qryup.bindValue(":budgetamount", budgetamountdouble);
                qryup.bindValue(":category", budgetcategory);
                qryup.bindValue(":username", globalUsername);
               // QSqlQuery qryup;

                //qryup.prepare("UPDATE budget SET budgetamount='"+budgetamountdouble+"'  WHERE category='"+budgetcategory+"' and username='"+globalUsername+"'");
                qryup.exec();

                if(qryup.exec()){

                    ui->lable->setText("update Sucsusfull...");

                }else{
                    ui->lable->setText("update Uncsusfull...!!!");
                }



            }
            if(countt>1)
                ui->lable->setText("Duplicated category");

            if(countt<1){
                ui->lable->setText("No value to seleectl...");

                //--------------write insert qury
               QSqlQuery qryaddbud;

                qryaddbud.prepare("INSERT INTO budget(category,budgetamount,username)""VALUES(:budgetcategory,:budgetamountdouble,:username)");


            //binding values

                qryaddbud.bindValue(":budgetamountdouble",budgetamount);
                qryaddbud.bindValue(":budgetcategory",budgetcategory);
                qryaddbud.bindValue(":username",globalUsername);


                if(qryaddbud.exec()){
                    ui->lable->setText("Registration Sucsusfull...");

                }else{
                      ui->lable->setText("Registration failed..." );
               }
            }
        }

        //=============== refresh table view-----------
        QSqlTableModel *tablemodel = new QSqlTableModel(this, sqlitedb);
        tablemodel->setTable("budget");
        tablemodel->setFilter(QString("username = '%1'").arg(globalUsername));
        tablemodel->select();

        ui->tableView->setModel(tablemodel);
        ui->tableView->show();


    }



}

void Budgetcreating::on_pushButton_tableview_clicked()
{
    //----------------table view for budget
    QSqlTableModel *tablemodel = new QSqlTableModel(this, sqlitedb);
    tablemodel->setTable("budget");
    tablemodel->setFilter(QString("username = '%1'").arg(globalUsername));
    tablemodel->select();

    ui->tableView->setModel(tablemodel);
    ui->tableView->show();

}


