#include "UserDataTableDialog.h"

#ifndef INCOMEUI_H
#define INCOMEUI_H

#include <QDialog>
#include <QApplication>
#include <QCalendarWidget>
#include <QDate>
#include <QSqlDatabase>
#include <QSqlQuery>

#include<QtSql>
#include<QDebug>
#include<QFileInfo>
#include<QMessageBox>
#include<QMainWindow>

namespace Ui {
class Incomeui;
}

class Incomeui : public UserDataTableDialog
{
    Q_OBJECT

public:
    explicit Incomeui(QWidget *parent = nullptr);
    ~Incomeui();

protected:
    // Implement the pure virtual functions from the base class
    QTableView* getTableView() const override;
    QString getTableName() const override;

private slots:
    void on_pushButton_back_clicked();

    //void on_pushButton_clicked();

    void on_pushButton_Add_clicked();
    void on_deleteOldRecordsButton_clicked();

private:
    Ui::Incomeui *ui;

};

#endif // INCOMEUI_H
