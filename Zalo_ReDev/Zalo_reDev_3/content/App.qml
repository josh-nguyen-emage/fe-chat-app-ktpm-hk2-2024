// Copyright (C) 2021 The Qt Company Ltd.
// SPDX-License-Identifier: LicenseRef-Qt-Commercial OR GPL-3.0-only

import QtQuick 6.2
import QtQuick.Controls 2.15
import Zalo_reDev_3

import "ChartView"
import "PersionalInforView"
import "LogginView"

Window {
    id: rootWindow
    width: 462
    height: 1000
    visible: true
    title: qsTr("Hello World")

    StackView {
        id: stack
        initialItem: logginView
        anchors.fill: parent
    }

    Component{
        id: chatListView
        ChatListView{
            // anchors.fill: parent
        }
    }

    Component{
        id: conversationView
        ConversationView{
            // anchors.fill: parent
        }
    }

    Component{
        id: persionalInforView
        PersionalInforView{
            // anchors.fill: parent
        }
    }

    Component{
        id: logginView
        LogginView{
        }
    }

    function setChatList(){
        stack.push(chatListView)
    }

    function setConversationView() {
        stack.push(conversationView)
    }

    function setPersionalInforView(){
        stack.push(persionalInforView)
    }



//    ChatListView{
//        anchors.fill: parent
//    }

    // Test{
    //     anchors.centerIn: parent
    // }

}

