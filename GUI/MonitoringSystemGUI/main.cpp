#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <monitorsystemdisplay.h>
#include <QQmlContext>

int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);

    MonitorSystemDisplay display;
    QQmlApplicationEngine engine;

    MonitorSystemDisplay disp;
    engine.rootContext()->setContextProperty("monitorSystemData", &disp);

    const QUrl url(u"qrc:/MonitoringSystemGUI/Main.qml"_qs);
    QObject::connect(
        &engine,
        &QQmlApplicationEngine::objectCreationFailed,
        &app,
        []() { QCoreApplication::exit(-1); },
        Qt::QueuedConnection);
    engine.load(url);

    return app.exec();
}
