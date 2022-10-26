#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include "TransObj.h"

int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);

    qmlRegisterType<GuZhiRebot>("an.qml.TransObj", 1, 0, "TransObj");

    QQmlApplicationEngine engine;
    engine.load(QUrl(QStringLiteral("qrc:/main.qml")));
    if (engine.rootObjects().isEmpty())
        return -1;

    return app.exec();
}
