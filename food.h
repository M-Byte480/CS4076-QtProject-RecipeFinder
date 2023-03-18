#ifndef FOOD_H
#define FOOD_H

#include <iostream>
#include <stdlib.h>
#include <string>
#include "consumable.cpp"
#include "allergies.h"
#include "helper.h"

using namespace helper;
using namespace std;

class Food : public Consumable
{
private: // Access specifiers
    int noIngredients;
    int timeToMake;
    string* methods;
    string* ingredients;
    string* allergiesString;
    int size;
    Allergy* allergies;
public:
    Food(string name) : Consumable(name){

    }
    Food(   string name,
            int numberOfIngredients,
            int timeInMinutes,
            string listOfIngredients,
            string listOfAllergies,
            string listOfMethods)
    try : Consumable(name),
        timeToMake{timeInMinutes},
        noIngredients{numberOfIngredients}
        {
            *ingredients = listOfIngredients;
            *allergiesString = listOfAllergies;
            *methods = listOfMethods;

//            vector<string> temp = split(*allergiesString, ',');
//            size = temp.capacity();
//            allergies = new Allergy[size];
//            for (int i = 0; i < temp.capacity(); ++i) {
//                allergies[i] = Allergy(temp.at(i));
//            }
        }
        catch(const exception &e)
        {
            cout << "Broken" << endl;
        };

//    Food(const Food &that) : Consumable(*that.name){
//        this -> noIngredients = that.noIngredients;

//        ingredients = new string();
//        *ingredients = *that.ingredients;

//        allergiesString = new string();
//        *allergiesString = *that.allergiesString;

//        methods = new string();
//        *methods = *that.methods;
//    }

    ~Food(){
        delete methods;
        delete ingredients;
        delete allergiesString;
        delete[] allergies;
    }

    bool contains(const Allergy& toCompare){
        for (int i = 0; i < size; ++i) {
            if( toCompare.name == (*(allergies + i)).name){
                return true;
            }
        }
        return false;
    }

    void howToConsume(){
        cout << "Eat" << endl;
    }

    void toString(){
        cout << *name << endl;
    }
};



#endif // FOOD_H
