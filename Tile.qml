import QtQuick 2.2

Rectangle {
    id: tile
    property int tileWidth: 70
    property string value: ""

    // retourn une chaine vide si 0, sinon la valeur
    function valueToText(value) {
        if (parseInt(value, 10) === 0) {
            return "";
        }
        return value;
    }

    // retourne la couleur en fonction de la valeur
    function valueToColor(value) {
        var v = parseInt(value, 10);
        var color;
        switch(v) {
        case 2:
            color = "#F0DECF";
            break;
        case 4:
            color = "#E9DBBD";
            break;
        case 8:
            color = "#EFA167";
            break;
        case 16:
            color = "#F18351";
            break;
        case 32:
            color = "#EF654D";
            break;
        case 64:
            color = "#F1472F";
            break;
        case 128:
            color = "#E9C561";
            break;
        case 256:
            color = "#E9C050";
            break;
        case 512:
            color = "#E9BD3F";
            break;
        case 1024:
            color = "#E8BB32";
            break;
        case 2048:
            color = "#E8B723";
            break;
        default:
            color = "#C2B4A5";
        }

        return color;
    }

    //On renvoie la taille de la police en fonction de la taille des tuiles
    function fontSize(value) {
        var v = parseInt(value, 10);
        if (v < 1024) {
            return tileWidth / 2.5;
        }
        return tileWidth / 3;
    }

    width: tileWidth
    height: tileWidth
    color: valueToColor(value)
    radius: tileWidth / 14

    //On définit le texte
    Text {
        text: valueToText(value)
        font.pointSize: fontSize(value)
        anchors.centerIn: parent
        color: "black"
    }
}
