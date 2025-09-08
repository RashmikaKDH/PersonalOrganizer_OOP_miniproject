#ifndef APPUTILS_H
#define APPUTILS_H

#include <QMessageBox>
#include <QWidget>

// A utility class for common helper functions used across the application.
class AppUtils
{
public:
    // Displays a consistently styled message box.
    static void showMessage(QWidget *parent, const QString &title, const QString &text);
    static void showToast(const QString& message, QWidget* parent);

    // You can add more static utility functions here later!
    // For example:
    // static bool isValidEmail(const QString &email);
    // static void applyStandardButtonStyle(QPushButton *button);

private:
    // Private constructor to ensure this class is never instantiated.
    AppUtils() {}
};

#endif // APPUTILS_H
