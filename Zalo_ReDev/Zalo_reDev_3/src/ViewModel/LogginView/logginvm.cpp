#include "logginvm.h"

LogginVM::LogginVM(QObject *parent)
    : QObject{parent}
{}

void LogginVM::registerUser(const QString &phoneNumber, const QString &username, const QString &password)
{
    logging_Model.registerUser(phoneNumber,username,password);
}

void LogginVM::loginUser(const QString &phoneNumber, const QString &password)
{
    logging_Model.loginUser(phoneNumber,password);
}
