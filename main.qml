import QtQuick 2.5
import QtQuick.Window 2.2
import QtQuick.Controls 2.3
import QtQuick.Layouts 1.3
import QtQuick.Controls.Material 2.0
import QtGraphicalEffects 1.0


Window {
    id: window
    visible: true
    width: 840
    height: 480
    title: qsTr("LingSrikeTurbo")
    Material.theme: Material.Light




    TabBar {
        id: bar
        x: 0
        y: 432
        width: parent.width
        anchors.bottom: parent.bottom
        TabButton {
            text: qsTr("Study")
        }
        TabButton {
            text: qsTr("Profile")
        }
        TabButton {
            text: qsTr("Words")
        }
        TabButton {
            text: qsTr("Spritz")
        }
    }

    StackLayout {
        anchors.top: parent.top
        anchors.topMargin: 0
        anchors.bottom: parent.bottom
        anchors.bottomMargin: 480
        anchors.left: parent.left
        anchors.leftMargin: 0
        anchors.right: parent.right
        anchors.rightMargin: 0
        currentIndex: bar.currentIndex
        Item {
            id: studyTab
            Layout.fillWidth: true
            Layout.fillHeight: true



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

//todo: Сделать модельку под лист
            ListModel {
                id: lessonsModel

                ListElement {
                    name: "Words"
                    description: "Studying words"
                }
                ListElement {
                    name: "Translate"
                    description: "Translating"
                }
                ListElement {
                    name: "Listening"
                    description: "Listening english text"
                }

                ListElement {
                    name: "Words1"
                    description: "Studying words1"
                }
                ListElement {
                    name: "Translate1"
                    description: "Translating1"
                }
                ListElement {
                    name: "Listening1"
                    description: "Listening english text1"
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



                               MouseArea{
                                   anchors.fill: parent
                                   hoverEnabled: true
                                   property var hov: false

                                   onHoveredChanged: {
                                        hov = !hov

                                        //parent.color = "#ea1863"
                                       //delegateD.background.
                                         //delegateD.color = "#ea1863"
                                        //opacity: 0.5
                                        delegateD.height = (hov == true) ? 90 : 80
                                   }
                                   onClicked: {

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
        Item {
            id: profileTab
        }
        Item {
            id: wordsTab
        }
        Item {
            id: spritzTab



        }
    }








}
