import QtQuick 2.15
import QtQuick.Controls 2.15

import "../CustomComponent"

Rectangle {
    width: 462
    height: 100
    Rectangle{
        id: userImage
        width: height
        height: parent.height
        Rectangle{
            width: parent.width*0.6
            height: parent.height*0.6
            anchors.centerIn: parent
            color: "transparent"
            CircleImage {
                id: mouthan
                anchors.fill: parent
                source: "../Resource/mouthan.png"
            }
        }
    }

    Rectangle{
        width: parent.width - userImage.width
        height: parent.height
        anchors.right: parent.right
        Rectangle{
            id: groupNameZone
            width: parent.width - 150
            height: 40
            x: 10
            y: parent.height*0.2
            Text {
                id: groupName
                anchors.fill: parent
                text: qsTr("Group Name")
                font.pixelSize: 20
            }

        }
        Rectangle{
            width: groupNameZone.width
            height: groupNameZone.height
            anchors.top: groupNameZone.bottom
            x: groupNameZone.x

            Text {
                id: lastText
                anchors.fill: parent
                font.pixelSize: 15
                text: qsTr("This is the last text recive from backend")
            }
        }

        Rectangle{
            id: chatInfor
            width: parent.width - groupNameZone.width
            height: parent.height
            anchors.right: parent.right
            Rectangle{
                width: 30
                height: 20
                anchors.horizontalCenter: parent.horizontalCenter
                y: parent.height*0.5
                color: "red"
                radius: width
                Text {
                    anchors.centerIn: parent
                    font.pixelSize: 20
                    color: "white"
                    text: qsTr("N")
                }
            }

            Rectangle{
                width: parent.width*0.8
                height: 20
                anchors.horizontalCenter: parent.horizontalCenter
                y: parent.height*0.2
                Text {
                    anchors.centerIn: parent
                    font.pixelSize: 15
                    color: "gray"
                    text: qsTr("3 Gio")
                }
            }
        }


    }

    MouseArea{
        anchors.fill: parent
        onClicked: {
            rootWindow.setConversationView()
        }
    }

}
