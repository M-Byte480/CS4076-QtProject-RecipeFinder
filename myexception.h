#ifndef MYEXCEPTION_H
#define MYEXCEPTION_H
#include <iostream>

using namespace std;

// Inherits class exception
class myException : public exception
{

public:
    myException();
    myException(char* errorMsg);
    ~myException(){};
    char* what();
    void setException(char* errorMsg);
    void causeException();

protected:
    char* msg = (char*) "Default Message";

};

#endif // MYEXCEPTION_H
