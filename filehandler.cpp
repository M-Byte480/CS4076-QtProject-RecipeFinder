#include <stdlib.h>
#include <string>
#include <fstream>
#include <sstream>
#include "filehandler.h"
#include <filesystem>

using namespace std;

void fileHandler::readFile(){
    ifstream myFile("..//cs4076//recipes.csv"); // Creates a debugging folder, hence we have to go back to access the file
    int count = 0;

    // We count how many recipes we need
    string line;
    while( myFile.good() ){
        getline(myFile, line);
        count++;
    }
    myFile.close();

    cout << "Number of lines read: " << count << endl << endl;
}
