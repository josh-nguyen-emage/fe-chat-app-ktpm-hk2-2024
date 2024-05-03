#include "UserController.h"

UserController::UserController(QObject *parent) : QObject(parent)
{
}

QString UserController::getUserToken() const
{
    return m_userToken;
}

void UserController::setUserToken(const QString &value)
{
    if (m_userToken != value) {
        m_userToken = value;
        emit userTokenChanged();
    }
}
