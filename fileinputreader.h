#ifndef FILEINPUTREADER_H
#define FILEINPUTREADER_H

#include "filehandler.h"
#include "myexception.h"

class fileInputReader :
        public fileHandler ,
        public myException
{
public:
    fileInputReader();
    fileInputReader(string name);
    virtual void readFile(string name);
    ~fileInputReader(){};
    string getName();
};

#endif // FILEINPUTREADER_H
