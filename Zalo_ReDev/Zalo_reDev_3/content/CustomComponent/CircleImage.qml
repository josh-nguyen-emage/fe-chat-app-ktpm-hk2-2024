import QtQuick 2.15
import QtQuick.Effects

Image {
    id: sourceItem
    source: "../Resource/mouthan.png"
    anchors.centerIn: parent
    width: 20
    height: 20
    visible: true

    // MultiEffect {
    //     source: sourceItem
    //     anchors.fill: sourceItem
    //     maskEnabled: true
    //     maskSource: mask
    // }

    // Item {
    //     id: mask
    //     width: sourceItem.width
    //     height: sourceItem.height
    //     // layer.enabled: true
    //     visible: true

    //     Rectangle {
    //         width: sourceItem.width
    //         height: sourceItem.height
    //         radius: width/2
    //         color: "black"
    //     }
    // }
}
