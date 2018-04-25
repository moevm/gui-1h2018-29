import QtQuick 2.5
import QtQuick.Window 2.2
import QtQuick.Controls 2.3
import QtQuick.Layouts 1.3
import QtQuick.Controls.Material 2.0
import QtGraphicalEffects 1.0
import QtQuick.Dialogs 1.0

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

            StackView {
                id: stackMain

                x: 0
                y: 0
                width: 840
                height: 433
                initialItem: view

                Component {
                    id: view
                    Item{

                    }

                }


                Component.onCompleted: {
                    stackMain.push("qrc:/StudyTab.qml")
                }


            }



        }
        Item {
            id: profileTab
            MyProfile{}

        }

        Item {
            id: spritzTab

            Spritz{}
        }
    }



}
