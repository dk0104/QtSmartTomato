import QtQuick 2.9
import QtQuick.Controls 2.2

Page {
    id: page
    width: 600
    height: 400
    property alias page: page

    Column {
        id: column
        spacing: 4
        anchors.fill: parent
        Rectangle{
            color: 'gray'
            width: parent.width
            height: parent.height/3


        }
        Rectangle{
            color: 'blue'
            width: parent.width
            height: parent.height-parent.height/3
            anchors.bottom: parent.bottom


        }
    }

}
