#include <stdlib.h>
#include <string>

using namespace std;


class Allergy
{
    public:
        string ingredient;

        Allergy(string name){
            ingredient = name;
        }

        bool compareTo(const Allergy& that){
          return ingredient == that.ingredient;
        };
};
