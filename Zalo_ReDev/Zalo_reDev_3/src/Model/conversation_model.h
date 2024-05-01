#ifndef CONVERSATION_MODEL_H
#define CONVERSATION_MODEL_H

#include <QObject>
#include <QWebSocket>
#include <QJsonObject>
#include <QJsonDocument>
#include <QQmlContext>
#include <QNetworkReply>
#include <QNetworkAccessManager>
#include <QNetworkRequest>
#include <QHttpMultiPart>
#include <QFile>
#include <QUrl>
#include <QFileInfo>

class Conversation_Model : public QObject
{
    Q_OBJECT
public:
    explicit Conversation_Model(QObject *parent = nullptr);

public slots:
    void sendMessage(QString text);
    void uploadImage(QString imagePath);
    void onMessageReceived(const QString& message);

private:
    QWebSocket m_webSocket;
};

#endif // CONVERSATION_MODEL_H