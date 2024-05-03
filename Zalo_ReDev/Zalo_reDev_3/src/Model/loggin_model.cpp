#include "loggin_model.h"
#include <QJsonDocument>
#include <QJsonObject>
#include <QDebug>

Logging_Model::Logging_Model(QObject *parent) : QObject(parent)
{
    m_baseUrl = "http://localhost:8099";
}

void Logging_Model::registerUser(const QString &phoneNumber, const QString &username, const QString &password)
{
    // Construct JSON data for registration
    QJsonObject json;
    json["phoneNumber"] = phoneNumber;
    json["username"] = username;
    json["password"] = password;

    QJsonDocument doc(json);
    QByteArray requestData = doc.toJson();

    sendRequest("/auth/register", requestData);
}

void Logging_Model::loginUser(const QString &phoneNumber, const QString &password)
{
    // Construct JSON data for login
    QJsonObject json;
    json["phoneNumber"] = phoneNumber;
    json["password"] = password;

    QJsonDocument doc(json);
    QByteArray requestData = doc.toJson();

    sendRequest("/auth/login", requestData);
}

void Logging_Model::logoutUser(const QString &accessToken)
{
    // Send logout request with access token
    QByteArray requestData = "Bearer " + accessToken.toUtf8();
    sendRequest("/logout", requestData);
}

void Logging_Model::registrationRequestFinished()
{
    handleResponse(qobject_cast<QNetworkReply*>(sender()));
}

void Logging_Model::loginRequestFinished()
{
    handleResponse(qobject_cast<QNetworkReply*>(sender()));
}

void Logging_Model::logoutRequestFinished()
{
    handleResponse(qobject_cast<QNetworkReply*>(sender()));
}

void Logging_Model::sendRequest(const QString &endpoint, const QByteArray &requestData)
{
    QNetworkRequest request;
    request.setUrl(QUrl(m_baseUrl + endpoint));
    request.setHeader(QNetworkRequest::ContentTypeHeader, "application/json");

    QNetworkReply *reply = nullptr;

    if (endpoint == "/auth/register") {
        reply = m_networkManager.post(request, requestData);
        connect(reply, &QNetworkReply::finished, this, &Logging_Model::registrationRequestFinished);
    } else if (endpoint == "/auth/login") {
        reply = m_networkManager.post(request, requestData);
        connect(reply, &QNetworkReply::finished, this, &Logging_Model::loginRequestFinished);
    } else if (endpoint == "/logout") {
        request.setRawHeader("Authorization", requestData);
        reply = m_networkManager.post(request, QByteArray());
        connect(reply, &QNetworkReply::finished, this, &Logging_Model::logoutRequestFinished);
    }

    if (reply) {
        connect(reply, &QNetworkReply::errorOccurred, this, &Logging_Model::handleNetworkError);
    } else {
        qDebug() << "Invalid endpoint:" << endpoint;
    }
}

void Logging_Model::handleNetworkError(QNetworkReply::NetworkError code)
{
    qDebug() << "Network error:" << code;
}

void Logging_Model::handleResponse(QNetworkReply *reply)
{
    if (reply->error() == QNetworkReply::NoError) {
        QByteArray responseData = reply->readAll();
        qDebug() << "Response:" << responseData;
    } else {
        qDebug() << "Request failed:" << reply->errorString();
    }
    reply->deleteLater();
}
