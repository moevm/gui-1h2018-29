import QtQuick 2.0



Item {

    Connections {
            target: controller

            onSendToQml: {
                    t.text = s
                      // someNumber = s // Устанавливаем счётчик в текстовый лейбл
            }

    }

    function init(){
        var lst = ctxList.getListOfTasks();
    }

    Rectangle{
        Component.onCompleted: {
            init();
        }
        id: back
        x: 0
        y: 0
        width: 35
        height: 35
        color: "red"
        Text{
        id:t
        text: "hu"
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
                stack.pop()
            }
        }
    }



    id: mainT
    property var someNumber: "Signal not recieved"

    Item {


        Component {
                id: taskDelegate
            Rectangle{
                color: "red"
                Text {
                    text: model.modelData.task_name + ": " + model.modelData.number
                }
            }
        }

        ListView {
            x: 0
            y: 105
            width: 641; height: 252
            spacing: 14
            model: ctxList
            delegate: taskDelegate

            Component.onCompleted: {
                var lst = ctxList.getListOfTasks();
                        for(var i = 0; i < lst.length; i++) {
                            model.append({ index: i, text: lst[i], type: "ItemDelegate", group: "Помещения", action: "move" });
                        }
            }
        }


        Text{
            id: task
            x: 209
            y: 221
            width: 198
            height: 19
            text: 'someNumber'
        }
    }

}
