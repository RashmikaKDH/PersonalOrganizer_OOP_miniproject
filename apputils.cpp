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
        "    background-color: #2E2F30;"
        "    color: #FFFFFF;"
        "    font: 12pt 'Segoe UI';"
        "}"
        "QLabel {"
        "    color: #FFFFFF;"
        "}"
        "QPushButton {"
        "    background-color: #5564ac;"
        "    color: white;"
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
        "   background-color: #333;"
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
    int y = parent->height() - toast->height() - 20; // 20px from bottom
    toast->move(x, y);

    // Show the notification
    toast->show();

    // Use a QTimer to automatically close (and delete) the label after 3 seconds
    QTimer::singleShot(3000, toast, &QLabel::close);
}
