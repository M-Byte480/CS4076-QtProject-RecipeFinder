#include "helper.h"

vector<string> helper::split(string str, char splitter){
    vector<string> result;
    int start = 0, end = 0;

    for (int i = 0; i <= str.size(); ++i) {
        if(str[i] == splitter || i == str.size()){
            end = i;
            result.push_back(str.substr(start, end));
            start = end + 1;
        }
    }

    return result;
}
