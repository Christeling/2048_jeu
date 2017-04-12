#include "grille.h"

grille::grille(QObject *parent, int size) : QObject(parent)
{
    //QList<QString> G;
    tailleGrille = size;
    for (int i=1; i<=tailleGrille; i++)
    {
        G.append(QList<int>());
        for (int j=1; j<=tailleGrille; j++) G[i].append(0);
    }
    G[1][2]=9;
    grilleChanged();
}

QList<QString> grille::readGrille()
{
    QList<QString> StrG;
    for (int i=1; i<=tailleGrille; i++)
    {
        for (int j=1; j<=tailleGrille; j++)
            {
            if (G[i][j] != 0)
                StrG.append(QString::number(G[i][j]));
            else StrG.append(QString());
            }
    }
    return StrG;
}

