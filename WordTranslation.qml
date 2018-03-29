import QtQuick 2.0
import QtQuick.Controls 2.3

Item {
    id: mainTaskWindow
    property int c: 0
    width: 840
    height: 480


    Item {
        id: item1
        x: 237
        y: 117
        width: 369
        height: 72

        Text{
           // anchors.left: mainTaskWindow.verticalCenter
            id: word
            x: 91
            y: 42
            width: 187
            height: 30
            horizontalAlignment: 80
            font.bold:  true
            font.pixelSize: 25

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

    Text{
        id: txt
        text:""
    }


    TextField {
        id: textField
        x: 354
        y: 212
        width: 263
        height: 56
        focus: false




    }

    Button {
        id: button
        x: 389
        y: 282
        text: qsTr("Далее")

        Component.onCompleted: {
            textField.focus = true
        }

        onClicked: {
            var lst = controller.getTheme(controller.getTextTheme()).getTaskElement(controller.getChosenTask()).getListPairs();
            if(lst[c].meaning === textField.text){
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

            textField.focus = true

        }
    }





}
