#include "conversation_model.h"


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
    qDebug() << "start uploadImage";
    // Initialize the network manager
    QNetworkAccessManager manager;

    // Create a QHttpMultiPart to hold the form data
    QHttpMultiPart *multiPart = new QHttpMultiPart(QHttpMultiPart::FormDataType);

    QString fileName = QFileInfo(imagePath).fileName();

    // Add the file
    QHttpPart filePart;
    filePart.setHeader(QNetworkRequest::ContentDispositionHeader, QVariant("form-data; Key=\"media_file\"; Value=\"" + fileName + "\""));


    QFile *file = new QFile(imagePath);
    if (!file->open(QIODevice::ReadOnly))
    {
        qDebug() << "Could not open file for reading";
        return;
    }
    filePart.setBodyDevice(file);
    multiPart->append(filePart);

    // Construct the URL
    QUrl url("http://localhost:8080/chatapp/api/media/upload");
    QNetworkRequest request(url);

    // Send the request
    QNetworkReply *reply = manager.post(request, multiPart);

    qDebug() << "Send Done";

    // Connect signals for handling the reply
    QObject::connect(reply, &QNetworkReply::finished, [&]() {
        if (reply->error() == QNetworkReply::NoError)
        {
            qDebug() << "Upload successful";
            qDebug() << "Response:" << reply->readAll();
        }
        else
        {
            qDebug() << "Error:" << reply->errorString();
        }
        // Clean up
        multiPart->deleteLater(); // delete the multiPart
        file->deleteLater();      // delete the file
        reply->deleteLater();     // delete the reply
    });
    qDebug() << "Function Done";
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
