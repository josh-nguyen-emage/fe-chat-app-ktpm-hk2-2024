#ifndef LOGGINVM_H
#define LOGGINVM_H

#include "src/Model/loggin_model.h"
#include <QObject>

class LogginVM : public QObject
{
    Q_OBJECT
public:
    explicit LogginVM(QObject *parent = nullptr);
    Logging_Model logging_Model;
    Q_INVOKABLE void registerUser(const QString &phoneNumber, const QString &username, const QString &password);
    Q_INVOKABLE void loginUser(const QString &phoneNumber, const QString &password);

public slots:
    void loginSuccess(const QString &accessToken);

signals:
    void signal_loginSuccess(const QString &accessToken);


};

#endif // LOGGINVM_H
