#ifndef CONSUMABLE_H
#define CONSUMABLE_H

#include <string>

using namespace std;

class consumable
{
public:
    consumable(){
        name = new string();
    }
    consumable(string nameOfConsumable){
        name = new string();
        *name = nameOfConsumable;
    }

    // Copy Constructor
    consumable(const consumable& that){
        name = new string();
        *(this -> name) = *(that.name);
    }
    ~consumable(){
        delete name;
    }

    // Abstract functions
    virtual void howToConsume() = 0;
    virtual string toString() = 0;

    // Return value of the register name points to
    string getName(){
        return *(this->name);
    }

    // Inheritable instance variable
protected:
    string* name;
};

#endif // CONSUMABLE_H
