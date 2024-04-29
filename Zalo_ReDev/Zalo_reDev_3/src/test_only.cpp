#include "test_only.h"

Test_Only::Test_Only(QObject *parent)
    : QObject{parent}
{}

void Test_Only::trigger(QString input)
{
    qDebug() << "Debug trigger" << input;
}
