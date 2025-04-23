/********************************************************************************
** Form generated from reading UI file 'incomeui.ui'
**
** Created by: Qt User Interface Compiler version 6.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_INCOMEUI_H
#define UI_INCOMEUI_H

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
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Incomeui
{
public:
    QPushButton *pushButton_back;
    QLabel *lable;
    QGroupBox *groupBox;
    QWidget *layoutWidget;
    QHBoxLayout *horizontalLayout;
    QLabel *label_income_source;
    QComboBox *comboBox_income_source;
    QWidget *layoutWidget1;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_Description;
    QTextEdit *textEdit_Description;
    QPushButton *pushButton_Add;
    QWidget *layoutWidget2;
    QHBoxLayout *horizontalLayout_4;
    QLabel *label;
    QDateEdit *QDate;
    QWidget *layoutWidget3;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_Amount;
    QLineEdit *lineEdit_Amount;
    QTableView *tableView;

    void setupUi(QDialog *Incomeui)
    {
        if (Incomeui->objectName().isEmpty())
            Incomeui->setObjectName("Incomeui");
        Incomeui->resize(1280, 768);
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/image/image/window_icon.png"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        Incomeui->setWindowIcon(icon);
        Incomeui->setStyleSheet(QString::fromUtf8("\n"
"QDialog{border-image: url(:/image/Background04.png) 0 0 0 0 stretch stretch;}\n"
""));
        pushButton_back = new QPushButton(Incomeui);
        pushButton_back->setObjectName("pushButton_back");
        pushButton_back->setGeometry(QRect(1180, 710, 71, 31));
        pushButton_back->setStyleSheet(QString::fromUtf8("border: 3px solid #000000;\n"
"background-color:#000000;\n"
"border-radius: 15px;\n"
"color: white;\n"
"font: 700 10pt \"Segoe UI\";\n"
"	"));
        lable = new QLabel(Incomeui);
        lable->setObjectName("lable");
        lable->setGeometry(QRect(460, 10, 431, 41));
        lable->setStyleSheet(QString::fromUtf8("  border: 1px solid #ff99cc;\n"
"  border-radius: 10px;\n"
"color: #ff99cc;"));
        groupBox = new QGroupBox(Incomeui);
        groupBox->setObjectName("groupBox");
        groupBox->setGeometry(QRect(60, 130, 551, 521));
        groupBox->setStyleSheet(QString::fromUtf8("QGroupBox{font: 19pt \"Segoe UI\";\n"
"color:White;\n"
"\n"
"border-radius: 15px;\n"
"\n"
"background-color: #841ebc;\n"
"border: 1px solid #a23fdf;}"));
        layoutWidget = new QWidget(groupBox);
        layoutWidget->setObjectName("layoutWidget");
        layoutWidget->setGeometry(QRect(40, 60, 471, 31));
        horizontalLayout = new QHBoxLayout(layoutWidget);
        horizontalLayout->setObjectName("horizontalLayout");
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        label_income_source = new QLabel(layoutWidget);
        label_income_source->setObjectName("label_income_source");
        label_income_source->setStyleSheet(QString::fromUtf8(""));

        horizontalLayout->addWidget(label_income_source);

        comboBox_income_source = new QComboBox(layoutWidget);
        comboBox_income_source->addItem(QString());
        comboBox_income_source->addItem(QString());
        comboBox_income_source->addItem(QString());
        comboBox_income_source->addItem(QString());
        comboBox_income_source->setObjectName("comboBox_income_source");
        comboBox_income_source->setStyleSheet(QString::fromUtf8("font: 12pt \"Segoe UI\";\n"
"border: 2px solid  white;\n"
" border-radius: 5px;\n"
"background-color: transparent;\n"
"color: white;"));

        horizontalLayout->addWidget(comboBox_income_source);

        layoutWidget1 = new QWidget(groupBox);
        layoutWidget1->setObjectName("layoutWidget1");
        layoutWidget1->setGeometry(QRect(40, 180, 471, 75));
        horizontalLayout_2 = new QHBoxLayout(layoutWidget1);
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        label_Description = new QLabel(layoutWidget1);
        label_Description->setObjectName("label_Description");

        horizontalLayout_2->addWidget(label_Description);

        textEdit_Description = new QTextEdit(layoutWidget1);
        textEdit_Description->setObjectName("textEdit_Description");
        textEdit_Description->setStyleSheet(QString::fromUtf8("font: 12pt \"Segoe UI\";\n"
"border: 2px solid  white;\n"
" border-radius: 5px;\n"
"background-color: transparent;\n"
"color: white;"));

        horizontalLayout_2->addWidget(textEdit_Description);

        pushButton_Add = new QPushButton(groupBox);
        pushButton_Add->setObjectName("pushButton_Add");
        pushButton_Add->setGeometry(QRect(390, 360, 81, 31));
        pushButton_Add->setStyleSheet(QString::fromUtf8("border: 3px solid #000000;\n"
"background-color:#000000;\n"
"border-radius: 15px;\n"
"color: white;\n"
"font: 700 10pt \"Segoe UI\";\n"
"	"));
        layoutWidget2 = new QWidget(groupBox);
        layoutWidget2->setObjectName("layoutWidget2");
        layoutWidget2->setGeometry(QRect(40, 120, 471, 31));
        horizontalLayout_4 = new QHBoxLayout(layoutWidget2);
        horizontalLayout_4->setObjectName("horizontalLayout_4");
        horizontalLayout_4->setContentsMargins(0, 0, 0, 0);
        label = new QLabel(layoutWidget2);
        label->setObjectName("label");

        horizontalLayout_4->addWidget(label);

        QDate = new QDateEdit(layoutWidget2);
        QDate->setObjectName("QDate");
        QDate->setStyleSheet(QString::fromUtf8("font: 12pt \"Segoe UI\";\n"
"border: 2px solid  white;\n"
" border-radius: 5px;\n"
"background-color: transparent;\n"
"color: white;"));

        horizontalLayout_4->addWidget(QDate);

        layoutWidget3 = new QWidget(groupBox);
        layoutWidget3->setObjectName("layoutWidget3");
        layoutWidget3->setGeometry(QRect(40, 260, 471, 51));
        horizontalLayout_3 = new QHBoxLayout(layoutWidget3);
        horizontalLayout_3->setObjectName("horizontalLayout_3");
        horizontalLayout_3->setContentsMargins(0, 0, 0, 0);
        label_Amount = new QLabel(layoutWidget3);
        label_Amount->setObjectName("label_Amount");

        horizontalLayout_3->addWidget(label_Amount);

        lineEdit_Amount = new QLineEdit(layoutWidget3);
        lineEdit_Amount->setObjectName("lineEdit_Amount");
        lineEdit_Amount->setStyleSheet(QString::fromUtf8("font: 12pt \"Segoe UI\";\n"
"border: 2px solid  white;\n"
" border-radius: 5px;\n"
"background-color: transparent;\n"
"color: white;"));

        horizontalLayout_3->addWidget(lineEdit_Amount);

        tableView = new QTableView(Incomeui);
        tableView->setObjectName("tableView");
        tableView->setGeometry(QRect(620, 130, 601, 521));
        tableView->setStyleSheet(QString::fromUtf8("QGroupBox{font: 19pt \"Segoe UI\";\n"
"color:White;\n"
"\n"
"border-radius: 15px;\n"
"\n"
"background-color: #841ebc;\n"
"border: 1px solid #a23fdf;}"));

        retranslateUi(Incomeui);

        QMetaObject::connectSlotsByName(Incomeui);
    } // setupUi

    void retranslateUi(QDialog *Incomeui)
    {
        Incomeui->setWindowTitle(QCoreApplication::translate("Incomeui", "Income", nullptr));
        pushButton_back->setText(QCoreApplication::translate("Incomeui", "Back", nullptr));
        lable->setText(QCoreApplication::translate("Incomeui", "<html><head/><body><p><span style=\" font-size:22pt;\">TextLabel</span></p></body></html>", nullptr));
        groupBox->setTitle(QCoreApplication::translate("Incomeui", " ADD YOUR INCOME", nullptr));
        label_income_source->setText(QCoreApplication::translate("Incomeui", "<html><head/><body><p><span style=\"font-size:12pt; font-weight:700; color:#ffffff;\">Income Source</span></p></body></html>", nullptr));
        comboBox_income_source->setItemText(0, QCoreApplication::translate("Incomeui", "Job", nullptr));
        comboBox_income_source->setItemText(1, QCoreApplication::translate("Incomeui", "Allowance from parents", nullptr));
        comboBox_income_source->setItemText(2, QCoreApplication::translate("Incomeui", "Scholarship", nullptr));
        comboBox_income_source->setItemText(3, QCoreApplication::translate("Incomeui", "Student Aid", nullptr));

        label_Description->setText(QCoreApplication::translate("Incomeui", "<html><head/><body><p><span style=\"font-size:12pt; font-weight:700; color:#ffffff;\">Description</span></p></body></html>", nullptr));
        pushButton_Add->setText(QCoreApplication::translate("Incomeui", "ADD", nullptr));
        label->setText(QCoreApplication::translate("Incomeui", "<html><head/><body><p><span style=\"font-size:12pt; font-weight:700; color:#ffffff;\">Date</span></p></body></html>", nullptr));
        label_Amount->setText(QCoreApplication::translate("Incomeui", "<html><head/><body><p><span style=\"font-size:12pt; font-weight:700; color:#ffffff;;\">Amount</span></p></body></html>", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Incomeui: public Ui_Incomeui {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_INCOMEUI_H
