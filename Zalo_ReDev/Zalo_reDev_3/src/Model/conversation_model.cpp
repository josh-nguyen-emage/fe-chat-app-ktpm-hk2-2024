#include "conversation_model.h"
#include "src/AppDefine/define.h"

#include <src/Controller/PythonController.h>


Conversation_Model::Conversation_Model(QObject *parent) : QObject(parent)
{
    // Connect to WebSocket server
    m_webSocket.open(QUrl("ws://localhost:8080/conversations"));

    // Connect signals to slots
    connect(&m_webSocket, &QWebSocket::textMessageReceived,
            this, &Conversation_Model::onMessageReceived);
}

void Conversation_Model::sendMessage(QString text)
{
    qDebug() << "Send message" << text;
    // Construct JSON message to send
    QJsonObject messageObject;
    messageObject["textBody"] = text;
    // Add other fields as required by your API

    // Convert JSON to string
    QJsonDocument doc(messageObject);
    QString jsonString = doc.toJson(QJsonDocument::Compact);

    // Send message to WebSocket server
    // m_webSocket.sendTextMessage(jsonString);

    //try 1
    jsonString = "CONNECT\naccept-version:1.0\nheart-beat:10000,10000\n\n\u0000";
    m_webSocket.sendTextMessage(jsonString);
    jsonString = "SUBSCRIBE\ndestination:/queue/messages\nid:1\n\n\u0000";
    m_webSocket.sendTextMessage(jsonString);
    jsonString = "SEND\ndestination:/app/conversations\n{\"textBody\":\"ssss\"}\n\n\u0000";
    m_webSocket.sendTextMessage(jsonString);

    qDebug() << "Send " << jsonString << " done";
    qDebug() << "Send " << jsonString[4] << " done";
}

void Conversation_Model::uploadImage(QString imagePath)
{
    PythonController pythonController;
    QStringList inputArgument;
    inputArgument.append(imagePath);
    QStringList returnJson = pythonController.runPythonScript(Define::getInstance().backendPath+"\\uploadImage.py",inputArgument);

    QJsonDocument jsonDocument = QJsonDocument::fromJson(returnJson[0].toUtf8());

    if (!jsonDocument.isObject()) {
        qDebug() << "WTF bro ??? why "<<inputArgument[0]<<" return " << returnJson;
    }
    QJsonObject jsonObject = jsonDocument.object();
    QJsonValue idValue = jsonObject.value("id");

    qDebug() << "Image ID: " << idValue.toInt();
}

void Conversation_Model::downloadImage(int imageID)
{
    PythonController pythonController;
    QStringList inputArgument;
    inputArgument.append(QString::number(imageID));
    QStringList returnJson = pythonController.runPythonScript(Define::getInstance().backendPath+"\\downloadImage.py",inputArgument);

    QJsonDocument jsonDocument = QJsonDocument::fromJson(returnJson[0].toUtf8());

    if (!jsonDocument.isObject()) {
        qDebug() << "WTF bro ??? why "<<inputArgument[0]<<" return " << returnJson;
    }
    QJsonObject jsonObject = jsonDocument.object();
    QJsonValue idValue = jsonObject.value("id");

    qDebug() << "Image ID: " << idValue.toInt();
}

void Conversation_Model::onMessageReceived(const QString& message)
{
    // Parse received JSON message
    QJsonDocument doc = QJsonDocument::fromJson(message.toUtf8());
    if (!doc.isNull()) {
        QJsonObject object = doc.object();
        // Extract data fields from the received message
        QString textBody = object["textBody"].toString();
        // Extract other fields as required

        // Output received data using QDebug
        qDebug() << "Received message:" << textBody;
        // Output other fields as required
    }
    else {
        qDebug() << "Received invalid JSON message:" << message;
    }
}
