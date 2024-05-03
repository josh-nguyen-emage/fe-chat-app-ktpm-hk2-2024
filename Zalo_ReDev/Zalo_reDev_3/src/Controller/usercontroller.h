#ifndef USERCONTROLLER_H
#define USERCONTROLLER_H

#include <QObject>

class UserController : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QString userToken READ getUserToken WRITE setUserToken NOTIFY userTokenChanged)

public:
    explicit UserController(QObject *parent = nullptr);

    QString getUserToken() const;
    void setUserToken(const QString &value);

signals:
    void userTokenChanged();

private:
    QString m_userToken;
};

#endif // USERCONTROLLER_H
