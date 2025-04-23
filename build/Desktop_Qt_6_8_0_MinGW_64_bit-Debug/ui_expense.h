/********************************************************************************
** Form generated from reading UI file 'expense.ui'
**
** Created by: Qt User Interface Compiler version 6.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_EXPENSE_H
#define UI_EXPENSE_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDateEdit>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTableView>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Expense
{
public:
    QPushButton *pushButton_backto;
    QLabel *lable;
    QTableView *tableView;
    QGroupBox *groupBox;
    QWidget *layoutWidget;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_description;
    QLineEdit *lineEdit_description;
    QWidget *layoutWidget1;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_date;
    QDateEdit *dateEdit_expense;
    QWidget *layoutWidget2;
    QHBoxLayout *horizontalLayout_4;
    QLabel *label_amount;
    QLineEdit *lineEdit_amount;
    QPushButton *pushButton_add;
    QWidget *layoutWidget3;
    QHBoxLayout *horizontalLayout;
    QLabel *label_category;
    QComboBox *comboBox_category;

    void setupUi(QDialog *Expense)
    {
        if (Expense->objectName().isEmpty())
            Expense->setObjectName("Expense");
        Expense->resize(1280, 768);
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/image/image/window_icon.png"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        Expense->setWindowIcon(icon);
        Expense->setStyleSheet(QString::fromUtf8("\n"
"QDialog{border-image: url(:/image/Background04.png) 0 0 0 0 stretch stretch;}\n"
""));
        pushButton_backto = new QPushButton(Expense);
        pushButton_backto->setObjectName("pushButton_backto");
        pushButton_backto->setGeometry(QRect(1140, 710, 81, 31));
        pushButton_backto->setContextMenuPolicy(Qt::ContextMenuPolicy::DefaultContextMenu);
        pushButton_backto->setStyleSheet(QString::fromUtf8("border: 3px solid #000000;\n"
"background-color:#000000;\n"
"border-radius: 15px;\n"
"color: white;\n"
"font: 700 10pt \"Segoe UI\";\n"
"	"));
        lable = new QLabel(Expense);
        lable->setObjectName("lable");
        lable->setGeometry(QRect(430, 20, 451, 31));
        lable->setStyleSheet(QString::fromUtf8(" border: 1px solid #ff99cc;\n"
" border-radius: 10px;\n"
"color: #ff99cc;"));
        tableView = new QTableView(Expense);
        tableView->setObjectName("tableView");
        tableView->setGeometry(QRect(590, 140, 601, 501));
        tableView->setStyleSheet(QString::fromUtf8("QGroupBox{font: 12pt \"Segoe UI\";\n"
"border: 2px solid  #3C536F;\n"
" border-radius: 10px;\n"
"background-color: transparent;\n"
"color: #3C536F;}"));
        groupBox = new QGroupBox(Expense);
        groupBox->setObjectName("groupBox");
        groupBox->setGeometry(QRect(90, 140, 491, 501));
        groupBox->setStyleSheet(QString::fromUtf8("/*QGroupBox{font: 20pt \"Segoe UI\";\n"
"border: 5px solid  #3C536F;\n"
" border-radius: 10px;\n"
"/* From https://css.glass \n"
"background: rgba(0, 0, 0, 0.14);\n"
"border-radius: 16px;\n"
"box-shadow: 0 4px 30px rgba(0, 0, 0, 0.1);\n"
"backdrop-filter: blur(11.4px);\n"
"-webkit-backdrop-filter: blur(11.4px);\n"
"border: 1px solid rgba(0, 0, 0, 0.11);\n"
"color: #3C536F;}*/\n"
"QGroupBox{font: 19pt \"Segoe UI\";\n"
"color:White;\n"
"\n"
"border-radius: 15px;\n"
"\n"
"background-color: #841ebc;\n"
"border: 1px solid #a23fdf;}"));
        layoutWidget = new QWidget(groupBox);
        layoutWidget->setObjectName("layoutWidget");
        layoutWidget->setGeometry(QRect(30, 150, 421, 51));
        horizontalLayout_2 = new QHBoxLayout(layoutWidget);
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        label_description = new QLabel(layoutWidget);
        label_description->setObjectName("label_description");
        label_description->setStyleSheet(QString::fromUtf8("color: rgb(60, 83, 111);"));

        horizontalLayout_2->addWidget(label_description);

        lineEdit_description = new QLineEdit(layoutWidget);
        lineEdit_description->setObjectName("lineEdit_description");
        lineEdit_description->setStyleSheet(QString::fromUtf8("font: 12pt \"Segoe UI\";\n"
"border: 2px solid  white;\n"
" border-radius: 5px;\n"
"background-color: transparent;\n"
"color: white;"));

        horizontalLayout_2->addWidget(lineEdit_description);

        layoutWidget1 = new QWidget(groupBox);
        layoutWidget1->setObjectName("layoutWidget1");
        layoutWidget1->setGeometry(QRect(30, 230, 421, 51));
        horizontalLayout_3 = new QHBoxLayout(layoutWidget1);
        horizontalLayout_3->setObjectName("horizontalLayout_3");
        horizontalLayout_3->setContentsMargins(0, 0, 0, 0);
        label_date = new QLabel(layoutWidget1);
        label_date->setObjectName("label_date");
        label_date->setStyleSheet(QString::fromUtf8("color: rgb(60, 83, 111);"));

        horizontalLayout_3->addWidget(label_date);

        dateEdit_expense = new QDateEdit(layoutWidget1);
        dateEdit_expense->setObjectName("dateEdit_expense");
        dateEdit_expense->setStyleSheet(QString::fromUtf8("font: 12pt \"Segoe UI\";\n"
"border: 2px solid  white;\n"
" border-radius: 5px;\n"
"background-color: transparent;\n"
"color: white;"));

        horizontalLayout_3->addWidget(dateEdit_expense);

        layoutWidget2 = new QWidget(groupBox);
        layoutWidget2->setObjectName("layoutWidget2");
        layoutWidget2->setGeometry(QRect(30, 310, 421, 51));
        horizontalLayout_4 = new QHBoxLayout(layoutWidget2);
        horizontalLayout_4->setObjectName("horizontalLayout_4");
        horizontalLayout_4->setContentsMargins(0, 0, 0, 0);
        label_amount = new QLabel(layoutWidget2);
        label_amount->setObjectName("label_amount");
        label_amount->setStyleSheet(QString::fromUtf8(""));

        horizontalLayout_4->addWidget(label_amount);

        lineEdit_amount = new QLineEdit(layoutWidget2);
        lineEdit_amount->setObjectName("lineEdit_amount");
        lineEdit_amount->setStyleSheet(QString::fromUtf8("font: 12pt \"Segoe UI\";\n"
"border: 2px solid  white;\n"
" border-radius: 5px;\n"
"background-color: transparent;\n"
"color: white;"));

        horizontalLayout_4->addWidget(lineEdit_amount);

        pushButton_add = new QPushButton(groupBox);
        pushButton_add->setObjectName("pushButton_add");
        pushButton_add->setGeometry(QRect(370, 380, 81, 31));
        pushButton_add->setStyleSheet(QString::fromUtf8("border: 3px solid #000000;\n"
"background-color:#000000;\n"
"border-radius: 15px;\n"
"color: white;\n"
"font: 700 10pt \"Segoe UI\";\n"
"	"));
        layoutWidget3 = new QWidget(groupBox);
        layoutWidget3->setObjectName("layoutWidget3");
        layoutWidget3->setGeometry(QRect(30, 90, 421, 31));
        horizontalLayout = new QHBoxLayout(layoutWidget3);
        horizontalLayout->setObjectName("horizontalLayout");
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        label_category = new QLabel(layoutWidget3);
        label_category->setObjectName("label_category");
        label_category->setStyleSheet(QString::fromUtf8("color: rgb(60, 83, 111);"));

        horizontalLayout->addWidget(label_category);

        comboBox_category = new QComboBox(layoutWidget3);
        comboBox_category->addItem(QString());
        comboBox_category->addItem(QString());
        comboBox_category->addItem(QString());
        comboBox_category->addItem(QString());
        comboBox_category->addItem(QString());
        comboBox_category->addItem(QString());
        comboBox_category->setObjectName("comboBox_category");
        comboBox_category->setStyleSheet(QString::fromUtf8("font: 12pt \"Segoe UI\";\n"
"border: 2px solid  white;\n"
" border-radius: 5px;\n"
"background-color: transparent;\n"
"color: white;"));

        horizontalLayout->addWidget(comboBox_category);


        retranslateUi(Expense);

        QMetaObject::connectSlotsByName(Expense);
    } // setupUi

    void retranslateUi(QDialog *Expense)
    {
        Expense->setWindowTitle(QCoreApplication::translate("Expense", "Expense", nullptr));
#if QT_CONFIG(accessibility)
        pushButton_backto->setAccessibleName(QString());
#endif // QT_CONFIG(accessibility)
        pushButton_backto->setText(QCoreApplication::translate("Expense", "Back", nullptr));
        lable->setText(QCoreApplication::translate("Expense", "TextLabel", nullptr));
        groupBox->setTitle(QCoreApplication::translate("Expense", " ADD YOUR EXPENSES", nullptr));
        label_description->setText(QCoreApplication::translate("Expense", "<html><head/><body><p><span style=\"font-size:12pt; font-weight:700; color:#ffffff;\">Description</span></p></body></html>", nullptr));
        label_date->setText(QCoreApplication::translate("Expense", "<html><head/><body><p><span style=\"font-size:12pt; font-weight:700; color:#ffffff;\">Description</span></p></body></html>", nullptr));
        label_amount->setText(QCoreApplication::translate("Expense", "<html><head/><body><p><span style=\"font-size:12pt; font-weight:700; color:#ffffff;\">Description</span></p></body></html>", nullptr));
        pushButton_add->setText(QCoreApplication::translate("Expense", "Add", nullptr));
        label_category->setText(QCoreApplication::translate("Expense", "<html><head/><body><p><span style=\"font-size:12pt; font-weight:700; color:#ffffff;\">Description</span></p></body></html>", nullptr));
        comboBox_category->setItemText(0, QCoreApplication::translate("Expense", "Food", nullptr));
        comboBox_category->setItemText(1, QCoreApplication::translate("Expense", "Entertainment", nullptr));
        comboBox_category->setItemText(2, QCoreApplication::translate("Expense", "Traveling", nullptr));
        comboBox_category->setItemText(3, QCoreApplication::translate("Expense", "Clothing", nullptr));
        comboBox_category->setItemText(4, QCoreApplication::translate("Expense", "Education Equipment", nullptr));
        comboBox_category->setItemText(5, QCoreApplication::translate("Expense", "University Fees", nullptr));

    } // retranslateUi

};

namespace Ui {
    class Expense: public Ui_Expense {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_EXPENSE_H
