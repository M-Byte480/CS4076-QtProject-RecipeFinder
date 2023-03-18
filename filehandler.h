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
    void readFile(string name);
    ~fileHandler(){
//        delete data;
    }
private:
    vector<std::string> data;
};


#endif // FILEHANDLER_H
