#include "DatabaseManager.h"
#include <QSqlError>
#include <QCoreApplication>
#include <QDir>
#include "AppUtils.h"

DatabaseManager& DatabaseManager::instance() {
    static DatabaseManager singletonInstance;
    return singletonInstance;
}

DatabaseManager::DatabaseManager() {
    // Start from the application dir
    QDir dir(QCoreApplication::applicationDirPath());
    dir.cdUp(); // go up from /debug
    dir.cdUp(); // go up from /Desktop_Qt_...-Debug

    // Build both DB paths from the same base dir
    QString loginDbPath = dir.filePath("Db/logindatabase.db");
    QString scheduleDbPath = dir.filePath("Db/schedules.db");
    //QString loginDbPath = QDir(QCoreApplication::applicationDirPath()).filePath("Db/logindatabase.db");
   // QString scheduleDbPath = QDir(QCoreApplication::applicationDirPath()).filePath("Db/schedules.db");

    // --- Connection 1: Login Database ---
    m_db = QSqlDatabase::addDatabase("QSQLITE", "main_connection");
    m_db.setDatabaseName(loginDbPath);

    qDebug() << "Application Dir:" << QCoreApplication::applicationDirPath();
    qDebug() << "Resolved Login DB Path:" << loginDbPath;
    qDebug() << "Resolved Schedule DB Path:" << scheduleDbPath;

    if (!m_db.open()) {
        qDebug() << "Error: Failed to connect to login database." << m_db.lastError().text();
    } else {
        qDebug() << "Login database connection established successfully.";
    }

    // --- (Optional) Second connection: Schedule DB ---
    QSqlDatabase scheduleDb = QSqlDatabase::addDatabase("QSQLITE", "schedule_connection");
    scheduleDb.setDatabaseName(scheduleDbPath);

    if (!scheduleDb.open()) {
        qDebug() << "Error: Failed to connect to schedule database." << scheduleDb.lastError().text();
    } else {
        qDebug() << "Schedule database connection established successfully.";
    }
}

DatabaseManager::~DatabaseManager() {
    if (m_db.isOpen()) {
        m_db.close();
    }
    if (m_scheduleDb.isOpen()) {
        m_scheduleDb.close();
    }
}

QSqlDatabase& DatabaseManager::getDatabase() {
    return m_db;
}

QSqlDatabase& DatabaseManager::getScheduleDatabase() {
    return m_scheduleDb;
}

void DatabaseManager::close() {
    if (m_db.isOpen()) {
        QString conName = m_db.connectionName();
        m_db.close();
        QSqlDatabase::removeDatabase(conName);
        qDebug() << "Database connection close";
    }
}
