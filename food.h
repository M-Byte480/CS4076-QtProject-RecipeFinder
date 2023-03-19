#ifndef FOOD_H
#define FOOD_H

#include <iostream>
#include <stdlib.h>
#include <string>
#include "consumable.cpp"
#include "allergies.h"
#include <vector>
#include "helper.h"

using namespace helper;
using namespace std;

class Food
        : public consumable
{
private: // Access specifiers
    int noIngredients;
    int timeToMake;
    string* methods;
    string* ingredients;
    string* allergiesString;
    int size;
    Allergy* allergies;
    int difficulty;

public:
    Food(string name = "name") : consumable(name)
    {
        noIngredients = 0;
        timeToMake = 0;
        size = 0;
        methods = new string();
        ingredients = new string();
        allergiesString = new string();
        allergies = new Allergy[size];
        difficulty = 0;
    }

    Food(   string name, int difficulty, int numberOfIngredients, int timeInMinutes,
            string listOfIngredients, string listOfAllergies,
            string listOfMethods)
    try
        : consumable(name), timeToMake{timeInMinutes}, noIngredients{numberOfIngredients}, difficulty{difficulty}
        {
        noIngredients = 0;
        timeToMake = 0;
        size = 0;
        methods = new string();
        ingredients = new string();
        allergiesString = new string();
        allergies = new Allergy[size];

        *ingredients = listOfIngredients;
        *allergiesString = listOfAllergies;
        *methods = listOfMethods;

        vector<string> temp = split(*allergiesString, ',');
        size = temp.capacity();
        allergies = new Allergy[size];
        for (int i = 0; i < temp.capacity(); ++i) {
            allergies[i] = Allergy(temp.at(i));
        }


        }
        catch(const exception &e)
        {
            cout << "Broken" << endl;
        };



    ~Food(){
        delete methods;
        delete ingredients;
        delete allergiesString;
        delete[] allergies;
    }

    Food(const Food &that) : consumable(that){
        this -> noIngredients = that.noIngredients;

        ingredients = new string();
        *ingredients = *that.ingredients;

        allergiesString = new string();
        *allergiesString = *that.allergiesString;

        methods = new string();
        *methods = *that.methods;
    }

    string getName(){
        return *(this->name);
    }

    bool contains(const Allergy toCompare){
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
        cout << endl;
    }

    void setName(string newName){
        *name = newName;
    }

    void setDifficulty(int newDiff){
        difficulty = newDiff;
    }

    void setMethods(string method){
        *methods = method;
    }

    void setIngredients(string newIngredients){
        *ingredients = newIngredients;
    }

    void setAlleriges(string newAllergies){
        *allergiesString = newAllergies;
        // Set the array
    }
};



#endif // FOOD_H
