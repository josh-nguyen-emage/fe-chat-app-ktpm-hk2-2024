#include "persionalinforvm.h"
#include "qjsondocument.h"
#include "qjsonobject.h"

PersionalInforVM::PersionalInforVM(QObject *parent)
    : QObject{parent}
{}

QVariantList PersionalInforVM::requestUserData()
{
    QString persionalInfor = persionalInfor_Model.requestUserData();
    qDebug() << "PersionalInforVM :" << persionalInfor;

    QVariantList userInfo;
    QJsonDocument jsonDocument = QJsonDocument::fromJson(persionalInfor.toUtf8());
    if (!jsonDocument.isNull()) {
        QJsonObject jsonObject = jsonDocument.object();

        // Extract values
        QString username = jsonObject["username"].toString();
        QString phoneNumber = jsonObject["phoneNumber"].toString();
        QString email = jsonObject["emailAddress"].toString();
        QString firstName = jsonObject["firstName"].toString();
        QString lastName = jsonObject["lastName"].toString();
        QString birthDate = jsonObject["birthDate"].toString();

        // Append values to QVariantList
        userInfo.append(username);
        userInfo.append(phoneNumber);
        userInfo.append(email);
        userInfo.append(firstName);
        userInfo.append(lastName);
        userInfo.append(birthDate);
    }

    return userInfo;
}
