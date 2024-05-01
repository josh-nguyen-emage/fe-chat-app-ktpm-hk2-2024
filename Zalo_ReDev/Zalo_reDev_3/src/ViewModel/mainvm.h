#ifndef MAINVM_H
#define MAINVM_H

#include "src/ViewModel/ChatView/conversationvm.h"
#include <QQmlApplicationEngine>

class MainVM
{
public:
    MainVM(QQmlApplicationEngine *engine);

    ConversationVM *conversationVM;
};

#endif // MAINVM_H
