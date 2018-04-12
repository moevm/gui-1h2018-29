import QtQuick 2.0
import QtQuick.Controls 2.3

Item {
    id: item2

    property int c: 0

    function setWord(lst, i){
        if(lst.length > c){
            word.text = lst[i].word
        } else {
            word.text = qsTr("Done")
            textField.visible = false
            button.visible = false
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
                stackMain.pop()
            }
        }

    }


    Item {
        id: item1
        anchors.bottom: parent.bottom
        anchors.bottomMargin: 331
        anchors.left: parent.left
        anchors.leftMargin: 24
        anchors.right: parent.right
        anchors.rightMargin: 8
        anchors.top: parent.top
        anchors.topMargin: 87

        Text{
            id: word
            anchors.rightMargin: 13
            anchors.bottomMargin: 0
            anchors.leftMargin: 174
            anchors.topMargin: 0
            anchors.fill: parent
            font.pixelSize: 20
        }
        Component.onCompleted: {

            var lst = controller.getTheme(controller.getTextTheme()).getTaskElement(controller.getChosenTask()).getListPairs();
            setWord(lst, c)



        }
    }

    Text{
        id: txt
        x: 41
        y: 30
        text:""
    }


    TextField {
        id: textField
        width: 591
        height: 43
        text: qsTr("")
        anchors.left: parent.left
        anchors.leftMargin: 41
        anchors.bottom: parent.bottom
        anchors.bottomMargin: 218
    }



    Button {
        id: button
        y: 305
        text: qsTr("Далее")
        anchors.right: parent.right
        anchors.rightMargin: 288
        anchors.left: parent.left
        anchors.leftMargin: 288
        anchors.bottom: parent.bottom
        anchors.bottomMargin: 127

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
        x: 541
        y: 67

        Image{
            source: "qrc:/src/loop.png"
            anchors.fill: parent
        }

        text: qsTr("")
        anchors.right: parent.right
        anchors.rightMargin: 35
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
