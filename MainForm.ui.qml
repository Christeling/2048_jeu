import QtQuick 2.2
import QtQuick.Window 2.1
import QtQuick.Layouts 1.1

Item {
    id: main
    visible: true
    width: 360
    height: 360

    //On définit la fenêtre
    Rectangle {
        color: "#AD9D90"
        anchors.fill: parent
        focus: true

        //On définit le contrôle des événements à partir de la classe Grille
        Keys.onPressed: {
          switch (event.key) {
          case Qt.Key_Up:
              Grille.up();
              break;
          case Qt.Key_Right:
              Grille.right();
              break;
          case Qt.Key_Down:
              Grille.down();
              break;
          case Qt.Key_Left:
              Grille.left();
              break;
          }
        }

        //On utilise un ColumnLayout
        ColumnLayout {
            anchors.fill: parent
            //Bandeau d'affichage du score et des informations
            RowLayout {

                //on affiche si le joueur a gagné ou perdu
                Text {
                    text: {
                        if (Grille.win) {
                            return "YOU WIN!"
                        } else if (Grille.gameover) {
                            return "GAME OVER";
                        } else {
                            return "";
                        }
                    }
                    color: "#f3eaea"
                    opacity: 0.3
                    font.pointSize: Math.min(main.width, main.height) / 12
                    font.family: "Verdana"
                    Layout.fillWidth: true
                }

                //On affiche le score
                Text {
                    text: Grille.score
                    color: "#f3eaea"
                    opacity: 0.3
                    font.pointSize: Math.min(main.width, main.height) / 12
                    font.family: "Verdana"
                }
            }

            //Création de la grille
            Rectangle {
                id: mainGrille
                Layout.fillHeight: true
                Layout.fillWidth: true

                function step() {
                    return Math.min(mainGrille.width, mainGrille.height) / 33;
                }

                width: 330
                height: 330
                color: "#AD9D90"

                //On crée les cases de la grille
                Grid {
                    y: mainGrille.step()
                    anchors.horizontalCenter: parent.horizontalCenter
                    rows: 4
                    columns: 4
                    spacing: mainGrille.step()

                    //On utilise une boucle pour créer les cases
                    Repeater {
                        id: boardRepeater
                        model: Grille

                        //On renvoie au fichier Tile.qml
                        delegate: Tile {
                            value: display
                            tileWidth: mainGrille.step() * 7
                        }

                    }
                }
            }
        }
    }
}
