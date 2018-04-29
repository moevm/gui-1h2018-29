import QtQuick 2.5
import QtQuick.Window 2.2
import QtQuick.Controls 2.0
import QtQuick.Layouts 1.3
import QtQuick.Controls.Material 2.0
import QtGraphicalEffects 1.0
import QtQuick.Dialogs 1.0
import QtQuick.Dialogs 1.3

Item {

    property var source: imageOriginal.source
    property var radius: 20


    Connections {
            target: controller

            onSendToQml: {
                    //t.text = s
                      // someNumber = s // Устанавливаем счётчик в текстовый лейбл
            }

    }


    Text{
        x: 41
        y: 109
        width: 191
        height: 63
        text: "Ваш прогресс в приложении: "
        font.pointSize: 19


    }

    Item {
        id: item1
        x: 153
        y: 178
        width: 334
        height: 57


        Text{
            y: 17
            id: progress
            text: setProgress()
            anchors.left: parent.horizontalCenter

            anchors.leftMargin: -280

            font.pointSize: 14

        }
    }

    Timer{
        id: timer
        interval: 1000
        running: true
        repeat: true
        onTriggered: setProgress()
    }

    Item {
        id: item2
        x: 41
        y: 227
        width: 334
        height: 200

        Text{
            y: 19
            id: progressPercent
            anchors.left: parent.horizontalCenter

            text: ""
            anchors.leftMargin: -167

            font.pointSize: 14
        }
    }

    Item{
        x: 0
        y: 0
        width: 217
        height: 103


        Label {
            horizontalAlignment: Text.AlignRight
            id: label
            x: 432
            y: 24
            width: 106
            height: 36
            text: controller.getSettingsItem("userName")
            font.pointSize: 15
        }

        Item {
            x: 544
            y: 8
            width: 80
            height: 80

            Image {
                id: imageOriginal
                anchors.fill: parent
                source: controller.getSettingsItem("userPhoto")
                visible: false
            }

            Rectangle {
                id: rectangleMask
                anchors.fill: parent
                radius: 0.5*height
                visible: false
            }

            OpacityMask {
                id: opacityMask
                anchors.fill: imageOriginal
                source: imageOriginal
                maskSource: rectangleMask
            }
        }

        Image {
            id: edit
            x: 575
            y: 94
            source: "qrc:/src/edit.png"

            height: 30
            width: 34


            MouseArea{
                anchors.leftMargin: 0
                anchors.topMargin: 0
                anchors.rightMargin: 0
                anchors.bottomMargin: 0
                anchors.fill: parent



                onClicked: dialog.open()
            }
        }
    }

    Dialog{

        height: 300
        width: 400

        id: dialog

        TextField{
            placeholderText: qsTr("Введите имя")
            maximumLength: 10
            id: name
            x: 15
            y: 15
            height: 40
            width: 200

        }

        TextField{
            placeholderText: qsTr("Путь к файлу")
            x: 15
            y: 70
            id: chosenAvatar
            height: 40
            width: 200

            //visible: false
        }

        Button{
            y: 70
            x: 120
            text: qsTr("Выберите файл")
            anchors.left: chosenAvatar.right
            onClicked: fileDialog.open()
        }


        onAccepted: {
            imageOriginal.source = (chosenAvatar.text == "") ? imageOriginal.source : chosenAvatar.text
            label.text = (name.text == "") ? label.text : name.text

            controller.setProfile(name.text, imageOriginal.source)
        }

    }


    FileDialog {
        id: fileDialog
        title: "Please choose a file"
        folder: shortcuts.home
        nameFilters: [ "Image Files (*.jpg; *.jpeg; *.png);" ]
        onAccepted: {

            chosenAvatar.text = fileDialog.fileUrl
            //setPicture(fileDialog.fileUrl); // получаем директорию файла
            close();
        }
        onRejected: {
            close()
        }
    }



    function setProgress(){
        progress.text = "Вы завершили " + controller.getNumberDoneTasks()  + " из 6 заданий!"
        progressPercent.text =  "Это " + Math.round((controller.getNumberDoneTasks() / 6 * 100)) + "% от курса.";

    }

    function setPictureAndName(){


    }
}
