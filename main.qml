import QtQuick 2.9
import QtQuick.Window 2.2
import QtQuick.Controls 2.2
import QtQuick.Controls.Material 2.2

Window {
    id: window
    visible: true
    width: 840
    height: 480
    title: qsTr("marxx")



    ListModel {
        id: notesModel

        ListElement { name: "note 1"; type: "note"; text: "this is note 1" }
        ListElement { name: "note 2"; type: "note"; text: "this is note 2" }
        ListElement { name: "note 3"; type: "note"; text: "this is note 3" }
    }

    TextField {
        id: textField
        x: 301
        y: 11
        text: qsTr("Text Field")
    }

    Button {
        id: button
        x: 427
        y: 11
        text: qsTr("Search")
    }
    Rectangle{
        x: 41
        y: 113
        height: 65
        width: parent.width - 150
        color: "#fbebff"
        border.color: "black"
        radius: 10
        border.width: 2
        Text{
            x: 8
            y: 14
            text: "Short theme description"
        }
    }

    Rectangle{
        x: 0
        y: 430
        width: parent.width
        height: 50
        color: "#f0f0ff"

        Button {
            id: button1
            x: 235
            y: 8
            text: qsTr("Study")
        }

        Button {
            id: button2
            x: 327
            y: 8
            text: qsTr("Words")
        }

        Button {
            id: button3
            x: 417
            y: 8
            text: qsTr("Spritz")
        }

        Button {
            id: button4
            x: 505
            y: 8
            text: qsTr("Info")
        }

    }

    Label {
        id: label
        x: 41
        y: 78
        width: 152
        height: 29
        text: qsTr("Theme")
    }
}
