/********************************************************************************
** Form generated from reading UI file 'signup.ui'
**
** Created by: Qt User Interface Compiler version 6.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SIGNUP_H
#define UI_SIGNUP_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_signup
{
public:
    QGroupBox *groupBox_register;
    QWidget *layoutWidget;
    QVBoxLayout *verticalLayout_2;
    QLabel *label_register_password;
    QLineEdit *lineedit_register_password;
    QWidget *layoutWidget_2;
    QVBoxLayout *verticalLayout_3;
    QLabel *label_register_email;
    QLineEdit *lineedit_register_email;
    QWidget *layoutWidget_3;
    QVBoxLayout *verticalLayout_4;
    QLabel *label_register_phone;
    QLineEdit *lineedit_register_phone;
    QPushButton *pushButton_register;
    QWidget *layoutWidget1;
    QVBoxLayout *verticalLayout;
    QLabel *label_register_username;
    QLineEdit *lineedit_register_username;
    QLabel *label;
    QPushButton *pushButton_back;

    void setupUi(QDialog *signup)
    {
        if (signup->objectName().isEmpty())
            signup->setObjectName("signup");
        signup->resize(1280, 768);
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/image/image/window_icon.png"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        signup->setWindowIcon(icon);
        signup->setStyleSheet(QString::fromUtf8("#signup{\n"
"\n"
"border-image:  url(:/image/Background03.png) 0 0 0 0 stretch stretch;}\n"
"\n"
""));
        groupBox_register = new QGroupBox(signup);
        groupBox_register->setObjectName("groupBox_register");
        groupBox_register->setGeometry(QRect(440, 160, 401, 491));
        groupBox_register->setStyleSheet(QString::fromUtf8("#groupBox_register{font: 19pt \"Segoe UI\";\n"
"color:White;\n"
"\n"
"border-radius: 15px;\n"
"\n"
"background-color: #841ebc;\n"
"border: 1px solid #a23fdf;}"));
        layoutWidget = new QWidget(groupBox_register);
        layoutWidget->setObjectName("layoutWidget");
        layoutWidget->setGeometry(QRect(60, 160, 281, 58));
        verticalLayout_2 = new QVBoxLayout(layoutWidget);
        verticalLayout_2->setObjectName("verticalLayout_2");
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        label_register_password = new QLabel(layoutWidget);
        label_register_password->setObjectName("label_register_password");

        verticalLayout_2->addWidget(label_register_password);

        lineedit_register_password = new QLineEdit(layoutWidget);
        lineedit_register_password->setObjectName("lineedit_register_password");
        lineedit_register_password->setStyleSheet(QString::fromUtf8("font: 12pt \"Segoe UI\";\n"
"border: 2px solid  white;\n"
" border-radius: 5px;\n"
"background-color: transparent;\n"
"color: white;"));
        lineedit_register_password->setEchoMode(QLineEdit::EchoMode::Password);

        verticalLayout_2->addWidget(lineedit_register_password);

        layoutWidget_2 = new QWidget(groupBox_register);
        layoutWidget_2->setObjectName("layoutWidget_2");
        layoutWidget_2->setGeometry(QRect(60, 240, 281, 58));
        verticalLayout_3 = new QVBoxLayout(layoutWidget_2);
        verticalLayout_3->setObjectName("verticalLayout_3");
        verticalLayout_3->setContentsMargins(0, 0, 0, 0);
        label_register_email = new QLabel(layoutWidget_2);
        label_register_email->setObjectName("label_register_email");

        verticalLayout_3->addWidget(label_register_email);

        lineedit_register_email = new QLineEdit(layoutWidget_2);
        lineedit_register_email->setObjectName("lineedit_register_email");
        lineedit_register_email->setStyleSheet(QString::fromUtf8("font: 12pt \"Segoe UI\";\n"
"border: 2px solid  white;\n"
" border-radius: 5px;\n"
"background-color: transparent;\n"
"color: white;"));

        verticalLayout_3->addWidget(lineedit_register_email);

        layoutWidget_3 = new QWidget(groupBox_register);
        layoutWidget_3->setObjectName("layoutWidget_3");
        layoutWidget_3->setGeometry(QRect(60, 330, 281, 58));
        verticalLayout_4 = new QVBoxLayout(layoutWidget_3);
        verticalLayout_4->setObjectName("verticalLayout_4");
        verticalLayout_4->setContentsMargins(0, 0, 0, 0);
        label_register_phone = new QLabel(layoutWidget_3);
        label_register_phone->setObjectName("label_register_phone");

        verticalLayout_4->addWidget(label_register_phone);

        lineedit_register_phone = new QLineEdit(layoutWidget_3);
        lineedit_register_phone->setObjectName("lineedit_register_phone");
        lineedit_register_phone->setStyleSheet(QString::fromUtf8("font: 12pt \"Segoe UI\";\n"
"border: 2px solid  white;\n"
" border-radius: 5px;\n"
"background-color: transparent;\n"
"color: white;"));

        verticalLayout_4->addWidget(lineedit_register_phone);

        pushButton_register = new QPushButton(groupBox_register);
        pushButton_register->setObjectName("pushButton_register");
        pushButton_register->setGeometry(QRect(170, 430, 71, 31));
        pushButton_register->setStyleSheet(QString::fromUtf8("  border: 2px solid #ffffff;\n"
"font: 10pt \"Segoe UI\";\n"
"  border-radius: 15px;\n"
"color: #ffffff;"));
        layoutWidget1 = new QWidget(groupBox_register);
        layoutWidget1->setObjectName("layoutWidget1");
        layoutWidget1->setGeometry(QRect(60, 70, 281, 58));
        verticalLayout = new QVBoxLayout(layoutWidget1);
        verticalLayout->setObjectName("verticalLayout");
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        label_register_username = new QLabel(layoutWidget1);
        label_register_username->setObjectName("label_register_username");

        verticalLayout->addWidget(label_register_username);

        lineedit_register_username = new QLineEdit(layoutWidget1);
        lineedit_register_username->setObjectName("lineedit_register_username");
        lineedit_register_username->setStyleSheet(QString::fromUtf8("font: 12pt \"Segoe UI\";\n"
"border: 2px solid  white;\n"
" border-radius: 5px;\n"
"background-color: transparent;\n"
"color: white;"));

        verticalLayout->addWidget(lineedit_register_username);

        label = new QLabel(signup);
        label->setObjectName("label");
        label->setGeometry(QRect(400, 80, 481, 41));
        label->setStyleSheet(QString::fromUtf8("  border: 1px solid #ff99cc;\n"
"  border-radius: 10px;\n"
"color: #ff99cc;"));
        pushButton_back = new QPushButton(signup);
        pushButton_back->setObjectName("pushButton_back");
        pushButton_back->setGeometry(QRect(1160, 710, 81, 31));
        pushButton_back->setStyleSheet(QString::fromUtf8("border: 3px solid #000000;\n"
"background-color:#000000;\n"
"border-radius: 15px;\n"
"color: white;\n"
"font: 700 10pt \"Segoe UI\";\n"
"	"));

        retranslateUi(signup);

        QMetaObject::connectSlotsByName(signup);
    } // setupUi

    void retranslateUi(QDialog *signup)
    {
        signup->setWindowTitle(QCoreApplication::translate("signup", "SingUp", nullptr));
        groupBox_register->setTitle(QCoreApplication::translate("signup", " Please Register", nullptr));
        label_register_password->setText(QCoreApplication::translate("signup", "<html><head/><body><p><span style=\" font-size:12pt; font-weight:700; color:#ffffff;\">Password</span></p></body></html>", nullptr));
        label_register_email->setText(QCoreApplication::translate("signup", "<html><head/><body><p><span style=\" font-size:12pt; font-weight:700; color:#ffffff;\">Email</span></p></body></html>", nullptr));
        label_register_phone->setText(QCoreApplication::translate("signup", "<html><head/><body><p><span style=\" font-size:12pt; font-weight:700; color:#ffffff;\">Phone</span></p></body></html>", nullptr));
        pushButton_register->setText(QCoreApplication::translate("signup", "Register", nullptr));
        label_register_username->setText(QCoreApplication::translate("signup", "<html><head/><body><p><span style=\" font-size:12pt; font-weight:700; color:#ffffff;\">UserName</span></p></body></html>", nullptr));
        label->setText(QString());
        pushButton_back->setText(QCoreApplication::translate("signup", "Back", nullptr));
    } // retranslateUi

};

namespace Ui {
    class signup: public Ui_signup {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SIGNUP_H
