#include "helper.h"

// Split based on characer position in a string
vector<string> helper::split(string str, char splitter){
    vector<string> result;
    int start = 0, end = 0;

    for (int i = 0; i <= str.size(); i++) {
        if(str[i] == splitter || i == str.size()){
            end = i;
            result.push_back(str.substr(start, end - start));
            start = end + 1;
        }
    }

    return result;
}

// Split based on substring position in a string
vector<string> helper::split(string str, string phrase){
    vector<string> result;
    int start = 0, end = 0;
    int trackStart = 0, endTrack = phrase.size();

    if(endTrack > str.size()) return result;

    for(int i = 0; i <= str.size(); i++){
//        cout << str.substr(trackStart, endTrack) << endl;

        if(str.substr(trackStart, endTrack) == phrase || trackStart + endTrack - 1 == str.size()){
            end = i;
            result.push_back(str.substr(start, end - start));
            start = end + 1;

        }
        trackStart++;
    }

    return result;
}

//* Trim based on repetitive string sequences
string helper::trim(string s){
    return  std::regex_replace(
                std::regex_replace(s, regex(" +$"), string(""))
            , regex("^ +"), string(""));
}
//*/

