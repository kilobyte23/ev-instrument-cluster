#include "database.h"
#include <QSqlQuery>
#include <QSqlError>
#include <QDebug>
#include <QVariant>
#include <QStandardPaths>
#include <QDir>

DatabaseManager::DatabaseManager(QObject *parent) 
    : QObject(parent),
      m_isInitialized(false)
{
}

bool DatabaseManager::init()
{
    // Use application data directory
    QString dataPath = QStandardPaths::writableLocation(QStandardPaths::AppDataLocation);
    QDir().mkpath(dataPath);
    
    QString dbPath = dataPath + "/ev_cluster.db";
    
    m_db = QSqlDatabase::addDatabase("QSQLITE");
    m_db.setDatabaseName(dbPath);
    
    if (!m_db.open()) {
        qCritical() << "Error opening database:" << m_db.lastError().text();
        return false;
    }
    
    qDebug() << "Database opened successfully at:" << dbPath;
    
    m_isInitialized = createTables();
    return m_isInitialized;
}

bool DatabaseManager::createTables()
{
    QSqlQuery query(m_db);
    
    // Create trips table
    QString createTripsTable = R"(
        CREATE TABLE IF NOT EXISTS trips (
            id INTEGER PRIMARY KEY AUTOINCREMENT,
            start_time DATETIME,
            end_time DATETIME,
            distance_km REAL,
            energy_kwh REAL,
            avg_efficiency REAL,
            start_soc REAL,
            end_soc REAL
        )
    )";
    
    if (!query.exec(createTripsTable)) {
        qCritical() << "Error creating trips table:" << query.lastError().text();
        return false;
    }
    
    // Create settings table
    QString createSettingsTable = R"(
        CREATE TABLE IF NOT EXISTS settings (
            key TEXT PRIMARY KEY,
            value TEXT
        )
    )";
    
    if (!query.exec(createSettingsTable)) {
        qCritical() << "Error creating settings table:" << query.lastError().text();
        return false;
    }
    
    qDebug() << "Database tables created successfully";
    return true;
}

int DatabaseManager::saveTrip(const TripRecord &trip)
{
    if (!m_isInitialized) return -1;
    
    QSqlQuery query(m_db);
    query.prepare(R"(
        INSERT INTO trips (start_time, end_time, distance_km, energy_kwh, 
                          avg_efficiency, start_soc, end_soc)
        VALUES (:start_time, :end_time, :distance_km, :energy_kwh,
                :avg_efficiency, :start_soc, :end_soc)
    )");
    
    query.bindValue(":start_time", trip.startTime);
    query.bindValue(":end_time", trip.endTime);
    query.bindValue(":distance_km", trip.distanceKm);
    query.bindValue(":energy_kwh", trip.energyKwh);
    query.bindValue(":avg_efficiency", trip.averageEfficiency);
    query.bindValue(":start_soc", trip.startSoc);
    query.bindValue(":end_soc", trip.endSoc);
    
    if (!query.exec()) {
        qCritical() << "Error saving trip:" << query.lastError().text();
        return -1;
    }
    
    int tripId = query.lastInsertId().toInt();
    qDebug() << "Trip saved with ID:" << tripId;
    return tripId;
}

QList<TripRecord> DatabaseManager::getRecentTrips(int count)
{
    QList<TripRecord> trips;
    
    if (!m_isInitialized) return trips;
    
    QSqlQuery query(m_db);
    query.prepare("SELECT * FROM trips ORDER BY end_time DESC LIMIT :count");
    query.bindValue(":count", count);
    
    if (!query.exec()) {
        qCritical() << "Error retrieving trips:" << query.lastError().text();
        return trips;
    }
    
    while (query.next()) {
        TripRecord trip;
        trip.id = query.value("id").toInt();
        trip.startTime = query.value("start_time").toDateTime();
        trip.endTime = query.value("end_time").toDateTime();
        trip.distanceKm = query.value("distance_km").toFloat();
        trip.energyKwh = query.value("energy_kwh").toFloat();
        trip.averageEfficiency = query.value("avg_efficiency").toFloat();
        trip.startSoc = query.value("start_soc").toFloat();
        trip.endSoc = query.value("end_soc").toFloat();
        trips.append(trip);
    }
    
    return trips;
}

TripRecord DatabaseManager::getTrip(int tripId)
{
    TripRecord trip;
    trip.id = -1;
    
    if (!m_isInitialized) return trip;
    
    QSqlQuery query(m_db);
    query.prepare("SELECT * FROM trips WHERE id = :id");
    query.bindValue(":id", tripId);
    
    if (query.exec() && query.next()) {
        trip.id = query.value("id").toInt();
        trip.startTime = query.value("start_time").toDateTime();
        trip.endTime = query.value("end_time").toDateTime();
        trip.distanceKm = query.value("distance_km").toFloat();
        trip.energyKwh = query.value("energy_kwh").toFloat();
        trip.averageEfficiency = query.value("avg_efficiency").toFloat();
        trip.startSoc = query.value("start_soc").toFloat();
        trip.endSoc = query.value("end_soc").toFloat();
    }
    
    return trip;
}

float DatabaseManager::getTotalDistance()
{
    if (!m_isInitialized) return 0.0f;
    
    QSqlQuery query("SELECT SUM(distance_km) FROM trips", m_db);
    if (query.next()) {
        return query.value(0).toFloat();
    }
    return 0.0f;
}

float DatabaseManager::getTotalEnergy()
{
    if (!m_isInitialized) return 0.0f;
    
    QSqlQuery query("SELECT SUM(energy_kwh) FROM trips", m_db);
    if (query.next()) {
        return query.value(0).toFloat();
    }
    return 0.0f;
}

int DatabaseManager::getTotalTrips()
{
    if (!m_isInitialized) return 0;
    
    QSqlQuery query("SELECT COUNT(*) FROM trips", m_db);
    if (query.next()) {
        return query.value(0).toInt();
    }
    return 0;
}

void DatabaseManager::saveSetting(const QString &key, const QVariant &value)
{
    if (!m_isInitialized) return;
    
    QSqlQuery query(m_db);
    query.prepare("INSERT OR REPLACE INTO settings (key, value) VALUES (:key, :value)");
    query.bindValue(":key", key);
    query.bindValue(":value", value.toString());
    
    if (!query.exec()) {
        qCritical() << "Error saving setting:" << query.lastError().text();
    }
}

QVariant DatabaseManager::getSetting(const QString &key, const QVariant &defaultValue)
{
    if (!m_isInitialized) return defaultValue;
    
    QSqlQuery query(m_db);
    query.prepare("SELECT value FROM settings WHERE key = :key");
    query.bindValue(":key", key);
    
    if (query.exec() && query.next()) {
        return query.value(0);
    }
    
    return defaultValue;
}

void DatabaseManager::clearOldTrips(int daysToKeep)
{
    if (!m_isInitialized) return;
    
    QSqlQuery query(m_db);
    query.prepare("DELETE FROM trips WHERE end_time < datetime('now', '-' || :days || ' days')");
    query.bindValue(":days", daysToKeep);
    
    if (query.exec()) {
        qDebug() << "Cleared trips older than" << daysToKeep << "days";
    } else {
        qCritical() << "Error clearing old trips:" << query.lastError().text();
    }
}
