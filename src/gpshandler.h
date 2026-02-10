#ifndef GPSHANDLER_H
#define GPSHANDLER_H

#include <QObject>
#include <QGeoCoordinate>
#include <QList>

struct GPSPoint {
    double latitude;
    double longitude;
    qint64 timestamp;  // milliseconds since epoch
    float speed;       // km/h
};

class GPSHandler : public QObject
{
    Q_OBJECT

public:
    explicit GPSHandler(QObject *parent = nullptr);
    
    // Process new GPS data
    void updatePosition(double latitude, double longitude, float heading, float speed);
    
    // Getters
    double getCurrentLatitude() const { return m_currentLat; }
    double getCurrentLongitude() const { return m_currentLon; }
    float getCurrentHeading() const { return m_currentHeading; }
    float getDistanceTraveled() const { return m_totalDistance; }
    float getTripDistance() const { return m_tripDistance; }
    float getAverageSpeed() const;
    
    // Calculate distance between two GPS coordinates (Haversine formula)
    static double calculateDistance(double lat1, double lon1, double lat2, double lon2);
    
    // Calculate bearing between two points
    static double calculateBearing(double lat1, double lon1, double lat2, double lon2);
    
    // Reset functions
    void resetTrip();
    void clearHistory();

private:
    double m_currentLat;
    double m_currentLon;
    float m_currentHeading;
    double m_previousLat;
    double m_previousLon;
    float m_totalDistance;      // meters
    float m_tripDistance;       // meters
    qint64 m_tripStartTime;     // milliseconds
    
    QList<GPSPoint> m_routeHistory;
    bool m_firstUpdate;
};

#endif // GPSHANDLER_H
