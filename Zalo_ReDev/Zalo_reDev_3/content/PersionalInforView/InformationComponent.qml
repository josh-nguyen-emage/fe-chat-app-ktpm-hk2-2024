import QtQuick 2.15
import QtQuick.Controls 2.15

Rectangle{
    id: currentRoot
    width: 462
    height: 70
    property string iconSource: "../Resource/zaloNameIcon.png"
    property string label: "Tên Zalo"
    property string value: "Nguyễn Duy Thịnh"
    property bool isPassword: false
    IconImage{
        height: parent.height * 0.6
        width: height
        anchors.verticalCenter: parent.verticalCenter
        x: 10
        source: currentRoot.iconSource
        color: "#727272"
    }

    Text{
        text: currentRoot.label
        font.pixelSize: 20
        color: "#707070"
        anchors.verticalCenter: parent.verticalCenter
        x: 70
    }

    Text{
        text: currentRoot.value
        font.pixelSize: 20
        color: "#4a4a4a"
        anchors.verticalCenter: parent.verticalCenter
        anchors.right: parent.right
        rightPadding: 15
    }

    Rectangle{
        x: 70
        width: parent.width - x
        height: 1
        color: "#e7e7e7"
        anchors.bottom: parent.bottom
    }
}
