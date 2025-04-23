/********************************************************************************
** Form generated from reading UI file 'budgetcreating.ui'
**
** Created by: Qt User Interface Compiler version 6.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_BUDGETCREATING_H
#define UI_BUDGETCREATING_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTableView>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Budgetcreating
{
public:
    QWidget *centralwidget;
    QLabel *lable;
    QPushButton *pushButton_back;
    QTableView *tableView;
    QPushButton *pushButton_tableview;
    QGroupBox *groupBox;
    QWidget *layoutWidget;
    QHBoxLayout *horizontalLayout;
    QLabel *label_category;
    QComboBox *comboBox_category;
    QWidget *layoutWidget1;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_budgetamount;
    QLineEdit *lineEdit_budgetamount;
    QPushButton *pushButton_addbudget;
    QPushButton *pushButton_update;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *Budgetcreating)
    {
        if (Budgetcreating->objectName().isEmpty())
            Budgetcreating->setObjectName("Budgetcreating");
        Budgetcreating->setEnabled(true);
        Budgetcreating->resize(1280, 768);
        Budgetcreating->setStyleSheet(QString::fromUtf8("QMainWindow{border-image: url(:/image/Background04.png) 0 0 0 0 stretch stretch;}\n"
"\n"
""));
        centralwidget = new QWidget(Budgetcreating);
        centralwidget->setObjectName("centralwidget");
        centralwidget->setEnabled(true);
        lable = new QLabel(centralwidget);
        lable->setObjectName("lable");
        lable->setGeometry(QRect(50, 540, 571, 41));
        lable->setStyleSheet(QString::fromUtf8("  border: 1px solid #ff99cc;\n"
"  border-radius: 10px;\n"
"color: #ff99cc;"));
        pushButton_back = new QPushButton(centralwidget);
        pushButton_back->setObjectName("pushButton_back");
        pushButton_back->setGeometry(QRect(930, 540, 91, 31));
        pushButton_back->setStyleSheet(QString::fromUtf8("border: 2px solid #DEC8AC;\n"
"font: 700 10pt \"Segoe UI\";\n"
"border-radius: 15px;\n"
"color: #DEC8AC;"));
        tableView = new QTableView(centralwidget);
        tableView->setObjectName("tableView");
        tableView->setEnabled(true);
        tableView->setGeometry(QRect(560, 40, 481, 421));
        pushButton_tableview = new QPushButton(centralwidget);
        pushButton_tableview->setObjectName("pushButton_tableview");
        pushButton_tableview->setGeometry(QRect(810, 540, 101, 31));
        pushButton_tableview->setStyleSheet(QString::fromUtf8("border: 2px solid #DEC8AC;\n"
"font: 700 10pt \"Segoe UI\";\n"
"border-radius: 15px;\n"
"color: #DEC8AC;"));
        groupBox = new QGroupBox(centralwidget);
        groupBox->setObjectName("groupBox");
        groupBox->setGeometry(QRect(50, 40, 491, 421));
        groupBox->setStyleSheet(QString::fromUtf8("QGroupBox{font: 20pt \"Segoe UI\";\n"
"border: 5px solid  #3C536F;\n"
" border-radius: 10px;\n"
"/* From https://css.glass */\n"
"background: rgba(0, 0, 0, 0.14);\n"
"border-radius: 16px;\n"
"box-shadow: 0 4px 30px rgba(0, 0, 0, 0.1);\n"
"backdrop-filter: blur(11.4px);\n"
"-webkit-backdrop-filter: blur(11.4px);\n"
"border: 1px solid rgba(0, 0, 0, 0.11);color: #3C536F;}"));
        layoutWidget = new QWidget(groupBox);
        layoutWidget->setObjectName("layoutWidget");
        layoutWidget->setGeometry(QRect(40, 80, 421, 61));
        horizontalLayout = new QHBoxLayout(layoutWidget);
        horizontalLayout->setObjectName("horizontalLayout");
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        label_category = new QLabel(layoutWidget);
        label_category->setObjectName("label_category");
        label_category->setStyleSheet(QString::fromUtf8("color: rgb(60, 83, 111);"));

        horizontalLayout->addWidget(label_category);

        comboBox_category = new QComboBox(layoutWidget);
        comboBox_category->addItem(QString());
        comboBox_category->addItem(QString());
        comboBox_category->addItem(QString());
        comboBox_category->addItem(QString());
        comboBox_category->addItem(QString());
        comboBox_category->addItem(QString());
        comboBox_category->setObjectName("comboBox_category");

        horizontalLayout->addWidget(comboBox_category);

        layoutWidget1 = new QWidget(groupBox);
        layoutWidget1->setObjectName("layoutWidget1");
        layoutWidget1->setGeometry(QRect(40, 190, 421, 61));
        horizontalLayout_2 = new QHBoxLayout(layoutWidget1);
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        label_budgetamount = new QLabel(layoutWidget1);
        label_budgetamount->setObjectName("label_budgetamount");
        label_budgetamount->setStyleSheet(QString::fromUtf8("color: rgb(60, 83, 111);"));

        horizontalLayout_2->addWidget(label_budgetamount);

        lineEdit_budgetamount = new QLineEdit(layoutWidget1);
        lineEdit_budgetamount->setObjectName("lineEdit_budgetamount");
        lineEdit_budgetamount->setStyleSheet(QString::fromUtf8("QLineEdit{font: 12pt \"Segoe UI\";\n"
"border: 2px solid  #3C536F;\n"
" border-radius: 5px;\n"
"background-color: transparent;\n"
"color: #3C536F;\n"
"}"));

        horizontalLayout_2->addWidget(lineEdit_budgetamount);

        pushButton_addbudget = new QPushButton(groupBox);
        pushButton_addbudget->setObjectName("pushButton_addbudget");
        pushButton_addbudget->setGeometry(QRect(140, 320, 101, 31));
        pushButton_addbudget->setStyleSheet(QString::fromUtf8("border: 2px solid #3C536F;\n"
"font: 700 10pt \"Segoe UI\";\n"
"border-radius: 15px;\n"
"color: #3C536F;"));
        pushButton_update = new QPushButton(groupBox);
        pushButton_update->setObjectName("pushButton_update");
        pushButton_update->setGeometry(QRect(260, 320, 121, 31));
        pushButton_update->setStyleSheet(QString::fromUtf8("border: 2px solid #3C536F;\n"
"font: 700 10pt \"Segoe UI\";\n"
"border-radius: 15px;\n"
"color: #3C536F;"));
        Budgetcreating->setCentralWidget(centralwidget);
        pushButton_back->raise();
        tableView->raise();
        pushButton_tableview->raise();
        groupBox->raise();
        lable->raise();
        menubar = new QMenuBar(Budgetcreating);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 1280, 21));
        Budgetcreating->setMenuBar(menubar);
        statusbar = new QStatusBar(Budgetcreating);
        statusbar->setObjectName("statusbar");
        Budgetcreating->setStatusBar(statusbar);

        retranslateUi(Budgetcreating);

        QMetaObject::connectSlotsByName(Budgetcreating);
    } // setupUi

    void retranslateUi(QMainWindow *Budgetcreating)
    {
        Budgetcreating->setWindowTitle(QCoreApplication::translate("Budgetcreating", "MainWindow", nullptr));
        lable->setText(QCoreApplication::translate("Budgetcreating", "TextLabel", nullptr));
        pushButton_back->setText(QCoreApplication::translate("Budgetcreating", "BACK", nullptr));
        pushButton_tableview->setText(QCoreApplication::translate("Budgetcreating", "Refresh table", nullptr));
        groupBox->setTitle(QCoreApplication::translate("Budgetcreating", "CREATE YOUR BUDGET", nullptr));
        label_category->setText(QCoreApplication::translate("Budgetcreating", "<html><head/><body><p><span style=\" font-size:16pt;\">Category</span></p></body></html>", nullptr));
        comboBox_category->setItemText(0, QCoreApplication::translate("Budgetcreating", "Food", nullptr));
        comboBox_category->setItemText(1, QCoreApplication::translate("Budgetcreating", "Entertainment", nullptr));
        comboBox_category->setItemText(2, QCoreApplication::translate("Budgetcreating", "Traveling", nullptr));
        comboBox_category->setItemText(3, QCoreApplication::translate("Budgetcreating", "Clothing", nullptr));
        comboBox_category->setItemText(4, QCoreApplication::translate("Budgetcreating", "Education Equipment", nullptr));
        comboBox_category->setItemText(5, QCoreApplication::translate("Budgetcreating", "University Fees", nullptr));

        label_budgetamount->setText(QCoreApplication::translate("Budgetcreating", "<html><head/><body><p><span style=\" font-size:16pt;\">Budget Amount</span></p></body></html>", nullptr));
        pushButton_addbudget->setText(QCoreApplication::translate("Budgetcreating", "Add Budget", nullptr));
        pushButton_update->setText(QCoreApplication::translate("Budgetcreating", "Update Budget", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Budgetcreating: public Ui_Budgetcreating {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_BUDGETCREATING_H
