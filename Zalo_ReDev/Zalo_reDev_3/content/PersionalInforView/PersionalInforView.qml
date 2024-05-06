import QtQuick 2.15
import QtQuick.Layouts 1.15
import QtQuick.Controls 2.15

Item {
    id: mainWindow
    width: 462
    height: 1000

    Component.onCompleted: {
        var dataList = persionalInforVM.requestUserData()
        viewUserName.value = dataList[0]
        viewPhoneNumber.value = dataList[1]
        viewEmail.value = dataList[2]
        viewName.value = dataList[3] + " " + dataList[4]
        viewBirthDate.value = dataList[5]
        console.log(dataList)

    }

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
                source: "../Resource/persionalInfor_header.png"
                fillMode: Image.PreserveAspectFit
                color: "white"
            }

            Text{
                x: parent.width * 0.07
                y: parent.height * 0.55
                text: "Thông tin cá nhân"
                color: "white"
                font.bold: true
                font.pixelSize: 20
            }

            MouseArea{
                width: parent.width*0.08
                height: parent.height*0.5
                anchors.bottom: parent.bottom
                onClicked: {
                    rootWindow.setChatList()
                }
            }
        }

        Rectangle{
            Layout.fillWidth: true
            Layout.fillHeight: true
            color: "#e2e9f1"

            ColumnLayout{
                anchors.fill: parent
                spacing: 0
                Rectangle{
                    Layout.fillWidth: true
                    Layout.preferredHeight: 150
                    Image{
                        height: parent.height * 0.8
                        width: height
                        anchors.centerIn: parent
                        source: "../Resource/mouthan.png"
                    }
                }

                InformationComponent{
                    id: viewName
                    Layout.fillWidth: true
                    Layout.preferredHeight: 60
                    iconSource: "../Resource/zaloNameIcon.png"
                    label: "Tên"
                    value: "Nguyễn Duy Thịnh"
                }

                InformationComponent{
                    id: viewUserName
                    Layout.fillWidth: true
                    Layout.preferredHeight: 60
                    iconSource: "../Resource/zaloNameIcon.png"
                    label: "User Name"
                    value: "Duy Thịnh"
                }

                InformationComponent{
                    id: viewEmail
                    Layout.fillWidth: true
                    Layout.preferredHeight: 60
                    iconSource: "../Resource/zaloNameIcon.png"
                    label: "Email"
                    value: "ndthinh.sdh232@hcmut.edu.vn"
                }

                InformationComponent{
                    id: viewPhoneNumber
                    Layout.fillWidth: true
                    Layout.preferredHeight: 60
                    iconSource: "../Resource/zaloNameIcon.png"
                    label: "Số Điện Thoại"
                    value: "0868951004"
                }

                InformationComponent{
                    id: viewBirthDate
                    Layout.fillWidth: true
                    Layout.preferredHeight: 60
                    iconSource: "../Resource/birthDate.png"
                    label: "Ngày Sinh"
                    value: "16/9/2001"
                }

                InformationComponent{
                    Layout.fillWidth: true
                    Layout.preferredHeight: 60
                    iconSource: "../Resource/genderIcon.png"
                    label: "Giới tính"
                    value: "Nam"
                }

                Rectangle{
                    Layout.fillWidth: true
                    Layout.preferredHeight: 60

                    Rectangle{
                        width: parent.width - 20
                        height: parent.height - 20
                        anchors.centerIn: parent
                        radius: height
                        color: "#e9edf0"
                        Text{
                            anchors.centerIn: parent
                            text: "Chỉnh sửa"
                            font.pixelSize: 20
                        }
                    }
                }

                Rectangle{
                    Layout.fillWidth: true
                    Layout.fillHeight: true
                    color: "transparent"
                }
            }
        }

    }


}
