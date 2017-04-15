import QtQuick 2.2
import QtQuick.Controls 1.3
import QtQuick.Dialogs 1.2

ApplicationWindow{
    visible:true
    width:640
    height:480
    title: qsTr("2048")

    MainForm{
        anchors.fill:parent
    }
}
