#ifndef CHATLIST_MODEL_H
#define CHATLIST_MODEL_H

#include <QObject>

class ChatList_Model : public QObject
{
    Q_OBJECT
public:
    explicit ChatList_Model(QObject *parent = nullptr);

signals:
};

#endif // CHATLIST_MODEL_H
