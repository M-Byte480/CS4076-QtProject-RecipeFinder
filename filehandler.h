#ifndef FILEHANDLER_H
#define FILEHANDLER_H

#include <stdlib.h>
#include <string>
#include <fstream>
#include "food.cpp"
#include <sstream>
#include <vector>

using namespace std;

class fileHandler{
public:
    fileHandler();
    fileHandler(string name);
    void readFile(string name);
    ~fileHandler(){
    }
    vector<std::string> getData();
    void printData();
    string getDataToString();
protected:
    vector<std::string> data;
};


#endif // FILEHANDLER_H
