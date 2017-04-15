#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QtQml>

#include "grilleModele.h"

int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);

    QQmlApplicationEngine engine;
    GrilleModele Grille;
    engine.rootContext()->setContextProperty("Grille", &Grille);
    engine.load(QUrl(QStringLiteral("qrc:///main.qml")));

    return app.exec();
}
