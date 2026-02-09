#include "caninterface.h"
#include <QCanBus>
#include <QCanBusDevice>
#include <QCanBusFrame>
#include <QDebug>

CANInterface::CANInterface(QObject *parent) : QObject(parent)
{
}

CANInterface::~CANInterface()
{
    disconnectDevice();
}

bool CANInterface::connectDevice(const QString &plugin, const QString &interface)
{
    QString errorString;
    m_device = QCanBus::instance()->createDevice(plugin, interface, &errorString);

    if (!m_device) {
        qWarning() << "Error creating CAN device:" << errorString;
        return false;
    }

    connect(m_device, &QCanBusDevice::framesReceived, this, &CANInterface::onFramesReceived);
    // In Qt6 errorOccurred is the signal name, might differ in older versions but we target 6
    // connect(m_device, &QCanBusDevice::errorOccurred, this, &CANInterface::onErrorOccurred);

    if (!m_device->connectDevice()) {
        qWarning() << "Connection error:" << m_device->errorString();
        delete m_device;
        m_device = nullptr;
        return false;
    }

    qDebug() << "CAN Interface connected:" << interface;
    return true;
}

void CANInterface::disconnectDevice()
{
    if (m_device) {
        m_device->disconnectDevice();
        delete m_device;
        m_device = nullptr;
    }
}

void CANInterface::onFramesReceived()
{
    if (!m_device) return;

    while (m_device->framesAvailable()) {
        const QCanBusFrame frame = m_device->readFrame();
        processFrame(frame);
    }
}

void CANInterface::processFrame(const QCanBusFrame &frame)
{
    // Mock parsing logic based on ID
    // In reality, this would use a DBC file parser or a lookup table
    
    QVariantMap data;
    
    switch (frame.frameId()) {
    case 0x100: // Motor Controller
        // Example: Speed in byte 0, 1
        // data["speed"] = ...
        break;
    case 0x200: // BMS
        // data["soc"] = ...
        break;
    default:
        break;
    }
    
    if (!data.isEmpty()) {
        emit processedDataReceived(data);
    }
}

void CANInterface::onErrorOccurred(int error)
{
    qDebug() << "CAN Error:" << error;
}
