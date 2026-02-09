#include "database.h"
#include <QSqlQuery>
#include <QSqlError>
#include <QDebug>

DatabaseManager::DatabaseManager(QObject *parent) : QObject(parent) {}

void DatabaseManager::init() {
    m_db = QSqlDatabase::addDatabase("QSQLITE");
    m_db.setDatabaseName("ev_cluster.db");
    if (!m_db.open()) {
        qCritical() << "Error opening database:" << m_db.lastError();
    }
}
