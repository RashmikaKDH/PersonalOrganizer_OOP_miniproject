#include "AppUtils.h"
#include "loginwindow.h"
#include "DatabaseManager.h"
#include "shedulemaneger.h"
#include "ui_shedulemaneger.h"
#include"organizerui.h"
#include <QMessageBox>
#include <QDateTime>
#include <QSqlQuery>
#include <QSqlError>
#include <QVariant>
#include <QTimer>
#include <QStringList>
#include <QDebug>
#include "AppUtils.h"


shedulemaneger::shedulemaneger(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::shedulemaneger)
    , deadlineTimer(new QTimer(this))
{
    ui->setupUi(this);

    if(!DatabaseManager::instance().getScheduleDatabase().isOpen()){
        qDebug() << "Failed to Open Schedule Database";
    } else {
        qDebug() << "Schedule Database Connected via Manager..";
    }

   // refreshTable();
    QDateTime utcTime = QDateTime::currentDateTimeUtc();
    QDateTime localTime = utcTime.toLocalTime();
    qDebug() << "UTC Time:" << utcTime.toString();
    qDebug() << "Local Time:" << localTime.toString();


    // Connect signals and slots
    connect(ui->addButton, &QPushButton::clicked, this, &shedulemaneger::onAddSchedule);
    // connect(deadlineTimer, &QTimer::timeout, this, &MainWindow::checkDeadlines);
    connect(deadlineTimer, &QTimer::timeout, this, &shedulemaneger::checkDeadlines);

    // Start the deadline checker timer
    deadlineTimer->start(60000); // Check every minute

    // Initialize the database and load schedules into the table widget
    initialize();
    loadSchedulesToTable();
}

shedulemaneger::~shedulemaneger()
{
    delete ui;

}


void shedulemaneger::initialize() {
    if(!DatabaseManager::instance().getScheduleDatabase().isOpen()) {
        //qWarning() << "Failed to open database:";
        qDebug() << "Failed to open database:";


        return;
    }

    // Create the schedules table if it does not exist
    QSqlQuery query1(DatabaseManager::instance().getScheduleDatabase());
    // Create table if not exists
    query1.exec("CREATE TABLE IF NOT EXISTS schedules (id INTEGER PRIMARY KEY, name TEXT, time TEXT, deadline TEXT)");

}
void shedulemaneger::addSchedule(const QString &name, const QTime &time, const QDateTime &deadline) {
    QSqlQuery query(DatabaseManager::instance().getScheduleDatabase());

    query.prepare("INSERT INTO schedules (name, time, deadline,username) VALUES (:name, :time, :deadline, :username)");

    //query.prepare("INSERT INTO schedules (name, time, deadline) VALUES (?, ?, ?)");
    query.bindValue(":name", name);
    query.bindValue(":time", time.toString(Qt::ISODate));  // Ensure QTime is converted to a string
    query.bindValue(":deadline", deadline.toString("yyyy-MM-dd HH:mm:ss"));
    query.bindValue(":username",globalUsername);

    if (!query.exec()) {
        //qWarning() << "Failed to add schedule:" << query.lastError().text();
        AppUtils::showToastred("Failed to add schedule..", this);

    }
}

QStringList shedulemaneger::getDueSchedules() {
    QStringList alerts;
    QSqlQuery query(DatabaseManager::instance().getScheduleDatabase());
    //-------to select deadline expires now
    if (!query.exec("SELECT name, deadline FROM schedules WHERE deadline <= datetime('now', 'localtime') AND deadline > datetime('now', 'localtime', '-1 minute')")) {
        //qWarning() << "Query failed:" << query.lastError().text();
        qDebug() << "Query failed:" << query.lastError().text();
        return alerts;
    }

    while (query.next()) {
        QString name = query.value(0).toString();
        QString deadlineStr = query.value(1).toString();

        QDateTime deadline = QDateTime::fromString(deadlineStr, Qt::ISODate);
        if (!deadline.isValid()) {
            //qWarning() << "Invalid deadline format for schedule:" << name << "Raw deadline:" << deadlineStr;
            qDebug() << "Invalid deadline format for schedule:" << name << "Raw deadline:" << deadlineStr;
            continue;
        }

        qDebug() << "Upcoming schedule:" << name << "Deadline:" << deadline.toString();

        alerts.append(QString("Schedule '%1' is due! Deadline: %2")
                          .arg(name)
                          .arg(deadline.toString("yyyy-MM-dd hh:mm:ss")));
    }

    return alerts;
}




QStringList shedulemaneger::getOverdueSchedules() {
    QStringList alerts;
    QSqlQuery query(DatabaseManager::instance().getScheduleDatabase());
    query.exec("SELECT name, deadline FROM schedules WHERE deadline < datetime('now')");

    while (query.next()) {
        QString name = query.value(0).toString();
        QDateTime deadline = QDateTime::fromString(query.value(1).toString(), Qt::ISODate);

        alerts.append(QString("Schedule '%1' was due at %2.")
                          .arg(name)
                          .arg(deadline.toString("yyyy-MM-dd hh:mm:ss")));
    }

    return alerts;
}





QString name;


