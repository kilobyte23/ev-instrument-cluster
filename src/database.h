#ifndef DATABASE_H
#define DATABASE_H

#include <QObject>
#include <QSqlDatabase>
#include <QDateTime>

struct TripRecord {
    int id;
    QDateTime startTime;
    QDateTime endTime;
    float distanceKm;
    float energyKwh;
    float averageEfficiency;  // Wh/km
    float startSoc;
    float endSoc;
};

class DatabaseManager : public QObject
{
    Q_OBJECT

public:
    explicit DatabaseManager(QObject *parent = nullptr);
    
    // Initialize database
    bool init();
    bool createTables();
    
    // Trip operations
    int saveTrip(const TripRecord &trip);
    QList<TripRecord> getRecentTrips(int count = 10);
    TripRecord getTrip(int tripId);
    
    // Statistics
    float getTotalDistance();
    float getTotalEnergy();
    int getTotalTrips();
    
    // Settings operations
    void saveSetting(const QString &key, const QVariant &value);
    QVariant getSetting(const QString &key, const QVariant &defaultValue = QVariant());
    
    // Cleanup
    void clearOldTrips(int daysToKeep = 30);

private:
    QSqlDatabase m_db;
    bool m_isInitialized;
};

#endif // DATABASE_H
