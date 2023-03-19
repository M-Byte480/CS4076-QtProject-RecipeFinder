#include <stdlib.h>
#include <string>
#include <fstream>
#include <sstream>
#include "filehandler.h"
#include <filesystem>
#include "helper.h"
#include<bits/stdc++.h>

using namespace std;
using namespace helper;
fileHandler::fileHandler(){
    vector<string> data;
}

fileHandler::fileHandler(string name){
    vector<string> data;
    readFile(name);
}

void fileHandler::readFile(string name){
    ifstream myFile(name);
    int count = 0;
//    vector<string> data;
    // We count how many recipes we need
    string line;
    while( getline(myFile, line) ){
        data.push_back(line);
        count++;
    }
    myFile.close();

    println("Number of lines read: " +  to_string(count));
}

std::vector<std::string> fileHandler::getData(){
    return this->data;
}

void fileHandler::printData(){
    for(string s : data){
        cout << s << endl;
    }
}

string fileHandler::getDataToString(){
//    string str(data.begin(), data.end());
//    return str;
    return "Hello world";
}
