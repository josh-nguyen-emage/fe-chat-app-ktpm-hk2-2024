#ifndef TEST_ONLY_H
#define TEST_ONLY_H

#include <QObject>
#include <QDebug>

class Test_Only : public QObject
{
    Q_OBJECT
public:
    explicit Test_Only(QObject *parent = nullptr);
    Q_INVOKABLE void trigger(QString input);

signals:
};

#endif // TEST_ONLY_H