void shedulemaneger::onAddSchedule() {

    QTime time;
    QDateTime deadline;

    name = ui->nameEdit->text();
    time = ui->timeEdit->time();
    deadline = ui->deadlineEdit->dateTime();

    if (name.isEmpty()) {
        //QMessageBox::warning(this, "Input Error", "Schedule name cannot be empty.");
        AppUtils::showToastred("Schedule name cannot be empty.", this);
        return;
    }
    addSchedule(name, time, deadline);

    //QMessageBox::information(this, "Success", "Schedule added successfully.");
    AppUtils::showToast("New Schedule added...", this);

    // --- THE CRITICAL FIX: ADD this single line of code. ---
    // This tells the table to reload ALL its data from the database,
    // ensuring that the new schedule you just added is now visible.
    loadSchedulesToTable();
}

void shedulemaneger::checkDeadlines() {
    // Retrieve due schedules from the database
    QStringList alerts = getDueSchedules();
    //QStringList alerts = db->getOverdueSchedules();

    // Display alerts for each due schedule
    for (const QString &alert : alerts) {
        QMessageBox::warning(this, "Deadline Alert", alert);
    }
}

void shedulemaneger::loadSchedulesToTable() {

    ui->scheduleTable->setRowCount(0);

    QSqlQuery query(DatabaseManager::instance().getScheduleDatabase());
    query.prepare("SELECT name, time, deadline FROM schedules WHERE username = :username");
    query.bindValue(":username", globalUsername);

    if (!query.exec()) {
        qDebug() << "Failed to load schedules for user:" << globalUsername << "Error:" << query.lastError().text();
        return;
    }
    while (query.next()) {
        QString name = query.value(0).toString();
        QString time = query.value(1).toString();
        QString deadline = query.value(2).toString();

        QTime parsedTime = QTime::fromString(time, Qt::ISODate);

        int row = ui->scheduleTable->rowCount();
        ui->scheduleTable->insertRow(row);
        ui->scheduleTable->setItem(row, 0, new QTableWidgetItem(name));
        ui->scheduleTable->setItem(row, 1, new QTableWidgetItem(parsedTime.toString("hh:mm:ss")));
        ui->scheduleTable->setItem(row, 2, new QTableWidgetItem(deadline));
    }
}


void shedulemaneger::on_pushButton_backto_clicked()
{
     //conclose();
    this->close();
    organizerui *backtoor = new organizerui;
    backtoor->show();
}


void shedulemaneger::on_deleteSheduleButton_clicked()
{
    name = ui->nameEdit->text();
    if (name.isEmpty()) {
       // QMessageBox::warning(this, "Input Error", "Schedule name cannot be empty.");
        AppUtils::showToastred("Schedule name cannot be empty..", this);

        return;
    }
    QSqlQuery deleteshedule(DatabaseManager::instance().getScheduleDatabase());
    deleteshedule.prepare("DELETE FROM schedules WHERE name = :name");
    deleteshedule.bindValue(":name", name);

    if (!deleteshedule.exec()) {
        //qWarning() << "Failed Delete from shedule:" << deleteshedule.lastError().text();
        qDebug() << "Failed Delete from shedule:" << deleteshedule.lastError().text();
        AppUtils::showToastred("Failed Delete from shedule..", this);

        //ui->lable->setText("Failed to Delete from shedule:");
    }else{
      //   ui->lable->setText("Delete from shedule:");
      //  QMessageBox::information(this, "Deleted", "Schedule Delete successfully.");
         AppUtils::showToast("Schedule Delete successfully..", this);

    }
    loadSchedulesToTable();
    //refreshTable();
}

//++++++++++++Update button++++++++
void shedulemaneger::on_deleteSheduleButton_2_clicked()
{

    QTime time;
    QDateTime deadline;
    // Retrieve user input
    name = ui->nameEdit->text();
    time = ui->timeEdit->time();
    deadline = ui->deadlineEdit->dateTime();

    // Validate input
    if (name.isEmpty()) {
       // QMessageBox::warning(this, "Input Error", "Schedule name cannot be empty.");
        AppUtils::showToastred("Schedule name cannot be empty..", this);
        return;
    }
    QSqlQuery updateshedule(DatabaseManager::instance().getScheduleDatabase());
    updateshedule.prepare("UPDATE schedules SET time = :newTime, deadline = :newDeadline "
                  "WHERE name = :name ");

    // Bind new values for the update
     updateshedule.bindValue(":newTime", time.toString(Qt::ISODate));  // Convert QTime to ISO format
    updateshedule.bindValue(":newDeadline", deadline.toString("yyyy-MM-dd HH:mm:ss"));  // Convert QDateTime

    // Bind original values for the WHERE clause
    updateshedule.bindValue(":name", name);

    if (!updateshedule.exec()) {
        //qWarning() << "Failed to update schedule:" << updateshedule.lastError().text();
        qDebug() << "Failed to update schedule:" << updateshedule.lastError().text();
        AppUtils::showToastred("Failed to update schedule..", this);

    }
    else{
        //QMessageBox::information(this, "Updated", "Schedule Update successfully.");
        AppUtils::showToast("Schedule Update successfully..", this);
    }
    loadSchedulesToTable();
    //refreshTable();



}

