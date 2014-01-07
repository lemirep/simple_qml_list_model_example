import QtQuick 2.0
import org.qtproject.models 1.0

Rectangle {
    width: 800
    height: 600
    color : "red"

    Car
    {
        id : car_1
        carName : "H1"
        carBrand : "Hummer"
        carPrice : 125000
    }

    ListView
    {
        anchors
        {
            left : parent.left
            right : parent.right
            top : parent.top
            bottom : parent.verticalCenter
        }
        model : myCarModel
        delegate: car_delegate
    }


    Rectangle
    {
        width : 200
        height : 50
        color : "orange"
        radius : 15

        anchors
        {
            horizontalCenter : parent.horizontalCenter
            bottom : parent.bottom
        }

        Text
        {
            anchors.centerIn: parent
            text : "Add car_1 to model";
        }
        MouseArea
        {
            anchors.fill: parent
            onClicked: myCarModel.appendRowFromQml(car_1);
        }
    }

    Component {
        id : car_delegate
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
            MouseArea
            {
                anchors.fill: parent
                onClicked:
                {
                    model.car_price += 1
                }
            }
        }
    }
}
