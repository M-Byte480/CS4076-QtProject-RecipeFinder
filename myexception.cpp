#include "myexception.h"

// Default constructor
myException::myException()
{
    msg = (char*) "Default";
}

// Call the base class constructor
myException::myException(char* errorMsg) : msg{errorMsg}{

}

// Overwrite the what() function
char* myException::what(){
    return msg;
}

// Set error message
void myException::setException(char* errorMsg){
    msg = errorMsg;
}

// Raises exception of this instance
void myException::causeException(){
    throw(*this);
}

