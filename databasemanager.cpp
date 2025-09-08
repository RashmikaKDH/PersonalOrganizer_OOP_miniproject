#include "DatabaseManager.h"
#include <QSqlError>

DatabaseManager& DatabaseManager::instance() {
    static DatabaseManager singletonInstance;
    return singletonInstance;
}

DatabaseManager::DatabaseManager() {
    m_db = QSqlDatabase::addDatabase("QSQLITE", "main_connection");
    m_db.setDatabaseName("C:/Users/Rashmika97/Music/PersonalOrganizerOOP/Db/logindatabase.db");

    if (!m_db.open()) {
        qDebug() << "Error: Failed to connect to database." << m_db.lastError().text();
    } else {
        qDebug() << "Database connection established successfully.";
    }

    // --- Connection 2: Schedule Database ---
    m_scheduleDb = QSqlDatabase::addDatabase("QSQLITE", "schedule_connection");
    m_scheduleDb.setDatabaseName("C:/Users/Rashmika97/Music/PersonalOrganizerOOP/Db/schedules.db");

    if (!m_scheduleDb.open()) {
        qDebug() << "Error: Failed to connect to schedule database:" << m_scheduleDb.lastError().text();
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
