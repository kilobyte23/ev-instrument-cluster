#ifndef RANGEPREDICTOR_H
#define RANGEPREDICTOR_H
#include <QObject>

class RangePredictor : public QObject {
    Q_OBJECT
public:
    explicit RangePredictor(QObject *parent = nullptr) : QObject(parent) {}
    Q_INVOKABLE float calculateRange(float soc, float recentConsumption) { return soc * 3.5f; } // Mock algo
};
#endif
