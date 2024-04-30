import QtQuick 2.15
import QtQuick.Layouts 1.15
import QtQuick.Controls 2.15

Item {
    id: mainWindow
    width: 462
    height: 1000

    ColumnLayout{
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
                source: "../Resource/chat_header.png"
                fillMode: Image.PreserveAspectFit
                color: "white"
            }

            Text{
                x: parent.width * 0.07
                y: parent.height * 0.5
                text: "Duy Thịnh"
                color: "white"
                font.bold: true
                font.pixelSize: 23
            }

            Text{
                x: parent.width * 0.07
                y: parent.height * 0.77
                text: "Truy cập 12 phút trước"
                color: "white"
                font.pixelSize: 15
            }
        }

        Rectangle{
            Layout.fillWidth: true
            Layout.fillHeight: true
            color: "#e2e9f1"
            ListView {
                id: listView
                anchors.fill: parent
                model: ListModel {
                    ListElement { send: true; content: "obviously neither of those. It also has an aspect ratio of about";
                        value3: "Description of Item 1" }
                    ListElement { send: false; content: "obviously neither of those. It also has an aspect ratio of about";
                        value3: "Description of Item 1" }
                    ListElement { send: true; content: "bruh một hai ba bốn năm";
                        value3: "Description of Item 1" }
                    ListElement { send: false; content: "ba hai một";
                        value3: "Description of Item 1" }
                    ListElement { send: true; content: "We’d love to know when best time of year to visit your country. Also, we want to meet people of our own age (17-18). What’s the best way to do this?";
                        value3: "Description of Item 1" }
                    // Add more ListElements as needed
                }

                delegate: Rectangle {
                    width: listView.width
                    height: textBlock.height + 20
                    color: "transparent"

                    Rectangle {
                        y: 10
                        id: userAvatar
                        width: 40
                        height: 40
                        visible: model.send
                        Rectangle {
                            anchors.centerIn: parent
                            width: 30
                            height: 30
                            Image{
                                anchors.fill: parent
                                source: "../Resource/mouthan.png"
                                fillMode: Image.PreserveAspectFit
                            }
                        }
                    }

                    Rectangle {
                        y: 10
                        id: textBlock
                        width: textItem.contentWidth + 30 // Width of the rectangle
                        height: textItem.contentHeight + 20 // Height of the rectangle adjusts to content
                        color: model.send?"#d0f0fd":"white"
                        radius: 10
                        x: model.send?userAvatar.width + 10:parent.width - width - 10
                        border.width: 1
                        border.color: "#d6d9dc"
                    }

                    Text {
                        id: textItem
                        text: model.content
                        wrapMode: Text.WordWrap // Allow text wrapping
                        leftPadding: 10
                        width: 350 // Text width same as rectangle width
                        anchors.verticalCenter: parent.verticalCenter
                        x: model.send?userAvatar.width + 10:parent.width - textItem.contentWidth - 30
                        font.pixelSize: 20
                    }

                }
            }
        }

        Rectangle{
            Layout.fillWidth: true
            Layout.preferredHeight: mainWindow.height*0.05
            TextField {
                id: textInput
                width: parent.width - parent.height
                height: parent.height
                placeholderText: "Enter text here..."
                anchors.left: parent.left

                // Define behavior when text is entered
                onTextChanged: {
                    console.log("Text entered:", textInput.text)
                }
            }
            Rectangle{
                width: parent.height
                height: parent.height
                anchors.right: parent.right
                Image {
                    source: "../Resource/imageIcon"
                    width: parent.width
                    height: parent.height
                }
            }
        }
    }


}
