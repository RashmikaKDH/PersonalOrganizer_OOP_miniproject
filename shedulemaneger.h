#ifndef SHEDULEMANEGER_H
#define SHEDULEMANEGER_H

#include <QMainWindow>
#include <QDialog>

#include <QTimer>
#include <QMap>
#include <QDateTime>
#include <QDate>
#include <QSqlDatabase>
#include <QSqlQuery>

#include<QtSql>
#include<QDebug>
#include<QFileInfo>
#include<QMessageBox>
#include<QSqlTableModel>

#include <QTableWidget>
#include <QString>
#include <QStringList>

namespace Ui {
class shedulemaneger;
}

class shedulemaneger : public QMainWindow
{
    Q_OBJECT

public:
    explicit shedulemaneger(QWidget *parent = nullptr);
    ~shedulemaneger();
    void initialize(); // Initialize the database and create tables if needed
    void addSchedule(const QString &name, const QTime &time, const QDateTime &deadline); // Add a new schedule
    QStringList getDueSchedules(); // Retrieve schedules with deadlines due
    QStringList getOverdueSchedules();

    void conclose(){

        db.close();
        db.removeDatabase(QSqlDatabase::defaultConnection);
    }

private slots:
    void onAddSchedule(); // Handle adding a new schedule
    void checkDeadlines(); // Check for schedules with approaching deadlines
    void loadSchedulesToTable(); // Load schedules from the database to the table widget



    void on_pushButton_backto_clicked();

    void on_deleteSheduleButton_clicked();

    void on_deleteSheduleButton_2_clicked();

private:
    Ui::shedulemaneger *ui;
    QSqlDatabase db; // SQLite database connection
    QTimer *deadlineTimer;
};

#endif // SHEDULEMANEGER_H
