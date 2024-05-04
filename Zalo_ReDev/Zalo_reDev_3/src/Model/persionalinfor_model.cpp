#include "persionalinfor_model.h"
#include "qdebug.h"

PersionalInfor_Model::PersionalInfor_Model(QObject *parent)
    : QObject{parent}
{

    manager = new QNetworkAccessManager(this);
    connect(manager, &QNetworkAccessManager::finished, this, [=](QNetworkReply *reply) {
        if (reply->error() == QNetworkReply::NoError) {
            qDebug() << "Request succeeded";
            // Handle the reply here
        } else {
            qDebug() << "Error:" << reply->errorString();
            // Handle the error here
        }
        reply->deleteLater();
    });
}

void PersionalInfor_Model::reciveUserToken(const QString &accessToken)
{
    currentUserToken = accessToken;
    qDebug() << "currentToken:" << currentUserToken;
}

void PersionalInfor_Model::requestUserData()
{
    QNetworkRequest request(QUrl("http://localhost:8099/user/0868951004"));
    request.setHeader(QNetworkRequest::ContentTypeHeader, "application/json");
    request.setRawHeader("Authorization", "Bearer " + currentUserToken.toUtf8());
    manager->get(request);
}
