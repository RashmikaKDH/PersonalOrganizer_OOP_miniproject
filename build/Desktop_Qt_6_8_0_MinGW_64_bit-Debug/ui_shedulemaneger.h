/********************************************************************************
** Form generated from reading UI file 'shedulemaneger.ui'
**
** Created by: Qt User Interface Compiler version 6.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SHEDULEMANEGER_H
#define UI_SHEDULEMANEGER_H

#include <QtCore/QDate>
#include <QtCore/QLocale>
#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDateTimeEdit>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QTimeEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_shedulemaneger
{
public:
    QWidget *centralwidget;
    QTableWidget *scheduleTable;
    QLabel *lable;
    QGroupBox *groupBox;
    QPushButton *addButton;
    QWidget *layoutWidget;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QLineEdit *nameEdit;
    QWidget *layoutWidget1;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_2;
    QTimeEdit *timeEdit;
    QWidget *layoutWidget2;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_3;
    QDateTimeEdit *deadlineEdit;
    QPushButton *deleteSheduleButton;
    QPushButton *deleteSheduleButton_2;
    QPushButton *pushButton_backto;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *shedulemaneger)
    {
        if (shedulemaneger->objectName().isEmpty())
            shedulemaneger->setObjectName("shedulemaneger");
        shedulemaneger->resize(1080, 667);
        shedulemaneger->setStyleSheet(QString::fromUtf8(" #centralwidget{border-image: url(:/image/image/Background15.jpg) 0 0 0 0 stretch stretch;}\n"
""));
        centralwidget = new QWidget(shedulemaneger);
        centralwidget->setObjectName("centralwidget");
        scheduleTable = new QTableWidget(centralwidget);
        if (scheduleTable->columnCount() < 3)
            scheduleTable->setColumnCount(3);
        QFont font;
        font.setBold(false);
        font.setStrikeOut(false);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        __qtablewidgetitem->setTextAlignment(Qt::AlignHCenter|Qt::AlignBottom);
        __qtablewidgetitem->setFont(font);
        scheduleTable->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        scheduleTable->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        scheduleTable->setHorizontalHeaderItem(2, __qtablewidgetitem2);
        scheduleTable->setObjectName("scheduleTable");
        scheduleTable->setGeometry(QRect(40, 90, 541, 401));
        QSizePolicy sizePolicy(QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(scheduleTable->sizePolicy().hasHeightForWidth());
        scheduleTable->setSizePolicy(sizePolicy);
        scheduleTable->setStyleSheet(QString::fromUtf8("background: rgb(255, 255, 255);\n"
"border-radius: 16px;\n"
"border: 1px solid rgba(0, 0, 0, 1);\n"
"\n"
"/* Styling for the headers */\n"
"QHeaderView::section {\n"
"    background-color: rgba(0, 0, 0, 0.77); /* Green background for headers */\n"
"    color: white; /* White text for headers */\n"
"    padding: 5px;\n"
"    border: 1px solid #ddd; /* Divider color */\n"
"    font-weight: bold;\n"
"    text-align: center;\n"
"	border-radius: 16px\n"
"}\n"
"\n"
"/* Alternating row colors */\n"
"QTableWidget::item:!selected {\n"
"    /* From https://css.glass */\n"
"background: rgba(76, 0, 101, 0.45);\n"
"border-radius: 16px;\n"
"border: 1px solid rgba(76, 0, 101, 0.45);\n"
"}\n"
"QTableWidget::item:!selected:nth-child(even) {\n"
"    background-color: #f2f2f2; /* Light gray background for alternating rows */\n"
"}\n"
"\n"
"/* Highlight selected rows */\n"
"QTableWidget::item:selected {\n"
"    background-color: #ffcc80; /* Orange background for selected rows */\n"
"    color: red; /* Black text for better contra"
                        "st */\n"
"}\n"
"\n"
"/* Hover effect for cells */\n"
"QTableWidget::item:hover {\n"
"    background-color: #ffeb99; /* Yellow background on hover */\n"
"    color: black; /* Black text on hover */\n"
"}\n"
"\n"
"/* Vertical and horizontal scrollbars */\n"
"QScrollBar:vertical {\n"
"    background-color: #f2f2f2;\n"
"    width: 10px;\n"
"    border: none;\n"
"}\n"
"QScrollBar::handle:vertical {\n"
"    background-color: #4CAF50; /* Green scrollbar handle */\n"
"    border-radius: 5px;\n"
"    min-height: 20px;\n"
"}\n"
"QScrollBar::add-line:vertical, QScrollBar::sub-line:vertical {\n"
"    background: none; /* Remove buttons on scrollbars */\n"
"}\n"
"\n"
"QScrollBar:horizontal {\n"
"    background-color: #f2f2f2;\n"
"    height: 10px;\n"
"    border: none;\n"
"}\n"
"QScrollBar::handle:horizontal {\n"
"    background-color: #4CAF50; /* Green scrollbar handle */\n"
"    border-radius: 5px;\n"
"    min-width: 20px;\n"
"}\n"
"QScrollBar::add-line:horizontal, QScrollBar::sub-line:horizontal {\n"
"    background: no"
                        "ne;\n"
