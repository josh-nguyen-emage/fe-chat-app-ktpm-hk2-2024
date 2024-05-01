#ifndef CHATLISTVM_H
#define CHATLISTVM_H

#include <QObject>

class ChatListVM : public QObject
{
    Q_OBJECT
public:
    explicit ChatListVM(QObject *parent = nullptr);

signals:
};

#endif // CHATLISTVM_H
