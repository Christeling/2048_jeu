import QtQuick 2.4
import QtQuick.Controls 1.3
import QtQuick.Layouts 1.1

Item {
    id: page
    width: 640
    height: 480
    Column{
        anchors.horizontalCenter: parent.horizontalCenter
        anchors.verticalCenter: parent.verticalCenter
        Repeater{
            model: 4
            Row{
                Repeater{
                    model: 4
                    property int outerIndex: index
                    Rectangle{ width: page.height/6
                        height: page.height/6
                        border.color: "#000000"
                        border.width: 1
                        Text{
                            //text: qsTr("Grrr")
                            text: vueObjetGrille.grilleQML[columns.outerIndex * 4 + index]
                            anchors.horizontalCenter: parent.horizontalCenter
                            anchors.verticalCenter: parent.verticalCenter
                        }
                    }
                }
            }
        }
    }
}
