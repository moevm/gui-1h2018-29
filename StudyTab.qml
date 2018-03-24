import QtQuick 2.5
import QtQuick.Window 2.2
import QtQuick.Controls 2.3
import QtQuick.Layouts 1.3
import QtQuick.Controls.Material 2.0
import QtGraphicalEffects 1.0
import QtQuick.Dialogs 1.0

Item {
    Layout.fillWidth: true
    Layout.fillHeight: true


    Connections {
            target: controller

            onSendToQml: {
                    //t.text = s
                      // someNumber = s // Устанавливаем счётчик в текстовый лейбл
            }

    }


    Rectangle{
        id: deleg
        width: 840
        height: 35
        //Material.color: "#ea1863"
        color: "#ea1863"
        anchors.rightMargin: 0
        anchors.leftMargin: 0
        anchors.topMargin: 0
        opacity: 0.5
        anchors.left: parent.left
        anchors.right: parent.right
        anchors.top: parent.top
        Text{
            id: lab
            x: 0
            y: 0
            text: "v1.0"
            font.pixelSize: 14
            font.italic: true
        }


        Item{
            width: 205
            height: 35

            anchors.right: parent.right
            TextField {
                id: textField
                anchors.left: parent.left
                width: 161
                height: 40
                text: qsTr("Text Field")
            }

            Button {
                anchors.right: parent.right
                id: button

                width: 40
                height: 40
                Image {
                    anchors.fill: parent
                    anchors.margins: 5
                    height: 30
                    width: 30
                    id: search
                    source: "/src/search-512.png"
                }
            }

        }
    }

    Component {
            id: lessonsDelegate


                Pane {
                       //Rectangle{
                       id: delegateD
                       width:  parent.width
                       height: 80


                       Material.elevation: 6


                       smooth: true
                       visible: true

                       anchors.left: parent.left
                       anchors.right: parent.right

                       antialiasing: true

                       ColumnLayout{
                            spacing: 15


                            Text {
                                text: model.modelData.theme_name
                                font.pixelSize: 15

                            }


                            Text {
                                text: model.modelData.task_description

                            }



                       }

                       //signal qmlSignal(var anObject)

                       MouseArea{
                           anchors.fill: parent
                           hoverEnabled: true
                           property var hov: false

                           onHoveredChanged: {
                                hov = !hov
                                //delegateD.height = (hov == true) ? 90 : 80
                           }

                           onClicked: {
                                //back.visible = true
                               var theme = controller.getTheme(model.modelData.theme_name)
                               //var list = theme.getListOfTasks();
                               ctxList = theme;

                               stack.push("qrc:/TaskForm.qml")
                           }
                       }

            }


   // }


    }

    ListView{
        x: 0
        y: 36
        width: 840
        height: 388
        anchors.leftMargin: 0
        anchors.rightMargin: 0
        anchors.left: parent.left
        anchors.right: parent.right

        transformOrigin: Item.Center
        opacity: 0.9
        boundsBehavior: Flickable.StopAtBounds
        model: myModel
        delegate: lessonsDelegate
        spacing: 15
        clip: true
    }

}
