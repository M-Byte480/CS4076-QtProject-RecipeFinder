#ifndef HELPER_H
#define HELPER_H

#include <iostream>
#include <string>
#include <vector>
#include <regex>

using namespace std;

// Helper Library
namespace helper{

    // Split template methods to print to console
    template <typename T> static void print(T a){
    std::cout << a;
    };

    template <typename T> static void println(T a){
       std::cout << (a) << endl;
    };

    // String splitters
    vector<string> split(string str, char splitter);
    vector<string> split(string str, string phrase);

    // String trimmer
    string trim(string s);

}

#endif // HELPER_H
