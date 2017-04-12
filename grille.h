#ifndef GRILLE_H
#define GRILLE_H

#include <QObject>
#include <QList>


class grille : public QObject
{
    Q_OBJECT
public:
    explicit grille(QObject *parent = 0);
    Q_PROPERTY(QList<QString> grilleQML READ readGrille NOTIFY cptChanged)
    QList<QString> readGrille();
signals:
    void cptChanged();
public slots:
private:

    QList<QString> G;

};

#endif // GRILLE_H
