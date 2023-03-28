#include "fileinputreader.h"

/* Default constructor, with
 * Default base constructor and
 * Char pointer of string literal */
fileInputReader::fileInputReader() :
    fileHandler(),
    myException((char *) "File Not Found: ")
{}

/* We take the relative path to file
 * Check if it's found, else return exception message */
fileInputReader::fileInputReader(string name) :
    fileHandler(name),
    myException((char*) "File Not Found: ")
{
    if(this->count == 0){
        causeException();
    }
}

// Same as 1-arg constructor, except we assign the read
// To this instance
void fileInputReader::readFile(string name){

    fileHandler::readFile(name);
    if(this->getFileLine().capacity() == 0){
        causeException();
    }
}

// We invoke the base class printName()
void fileInputReader::printName(){
    this -> fileHandler::printName();
}
