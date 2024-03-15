import QtQuick 2.15
import QtQuick.Window 2.15

import "ChartViewModel"

Rectangle {
    width: 1080
    height: 1920

    Rectangle {
        id: mainWindow
        anchors.fill: parent
        Rectangle {
            id: header
            width: parent.width
            height: parent.height * 0.1
            color: "#00a0f8"
        }
        Rectangle {
            id: center
            width: parent.width
            height: parent.height * 0.8
            anchors.top: header.bottom
            clip: true
            ListView {
                width: parent.width
                height: parent.height

                model: ListModel {
                    ListElement {
                        name: "Item 1"
                    }
                    ListElement {
                        name: "Item 2"
                    }
                    ListElement {
                        name: "Item 3"
                    }
                    ListElement {
                        name: "Item 4"
                    }
                    ListElement {
                        name: "Item 5"
                    }
                    ListElement {}
                    ListElement {}
                    ListElement {}
                    ListElement {}
                    ListElement {}
                    ListElement {}
                    ListElement {}
                }

                delegate: ChatComponent {}
            }
        }

        Rectangle {
            anchors.bottom: parent.bottom
            width: parent.width
            height: parent.height * 0.1
            color: "blue"
        }
    }
}
