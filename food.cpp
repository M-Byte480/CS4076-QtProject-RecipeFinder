#include <iostream>
#include <stdlib.h>

using namespace std;

class food{
    public: // Access specifiers
        string name;
        int noIngredients;
        int timeToMake;
        string* ingredients[];
        //string* allergies[];

        food(string name, int noIng, int timeInMinutes){
            name = name;
            noIngredients = noIng;
            timeToMake = timeInMinutes;
        }
};
