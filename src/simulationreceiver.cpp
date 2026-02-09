#include "simulationreceiver.h"
#include <QNetworkDatagram>
#include <QJsonDocument>
#include <QJsonObject>
#include <QDebug>

SimulationReceiver::SimulationReceiver(EVVehicleData *data, QObject *parent)
    : QObject(parent), m_vehicleData(data)
{
    m_socket = new QUdpSocket(this);
    if (m_socket->bind(QHostAddress::LocalHost, 5555)) {
        qDebug() << "Simulation Receiver listening on port 5555";
        connect(m_socket, &QUdpSocket::readyRead, this, &SimulationReceiver::processPendingDatagrams);
    } else {
        qWarning() << "Failed to bind Simulation Receiver socket port 5555";
    }
}

void SimulationReceiver::processPendingDatagrams()
{
    while (m_socket->hasPendingDatagrams()) {
        QNetworkDatagram datagram = m_socket->receiveDatagram();
        QJsonDocument doc = QJsonDocument::fromJson(datagram.data());
        
        if (doc.isObject()) {
            QVariantMap data = doc.object().toVariantMap();
            m_vehicleData->updateFromSimulation(data);
        }
    }
}
