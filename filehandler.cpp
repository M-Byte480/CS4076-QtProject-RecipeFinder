#include <stdlib.h>
#include <string>
#include <fstream>
#include <sstream>
#include "filehandler.h"

using namespace std;

void fileHandler::readFile(){
    ifstream myFile("../recipes.csv");

    int count = 0;
    // We count how many recipes we need
    for(string line; getline(myFile, line) ; ){
        count++;
    }

    cout << "Number of lines read: " << count << endl << endl;
}
