#ifndef CONVERSATIONVM_H
#define CONVERSATIONVM_H

#include "src/Model/conversation_model.h"
#include <QObject>
#include <QDebug>

class ConversationVM : public QObject
{
    Q_OBJECT
public:
    explicit ConversationVM(QObject *parent = nullptr);
    Conversation_Model conversationModel;

public slots:
    void sendMessage(QString text);
    void uploadImage(QString imagePath);
    void updateReciveTopic(QString newTopic);

};

#endif // CONVERSATIONVM_H
