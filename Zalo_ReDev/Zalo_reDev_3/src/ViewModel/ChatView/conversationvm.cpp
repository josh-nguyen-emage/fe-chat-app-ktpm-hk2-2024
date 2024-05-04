#include "conversationvm.h"

ConversationVM::ConversationVM(QObject *parent)
    : QObject{parent}
{}

void ConversationVM::sendMessage(QString text)
{
    conversationModel.sendMessage(text);
}

void ConversationVM::uploadImage(QString imagePath)
{
    conversationModel.uploadImage(imagePath);
}

void ConversationVM::updateReciveTopic(QString newTopic)
{
    conversationModel.updateReciverID("/topic/conversations/"+newTopic);
}
