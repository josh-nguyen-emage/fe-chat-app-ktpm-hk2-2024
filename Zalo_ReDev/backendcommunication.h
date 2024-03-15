#ifndef BACKENDCOMMUNICATION_H
#define BACKENDCOMMUNICATION_H

#include <QObject>
#include <QString>
#include <qqml.h>

class BackendCommunication : public QObject
{
Q_OBJECT
    Q_PROPERTY(QString userName READ userName WRITE setUserName NOTIFY userNameChanged)
    QML_ELEMENT

public:
    explicit BackendCommunication(QObject *parent = nullptr);

    QString userName();
    void setUserName(const QString &userName);

signals:
    void userNameChanged();

private:
    QString m_userName;
};

#endif // BACKENDCOMMUNICATION_H
