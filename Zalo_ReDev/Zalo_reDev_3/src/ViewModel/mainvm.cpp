#include "mainvm.h"
#include "qqmlcontext.h"

MainVM::MainVM(QQmlApplicationEngine *engine)
{
    conversationVM = new ConversationVM();
    engine->rootContext()->setContextProperty("conversationVM", conversationVM);

    logginVM = new LogginVM();
    engine->rootContext()->setContextProperty("logginVM", logginVM);

    persionalInforVM = new PersionalInforVM();
    engine->rootContext()->setContextProperty("persionalInforVM", persionalInforVM);

    MainVM::connect(&logginVM->logging_Model,&Logging_Model::loginSuccess, &persionalInforVM->persionalInfor_Model,&PersionalInfor_Model::reciveUserToken);
}
