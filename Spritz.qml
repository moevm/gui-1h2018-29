import QtQuick 2.5
import QtQuick.Window 2.2
import QtQuick.Controls 2.0
import QtQuick.Layouts 1.3
import QtQuick.Controls.Material 2.0
import QtGraphicalEffects 1.0
import QtQuick.Dialogs 1.0

Item {
    id: item1
    SpinBox {
        id: spinBox
        value: 90
        onValueChanged: setFrequency()
        x: 426
        y: 98
        font.pointSize: 14
        spacing: 10
        focusPolicy: Qt.ClickFocus
        editable: true
        font.family: "Verdana"
        wheelEnabled: true
        to: 1000
    }

    Text {
        id: wordField
        x: 19
        y: 61
        width: 373
        height: 230
        font.weight: Font.Medium
        font.family: "Courier"
        font.pixelSize: 16
        text: qsTr("Для чтения выберите\nтекстовый(*.txt) файл\nна своем компьютере...")
        verticalAlignment: Text.AlignVCenter
        horizontalAlignment: Text.AlignHCenter
    }

    Text {
        id: info
        x: 426
        y: 61
        width: 155
        height: 25
        text: qsTr("Кол-во слов в минуту")
        font.pixelSize: 16
    }


    Button {
        id: button
        x: 465
        y: 312
        text: qsTr("Выбрать файл")
        onClicked: fileDialog.open()
    }

    Component.onCompleted: {
    }

    FileDialog {
        id: fileDialog
        title: "Please choose a file"
        folder: shortcuts.home
        nameFilters: [ "Text Files (*.txt);" ]
        onAccepted: {
            readTextFile(fileDialog.fileUrl); // получаем директорию файла
            close();
        }
        onRejected: {
            close()
        }
    }

    Image {
        id: playButton
        x: 80
        y: 310
        width: 50
        height: 50
        sourceSize.height: 0
        sourceSize.width: 50
        source: "qrc:/src/play.png"
        MouseArea {
            anchors.fill: parent
            onClicked: play()
        }

    }

    Image {
        id: pauseButton
        x: 180
        y: 310
        width: 50
        height: 50
        source: "qrc:/src/pause.png"
        MouseArea {
            anchors.fill: parent
            onClicked: pause()
        }
    }

    Image {
        id: stopButton
        x: 280
        y: 310
        width: 50
        height: 50
        source: "qrc:/src/stop.png"
        MouseArea {
            anchors.fill: parent
            onClicked: stop()
        }
    }

    Slider {
        id: slider
        x: 426
        y: 216
        focusPolicy: Qt.ClickFocus
        hoverEnabled: false
        spacing: 1
        wheelEnabled: true
        stepSize: 1
        to: 25
        from: 10
        font.pointSize: 14
        value: 16
        onValueChanged: changeFontSize()
    }

    Text {
        id: text1
        x: 426
        y: 179
        text: qsTr("Размер шрифта")
        font.pixelSize: 16
    }

    Timer{
        id: timer
        interval: 3000
        running: false
        repeat: true
        onTriggered: setTime()
    }

    property var words: ""
    property var frequency: 3000

    function readTextFile(path) {
        var rawFile = new XMLHttpRequest();
            rawFile.open("GET", path, false);
            rawFile.onreadystatechange = function ()
            {
                if(rawFile.readyState === 4)
                {
                    if(rawFile.status === 200 || rawFile.status == 0)
                    {
                        var currStory = rawFile.responseText;
                        words = currStory.split(" ");
                        wordField.text = "Нажмите кнопку 'play'"
                    }
                }
            }
            rawFile.send(null);
    }

    property int pos: 0

    function play() {
        if(words.length!=0 && timer.running==false) {
            timer.running = true;
            setTime();
        }
    }

    function pause() {
        timer.running = false;
    }

    function setFrequency() {
        timer.interval = 60000/spinBox.value;
    }

    function setTime() {
        if(pos <= words.length-1) {
            wordField.text = words[pos++];
        } else {
            timer.stop();
            pos=0;
            wordField.text = "Нажмите кнопку 'play'"
        }
    }

    function stop() {
        timer.stop()
        pos = 0;
        if(words.length!=0) {
            wordField.text = "Нажмите кнопку 'play'"
        }
    }

    function changeFontSize() {
        wordField.font.pixelSize = slider.value;
    }

}

