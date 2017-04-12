#ifndef GRILLE_H
#define GRILLE_H

#include <QObject>
#include <QList>


class grille : public QObject
{
    Q_OBJECT
public:
    explicit grille(QObject *parent = 0, int size=4);
    Q_PROPERTY(QList<QString> grilleQML READ readGrille NOTIFY grilleChanged)
    QList<QString> readGrille();
signals:
    void grilleChanged();
public slots:
private:

    QList<QList<int>> G;
    int tailleGrille;

};

#endif // GRILLE_H
