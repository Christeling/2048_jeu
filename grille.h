#ifndef GRILLE_H
#define GRILLE_H

#include <QAbstractListModel>
#include <QObject>
#include <QStringList>

static const int tailleGrille = 4;

class Grille : public QObject {
    Q_OBJECT

public:
    explicit Grille(QObject *parent = 0);

    void up();
    void right();
    void down();
    void left();

    int get(const int x, const int y) const;
    int score() const;
    bool gameover();
    bool win();

signals:
    void grilleChanged();
    void scoreChanged();
    void end();

public slots:

private:
    int grille[tailleGrille][tailleGrille];
    int points;

    void start();
    int valeurAleatoire() const;
    void tuileAleatoire();
};

#endif // GRILLE_H
