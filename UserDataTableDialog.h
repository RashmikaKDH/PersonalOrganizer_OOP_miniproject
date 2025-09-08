#ifndef USERDATATABLEDIALOG_H
#define USERDATATABLEDIALOG_H

#include <QDialog>
#include <QDebug>
#include <QSqlTableModel>
#include <QTableView>
#include "DatabaseManager.h"
#include "loginwindow.h" // For globalUsername

class UserDataTableDialog : public QDialog {
public:
    explicit UserDataTableDialog(QWidget *parent = nullptr) : QDialog(parent), m_tableModel(nullptr) {}

protected:
    // Subclasses must implement these to provide their specific widgets and table names
    virtual QTableView* getTableView() const = 0;
    virtual QString getTableName() const = 0;

    void refreshTable() {
        if (!m_tableModel) {
            m_tableModel = new QSqlTableModel(this, DatabaseManager::instance().getDatabase());
        }
        m_tableModel->setTable(getTableName());
        m_tableModel->setFilter(QString("username = '%1'").arg(globalUsername));
        m_tableModel->select();
        getTableView()->setModel(m_tableModel);
        getTableView()->show();
    }

private:
    QSqlTableModel *m_tableModel;
};

#endif // USERDATATABLEDIALOG_H
