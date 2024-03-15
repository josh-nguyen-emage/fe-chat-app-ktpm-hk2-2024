#include "backendcommunication.h"

BackendCommunication::BackendCommunication(QObject *parent) :
    QObject(parent)
{

}

QString BackendCommunication::userName()
{
    return m_userName;
}

void BackendCommunication::setUserName(const QString &userName)
{
    if (userName == m_userName)
        return;

    m_userName = userName;
    emit userNameChanged();
    qDebug() << "Set UserName changed";
}
