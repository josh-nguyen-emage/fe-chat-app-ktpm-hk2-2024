#include "PythonController.h"
#include "qdebug.h"
#include <QTextStream>

PythonController::PythonController(QObject *parent) : QObject(parent), m_pythonProcess(nullptr) {}

QStringList PythonController::runPythonScript(const QString& pythonPath, QStringList& arguments) {
    QStringList output;
    arguments.prepend(pythonPath);
    m_pythonProcess = new QProcess();
    m_pythonProcess->setProgram("python");
    m_pythonProcess->setArguments(arguments);
    m_pythonProcess->setProcessChannelMode(QProcess::MergedChannels);


    // Start the Python process
    m_pythonProcess->start();

    if (!m_pythonProcess->waitForStarted()) {
        output.append("Error: Failed to start Python process.");
        return output;
    }

    // Wait for the process to finish
    m_pythonProcess->waitForFinished();
    output.append(m_pythonProcess->readAll());

    delete m_pythonProcess;
    m_pythonProcess = nullptr;

    return output;
}

void PythonController::streamPythonScript(const QString& pythonPath, QStringList& arguments) {
    m_pythonProcess = new QProcess();
     arguments.prepend(pythonPath);
    m_pythonProcess->setProgram("python");
    m_pythonProcess->setArguments(arguments);
    m_pythonProcess->setProcessChannelMode(QProcess::MergedChannels);

    connect(m_pythonProcess, &QProcess::readyReadStandardOutput, this, &PythonController::readOutput);

    // Start the Python process
    m_pythonProcess->start();
}

void PythonController::readOutput() {
    if (m_pythonProcess) {
        QTextStream textStream(m_pythonProcess);
        while (!textStream.atEnd()) {
            QString line = textStream.readLine();
            emit pythonOutput(line);
        }
    }
}
