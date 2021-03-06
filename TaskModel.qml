import QtQuick 2.5
import QtQuick.Window 2.2
import QtQuick.Controls 2.0
import QtQuick.Layouts 1.3
import QtQuick.Controls.Material 2.0
import QtGraphicalEffects 1.0
import QtQuick.Dialogs 1.0
import QtQml.Models 2.2


Item {

    id: mainTaskPage
    ListModel {
        id: taskModel


    }



    Rectangle{
        Component.onCompleted: {

        }
        id: back
        x: 0
        y: 0
        width: 35
        height: 35
        Image {
            anchors.fill: parent
            id: backButton
            source: "qrc:/src/back.png"
        }
        //visible: false
        MouseArea{
            id: mouseArea
            anchors.fill: parent
            x: -1
            y: -1
            height: 82
            anchors.rightMargin: -1
            anchors.bottomMargin: 0
            anchors.leftMargin: -1
            anchors.topMargin: 0
            width: 83
            onClicked: {
                //parent.visible = false
                stackMain.pop()
            }
        }
    }

    ListView {
        id: tskModel
        x: 0
        y: 79
        width: parent.width; height: 320
        spacing: 14
        model: taskModel
        delegate: taskDelegate

        clip: true

        Component.onCompleted: {


            var lst = controller.getTasksList(controller.getTextTheme());
            for(var i = 0; i < lst.length; i++) {
                model.append({ task_name: lst[i].task_name, type: lst[i].type, text: lst[i].number });

                console.log(lst + " - tasks list was read right.")

            }

        }
    }




    Component {
            id: taskDelegate

            Pane {
                   //Rectangle{
                   id: delegateTask
                   width:  mainTaskPage.width
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
                            text: model.task_name
                            font.pixelSize: 20

                        }


                        Text {
                            text: model.type
                            visible: false
                        }



                   }

                   //signal qmlSignal(var anObject)

                   MouseArea{
                       anchors.fill: parent
                       hoverEnabled: true

                       onClicked: {

                           tskModel.currentIndex = index



                           //controller.setTextTheme(model.modelData.theme_name);

                           if(model.type === "words"){
                                 controller.setChosenTask(tskModel.currentIndex);
//                                 console.log("\n")
//                                 console.log("###################################")
//                                 console.log("Trying to open task - " + index)
//                                 console.log(controller.getTextTheme() + " theme")
//                                 console.log(controller.getTheme(controller.getTextTheme()))
//                                 console.log("###################################")
//                                 console.log("\n")
//                                 console.log("\n")
                                 tskModel.currentIndex = 0
                                 stackMain.push("qrc:/WordTranslation.qml")
                           }

                           if(model.type === "sentenses"){
                                 controller.setChosenTask(tskModel.currentIndex);
                                 tskModel.currentIndex = 0
                                 stackMain.push("qrc:/SentTranslation.qml")
                           }
                           if(model.type === "check"){
                                 controller.setChosenTask(tskModel.currentIndex);
                                 tskModel.currentIndex = 0
                                 stackMain.push("qrc:/checkTask.qml")
                           }


                           //stackMain.push("qrc:/WordTranslation.qml")
                       }
                   }

            }




    }

    Label {
        id: label
        x: 8
        y: 51
        width: 155
        height: 22
        text: qsTr("Задания:")
        font.pointSize: 14
        color: "#555555"
    }


}
