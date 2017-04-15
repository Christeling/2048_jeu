#include "grille.h"


//Constructeur
Grille::Grille(QObject *parent) :
    QObject(parent) {
    start();
}


void Grille::start() {
    memset(grille, 0, sizeof(grille));
    points = 0;
    //Génération de 2 tuiles aléatoires pour commencer
    tuileAleatoire();
    tuileAleatoire();
}

void Grille::up() {
    bool success = false;
    //on condense les tuiles non vides vers le haut
    for (int i = 0; i < tailleGrille; i++) {
        for (int j = 0; j < tailleGrille; j++) {
            if (grille[i][j] == 0) {
                int k = j+1;
                while (k<tailleGrille && grille[i][k]==0) k++;
                if (k!=tailleGrille) {
                   grille[i][j]=grille[i][k];
                   grille[i][k]=0;
                }
             }
         }
        //on compare deux à deux pour "fusionner"
        int j=0;
        while(j<tailleGrille && grille[i][j]!=0){
            if (grille[i][j]==grille[i][j+1]){
                grille[i][j]=2*grille[i][j];
                points+=grille[i][j];
                scoreChanged();
                int k=j+1;
                while(k<tailleGrille-1 && grille[i][k]!=0){
                    grille[i][k]=grille[i][k+1];
                    k=k+1;
                }
                grille[i][tailleGrille-1]=0;
                j=j+1;
            }
            else j=j+1;
        }
        grilleChanged();
        success=true;
    }

    //on vérifie si la partie est terminée
    if(win() || gameover()) {
        end();
    }

    //sinon on génère une tuile aléatoire
    else if (success) {
        tuileAleatoire();
        grilleChanged();
    }
}

// idem que pour la fonction up
void Grille::left() {
    bool success = false;
    for (int j = 0; j < tailleGrille; j++) {
        for (int i = 0; i < tailleGrille; i++) {
            if (grille[i][j] == 0) {
                int k = i+1;
                while (k<tailleGrille && grille[k][j]==0) k++;
                if (k!=tailleGrille) {
                   grille[i][j]=grille[k][j];
                   grille[k][j]=0;
                }
             }
         }

        int i=0;
        while(i<tailleGrille-1 && grille[i][j]!=0){
            if (grille[i][j]==grille[i+1][j]){
                grille[i][j]=2*grille[i][j];
                points+=grille[i][j];
                scoreChanged();
                int k=i+1;
                while(k<tailleGrille-1 && grille[k][j]!=0){
                    grille[k][j]=grille[k+1][j];
                    k=k+1;
                }
                grille[tailleGrille-1][j]=0;
                i=i+1;
            }
            else i=i+1;
        }
        grilleChanged();
        success=true;
    }

    if(win() || gameover()) {
        end();
    }

    else if (success) {
        tuileAleatoire();
        grilleChanged();
    }
}

//idem que pour la fontion up
void Grille::down() {
    bool success = false;
    for (int i = 0; i < tailleGrille; i++) {

        for (int j = tailleGrille-1; j > 0; j--) {
            if (grille[i][j] == 0) {
                int k = j-1;
                while (k>=0 && grille[i][k]==0) k--;
                if (k!=-1) {
                   grille[i][j]=grille[i][k];
                   grille[i][k]=0;
                }
             }
         }

        int j=tailleGrille-1;
        while(j>0 && grille[i][j]!=0){
            if (grille[i][j]==grille[i][j-1]){
                grille[i][j]=2*grille[i][j];
                points+=grille[i][j];
                scoreChanged();
                int k=j-1;
                while(k>0 && grille[i][k]!=0){
                    grille[i][k]=grille[i][k-1];
                    k=k-1;
                }
                grille[i][0]=0;
                j=j-1;
            }
            else j=j-1;
        }
        grilleChanged();
        success=true;
    }

    if(win() || gameover()) {
        end();
    }

    else if (success) {
        tuileAleatoire();
        grilleChanged();
    }
}

//idem que pour la fonction up
void Grille::right() {

    bool success = false;
    for (int j = 0; j < tailleGrille; j++) {

        for (int i = tailleGrille-1; i > 0; i--) {
            if (grille[i][j] == 0) {
                int k = i-1;
                while (k>=0 && grille[k][j]==0) k--;
                if (k!=-1) {
                   grille[i][j]=grille[k][j];
                   grille[k][j]=0;
                }
             }
         }

        int i=tailleGrille-1;
        while(i>0 && grille[i][j]!=0){
            if (grille[i][j]==grille[i-1][j]){
                grille[i][j]=2*grille[i][j];
                points+=grille[i][j];
                scoreChanged();
                int k=i-1;
                while(k>0 && grille[k][j]!=0){
                    grille[k][j]=grille[k-1][j];
                    k=k-1;
                }
                grille[0][j]=0;
                i=i-1;
            }
            else i=i-1;
        }
        grilleChanged();
        success=true;
    }

    if(win() || gameover()) {
        end();
    }

    else if (success) {
        tuileAleatoire();
        grilleChanged();
    }
}

int Grille::get(const int x, const int y) const {
    return grille[x][y];
}

int Grille::score() const {
    return points;
}

//Génération da la valeur de la tuile aléatoire
int Grille::valeurAleatoire() const {
    return ((qrand() % 10) / 9 + 1) * 2;
}

//Création de la tuile aléatoire
void Grille::tuileAleatoire() {
    int x, y;
    int list[tailleGrille * tailleGrille][2];
    int len = 0;
    int r;

    //on crée une liste des tuiles vides
    for(x = 0; x < tailleGrille; x++) {
        for(y = 0; y < tailleGrille; y++) {
            if(grille[x][y] == 0) {
                list[len][0] = x;
                list[len][1] = y;
                len++;
            }
        }
    }

    //on tire au hasard une tuile dans la liste des tuiles vides
    if (len > 0) {
        r = qrand() % len;
        x = list[r][0];
        y = list[r][1];
        grille[x][y] = valeurAleatoire();
    }
}

//Test de partie perdue
bool Grille::gameover() {
    //on verifie si il y a des cases vides
    for (int i=0; i<tailleGrille; i++){
        for (int j=0; j<tailleGrille; j++){
            if (grille[i][j]==0) {return false;}
        }
    }

    //on regarde si il y a des paires
    for (int i=0; i<tailleGrille; i++){
        for (int j=0; j<tailleGrille-1; j++){
            if (grille[i][j]==grille[i][j+1]) {return false;}
        }
    }
    for (int j=0; j<tailleGrille; j++){
        for (int i=0; i<tailleGrille-1; i++){
            if (grille[i][j]==grille[i+1][j]) {return false;}
        }
    }

    //sinon on a perdu
    return true;
}

//Test de partie gagnée
bool Grille::win() {
    for (int i=0; i<tailleGrille; i++){
        for (int j=0; j<tailleGrille; j++){
            if(grille[i][j]==2048) return true;
        }
    }
    return false;
}
