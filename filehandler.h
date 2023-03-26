#ifndef FILEHANDLER_H
#define FILEHANDLER_H

#include "food.cpp"
#include <stdlib.h>
#include <string>
#include <fstream>
#include <sstream>
#include <vector>
#include<bits/stdc++.h>
#include <filesystem>
#include <stdlib.h>

using namespace std;

/*
 * This class will handle file inputs
 * For the list of recipes which are used
 * to display for the user
 */

class fileHandler{
public:
    // Constructors
    fileHandler();
    fileHandler(string name);
    ~fileHandler(){
    }

    // Overrideable functions
    virtual void readFile(string name);
    virtual void printName();

    // Functions
    vector<std::string> getFileLine();
    void printData();
    string dataToFormattedString();

protected:
    // Inheritable instance variables
    string name;
    int count;
    vector<std::string> data;
};


#endif // FILEHANDLER_H
