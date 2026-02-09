#include <QInteractTouch>
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
    
    const QUrl url(QStringLiteral("qrc:/qml/main.qml"));
    QObject::connect(&engine, &QQmlApplicationEngine::objectCreated,
                     &app, [url](QObject *obj, const QUrl &objUrl) {
        if (!obj && url == objUrl)
            QCoreApplication::exit(-1);
    }, Qt::QueuedConnection);
    
    // Load main.qml from the filesystem directly for easier dev, 
    // or from qrc if we were deploying. 
    // For now let's load from the copied qml dir to enable live reloading if we wanted to (conceptually)
    // Actually, following the CMakeLists, we copied qml to build dir.
    // But here we set qrc. Let's stick to qrc setup in main for production readiness,
    // but we can also load from file if we want.
    // For this environment, let's just use the file path since we haven't compiled the qrc yet
    // and maintaining qrc in this text-based interaction is annoying.
    
    // Let's use the absolute path for now to be safe and fast.
    engine.load(QUrl::fromLocalFile(QStringLiteral("/Users/mohithavala/.gemini/antigravity/scratch/ev-instrument-cluster/qml/main.qml")));

    // Initialize Simulation Receiver
    SimulationReceiver simReceiver(&vehicleData);

    return app.exec();
}
