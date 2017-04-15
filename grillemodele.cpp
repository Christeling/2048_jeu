#include "GrilleModele.h"


GrilleModele::GrilleModele(QObject *parent) :
    //On lie les signaux de Grille et de GrilleModele correspondants
    QAbstractListModel(parent)
{
    connect(&grille, &Grille::grilleChanged, this, &GrilleModele::onDataChanged);
    connect(&grille, &Grille::scoreChanged, this, &GrilleModele::scoreChanged);
    connect(&grille, &Grille::end, this, &GrilleModele::end);
}

//On compte la taille de la grille
int GrilleModele::rowCount(const QModelIndex &parent) const {
    Q_UNUSED(parent)

    return tailleGrille* tailleGrille;
}



QVariant GrilleModele::data(const QModelIndex &index, int role) const {
    int x, y;
    //si on n'est pas sur une case, on retourne un QVariant vide
    if (index.row() < 0 || index.row() >= tailleGrille * tailleGrille) {
        return QVariant();
    }

    //sinon on retourne la valeur de la case de coordonnées correspondant à l'index
    if (role == Qt::DisplayRole) {
        x = index.row() % tailleGrille;
        y = index.row() / tailleGrille;
        QString str = QString::number(grille.get(x, y));
        return str;
    }
    return QVariant();
}

//on lie les fontions de Grille à GrillemModele
void GrilleModele::up() {
    grille.up();
}

void GrilleModele::right() {
    grille.right();
}

void GrilleModele::down() {
    grille.down();
}

void GrilleModele::left() {
    grille.left();
}

//Renvoi du signal dataChanged
void GrilleModele::onDataChanged() {
    dataChanged(createIndex(0, 0), createIndex(rowCount() - 1, 0));
}


int GrilleModele::score() const {
    return grille.score();
}

bool GrilleModele::gameover() {
    return grille.gameover();
}

bool GrilleModele::win() {
    return grille.win();
}
