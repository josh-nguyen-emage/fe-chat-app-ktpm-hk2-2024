#ifndef MAINVM_H
#define MAINVM_H

#include "src/ViewModel/ChatView/conversationvm.h"
#include "src/ViewModel/LogginView/logginvm.h"
#include <QQmlApplicationEngine>

class MainVM
{
public:
    MainVM(QQmlApplicationEngine *engine);

    ConversationVM *conversationVM;
    LogginVM *logginVM;
};

#endif // MAINVM_H
