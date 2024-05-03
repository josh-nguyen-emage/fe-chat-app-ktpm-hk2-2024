#include "mainvm.h"
#include "qqmlcontext.h"

MainVM::MainVM(QQmlApplicationEngine *engine)
{
    conversationVM = new ConversationVM();
    engine->rootContext()->setContextProperty("conversationVM", conversationVM);

    logginVM = new LogginVM();
    engine->rootContext()->setContextProperty("logginVM", logginVM);
}
