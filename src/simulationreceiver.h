#ifndef SIMULATIONRECEIVER_H
#define SIMULATIONRECEIVER_H

#include <QObject>
#include <QUdpSocket>
#include "evvehicledata.h"

class SimulationReceiver : public QObject
{
    Q_OBJECT
public:
    explicit SimulationReceiver(EVVehicleData *data, QObject *parent = nullptr);

private slots:
    void processPendingDatagrams();

private:
    QUdpSocket *m_socket;
    EVVehicleData *m_vehicleData;
};

#endif // SIMULATIONRECEIVER_H
