#ifndef DATABASEMANAGER_H
#define DATABASEMANAGER_H

#include <QSqlDatabase>
#include <QString>
#include <QDebug>

class DatabaseManager {
public:
    // Static method to get the single instance of the class
    static DatabaseManager& instance();

    // Public method to get a reference to the database object
    QSqlDatabase& getDatabase();
    QSqlDatabase& getScheduleDatabase();

    // Method to close the connection
    void close();

private:
    // Private constructor to prevent direct instantiation
    DatabaseManager();
    // Private destructor
    ~DatabaseManager();

    // Delete copy constructor and assignment operator
    DatabaseManager(const DatabaseManager&) = delete;
    DatabaseManager& operator=(const DatabaseManager&) = delete;

    QSqlDatabase m_db; // The single database instance
    QSqlDatabase m_scheduleDb;
};

#endif // DATABASEMANAGER_H
