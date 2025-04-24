#include "signup.h"
#include "ui_signup.h"
#include"loginwindow.h"

signup::signup(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::signup)
{
    ui->setupUi(this);

//input informations for line edits
    ui->lineedit_register_username->setPlaceholderText("Enter Username");
    ui->lineedit_register_email->setPlaceholderText("Enter Email");
    ui->lineedit_register_password->setPlaceholderText("Enter Password");
    ui->lineedit_register_phone->setPlaceholderText("Enter Phone Number");

//connecting database for login
    sqlitedb = QSqlDatabase::addDatabase("QSQLITE");

    sqlitedb.setDatabaseName("C:/Users/Rashmika97/Music/PersonalOrganizerOOP/Db/logindatabase.db");

//checking conectivity of database
    if(!sqlitedb.open()){
        ui->label->setText("Failed to Open Database");
    }
    else{
        ui->label->setText("Database Conected..");
    }


}





signup::~signup()
{
    delete ui;
}

// Registration Button Click
void signup::on_pushButton_register_clicked()
{

//retreive data from input fields
    if(!sqlitedb.open()){

        QMessageBox::information(this,"Not Connected","Database Not Connected" );

    }
    else{
        //getting inputs from LineEdits
        QString registerusername = ui->lineedit_register_username->text();
        QString registurepassword = ui->lineedit_register_password->text();
        QString registeremail = ui->lineedit_register_email->text();
        QString registerphone = ui->lineedit_register_phone->text();

        //check Lineedits are not empty
        if (registerusername.isEmpty() || registeremail.isEmpty() || registurepassword.isEmpty() || registerphone.isEmpty()) {
            QMessageBox::warning(this, "Create An Account", "All fields must be filled!");
            return;
        }

        //define query to inseert data

        QSqlQuery qryregister;

        qryregister.prepare("INSERT INTO logininfo (username, password, email, phone)" "VALUES (:registerusername,:registurepassword,:registeremail,:registerphone)");

        qryregister.bindValue(":registerusername",registerusername);
        qryregister.bindValue(":registurepassword",registurepassword);
        qryregister.bindValue(":registeremail",registeremail);
        qryregister.bindValue(":registerphone",registerphone);

        if(qryregister.exec()){
            ui->label->setText("Registration Sucsusfull...");

            conclose();
//-----------redirect to liginwindow
            this->close();
            loginwindow *logwin =new loginwindow;
            logwin->show();

        }else{
            ui->label->setText("Registration Uncsusfull...!!!");
        }

    }

}





//back button
void signup::on_pushButton_back_clicked()
{
    this->close();
    loginwindow *logwin =new loginwindow;
    logwin->show();
}

