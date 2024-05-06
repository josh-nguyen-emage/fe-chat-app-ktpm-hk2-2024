#include "persionalinfor_model.h"
#include "qdebug.h"
#include "qjsondocument.h"
#include "qjsonobject.h"
#include "src/Controller/PythonController.h"
#include "src/AppDefine/define.h"

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

QString PersionalInfor_Model::requestUserData()
{
    PythonController pythonController;

    QStringList inputArgument;
    inputArgument.append(currentUserToken);
    inputArgument.append(Define::getInstance().phoneNumber);

    QStringList returnJson = pythonController.runPythonScript(Define::getInstance().backendPath+"\\GetUserData.py",inputArgument);
    return returnJson[0];
}

void PersionalInfor_Model::setUserInformation()
{
    QJsonObject userObject;
    userObject["username"] = "Duy Thinh";
    userObject["password"] = "7c4da56eH--@123456abcDEF-";
    userObject["emailAddress"] = "duythinh141592@gmail.com";
    userObject["avatarUrl"] = "";
    userObject["firstName"] = "Duy";
    userObject["lastName"] = "Thinh";
    userObject["birthDate"] = "2001-05-04";

    QJsonDocument doc(userObject);

    QByteArray jsonData = doc.toJson();

    QNetworkRequest request(QUrl("http://localhost:8099/user/0868951004"));
    request.setHeader(QNetworkRequest::ContentTypeHeader, "application/json");
    request.setRawHeader("Authorization", "Bearer " + currentUserToken.toUtf8());

    manager->post(request, jsonData);
}
