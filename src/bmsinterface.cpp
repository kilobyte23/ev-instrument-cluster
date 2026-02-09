#include "bmsinterface.h"
#include <QDebug>

BMSInterface::BMSInterface(QObject *parent) : QObject(parent),
    m_cellVoltageMin(3.2f), m_cellVoltageMax(3.2f),
    m_packVoltage(0.0f), m_packCurrent(0.0f), m_stateOfHealth(100.0f)
{
}

void BMSInterface::updateFromCAN(const QByteArray& payload)
{
    // Placeholder for CAN parsing logic
    // In a real implementation, we would decode the byte array
    // m_packVoltage = ...
    emit bmsDataChanged();
}
