import QtQuick 2.0
import QtQuick.Controls 2.3

Item {
    id: item2

    property int c: 0

    Item {
        id: item1
        x: 189
        y: 126
        width: 263
        height: 62

        Text{
            id: word
            anchors.rightMargin: 0
            anchors.bottomMargin: 0
            anchors.leftMargin: 0
            anchors.topMargin: 0
            anchors.fill: parent
            font.pixelSize: 20
        }
        Component.onCompleted: {

            var lst = controller.getTheme(controller.getTextTheme()).getTaskElement(controller.getChosenTask()).getListPairs();
            setWord(lst, c)

        }
    }

    function setWord(lst, i){
        if(lst.length > c){
            word.text = lst[i].word
        } else {
            word.text = qsTr("Done")
            textField.visible = false
            button.visible = false

            loop.visible = true
            c = 0
        }

    }

    function setWordEnd(word){
        word.text = word
    }

    function checkWord(lst, i){


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
                c = 0
                stackMain.pop()
                //controller.setChosenTask(0);
            }
        }
    }

    Text{
        id: txt
        text:""
    }


    TextField {
        id: textField
        y: 203
        height: 56
        anchors.right: parent.right
        anchors.rightMargin: 157
        anchors.left: parent.left
        anchors.leftMargin: 168
    }

    Button {
        id: button
        y: 288
        text: qsTr("Далее")
        anchors.left: parent.left
        anchors.leftMargin: 271
        anchors.right: parent.right
        anchors.rightMargin: 305

        onClicked: {
            var lst = controller.getTheme(controller.getTextTheme()).getTaskElement(controller.getChosenTask()).getListPairs();
            if(lst[c].meaning.toLowerCase() === textField.text.toLowerCase()){
                if(c < lst.length){
                    c++
                    setWord(lst, c)
                    textField.text = ""
                } else {
                    //word.text = qsTr("Done")


                   //
                    //setWordEnd("word")
                  //word.text = 'Done'
                }

                //word.text = "RIGHT"
            } else {
                word.text = "wrong! " + lst[c].word
            }

        }
    }

    Button{
        id: loop
        x: 527
        y: 103

        Image{
            source: "qrc:/src/loop.png"
            anchors.fill: parent
        }

        text: qsTr("")
        anchors.right: parent.right
        anchors.rightMargin: 49
        //visible: false

        onClicked: {
            textField.visible = true
            button.visible = true

            var lst = controller.getTheme(controller.getTextTheme()).getTaskElement(controller.getChosenTask()).getListPairs();
            c = 0
            setWord(lst, c)
        }

    }




}
