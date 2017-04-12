#include "grille.h"

grille::grille(QObject *parent) : QObject(parent)
{
    QList<QString> G;
    for (int i=1; i<=16; i++) G.append(QString::number(i));
    cptChanged();
}

QList<QString> grille::readGrille()
{
    return G;
}
