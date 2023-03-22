#include "myexception.h"

myException::myException()
{
    msg = (char*) "Default";
}

myException::myException(char* errorMsg) : msg{errorMsg}{

}

char* myException::what(){
    return msg;
}

void myException::setException(char* errorMsg){
    msg = errorMsg;
}

void myException::causeException(){
    throw(*this);
}

