#ifndef CHARGINGMANAGER_H
#define CHARGINGMANAGER_H
#include <QObject>
class ChargingManager : public QObject {
    Q_OBJECT
public:
    explicit ChargingManager(QObject *parent = nullptr) : QObject(parent) {}
};
#endif
