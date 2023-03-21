#ifndef HELPER_H
#define HELPER_H

#include <iostream>
#include <string>
#include <vector>

using namespace std;

namespace helper{
    template <typename T> static void print(T a){
        std::cout << a;
    };
    template <typename T> static void println(T a){
       std::cout << (a) << endl;
    };

    vector<string> split(string str, char splitter);



}


#endif // HELPER_H
