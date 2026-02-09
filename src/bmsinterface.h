#ifndef BMSINTERFACE_H
#define BMSINTERFACE_H

#include <QObject>

class BMSInterface : public QObject
{
    Q_OBJECT
    Q_PROPERTY(float cellVoltageMin READ cellVoltageMin NOTIFY bmsDataChanged)
    Q_PROPERTY(float cellVoltageMax READ cellVoltageMax NOTIFY bmsDataChanged)
    Q_PROPERTY(float packVoltage READ packVoltage NOTIFY bmsDataChanged)
    Q_PROPERTY(float packCurrent READ packCurrent NOTIFY bmsDataChanged)
    Q_PROPERTY(float stateOfHealth READ stateOfHealth NOTIFY bmsDataChanged)

public:
    explicit BMSInterface(QObject *parent = nullptr);

    float cellVoltageMin() const { return m_cellVoltageMin; }
    float cellVoltageMax() const { return m_cellVoltageMax; }
    float packVoltage() const { return m_packVoltage; }
    float packCurrent() const { return m_packCurrent; }
    float stateOfHealth() const { return m_stateOfHealth; }

signals:
    void bmsDataChanged();
    void criticalFault(const QString& code);

public slots:
    void updateFromCAN(const QByteArray& payload);

private:
    float m_cellVoltageMin;
    float m_cellVoltageMax;
    float m_packVoltage;
    float m_packCurrent;
    float m_stateOfHealth;
};

#endif // BMSINTERFACE_H
