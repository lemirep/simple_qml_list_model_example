import QtQuick 2.0

Rectangle {
    width: 800
    height: 600
    color : "red"

    ListView
    {
        anchors.fill: parent
        model : myCarModel
        delegate: Component {
           Rectangle
           {
               width : 800
               height : 50
               color : "blue"

               Text
               {
                   anchors.left: parent.left
                   anchors.verticalCenter : parent.verticalCenter
                   text : model.car_name
               }
               Text
               {
                   anchors.right: parent.right
                   anchors.verticalCenter : parent.verticalCenter
                   text : model.car_price
               }
               Text
               {
                   anchors.horizontalCenter : parent.horizontalCenter
                   anchors.verticalCenter : parent.verticalCenter
                   text : model.car_brand
               }
           }
        }
    }
}