"}\n"
"\n"
"/* Table corner button (top-left corner) */\n"
"QTableCornerButton::section {\n"
"    background-color: #4CAF50; /* Green corner background */\n"
"    border: 1px solid #ddd;\n"
"}\n"
"\n"
""));
        scheduleTable->setAlternatingRowColors(false);
        scheduleTable->setVerticalScrollMode(QAbstractItemView::ScrollMode::ScrollPerItem);
        scheduleTable->setColumnCount(3);
        scheduleTable->horizontalHeader()->setVisible(true);
        scheduleTable->horizontalHeader()->setCascadingSectionResizes(true);
        scheduleTable->horizontalHeader()->setMinimumSectionSize(35);
        scheduleTable->horizontalHeader()->setDefaultSectionSize(150);
        scheduleTable->horizontalHeader()->setHighlightSections(true);
        scheduleTable->horizontalHeader()->setProperty("showSortIndicator", QVariant(false));
        scheduleTable->horizontalHeader()->setStretchLastSection(true);
        scheduleTable->verticalHeader()->setCascadingSectionResizes(true);
        scheduleTable->verticalHeader()->setStretchLastSection(false);
        lable = new QLabel(centralwidget);
        lable->setObjectName("lable");
        lable->setGeometry(QRect(60, 530, 511, 41));
        lable->setStyleSheet(QString::fromUtf8("  border: 1px solid #ff99cc;\n"
"  border-radius: 10px;\n"
"color: #ff68cc;\n"
"\n"
""));
        groupBox = new QGroupBox(centralwidget);
        groupBox->setObjectName("groupBox");
        groupBox->setGeometry(QRect(620, 90, 431, 391));
        groupBox->setStyleSheet(QString::fromUtf8("#groupBox{\n"
"color: rgb(255, 255, 255);\n"
"font: 900 16pt \"Segoe UI Black\";\n"
"/* From https://css.glass */\n"
"background: rgba(138, 174, 181, 0.2);\n"
"\n"
"border: 1px solid rgba(138, 174, 181, 0.3);\n"
"}"));
        addButton = new QPushButton(groupBox);
        addButton->setObjectName("addButton");
        addButton->setGeometry(QRect(320, 300, 91, 31));
        addButton->setStyleSheet(QString::fromUtf8("border: 2px solid #DEC8AC;\n"
"font: 700 10pt \"Segoe UI\";\n"
"border-radius: 15px;\n"
"color: #DEC8AC;"));
        layoutWidget = new QWidget(groupBox);
        layoutWidget->setObjectName("layoutWidget");
        layoutWidget->setGeometry(QRect(10, 70, 411, 41));
        horizontalLayout = new QHBoxLayout(layoutWidget);
        horizontalLayout->setObjectName("horizontalLayout");
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        label = new QLabel(layoutWidget);
        label->setObjectName("label");

        horizontalLayout->addWidget(label);

        nameEdit = new QLineEdit(layoutWidget);
        nameEdit->setObjectName("nameEdit");
        nameEdit->setStyleSheet(QString::fromUtf8("background: rgba(255, 255, 255, 0.15);\n"
"border-radius: 16px;\n"
"\n"
"border: 1px solid rgba(255, 255, 255, 0.11);"));

        horizontalLayout->addWidget(nameEdit);

        layoutWidget1 = new QWidget(groupBox);
        layoutWidget1->setObjectName("layoutWidget1");
        layoutWidget1->setGeometry(QRect(10, 130, 411, 41));
        horizontalLayout_2 = new QHBoxLayout(layoutWidget1);
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        label_2 = new QLabel(layoutWidget1);
        label_2->setObjectName("label_2");

        horizontalLayout_2->addWidget(label_2);

        timeEdit = new QTimeEdit(layoutWidget1);
        timeEdit->setObjectName("timeEdit");
        timeEdit->setStyleSheet(QString::fromUtf8("background: rgba(255, 255, 255, 0.15);\n"
"\n"
""));
        timeEdit->setWrapping(false);
        timeEdit->setDateTime(QDateTime(QDate(2000, 1, 1), QTime(0, 0, 0)));
        timeEdit->setTimeSpec(Qt::TimeSpec::LocalTime);

        horizontalLayout_2->addWidget(timeEdit);

        layoutWidget2 = new QWidget(groupBox);
        layoutWidget2->setObjectName("layoutWidget2");
        layoutWidget2->setGeometry(QRect(10, 200, 411, 41));
        horizontalLayout_3 = new QHBoxLayout(layoutWidget2);
        horizontalLayout_3->setObjectName("horizontalLayout_3");
        horizontalLayout_3->setContentsMargins(0, 0, 0, 0);
        label_3 = new QLabel(layoutWidget2);
        label_3->setObjectName("label_3");

        horizontalLayout_3->addWidget(label_3);

        deadlineEdit = new QDateTimeEdit(layoutWidget2);
        deadlineEdit->setObjectName("deadlineEdit");
        deadlineEdit->setStyleSheet(QString::fromUtf8("background: rgba(255, 255, 255, 0.15);\n"
""));
        deadlineEdit->setLocale(QLocale(QLocale::English, QLocale::UnitedStates));
        deadlineEdit->setDate(QDate(2025, 1, 1));
        deadlineEdit->setCalendarPopup(true);
        deadlineEdit->setCurrentSectionIndex(0);
        deadlineEdit->setTimeSpec(Qt::TimeSpec::LocalTime);

        horizontalLayout_3->addWidget(deadlineEdit);

        deleteSheduleButton = new QPushButton(groupBox);
        deleteSheduleButton->setObjectName("deleteSheduleButton");
        deleteSheduleButton->setGeometry(QRect(180, 300, 111, 31));
        deleteSheduleButton->setStyleSheet(QString::fromUtf8("border: 2px solid #DEC8AC;\n"
"font: 700 10pt \"Segoe UI\";\n"
"border-radius: 15px;\n"
"color: #DEC8AC;"));
        deleteSheduleButton_2 = new QPushButton(groupBox);
        deleteSheduleButton_2->setObjectName("deleteSheduleButton_2");
        deleteSheduleButton_2->setGeometry(QRect(30, 300, 111, 31));
        deleteSheduleButton_2->setStyleSheet(QString::fromUtf8("border: 2px solid #DEC8AC;\n"
"font: 700 10pt \"Segoe UI\";\n"
"border-radius: 15px;\n"
"color: #DEC8AC;"));
        pushButton_backto = new QPushButton(centralwidget);
        pushButton_backto->setObjectName("pushButton_backto");
        pushButton_backto->setGeometry(QRect(850, 520, 81, 31));
        pushButton_backto->setContextMenuPolicy(Qt::ContextMenuPolicy::DefaultContextMenu);
        pushButton_backto->setStyleSheet(QString::fromUtf8("border: 2px solid #DEC8AC;\n"
"font: 700 10pt \"Segoe UI\";\n"
"border-radius: 15px;\n"
"color: #DEC8AC;"));
        shedulemaneger->setCentralWidget(centralwidget);
        menubar = new QMenuBar(shedulemaneger);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 1080, 22));
        shedulemaneger->setMenuBar(menubar);
        statusbar = new QStatusBar(shedulemaneger);
        statusbar->setObjectName("statusbar");
        shedulemaneger->setStatusBar(statusbar);

        retranslateUi(shedulemaneger);

        QMetaObject::connectSlotsByName(shedulemaneger);
    } // setupUi

    void retranslateUi(QMainWindow *shedulemaneger)
    {
        shedulemaneger->setWindowTitle(QCoreApplication::translate("shedulemaneger", "MainWindow", nullptr));
        QTableWidgetItem *___qtablewidgetitem = scheduleTable->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QCoreApplication::translate("shedulemaneger", "Neame Of Lectur / Event", nullptr));
        QTableWidgetItem *___qtablewidgetitem1 = scheduleTable->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QCoreApplication::translate("shedulemaneger", "Start Time", nullptr));
        QTableWidgetItem *___qtablewidgetitem2 = scheduleTable->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QCoreApplication::translate("shedulemaneger", "Deadline / End Time", nullptr));
        lable->setText(QCoreApplication::translate("shedulemaneger", "TextLabel", nullptr));
        groupBox->setTitle(QCoreApplication::translate("shedulemaneger", "Manage Your Shedules", nullptr));
        addButton->setText(QCoreApplication::translate("shedulemaneger", "Add shedule", nullptr));
        label->setText(QCoreApplication::translate("shedulemaneger", "<html><head/><body><p><span style=\" font-weight:700; color:#ffffff;\">Name of letcure / Event</span></p></body></html>", nullptr));
        label_2->setText(QCoreApplication::translate("shedulemaneger", "<html><head/><body><p><span style=\" color:#ffffff;\">Start Time</span></p></body></html>", nullptr));
        label_3->setText(QCoreApplication::translate("shedulemaneger", "<html><head/><body><p><span style=\" font-weight:700; color:#ffffff;\">Deadline / End Time</span></p></body></html>", nullptr));
        deleteSheduleButton->setText(QCoreApplication::translate("shedulemaneger", "Delete shedule", nullptr));
        deleteSheduleButton_2->setText(QCoreApplication::translate("shedulemaneger", "Update shedule", nullptr));
#if QT_CONFIG(accessibility)
        pushButton_backto->setAccessibleName(QString());
#endif // QT_CONFIG(accessibility)
        pushButton_backto->setText(QCoreApplication::translate("shedulemaneger", "Back", nullptr));
    } // retranslateUi

};

namespace Ui {
    class shedulemaneger: public Ui_shedulemaneger {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SHEDULEMANEGER_H
