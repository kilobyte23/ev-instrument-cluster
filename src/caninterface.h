#ifndef CANINTERFACE_H
#define CANINTERFACE_H

#include <QObject>
#include <QVariantMap>

// Forward declaration
class QCanBusDevice;

class CANInterface : public QObject
{
    Q_OBJECT
public:
    explicit CANInterface(QObject *parent = nullptr);
    ~CANInterface();

    bool connectDevice(const QString &plugin = "socketcan", const QString &interface = "can0");
    void disconnectDevice();

signals:
    void processedDataReceived(const QVariantMap &data);
    void rawFrameReceived(); // Debugging/Logging

private slots:
    void onFramesReceived();
    void onErrorOccurred(int error);

private:
    QCanBusDevice *m_device = nullptr;
    
    void processFrame(const struct QCanBusFrame &frame);
};

#endif // CANINTERFACE_H
