#ifndef PERSIONALINFORVM_H
#define PERSIONALINFORVM_H

#include "src/Model/persionalinfor_model.h"
#include <QObject>

class PersionalInforVM : public QObject
{
    Q_OBJECT
public:
    explicit PersionalInforVM(QObject *parent = nullptr);
    PersionalInfor_Model persionalInfor_Model;
    Q_INVOKABLE void requestUserData();

signals:
};

#endif // PERSIONALINFORVM_H
