#include "conversation_model.h"
#include "src/AppDefine/define.h"

Conversation_Model::Conversation_Model(QObject *parent) : QObject(parent)
{
    reciverController = nullptr;
}

void Conversation_Model::updateReciverID(QString newTopic)
{
    if (reciverController != nullptr){
        delete reciverController;
    }
    reciverController = new PythonController();
    QStringList inputArgument;

    inputArgument.append(newTopic);
    reciverController->streamPythonScript(Define::getInstance().backendPath+"\\STOMP\\main_sub.py",inputArgument);
    Conversation_Model::connect(reciverController,&PythonController::pythonOutput,this,&Conversation_Model::onMessageReceived);

}

void Conversation_Model::sendMessage(QString text)
{
    PythonController pythonController;
    // Construct JSON message to send
    QJsonObject messageObject;
    messageObject["textBody"] = text;
    messageObject["senderId"] = "1";
    messageObject["conversationId"] = "3";
    messageObject["sendTime"] = "2024-05-01T10:21:45.421953";
    // Add other fields as required by your API

    // Convert JSON to string
    QJsonDocument doc(messageObject);
    QString jsonString = doc.toJson(QJsonDocument::Compact);

    QStringList inputArgument;
    inputArgument.append(jsonString);

    QStringList returnJson = pythonController.runPythonScript(Define::getInstance().backendPath+"\\STOMP\\main_pub.py",inputArgument);

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
    qDebug() << "Message recive, fuck yeah";
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
