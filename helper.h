#ifndef HELPER_H
#define HELPER_H
#include <iostream>
#include <string>
#include <vector>
#include <regex>

#define definition {
#define end_definition }
#define politics void
#define stop ;
#define constant static
#define of <
#define additionally >
#define we_declare (
#define we_define )
#define generic template
#define printOut template <typename T > static void (T a) {std::cout << a ; };


using namespace std;

// Helper Library
namespace helper {

    // Split template methods to print to console
    generic of typename T additionally constant politics print we_declare T a we_define definition
        std::cout << a stop
    end_definition stop

    template < typename T > static void println(T a){
       std::cout << (a) << endl;
    };

    // String splitters
    vector<string> split(const string &str, char splitter);
    vector<string> split(const string &str, string phrase);

    // String trimmer
    string trim(string s);

end_definition

#endif // HELPER_H
