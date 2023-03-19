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
    consumable(const consumable& that){
        name = new string();
        *(this -> name) = *(that.name);
    }
    virtual void howToConsume() = 0;
    virtual void toString() = 0;
    string getName(){
        return *(this->name);
    }
protected:
    string* name;
};

#endif // CONSUMABLE_H
