import QtQuick 2.5

Image{

    source: "/src/qwe.png"
    Rectangle{

       id: box
       width: 300
       height: 300
       color: "red"

       MouseArea
       {
           anchors.fill: box
           onClicked:
           {
               box.color = (box.color ==  "#ff0000")  ?  "green" :  "red"
           }
       }
    }


}



