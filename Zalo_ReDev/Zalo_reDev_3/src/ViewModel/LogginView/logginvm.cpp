#include "logginvm.h"

LogginVM::LogginVM(QObject *parent)
    : QObject{parent}
{
    LogginVM::connect(&logging_Model,&Logging_Model::loginSuccess, this,&LogginVM::loginSuccess);
}

void LogginVM::registerUser(const QString &phoneNumber, const QString &username, const QString &password)
{
    logging_Model.registerUser(phoneNumber,username,password);
}

void LogginVM::loginUser(const QString &phoneNumber, const QString &password)
{
    logging_Model.loginUser(phoneNumber,password);
}

void LogginVM::loginSuccess(const QString &accessToken)
{
    qDebug() << "Signal trigger from LogginVM::loginSuccess";
    emit signal_loginSuccess(accessToken);
}
