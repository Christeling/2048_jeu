#ifndef GRILLEMODELE_H
#define GRILLEMODELE_H

#include <QAbstractListModel>
#include "grille.h"

class GrilleModele : public QAbstractListModel
{
    Q_OBJECT
    Q_PROPERTY(int score READ score NOTIFY scoreChanged)
    Q_PROPERTY(bool gameover READ gameover NOTIFY end)
    Q_PROPERTY(bool win READ win NOTIFY end)

public:
    explicit GrilleModele(QObject *parent = 0);

    int rowCount(const QModelIndex &parent = QModelIndex()) const;
    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const;

    Q_INVOKABLE void up();
    Q_INVOKABLE void right();
    Q_INVOKABLE void down();
    Q_INVOKABLE void left();

    int score() const;
    bool gameover();
    bool win();

signals:
    void scoreChanged();
    void grilleChanged();
    void end();

public slots:
    void onDataChanged();

private:
    Grille grille;

};

#endif // GRILLEMODELE_H
