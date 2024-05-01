import QtQuick 6.2
import QtQuick.Controls
import QtWebSockets

Rectangle{
    width: 500
    height: 500
    WebSocket {
            id: webSocket
            url: "ws://localhost:8080/ws" // Replace with your STOMP server URL
            onConnected: {
                console.log("Connected to WebSocket");
                // Connect to STOMP after WebSocket connection
                connectToStomp();
            }
            onMessageReceived: {
                console.log("Received message:", message);
                // Handle STOMP messages here
                handleMessage(message);
            }
        }

        function connectToStomp() {
            var connectFrame = "CONNECT\n" +
                                "accept-version:1.0\n" +
                                "heart-beat:10000,10000\n" +
                                "\n" +
                                "\u0000";
            webSocket.sendTextMessage(connectFrame);
        }

        function subscribeToTopic() {
            var subscribeFrame = "SUBSCRIBE\n" +
                                "destination:/topic/messages\n" +
                                "id:0\n" +
                                "\n" +
                                "\u0000";
            webSocket.sendTextMessage(subscribeFrame);
        }

        function handleMessage(message) {
            // Parse and handle STOMP message here
            // For example, display the message in a Text component
            messageText.text = JSON.parse(message).content;
        }

        Text {
            id: messageText
            anchors.centerIn: parent
        }

        Component.onCompleted: {
            // Connect to WebSocket when the QML component is completed
            webSocket.open();
        }

        Component.onDestruction: {
            // Disconnect WebSocket when the QML component is destroyed
            webSocket.close();
        }
}
