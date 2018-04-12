import QtQuick 2.5
import QtQuick.Window 2.2
import QtQuick.Controls 2.3
import QtQuick.Layouts 1.3
import QtQuick.Controls.Material 2.0
import QtGraphicalEffects 1.0
import QtQuick.Dialogs 1.0
import QtQml.Models 2.2



Item{
    StackView {
        id: stackView
        x: 0
        y: 0
        width: 640
        height: 480
        initialItem: view
        Component {
                id: view

                TaskModel {

                    }
                    //onClicked: stackView.push(view)
                }
       }
}

