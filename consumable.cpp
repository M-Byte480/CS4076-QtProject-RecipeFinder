#include <stdlib.h>
#include <string>

using namespace std;

class Consumable
{
    public:
        Consumable(string nameOfConsumable){
            *name = nameOfConsumable;
        }
        ~Consumable(){
            delete name;
        }
        virtual void howToConsume() = 0;
        virtual void toString() = 0;

    protected:
        string* name;

};
