#ifndef FOOD_H
#define FOOD_H

#include <iostream>
#include <stdlib.h>
#include "consumable.cpp"

using namespace std;

class Food : public Consumable
{
    public: // Access specifiers
        int noIngredients;
        int timeToMake;
        string* methods;
        string* ingredients;
        string* allergies;

    Food(   string name,
            int numberOfIngredients,
            int timeInMinutes,
            string listOfIngredients,
            string listOfAllergies,
            string listOfMethods)
    try : Consumable(name), timeToMake{timeInMinutes}
        {
            noIngredients = numberOfIngredients;
            *ingredients = listOfIngredients;
            *allergies = listOfAllergies;
            *methods = listOfMethods;
        }
        catch(const exception &e)
        {
            cout << "Broken" << endl;
        };
    ~Food(){
        delete methods;
        delete ingredients;
        delete allergies;
    }
};



#endif // FOOD_H
