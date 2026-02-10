#include "gpshandler.h"
#include <QDateTime>
#include <QtMath>
#include <QDebug>

GPSHandler::GPSHandler(QObject *parent)
    : QObject(parent),
      m_currentLat(0.0),
      m_currentLon(0.0),
      m_currentHeading(0.0),
      m_previousLat(0.0),
      m_previousLon(0.0),
      m_totalDistance(0.0f),
      m_tripDistance(0.0f),
      m_tripStartTime(0),
      m_firstUpdate(true)
{
    m_tripStartTime = QDateTime::currentMSecsSinceEpoch();
}

void GPSHandler::updatePosition(double latitude, double longitude, float heading, float speed)
{
    if (m_firstUpdate) {
        m_currentLat = latitude;
        m_currentLon = longitude;
        m_currentHeading = heading;
        m_previousLat = latitude;
        m_previousLon = longitude;
        m_firstUpdate = false;
        return;
    }
    
    // Calculate distance traveled since last update
    double distanceMeters = calculateDistance(m_previousLat, m_previousLon, latitude, longitude);
    
    // Only update if we've moved a reasonable distance (filter GPS noise)
    if (distanceMeters > 1.0) {  // More than 1 meter
        m_totalDistance += distanceMeters;
        m_tripDistance += distanceMeters;
        
        // Update positions
        m_previousLat = m_currentLat;
        m_previousLon = m_currentLon;
        m_currentLat = latitude;
        m_currentLon = longitude;
        m_currentHeading = heading;
        
        // Add to route history (limit to last 1000 points)
        GPSPoint point;
        point.latitude = latitude;
        point.longitude = longitude;
        point.timestamp = QDateTime::currentMSecsSinceEpoch();
        point.speed = speed;
        
        m_routeHistory.append(point);
        if (m_routeHistory.size() > 1000) {
            m_routeHistory.removeFirst();
        }
        
        qDebug() << "GPS: Position updated -" << latitude << "," << longitude 
                 << "Distance:" << distanceMeters << "m";
    }
}

double GPSHandler::calculateDistance(double lat1, double lon1, double lat2, double lon2)
{
    // Haversine formula for calculating distance between two GPS coordinates
    const double earthRadiusKm = 6371.0;
    
    double dLat = qDegreesToRadians(lat2 - lat1);
    double dLon = qDegreesToRadians(lon2 - lon1);
    
    double a = qSin(dLat / 2) * qSin(dLat / 2) +
               qCos(qDegreesToRadians(lat1)) * qCos(qDegreesToRadians(lat2)) *
               qSin(dLon / 2) * qSin(dLon / 2);
    
    double c = 2 * qAtan2(qSqrt(a), qSqrt(1 - a));
    
    double distanceKm = earthRadiusKm * c;
    return distanceKm * 1000.0;  // Convert to meters
}

double GPSHandler::calculateBearing(double lat1, double lon1, double lat2, double lon2)
{
    // Calculate bearing (heading) from point 1 to point 2
    double dLon = qDegreesToRadians(lon2 - lon1);
    double y = qSin(dLon) * qCos(qDegreesToRadians(lat2));
    double x = qCos(qDegreesToRadians(lat1)) * qSin(qDegreesToRadians(lat2)) -
               qSin(qDegreesToRadians(lat1)) * qCos(qDegreesToRadians(lat2)) * qCos(dLon);
    
    double bearing = qRadiansToDegrees(qAtan2(y, x));
    return fmod(bearing + 360.0, 360.0);  // Normalize to 0-360
}

float GPSHandler::getAverageSpeed() const
{
    if (m_routeHistory.size() < 2) {
        return 0.0f;
    }
    
    // Calculate average speed over trip
    qint64 tripDuration = QDateTime::currentMSecsSinceEpoch() - m_tripStartTime;
    if (tripDuration <= 0) {
        return 0.0f;
    }
    
    // Distance in km, time in hours
    float distanceKm = m_tripDistance / 1000.0f;
    float timeHours = tripDuration / 3600000.0f;
    
    return timeHours > 0 ? distanceKm / timeHours : 0.0f;
}

void GPSHandler::resetTrip()
{
    m_tripDistance = 0.0f;
    m_tripStartTime = QDateTime::currentMSecsSinceEpoch();
    qDebug() << "GPSHandler: Trip reset";
}

void GPSHandler::clearHistory()
{
    m_routeHistory.clear();
    m_totalDistance = 0.0f;
    resetTrip();
    qDebug() << "GPSHandler: All history cleared";
}
