#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QtQml>

#include "grille.h"

int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);

    grille uneGrille;


    QQmlApplicationEngine engine;
    engine.rootContext()->setContextProperty("vueObjetGrille", &uneGrille);
    engine.load(QUrl(QStringLiteral("qrc:/main.qml")));

    return app.exec();
}
