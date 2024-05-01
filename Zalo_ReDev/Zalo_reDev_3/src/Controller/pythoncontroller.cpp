#include "PythonController.h"
#include <QTextStream>

PythonController::PythonController(QObject *parent) : QObject(parent), m_pythonProcess(nullptr) {}

QStringList PythonController::runPythonScript(const QString& pythonPath, const QStringList& arguments) {
    QStringList output;
    m_pythonProcess = new QProcess();
    m_pythonProcess->setProgram(pythonPath);
    m_pythonProcess->setArguments(arguments);

    // Start the Python process
    m_pythonProcess->start();

    if (!m_pythonProcess->waitForStarted()) {
        output.append("Error: Failed to start Python process.");
        return output;
    }

    // Read output from the Python process
    QTextStream textStream(m_pythonProcess);
    while (!textStream.atEnd()) {
        output.append(textStream.readLine());
    }

    // Wait for the process to finish
    m_pythonProcess->waitForFinished();

    delete m_pythonProcess;
    m_pythonProcess = nullptr;

    return output;
}

void PythonController::streamPythonScript(const QString& pythonPath, const QStringList& arguments) {
    m_pythonProcess = new QProcess();
    m_pythonProcess->setProgram(pythonPath);
    m_pythonProcess->setArguments(arguments);

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
