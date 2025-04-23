/********************************************************************************
** Form generated from reading UI file 'organizerui.ui'
**
** Created by: Qt User Interface Compiler version 6.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ORGANIZERUI_H
#define UI_ORGANIZERUI_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_organizerui
{
public:
    QPushButton *pushButton_logout;
    QLabel *lable;
    QGroupBox *groupBox;
    QLabel *label;
    QPushButton *pushButton_income;
    QPushButton *pushButton_expense;
    QPushButton *pushButton_createbudget;
    QLabel *label_4;
    QGroupBox *groupBox_2;
    QLabel *label_2;
    QPushButton *pushButton_financialreports;
    QLabel *label_5;
    QGroupBox *groupBox_3;
    QLabel *label_3;
    QPushButton *pushButton_academic;
    QLabel *label_6;

    void setupUi(QDialog *organizerui)
    {
        if (organizerui->objectName().isEmpty())
            organizerui->setObjectName("organizerui");
        organizerui->resize(1280, 768);
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/image/image/window_icon.png"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        organizerui->setWindowIcon(icon);
        organizerui->setStyleSheet(QString::fromUtf8("#organizerui{\n"
"border-image: url(:/image/Background02.png) 0 0 0 0 stretch stretch;}"));
        pushButton_logout = new QPushButton(organizerui);
        pushButton_logout->setObjectName("pushButton_logout");
        pushButton_logout->setGeometry(QRect(1180, 20, 81, 31));
        pushButton_logout->setStyleSheet(QString::fromUtf8("border: 3px solid #ff000d;\n"
"background-color:#ff000d;\n"
"border-radius: 15px;\n"
"color: white;\n"
"font: 700 10pt \"Segoe UI\";\n"
"\n"
""));
        lable = new QLabel(organizerui);
        lable->setObjectName("lable");
        lable->setGeometry(QRect(30, 60, 451, 41));
        lable->setStyleSheet(QString::fromUtf8("font: 500 20pt \"Segoe UI\";\n"
"color: white;"));
        groupBox = new QGroupBox(organizerui);
        groupBox->setObjectName("groupBox");
        groupBox->setGeometry(QRect(70, 320, 381, 381));
        groupBox->setStyleSheet(QString::fromUtf8(""));
        label = new QLabel(groupBox);
        label->setObjectName("label");
        label->setGeometry(QRect(90, 20, 201, 221));
        label->setStyleSheet(QString::fromUtf8("border-image: url(:/image/OrganizerUI01.png) 0 0 0 0 stretch stretch;"));
        pushButton_income = new QPushButton(groupBox);
        pushButton_income->setObjectName("pushButton_income");
        pushButton_income->setGeometry(QRect(10, 320, 111, 31));
        pushButton_income->setStyleSheet(QString::fromUtf8("border: 3px solid #e4555c;\n"
"background-color:#e4555c;\n"
"border-radius: 15px;\n"
"color: white;\n"
"font: 700 10pt \"Segoe UI\";"));
        pushButton_expense = new QPushButton(groupBox);
        pushButton_expense->setObjectName("pushButton_expense");
        pushButton_expense->setGeometry(QRect(130, 320, 111, 31));
        pushButton_expense->setStyleSheet(QString::fromUtf8("border: 3px solid #e4555c;\n"
"background-color:#e4555c;\n"
"border-radius: 15px;\n"
"color: white;\n"
"font: 700 10pt \"Segoe UI\";"));
        pushButton_createbudget = new QPushButton(groupBox);
        pushButton_createbudget->setObjectName("pushButton_createbudget");
        pushButton_createbudget->setGeometry(QRect(250, 320, 121, 31));
        pushButton_createbudget->setStyleSheet(QString::fromUtf8("border: 3px solid #e4555c;\n"
"background-color:#e4555c;\n"
"border-radius: 15px;\n"
"color: white;\n"
"font: 700 10pt \"Segoe UI\";"));
        label_4 = new QLabel(groupBox);
        label_4->setObjectName("label_4");
        label_4->setGeometry(QRect(40, 250, 311, 51));
        label_4->setStyleSheet(QString::fromUtf8("color: #e4555c;\n"
"font: 700 10pt \"Segoe UI\";"));
        groupBox_2 = new QGroupBox(organizerui);
        groupBox_2->setObjectName("groupBox_2");
        groupBox_2->setGeometry(QRect(490, 320, 361, 381));
        label_2 = new QLabel(groupBox_2);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(50, 20, 251, 241));
        label_2->setStyleSheet(QString::fromUtf8("border-image: url(:/image/OrganizerUI02.png) 0 0 0 0 stretch stretch;"));
        pushButton_financialreports = new QPushButton(groupBox_2);
        pushButton_financialreports->setObjectName("pushButton_financialreports");
        pushButton_financialreports->setGeometry(QRect(120, 320, 131, 31));
        pushButton_financialreports->setStyleSheet(QString::fromUtf8("border: 3px solid #5564ac;\n"
"background-color:#5564ac;\n"
"border-radius: 15px;\n"
"color: white;\n"
"font: 700 10pt \"Segoe UI\";\n"
""));
        label_5 = new QLabel(groupBox_2);
        label_5->setObjectName("label_5");
        label_5->setGeometry(QRect(40, 250, 311, 51));
        label_5->setStyleSheet(QString::fromUtf8("color: #5564ac;\n"
"font: 700 10pt \"Segoe UI\";"));
        groupBox_3 = new QGroupBox(organizerui);
        groupBox_3->setObjectName("groupBox_3");
        groupBox_3->setGeometry(QRect(890, 320, 341, 381));
        label_3 = new QLabel(groupBox_3);
        label_3->setObjectName("label_3");
        label_3->setGeometry(QRect(20, 30, 301, 221));
        label_3->setStyleSheet(QString::fromUtf8("border-image: url(:/image/OrganizerUI03.png) 0 0 0 0 stretch stretch;"));
        pushButton_academic = new QPushButton(groupBox_3);
        pushButton_academic->setObjectName("pushButton_academic");
        pushButton_academic->setGeometry(QRect(100, 320, 141, 31));
        pushButton_academic->setStyleSheet(QString::fromUtf8("border: 3px solid #ae3296;\n"
"background-color:#ae3296;\n"
"border-radius: 15px;\n"
"color: white;\n"
"font: 700 10pt \"Segoe UI\";"));
        label_6 = new QLabel(groupBox_3);
        label_6->setObjectName("label_6");
        label_6->setGeometry(QRect(30, 250, 311, 51));
        label_6->setStyleSheet(QString::fromUtf8("color: #ae3296;\n"
"font: 700 10pt \"Segoe UI\";"));

        retranslateUi(organizerui);

        QMetaObject::connectSlotsByName(organizerui);
    } // setupUi

    void retranslateUi(QDialog *organizerui)
    {
        organizerui->setWindowTitle(QCoreApplication::translate("organizerui", "Organizer", nullptr));
        pushButton_logout->setText(QCoreApplication::translate("organizerui", "LogOut", nullptr));
        lable->setText(QCoreApplication::translate("organizerui", "TextLabel", nullptr));
        groupBox->setTitle(QString());
        label->setText(QString());
        pushButton_income->setText(QCoreApplication::translate("organizerui", "ADD INCOME", nullptr));
        pushButton_expense->setText(QCoreApplication::translate("organizerui", "ADD EXPENSE", nullptr));
        pushButton_createbudget->setText(QCoreApplication::translate("organizerui", "CREATE BUDGET", nullptr));
        label_4->setText(QCoreApplication::translate("organizerui", "You can manage Incomes or Expences from here \n"
"Add incomes or Expences and more.", nullptr));
        groupBox_2->setTitle(QString());
        label_2->setText(QString());
        pushButton_financialreports->setText(QCoreApplication::translate("organizerui", "Financial Reports", nullptr));
        label_5->setText(QCoreApplication::translate("organizerui", "You can generate monthly reports showing total\n"
"income total expences and savings..", nullptr));
        groupBox_3->setTitle(QString());
        label_3->setText(QString());
        pushButton_academic->setText(QCoreApplication::translate("organizerui", "Academic schedule", nullptr));
        label_6->setText(QCoreApplication::translate("organizerui", "You can Add their weekly lecture shedule and \n"
"set the time duration for it", nullptr));
    } // retranslateUi

};

namespace Ui {
    class organizerui: public Ui_organizerui {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ORGANIZERUI_H
