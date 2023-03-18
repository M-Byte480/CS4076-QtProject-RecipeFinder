#include <stdlib.h>
#include <string>
#include <fstream>
#include <sstream>
#include "filehandler.h"
#include <filesystem>
#include "helper.h"

using namespace std;
using namespace helper;

void fileHandler::readFile(string name){
    ifstream myFile(name); // Creates a debugging folder, hence we have to go back to access the file
    int count = 0;
    vector<string> data;
    // We count how many recipes we need
    string line;
    while( myFile.good() ){
        getline(myFile, line);
        data.push_back(line);
        count++;
    }
    myFile.close();

    println("Number of lines read: " +  to_string(count));
}
