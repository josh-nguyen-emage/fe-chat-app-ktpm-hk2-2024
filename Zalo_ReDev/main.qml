import QtQuick 2.15
import QtQuick.Window 2.15

import QtQuick.Controls 2.15

import io.qt.examples.backendcommunication 1.0

Window {
    width: 1080
    height: 1920
    visible: true
    title: qsTr("Hello World")

//    BackendCommunication {
//        id: backend
//    }

//    TextField {
//        text: backend.userName
//        placeholderText: qsTr("User name")
//        anchors.centerIn: parent

//        onEditingFinished: backend.userName = text
//    }

    HomeScreen{

    }

}
