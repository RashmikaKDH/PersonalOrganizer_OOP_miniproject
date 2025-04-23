
#include "loginwindow.h"
#include "ui_loginwindow.h"
#include"QMessageBox"


loginwindow::loginwindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::loginwindow)
{
    ui->setupUi(this);

//input informations for line edits

    ui->lineedit_username->setPlaceholderText("Enter Your Username");
    ui->lineedit_password->setPlaceholderText("Enter Your Password");

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

QString globalUsername;

void setGlobalUsername(const QString &username) {
    globalUsername = username;
}


loginwindow::~loginwindow()
{
    delete ui;
}


//cleare table function
void clearTable(const QString &tableName) {
    QSqlQuery query;

    // Construct the SQL query string
    QString sql = "DELETE FROM " + tableName;

    // Execute the query
    if (!query.exec(sql)) {
        qDebug() << "Error clearing table:" << query.lastError();
    } else {
        qDebug() << "Table cleared successfully!";
    }
}

void loginwindow::on_LPushButton_login_clicked()
{
//taking input from LineEdit
    QString username,password;
    username=ui->lineedit_username->text();
    password=ui->lineedit_password->text();

    setGlobalUsername(username);

    if (username.isEmpty() ||  password.isEmpty()) {
        QMessageBox::warning(this, "To Login ", "All fields must be filled!");
        return;
    }

//checking is database is open and connected
    if(!sqlitedb.isOpen()){
        qDebug()<<"Failed to open the database";
        return;
    }
//Query for checking data matching
    QSqlQuery qry;

    if(qry.exec("select * from logininfo where username='"+username+"'and password='"+password+"'"))
    {
        int countt=0;
        while (qry.next())
        {
            countt++;
        }
        if(countt==1){
            ui->label->setText("Username and password is correct");

            //saving username and id to atable
            QSqlQuery qrydatasave;
            clearTable("userinfo");
           //qrydatasave.prepare("DELETE * FROM userinfo");
            qrydatasave.prepare("INSERT INTO userinfo(username,password)""VALUES (:us,:ps)");

            qrydatasave.bindValue(":us",username);
            qrydatasave.bindValue(":ps",password);
            qrydatasave.exec();


            conclose();
            //loginui -> organizer ui connection
            this->close();
            Organizerui = new organizerui(this);
            Organizerui->show();






        }
        if(countt>1)
            ui->label->setText("Duplicated Username and password");
        if(countt<1)
            ui->label->setText("Username and password is not correct");
    }
}

//connecting singup button to singup window
void loginwindow::on_LPushButton_signup_clicked()
{
    hide();
    Signup1 = new signup(this);
    Signup1->show();

}




