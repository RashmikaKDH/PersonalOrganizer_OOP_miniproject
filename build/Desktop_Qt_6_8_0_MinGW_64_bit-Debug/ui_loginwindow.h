/********************************************************************************
** Form generated from reading UI file 'loginwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LOGINWINDOW_H
#define UI_LOGINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_loginwindow
{
public:
    QWidget *centralwidget;
    QGroupBox *groupBox;
    QPushButton *LPushButton_login;
    QWidget *layoutWidget;
    QVBoxLayout *verticalLayout;
    QLabel *LUNLable;
    QLineEdit *lineedit_username;
    QWidget *layoutWidget1;
    QVBoxLayout *verticalLayout_2;
    QLabel *LPLable;
    QLineEdit *lineedit_password;
    QLabel *label;
    QPushButton *LPushButton_signup;
    QLabel *label_signup;
    QLabel *label_3;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *loginwindow)
    {
        if (loginwindow->objectName().isEmpty())
            loginwindow->setObjectName("loginwindow");
        loginwindow->resize(1280, 768);
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/image/image/window_icon.png"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        loginwindow->setWindowIcon(icon);
        loginwindow->setAutoFillBackground(false);
        loginwindow->setStyleSheet(QString::fromUtf8("#centralwidget{\n"
"border-image:  url(:/image/Background01.png) 0 0 0 0 stretch stretch;}"));
        centralwidget = new QWidget(loginwindow);
        centralwidget->setObjectName("centralwidget");
        groupBox = new QGroupBox(centralwidget);
        groupBox->setObjectName("groupBox");
        groupBox->setGeometry(QRect(80, 180, 421, 361));
        groupBox->setStyleSheet(QString::fromUtf8("#groupBox\n"
"{font: 19pt \"Segoe UI\";\n"
"color:White;\n"
"\n"
"border-radius: 15px;\n"
"\n"
"background-color: #841ebc;}"));
        LPushButton_login = new QPushButton(groupBox);
        LPushButton_login->setObjectName("LPushButton_login");
        LPushButton_login->setGeometry(QRect(280, 290, 101, 31));
        LPushButton_login->setStyleSheet(QString::fromUtf8("  border: 2px solid #ffffff;\n"
"font: 10pt \"Segoe UI\";\n"
"  border-radius: 15px;\n"
"color: #ffffff;"));
        layoutWidget = new QWidget(groupBox);
        layoutWidget->setObjectName("layoutWidget");
        layoutWidget->setGeometry(QRect(30, 70, 351, 61));
        verticalLayout = new QVBoxLayout(layoutWidget);
        verticalLayout->setObjectName("verticalLayout");
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        LUNLable = new QLabel(layoutWidget);
        LUNLable->setObjectName("LUNLable");
        LUNLable->setStyleSheet(QString::fromUtf8(""));

        verticalLayout->addWidget(LUNLable);

        lineedit_username = new QLineEdit(layoutWidget);
        lineedit_username->setObjectName("lineedit_username");
        lineedit_username->setStyleSheet(QString::fromUtf8("font: 12pt \"Segoe UI\";\n"
"border: 2px solid  white;\n"
" border-radius: 5px;\n"
"background-color: transparent;\n"
"color: white;"));

        verticalLayout->addWidget(lineedit_username);

        layoutWidget1 = new QWidget(groupBox);
        layoutWidget1->setObjectName("layoutWidget1");
        layoutWidget1->setGeometry(QRect(30, 180, 351, 61));
        verticalLayout_2 = new QVBoxLayout(layoutWidget1);
        verticalLayout_2->setObjectName("verticalLayout_2");
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        LPLable = new QLabel(layoutWidget1);
        LPLable->setObjectName("LPLable");
        LPLable->setMaximumSize(QSize(16777215, 16777215));
        LPLable->setStyleSheet(QString::fromUtf8("font: 16pt \"Segoe UI\";"));

        verticalLayout_2->addWidget(LPLable);

        lineedit_password = new QLineEdit(layoutWidget1);
        lineedit_password->setObjectName("lineedit_password");
        lineedit_password->setStyleSheet(QString::fromUtf8("font: 12pt \"Segoe UI\";\n"
"border: 2px solid  #ffffff;\n"
" border-radius: 5px;\n"
"background-color: transparent;\n"
"color: rgb(0, 0, 0);"));
        lineedit_password->setEchoMode(QLineEdit::EchoMode::Password);

        verticalLayout_2->addWidget(lineedit_password);

        label = new QLabel(centralwidget);
        label->setObjectName("label");
        label->setGeometry(QRect(930, 150, 271, 41));
        label->setStyleSheet(QString::fromUtf8("color: white;"));
        LPushButton_signup = new QPushButton(centralwidget);
        LPushButton_signup->setObjectName("LPushButton_signup");
        LPushButton_signup->setGeometry(QRect(290, 550, 101, 31));
        LPushButton_signup->setStyleSheet(QString::fromUtf8("border: 3px solid #3f088f;\n"
"font:  10pt \"Segoe UI\";\n"
"border-radius: 15px;\n"
"color: #3f088f;"));
        label_signup = new QLabel(centralwidget);
        label_signup->setObjectName("label_signup");
        label_signup->setGeometry(QRect(190, 550, 101, 31));
        label_signup->setStyleSheet(QString::fromUtf8("color: #E07C53;\n"
"font: 750 italic 10pt \"Segoe UI\";\n"
""));
        label_3 = new QLabel(centralwidget);
        label_3->setObjectName("label_3");
        label_3->setGeometry(QRect(500, 30, 701, 141));
        loginwindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(loginwindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 1280, 21));
        loginwindow->setMenuBar(menubar);
        statusbar = new QStatusBar(loginwindow);
        statusbar->setObjectName("statusbar");
        loginwindow->setStatusBar(statusbar);

        retranslateUi(loginwindow);

        QMetaObject::connectSlotsByName(loginwindow);
    } // setupUi

    void retranslateUi(QMainWindow *loginwindow)
    {
        loginwindow->setWindowTitle(QCoreApplication::translate("loginwindow", "loginwindow", nullptr));
        groupBox->setTitle(QCoreApplication::translate("loginwindow", " Please Login", nullptr));
        LPushButton_login->setText(QCoreApplication::translate("loginwindow", "Login", nullptr));
        LUNLable->setText(QCoreApplication::translate("loginwindow", "<html><head/><body><p><span style=\" font-size:12pt; font-weight:700; color:#ffffff;\">User Name</span></p></body></html>", nullptr));
#if QT_CONFIG(whatsthis)
        lineedit_username->setWhatsThis(QCoreApplication::translate("loginwindow", "<html><head/><body><p><br/></p></body></html>", nullptr));
#endif // QT_CONFIG(whatsthis)
        lineedit_username->setText(QString());
        LPLable->setText(QCoreApplication::translate("loginwindow", "<html><head/><body><p><span style=\" font-size:12pt; font-weight:700; color:#ffffff;\">Password </span></p></body></html>", nullptr));
        lineedit_password->setText(QString());
        label->setText(QString());
        LPushButton_signup->setText(QCoreApplication::translate("loginwindow", " SignUp", nullptr));
        label_signup->setText(QCoreApplication::translate("loginwindow", "<html><head/><body><p><span style=\" color:#3f088f;\">Not a member </span></p></body></html>", nullptr));
        label_3->setText(QCoreApplication::translate("loginwindow", "<html><head/><body><p align=\"right\"><span style=\" font-size:36pt; font-weight:700; color:#ffffff;\">WELCOME BACK</span></p><p align=\"right\"><span style=\" font-size:16pt; font-weight:700; color:#ffffff;\">PERSONAL ORGANIZER</span></p></body></html>", nullptr));
    } // retranslateUi

};

namespace Ui {
    class loginwindow: public Ui_loginwindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LOGINWINDOW_H
