#ifndef FILEINPUTREADER_H
#define FILEINPUTREADER_H

#include "filehandler.h"
#include "myexception.h"

// Multiple Inheritance
class fileInputReader :
        public fileHandler ,
        public myException
{
public:
    // Constructors
    fileInputReader();
    fileInputReader(string name);
    ~fileInputReader(){};

    // Over-written virtual function
    virtual void readFile(string name);

    // Defined virtual function
    virtual void printName();
};

#endif // FILEINPUTREADER_H
