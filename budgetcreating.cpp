#include "DatabaseManager.h"
#include "budgetcreating.h"
#include "ui_budgetcreating.h"
#include "organizerui.h"
#include"loginwindow.h"

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

        QMessageBox::information(this,"Not Connected","Database Not Ci=onnected");


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

                    QMessageBox::information(this, "Success", "Budget update successful.");

                }else{
                    QMessageBox::information(this, "failed", "Budget update failed.");
                }



            }
            if(countt>1)
                QMessageBox::warning(this, "Warning", "Duplicated category");

            if(countt<1){
                QMessageBox::warning(this, "Warning", "No value to seleectl...");



                //--------------write insert qury
               QSqlQuery qryaddbud(DatabaseManager::instance().getDatabase());

                qryaddbud.prepare("INSERT INTO budget(category,budgetamount,username)""VALUES(:budgetcategory,:budgetamountdouble,:username)");


            //binding values

                qryaddbud.bindValue(":budgetamountdouble",budgetamount);
                qryaddbud.bindValue(":budgetcategory",budgetcategory);
                qryaddbud.bindValue(":username",globalUsername);


                if(qryaddbud.exec()){
                    //ui->lable->setText("Registration Sucsusfull...");
                    QMessageBox::information(this, "Success", "Budget update successful.");

                }else{
                    //ui->lable->setText("Registration failed..." );
                    QMessageBox::information(this, "Failed", "Budget update Unsuccessful.");
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


