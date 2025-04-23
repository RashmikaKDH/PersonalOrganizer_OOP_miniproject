/********************************************************************************
** Form generated from reading UI file 'financialreports.ui'
**
** Created by: Qt User Interface Compiler version 6.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FINANCIALREPORTS_H
#define UI_FINANCIALREPORTS_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDateEdit>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_financialreports
{
public:
    QGroupBox *groupBox;
    QPushButton *genaratepushButton;
    QWidget *layoutWidget;
    QHBoxLayout *horizontalLayout;
    QLabel *chosemonthyearlabel;
    QDateEdit *reportdateEdit;
    QWidget *layoutWidget1;
    QVBoxLayout *verticalLayout;
    QLabel *totalincomelabel;
    QLabel *totalexpenselabel;
    QLabel *savinglabel;
    QLabel *lable;
    QPushButton *pushButton;
    QLabel *label;

    void setupUi(QDialog *financialreports)
    {
        if (financialreports->objectName().isEmpty())
            financialreports->setObjectName("financialreports");
        financialreports->resize(1080, 667);
        financialreports->setStyleSheet(QString::fromUtf8("#financialreports{  border-image: url(:/image/image/Background15.jpg) 0 0 0 0 stretch stretch;}\n"
""));
        groupBox = new QGroupBox(financialreports);
        groupBox->setObjectName("groupBox");
        groupBox->setGeometry(QRect(280, 120, 531, 391));
        groupBox->setStyleSheet(QString::fromUtf8("#groupBox{\n"
"background: rgba(255, 255, 255, 0.15);\n"
"border-radius: 16px;\n"
"box-shadow: 0 4px 30px rgba(0, 0, 0, 0.1);\n"
"backdrop-filter: blur(13.1px);\n"
"-webkit-backdrop-filter: blur(13.1px);\n"
"border: 1px solid rgba(255, 255, 255, 0.11);\n"
"}"));
        genaratepushButton = new QPushButton(groupBox);
        genaratepushButton->setObjectName("genaratepushButton");
        genaratepushButton->setGeometry(QRect(230, 120, 71, 31));
        genaratepushButton->setStyleSheet(QString::fromUtf8("border: 2px solid #DEC8AC;\n"
"font: 700 10pt \"Segoe UI\";\n"
"border-radius: 15px;\n"
"color: #DEC8AC;"));
        layoutWidget = new QWidget(groupBox);
        layoutWidget->setObjectName("layoutWidget");
        layoutWidget->setGeometry(QRect(10, 40, 511, 61));
        horizontalLayout = new QHBoxLayout(layoutWidget);
        horizontalLayout->setObjectName("horizontalLayout");
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        chosemonthyearlabel = new QLabel(layoutWidget);
        chosemonthyearlabel->setObjectName("chosemonthyearlabel");

        horizontalLayout->addWidget(chosemonthyearlabel);

        reportdateEdit = new QDateEdit(layoutWidget);
        reportdateEdit->setObjectName("reportdateEdit");
        reportdateEdit->setInputMethodHints(Qt::InputMethodHint::ImhPreferNumbers);

        horizontalLayout->addWidget(reportdateEdit);

        layoutWidget1 = new QWidget(groupBox);
        layoutWidget1->setObjectName("layoutWidget1");
        layoutWidget1->setGeometry(QRect(10, 180, 511, 151));
        verticalLayout = new QVBoxLayout(layoutWidget1);
        verticalLayout->setObjectName("verticalLayout");
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        totalincomelabel = new QLabel(layoutWidget1);
        totalincomelabel->setObjectName("totalincomelabel");

        verticalLayout->addWidget(totalincomelabel);

        totalexpenselabel = new QLabel(layoutWidget1);
        totalexpenselabel->setObjectName("totalexpenselabel");

        verticalLayout->addWidget(totalexpenselabel);

        savinglabel = new QLabel(layoutWidget1);
        savinglabel->setObjectName("savinglabel");

        verticalLayout->addWidget(savinglabel);

        lable = new QLabel(financialreports);
        lable->setObjectName("lable");
        lable->setGeometry(QRect(330, 530, 281, 31));
        pushButton = new QPushButton(financialreports);
        pushButton->setObjectName("pushButton");
        pushButton->setGeometry(QRect(690, 530, 81, 31));
        pushButton->setStyleSheet(QString::fromUtf8("border: 2px solid #DEC8AC;\n"
"font: 700 10pt \"Segoe UI\";\n"
"border-radius: 15px;\n"
"color: #DEC8AC;"));
        label = new QLabel(financialreports);
        label->setObjectName("label");
        label->setGeometry(QRect(390, 30, 271, 61));

        retranslateUi(financialreports);

        QMetaObject::connectSlotsByName(financialreports);
    } // setupUi

    void retranslateUi(QDialog *financialreports)
    {
        financialreports->setWindowTitle(QCoreApplication::translate("financialreports", "Dialog", nullptr));
        groupBox->setTitle(QString());
        genaratepushButton->setText(QCoreApplication::translate("financialreports", "Genarate ", nullptr));
        chosemonthyearlabel->setText(QCoreApplication::translate("financialreports", "<html><head/><body><p><span style=\" font-size:14pt;\">Chose Month And Year</span></p></body></html>", nullptr));
        reportdateEdit->setDisplayFormat(QCoreApplication::translate("financialreports", "M/yyyy", nullptr));
        totalincomelabel->setText(QCoreApplication::translate("financialreports", "<html><head/><body><p><span style=\" font-size:14pt;\">Your total income</span></p></body></html>", nullptr));
        totalexpenselabel->setText(QCoreApplication::translate("financialreports", "<html><head/><body><p><span style=\" font-size:14pt;\">Your total expense</span></p></body></html>", nullptr));
        savinglabel->setText(QCoreApplication::translate("financialreports", "<html><head/><body><p><span style=\" font-size:14pt;\">Your Monthly savings</span></p></body></html>", nullptr));
        lable->setText(QCoreApplication::translate("financialreports", "TextLabel", nullptr));
        pushButton->setText(QCoreApplication::translate("financialreports", "Back", nullptr));
        label->setText(QCoreApplication::translate("financialreports", "<html><head/><body><p><span style=\" font-size:24pt; font-weight:700; font-style:italic; color:#1e2c47;\">Financial Report</span></p></body></html>", nullptr));
    } // retranslateUi

};

namespace Ui {
    class financialreports: public Ui_financialreports {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FINANCIALREPORTS_H
