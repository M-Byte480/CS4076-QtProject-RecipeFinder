#include "filehandler.h"
#include "helper.h"

using namespace std;
using namespace helper;

// Default Constructor
fileHandler::fileHandler(){
    vector<string> data;
}

// Takes relative file path upon construction and read it
fileHandler::fileHandler(string filePath){
    vector<string> data;
    fileHandler::readFile(filePath);
    this -> filePath = filePath;
}

// We take the file path and assign the data
// per line, into the data vector.
void fileHandler::readFile(string filePath){
    this->filePath  = filePath;
    println(filePath);
    ifstream myFile(filePath);
    count = 0;

    // We count how many lines are read and print it to console
    string line;
    while( getline(myFile, line) ){
        data.push_back(line);
        count++;
    }
    myFile.close();

    // Use print new line from helper library
    print("Number of lines read: "); println(count);
}

// Return copied vector of type string
std::vector<std::string> fileHandler::getFileLine(){
    return this->data;
}

// Print to console each string line from file
void fileHandler::printData(){
    for(string s : this->data){
        println(s);
    }
}

// Return each string line as a concatenated string with the
// formatting required for the method window.
string fileHandler::dataToFormattedString(){
    string str;
    int temp = 0;
    for(string s : this->data){
        str.append(to_string(++temp) + ") ").append(s).append("\n\n");
    }
    return str;
}

// Virtual function defined
void fileHandler::printName(){
    println(this->filePath);
}
