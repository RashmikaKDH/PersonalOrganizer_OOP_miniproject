#include "AppUtils.h"
#include <QPushButton>

#include <QLabel>
#include <QTimer>
#include <QStyle>
#include <QApplication>

// This is the main function that creates, styles, and shows the message box.
void AppUtils::showMessage(QWidget *parent, const QString &title, const QString &text)
{
    // Create an instance of a standard QMessageBox
    QMessageBox msgBox(parent);

    // Set the title and text from the function arguments
    msgBox.setWindowTitle(title);
    msgBox.setText(text);

    // Set the icon
    msgBox.setIcon(QMessageBox::Information);

    // Apply your custom stylesheet
    msgBox.setStyleSheet(
        "QMessageBox {"
        "    background-color: #f1f7ed;"
        "    color: #54494b;"
        "    font: 12pt 'Segoe UI';"
        "}"
        "QLabel {"
        "    color: #54494b;"
        "}"
        "QPushButton {"
        "    background-color: #91c7b1;"
        "    color: #54494b;"
        "    border-radius: 5px;"
        "    padding: 8px;"
        "    min-width: 80px;"
        "}"
        "QPushButton:hover {"
        "    background-color: #6A79C2;"
        "}"
        );

    // Show the message box
    msgBox.exec();
}


// A simple function to show a "toast" style notification
void AppUtils::showToast(const QString& message, QWidget* parent)
{
    if (!parent) {
        return;
    }

    // Create a QLabel for the notification
    QLabel* toast = new QLabel(message, parent);
    toast->setObjectName("toast"); // Set object name for styling

    // Style the notification using stylesheets for a modern look
    toast->setStyleSheet(
        "QLabel#toast {"
        "   background-color: #336A29;"
        "   color: white;"
        "   border-radius: 15px;"
        "   padding: 10px 15px;"
        "   font-size: 14px;"
        "}"
        );

    toast->setFixedSize(toast->sizeHint()); // Adjust size to content
    toast->setAttribute(Qt::WA_DeleteOnClose); // Delete when closed

    // Center the notification at the bottom of the parent window
    int x = (parent->width() - toast->width()) / 2;
    int y = parent->height() - toast->height() - 50; // 20px from bottom
    toast->move(x, y);

    // Show the notification
    toast->show();

    // Use a QTimer to automatically close (and delete) the label after 3 seconds
    QTimer::singleShot(3000, toast, &QLabel::close);
}
//++++++Red  showtost
void AppUtils::showToastred(const QString& message, QWidget* parent)
{
    if (!parent) {
        return;
    }

    // Create a QLabel for the notification
    QLabel* toast = new QLabel(message, parent);
    toast->setObjectName("toast"); // Set object name for styling

    // Style the notification using stylesheets for a modern look
    toast->setStyleSheet(
        "QLabel#toast {"
        "   background-color: #C7080C;"
        "   color: white;"
        "   border-radius: 15px;"
        "   padding: 10px 15px;"
        "   font-size: 14px;"
        "}"
        );

    toast->setFixedSize(toast->sizeHint()); // Adjust size to content
    toast->setAttribute(Qt::WA_DeleteOnClose); // Delete when closed

    // Center the notification at the bottom of the parent window
    int x = (parent->width() - toast->width()) / 2;
    int y = parent->height() - toast->height() - 50; // 20px from bottom
    toast->move(x, y);

    // Show the notification
    toast->show();

    // Use a QTimer to automatically close (and delete) the label after 3 seconds
    QTimer::singleShot(3000, toast, &QLabel::close);
}
bool AppUtils::askQuestion(QWidget *parent, const QString &title, const QString &question)
{
    QMessageBox msgBox(parent);
    msgBox.setWindowTitle(title);
    msgBox.setText(question);
    msgBox.setIcon(QMessageBox::Question);
    // Set the buttons to Yes and No
    msgBox.setStandardButtons(QMessageBox::Yes | QMessageBox::No);
    // Set the default button to No
    msgBox.setDefaultButton(QMessageBox::No);
    msgBox.setStyleSheet(
        "QMessageBox {"
        "    background-color: #f1f7ed;"
        "    color: #54494b;"
        "    font: 12pt 'Segoe UI';"
        "}"
        "QLabel {"
        "    color: #54494b;"
        "}"
        "QPushButton {"
        "    background-color: #91c7b1;"
        "    color: #54494b;"
        "    border-radius: 5px;"
        "    padding: 8px;"
        "    min-width: 80px;"
        "}"
        "QPushButton:hover {"
        "    background-color: #6A79C2;"
        "}"
        );


    // exec() returns the button that was clicked. We check if it was the Yes button.
    if (msgBox.exec() == QMessageBox::Yes) {
        return true;
    } else {
        return false;
    }
}
