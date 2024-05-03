import QtQuick 2.15
import QtQuick.Layouts 1.15
import QtQuick.Controls 2.15

Rectangle {
    width: 462
    height: 1000

    ColumnLayout {
        id: mainWindow
        anchors.fill: parent
        spacing: 0
        Rectangle{
            Layout.fillWidth: true
            Layout.preferredHeight: mainWindow.height*0.1
            color: "#009ef9"
            gradient: Gradient {
                orientation: Gradient.Horizontal
                GradientStop { position: 0.0; color: "#0085fe" }
                GradientStop { position: 1.0; color: "#00acf4" }
            }

            IconImage{
                anchors.fill: parent
                source: "../Resource/main_header.png"
                fillMode: Image.PreserveAspectFit
                color: "white"
            }
        }
        Rectangle {
            id: center
            Layout.fillWidth: true
            Layout.fillHeight: true
            clip: true
            ListView {
                width: parent.width
                height: parent.height

                model: ListModel {
                    ListElement {
                        imagePath: "../Resource/mouthan.png";
                        chatName: "Alice";
                        lastText: "Hey, how's it going?";
                        isReaded: true
                    }

                    ListElement {
                        imagePath: "../Resource/mouthan.png";
                        chatName: "Bob";
                        lastText: "Not bad, you?";
                        isReaded: false
                    }

                    ListElement {
                        imagePath: "../Resource/mouthan.png";
                        chatName: "Charlie";
                        lastText: "I'm doing well, thanks!";
                        isReaded: true
                    }

                    ListElement {
                        imagePath: "../Resource/mouthan.png";
                        chatName: "David";
                        lastText: "Anyone seen my keys?";
                        isReaded: false
                    }

                    ListElement {
                        imagePath: "../Resource/mouthan.png";
                        chatName: "Emma";
                        lastText: "I'll help you look for them.";
                        isReaded: true
                    }

                    ListElement {
                        imagePath: "../Resource/mouthan.png";
                        chatName: "Frank";
                        lastText: "Did you hear about the concert next week?";
                        isReaded: false
                    }

                    ListElement {
                        imagePath: "../Resource/mouthan.png";
                        chatName: "Grace";
                        lastText: "Yes! I'm so excited!";
                        isReaded: true
                    }
                }


                delegate: ChatComponent {
                    parentDeletageModel: model
                }
            }
        }

        Rectangle {
            Layout.preferredWidth: parent.width
            Layout.preferredHeight: 1
            color: "#b3b3b3"
        }

        Rectangle {
            Layout.preferredWidth: parent.width
            Layout.preferredHeight: parent.height*0.1
            color: "white"
            Rectangle{
                width: parent.width/2
                height: parent.height
                IconImage{
                    width: 50
                    height: width
                    anchors.horizontalCenter: parent.horizontalCenter
                    y: parent.height * 0.1
                    source: "../Resource/messageButton.png"
                    fillMode: Image.PreserveAspectFit
                    color: "#777777"
                    Text{
                        text: "Tin Nhắn"
                        color: "#a1a1a1"
                        font.pixelSize: 15
                        anchors.horizontalCenter: parent.horizontalCenter
                        y: parent.height
                    }

                    MouseArea{
                        anchors.fill: parent
                        onClicked: {
                            console.log("message click")
                        }
                    }
                }
            }

            Rectangle{
                width: parent.width/2
                height: parent.height
                anchors.right: parent.right
                IconImage{
                    width: 50
                    height: width
                    anchors.horizontalCenter: parent.horizontalCenter
                    y: parent.height * 0.1
                    source: "../Resource/genderIcon.png"
                    fillMode: Image.PreserveAspectFit
                    color: "#777777"
                    Text{
                        text: "Cá Nhân"
                        color: "#a1a1a1"
                        font.pixelSize: 15
                        anchors.horizontalCenter: parent.horizontalCenter
                        y: parent.height
                    }

                    MouseArea{
                        anchors.fill: parent
                        onClicked: {
                            console.log("persional tab")
                            rootWindow.setPersionalInforView()
                        }
                    }
                }
            }
        }
    }
}
