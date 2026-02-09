#ifndef ENERGYCALCULATOR_H
#define ENERGYCALCULATOR_H

#include <QObject>

class EnergyCalculator : public QObject
{
    Q_OBJECT
public:
    explicit EnergyCalculator(QObject *parent = nullptr);

public slots:
    void updateConsumption(float powerKw, float speedKmph);
    float getTripConsumption();
    float getAverageConsumption();

private:
    float m_totalEnergyKwh;
    float m_totalDistanceKm;
};

#endif // ENERGYCALCULATOR_H
