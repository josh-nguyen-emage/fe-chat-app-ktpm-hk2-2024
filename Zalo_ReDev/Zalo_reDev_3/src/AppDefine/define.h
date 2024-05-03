// define.h

#ifndef DEFINE_H
#define DEFINE_H

#include <QString>

class Define
{
public:
    static Define& getInstance(); // Static method to get the instance
    QString backendPath; // Public member for backend path
    QString userToken;

private:
    Define(); // Private constructor to prevent instantiation
    Define(const Define&) = delete; // Delete copy constructor
    Define& operator=(const Define&) = delete; // Delete assignment operator
};

#endif // DEFINE_H
