#include "persionalinforvm.h"

PersionalInforVM::PersionalInforVM(QObject *parent)
    : QObject{parent}
{}

void PersionalInforVM::requestUserData()
{
    persionalInfor_Model.requestUserData();
}
