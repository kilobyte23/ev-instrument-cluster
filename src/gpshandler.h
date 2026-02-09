#ifndef GPSHANDLER_H
#define GPSHANDLER_H
#include <QObject>
class GPSHandler : public QObject {
    Q_OBJECT
public:
    explicit GPSHandler(QObject *parent = nullptr) : QObject(parent) {}
};
#endif
