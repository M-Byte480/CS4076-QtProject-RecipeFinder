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

    Food(const Food &that) : Consumable(*that.name){
        this -> noIngredients = that.noIngredients;

        ingredients = new string();
        *ingredients = *that.ingredients;

        allergies = new string();
        *allergies = *that.allergies;

        methods = new string();
        *methods = *that.methods;
    }

    ~Food(){
        delete methods;
        delete ingredients;
        delete allergies;
    }
};



#endif // FOOD_H
