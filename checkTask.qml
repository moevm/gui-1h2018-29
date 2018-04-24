import QtQuick 2.0
import QtQuick.Controls 2.3

Item {

    property int c: -1
    property var chosen: 0
    property var lst
    property bool clickedOnce: false

    // использование Math.round() даст неравномерное распределение!
    function getRandomInt(min, max)
    {
      return Math.floor(Math.random() * (max - min + 1)) + min;
    }


    Item {
        id: item1
        x: 190
        y: 105
        width: 263
        height: 62

        Text{
            id: word
            font.pixelSize: 20
        }
        Component.onCompleted: {

//            var radio ={


//            };

//            radio.r1 = radioButton
//            radio.r2 = radioButton1
//            radio.r3 = radioButton2
//            radio.r4 = radioButton3

            lst = controller.getTheme(controller.getTextTheme()).getTaskElement(controller.getChosenTask()).getListPairs();

            //console.log(lst)

            setWord(lst, c-1)

        }
    }

    function setWord(lst, i){
        c++
        if(lst.length > c){
            console.log(lst[c].word)
            word.text = lst[c].word

            var rand = getRandomInt(0,3)

            switch(rand){
            case 0:
                radioButton3.text = lst[c].fake1;
                radioButton1.text = lst[c].fake2;
                radioButton2.text = lst[c].fake3;
                radioButton.text = lst[c].meaning;
            break

            case 1:
                radioButton.text = lst[c].fake2;
                radioButton1.text = lst[c].meaning;
                radioButton3.text = lst[c].fake1;
                radioButton2.text = lst[c].fake3;

            break

            case 2:
                radioButton.text = lst[c].fake3;
                radioButton1.text = lst[c].fake2;
                radioButton2.text = lst[c].fake1;
                radioButton3.text = lst[c].meaning;
            break


            case 3:
                radioButton.text = lst[c].fake1;
                radioButton1.text = lst[c].fake2;
                radioButton3.text = lst[c].fake3;
                radioButton2.text = lst[c].meaning;
            break


            }


        } else {
            word.text = qsTr("Done")
            controller.getTheme(controller.getTextTheme()).getTaskElement(controller.getChosenTask()).setCompleted();
            radioButton.visible = false
            radioButton1.visible = false
            radioButton2.visible = false
            radioButton3.visible = false
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

    Text{
        id: txt
        text:""
    }


    function checkTask(checking, c){
        //var lst = controller.getTheme(controller.getTextTheme()).getTaskElement(controller.getChosenTask()).getListPairs();

        console.log(checking)

        if(lst[c].meaning === checking){
            if(c < lst.length){

                setWord(lst, c)

            } else {

            }

        } else {
            word.text = "wrong! " + lst[c].word
        }

    }

    Button {
        id: button
        x: 272
        y: 380
        text: qsTr("Далее")

        onClicked: {
            if(clickedOnce){
                if(chosen == 0){
                    checkTask(radioButton.text, c)
                    radioButton.checked = false
                }
                if(chosen == 1){
                    checkTask(radioButton1.text, c)
                    radioButton1.checked = false
                }
                if(chosen == 2){
                    checkTask(radioButton2.text, c)
                    radioButton2.checked = false
                }
                if(chosen == 3){
                    checkTask(radioButton3.text, c)
                    radioButton3.checked = false
                }

            }


        }
    }

    RadioButton {
        id: radioButton
        x: 198
        y: 173
        width: 240
        height: 40
        onClicked: {
            chosen = 0
            clickedOnce = true
        }
    }

    RadioButton {
        id: radioButton1
        x: 198
        y: 220
        onClicked: {
            chosen = 1
            clickedOnce = true

        }
    }

    RadioButton {
        id: radioButton2
        x: 198
        y: 266
        onClicked: {
            chosen = 2
            clickedOnce = true

        }
    }

    RadioButton {
        id: radioButton3
        x: 198
        y: 312
        onClicked: {
            chosen = 3
            clickedOnce = true

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
            radioButton.visible = true
            radioButton1.visible = true
            radioButton2.visible = true
            radioButton3.visible = true
            button.visible = true

            //var lst = controller.getTheme(controller.getTextTheme()).getTaskElement(controller.getChosenTask()).getListPairs();
            c = -1
            setWord(lst, c)
        }

    }




}
