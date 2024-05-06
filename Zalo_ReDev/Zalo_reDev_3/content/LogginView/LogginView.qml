import QtQuick 6.2
import QtQuick.Controls
import QtQuick.Layouts
import QtWebSockets

Rectangle{
    width: 462
    height: 1000
    color: "#aad6ff"

    Connections{
        target: logginVM
        function onSignal_loginSuccess(tokenValue){
            console.log("qml loggin sucess Trigger", tokenValue)
            rootWindow.setChatList()
        }
    }

    ColumnLayout{
        anchors.centerIn: parent
        width: parent.width*0.8
        spacing: 0
        Rectangle{
            Layout.fillWidth: true
            Layout.preferredHeight: 200
            color: "transparent"
            Image {
                source: "../Resource/zalo_logo.png"
                width: parent.width
                height: parent.height/2
                fillMode: Image.PreserveAspectFit
            }
            Text{
                width: parent.width
                height: parent.height/2
                anchors.bottom: parent.bottom
                text: "Đăng nhập tài khoản Zalo\nđể kết nối với ứng dụng Zalo Web"
                horizontalAlignment: Text.AlignHCenter
                font.pixelSize: 20
                color: "#454c52"
            }
        }

        Rectangle{
            Layout.fillWidth: true
            Layout.preferredHeight: 200
            ColumnLayout{
                anchors.fill: parent
                Rectangle{
                    Layout.fillWidth: true
                    Layout.preferredHeight: 50
                    Image {
                        source: "../Resource/phoneIcon.png"
                        width: parent.height
                        height: parent.height
                        fillMode: Image.PreserveAspectFit
                    }
                    TextInput {
                        id: phoneNumberInput
                        width: parent.width - parent.height
                        anchors.right: parent.right
                        text: "0868951005"
                        font.pixelSize: 25
                        anchors.verticalCenter: parent.verticalCenter
                    }
                    Rectangle{
                        width: parent.width
                        height: 1
                        anchors.bottom: parent.bottom
                        color: "#edeef1"
                    }
                }

                Rectangle{
                    Layout.fillWidth: true
                    Layout.preferredHeight: 50
                    Image {
                        source: "../Resource/passIcon.png"
                        width: parent.height
                        height: parent.height
                        fillMode: Image.PreserveAspectFit
                    }
                    TextInput {
                        id: passwordInput
                        width: parent.width - parent.height
                        anchors.right: parent.right
                        text: "Test_regist#123"
                        echoMode: TextInput.Password
                        horizontalAlignment: Text.AlignLeft
                        clip: true
                        font.pixelSize: 25
                        anchors.verticalCenter: parent.verticalCenter
                    }
                    Rectangle{
                        width: parent.width
                        height: 1
                        anchors.bottom: parent.bottom
                        color: "#edeef1"
                    }
                }

                Rectangle{
                    Layout.fillWidth: true
                    Layout.preferredHeight: 50
                    Rectangle{
                        width: parent.width*0.7
                        height: parent.height*0.7
                        anchors.centerIn: parent
                        color: "#0190f3"
                        radius: 5
                        Text{
                            id: logginTextButton
                            text: "Đăng nhập"
                            color: "white"
                            font.pixelSize: 20
                            anchors.centerIn: parent
                        }

                        MouseArea{
                            anchors.fill: parent
                            onClicked: {
                                console.log("loggin clicked")
                                logginVM.loginUser(phoneNumberInput.text, passwordInput.text)
                                logginTextButton.text = "..."
                            }
                        }
                    }
                }

                Rectangle{
                    Layout.fillWidth: true
                    Layout.fillHeight: true
                }
            }
        }




    }


}
