import QtQuick 2.5

Item {


    Connections {
            target: controller

            onSendToQml: {
                    //t.text = s
                      // someNumber = s // Устанавливаем счётчик в текстовый лейбл
            }

    }


    Text{
        x: 166
        y: 121
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

            anchors.leftMargin: -159

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
        x: 166
        y: 263
        width: 334
        height: 200

        Text{
            y: 19
            anchors.left: parent.horizontalCenter

            text: "Это " + controller.getNumberDoneTasks() / 6 * 100 + "% от курса.";
            anchors.leftMargin: -167

            font.pointSize: 14
        }
    }

    function setProgress(){
        progress.text = "Вы завершили " + controller.getNumberDoneTasks()  + " из 6 заданий!"
    }
}
