import QtQuick 6.2
import QtQuick.Controls

Rectangle{
    width: 500
    height: 500
    Button{
        anchors.centerIn: parent
        onClicked: {
            testOnly.trigger("ui trigger")
        }
    }
}
