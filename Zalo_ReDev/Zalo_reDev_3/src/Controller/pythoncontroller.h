#ifndef PYTHONCONTROLLER_H
#define PYTHONCONTROLLER_H

#include <QObject>
#include <QProcess>
#include <QString>
#include <QStringList>

class PythonController : public QObject {
    Q_OBJECT

public:
    explicit PythonController(QObject *parent = nullptr);

    QStringList runPythonScript(const QString& pythonPath,  QStringList& arguments);

public slots:
    void streamPythonScript(const QString& pythonPath, QStringList& arguments);

signals:
    void pythonOutput(const QString& output);

private:
    void readOutput();

    QProcess* m_pythonProcess;
};

#endif // PYTHONCONTROLLER_H
