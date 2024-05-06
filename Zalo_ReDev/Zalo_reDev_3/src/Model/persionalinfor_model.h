#ifndef PERSIONALINFOR_MODEL_H
#define PERSIONALINFOR_MODEL_H

#include <QObject>
#include <QNetworkAccessManager>
#include <QNetworkRequest>
#include <QNetworkReply>

class PersionalInfor_Model : public QObject
{
    Q_OBJECT
public:
    explicit PersionalInfor_Model(QObject *parent = nullptr);

    QString currentUserToken;

public slots:
    void reciveUserToken(const QString &accessToken);
    QString requestUserData();
    void setUserInformation();

signals:

private:
    QNetworkAccessManager *manager;
};

#endif // PERSIONALINFOR_MODEL_H
