// #include <QInteractTouch>
#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>
#include "evvehicledata.h"
#include "simulationreceiver.h"

int main(int argc, char *argv[])
{
#if QT_VERSION < QT_VERSION_CHECK(6, 0, 0)
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
#endif
    QGuiApplication app(argc, argv);

    // Register our C++ types
    qmlRegisterType<EVVehicleData>("EVComponents", 1, 0, "EVVehicleData");

    EVVehicleData vehicleData; // The singleton instance for the app

    QQmlApplicationEngine engine;
    
    // transform the EVVehicleData instance into a context property
    // so it is accessible globally in QML as "Vehicle"
    engine.rootContext()->setContextProperty("VehicleData", &vehicleData);
    
    // Load from embedded resource for portability
    const QUrl url(QStringLiteral("qrc:/qml/main.qml"));
    
    QObject::connect(&engine, &QQmlApplicationEngine::objectCreated,
                     &app, [url](QObject *obj, const QUrl &objUrl) {
        if (!obj && url == objUrl)
            QCoreApplication::exit(-1);
    }, Qt::QueuedConnection);
    
    engine.load(url);

    // Initialize Simulation Receiver
    SimulationReceiver simReceiver(&vehicleData);

    return app.exec();
}
