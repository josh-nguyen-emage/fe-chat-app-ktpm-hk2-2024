#ifndef MAINVM_H
#define MAINVM_H

#include "src/ViewModel/ChatView/conversationvm.h"
#include "src/ViewModel/LogginView/logginvm.h"
#include "src/ViewModel/PersionalInforView/persionalinforvm.h"
#include <QQmlApplicationEngine>

class MainVM : public QObject
{
    Q_OBJECT
public:

    MainVM(QQmlApplicationEngine *engine);

    ConversationVM *conversationVM;
    PersionalInforVM *persionalInforVM;
    LogginVM *logginVM;

};

#endif // MAINVM_H
