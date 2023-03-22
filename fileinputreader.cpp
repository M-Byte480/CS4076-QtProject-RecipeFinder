#include "fileinputreader.h"

fileInputReader::fileInputReader() :
    fileHandler(),
    myException((char *) "File Not Found: ")
{

}

fileInputReader::fileInputReader(string name) :
    fileHandler(name),
    myException((char*) "File Not Found: ")
{
    if(this->count == 0){
        causeException();
    }
}

void fileInputReader::readFile(string name){

    fileHandler::readFile(name);
    if(this->getData().capacity() == 0){
        causeException();
    }
}

string fileInputReader::getName(){
    return this->getName();
}
