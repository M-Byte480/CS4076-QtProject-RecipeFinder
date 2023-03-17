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
        virtual void print();

    protected:
        string* name;
};
