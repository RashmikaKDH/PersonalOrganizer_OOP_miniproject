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
/*
    // Source folder (project root Db folder)
    QString srcPath = QDir(PROJECT_ROOT_PATH).filePath("Db");
    //QString srcPath = QDir(QCoreApplication::applicationDirPath()).filePath("../../Db");
    QString destPath = QDir(QCoreApplication::applicationDirPath()).filePath("Db");

    // Ensure destination folder exists
    QDir().mkpath(destPath);

    // List of database files
    QStringList dbFiles = {"logindatabase.db", "schedules.db"};

    for (const QString &dbFile : dbFiles) {
        QString srcFile = QDir(srcPath).filePath(dbFile);
        QString destFile = QDir(destPath).filePath(dbFile);

        // Only copy if the file doesn't already exist
        if (!QFile::exists(destFile)) {
            if (!QFile::copy(srcFile, destFile))
                qDebug() << "Failed to copy" << srcFile << "to" << destFile;
            else
                qDebug() << "Copied" << srcFile << "to" << destFile;
        } else {
            qDebug() << destFile << "already exists, skipping copy.";
        }
    }*/

    QString loginDbPath = QDir(PROJECT_ROOT_PATH).filePath("Db/logindatabase.db");
    QString scheduleDbPath = QDir(PROJECT_ROOT_PATH).filePath("Db/schedules.db");

   // QString loginDbPath = QDir(QCoreApplication::applicationDirPath()).filePath("Db/logindatabase.db");
  //  QString scheduleDbPath = QDir(QCoreApplication::applicationDirPath()).filePath("Db/schedules.db");

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
    m_scheduleDb =QSqlDatabase::addDatabase("QSQLITE", "schedule_connection");
    m_scheduleDb.setDatabaseName(scheduleDbPath);

    if (!m_scheduleDb.open()) {
        qDebug() << "Error: Failed to connect to schedule database." << m_scheduleDb.lastError().text();
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
