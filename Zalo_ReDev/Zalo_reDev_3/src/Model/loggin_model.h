#ifndef LOGGING_MODEL_H
#define LOGGING_MODEL_H

#include <QObject>
#include <QNetworkAccessManager>
#include <QNetworkReply>

class Logging_Model : public QObject
{
    Q_OBJECT
public:
    explicit Logging_Model(QObject *parent = nullptr);

    Q_INVOKABLE void registerUser(const QString &phoneNumber, const QString &username, const QString &password);
    Q_INVOKABLE void loginUser(const QString &phoneNumber, const QString &password);
    Q_INVOKABLE void logoutUser(const QString &accessToken);

signals:
    void registrationSuccess();
    void registrationFailed(const QString &error);
    void loginSuccess(const QString &accessToken);
    void loginFailed(const QString &error);
    void logoutSuccess();
    void logoutFailed(const QString &error);

private slots:
    void registrationRequestFinished();
    void loginRequestFinished();
    void logoutRequestFinished();
    void handleNetworkError(QNetworkReply::NetworkError code);
    void handleResponse(QNetworkReply *reply);

private:
    QNetworkAccessManager m_networkManager;
    QString m_baseUrl;

    void sendRequest(const QString &endpoint, const QByteArray &requestData);
};

#endif // LOGGING_MODEL_H
