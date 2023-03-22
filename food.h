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
    int* difficulty;
    Allergy* allergies;

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
        difficulty = new int();
        *difficulty = 0;
    }

    Food(   string name,
            int diff,
            int numberOfIngredients,
            int timeInMinutes,
            string listOfIngredients,
            string listOfAllergies,
            string listOfMethods)
    try
        : consumable(name),
          timeToMake{timeInMinutes},
          noIngredients{numberOfIngredients},
          difficulty{new int()}
        {
//        noIngredients = 0;
//        timeToMake = 0;
        size = 0;
        methods = new string();
        ingredients = new string();
        allergiesString = new string();
        allergies = new Allergy[size];

        *difficulty = diff;
        *ingredients = listOfIngredients;
        *allergiesString = listOfAllergies;
        *methods = listOfMethods;

        vector<string> temp = split(*allergiesString, ',');
        size = temp.capacity();
        allergies = new Allergy[size];
        for (int i = 0; i < temp.capacity(); ++i) {
            allergies[i] = Allergy(temp.at(i));
        }

        timeToMake = timeInMinutes;
        }
        catch(const exception &e)
        {
            cout << "Broken" << endl;
        };



    ~Food(){
        delete methods;
        delete ingredients;
        delete allergiesString;
        delete difficulty;
        delete[] allergies;
    }

    Food(const Food &that) : consumable(that){
        this -> noIngredients = that.noIngredients;  
        this->size = that.size;
        this->timeToMake = that.timeToMake;

        ingredients = new string();
        *ingredients = *that.ingredients;

        allergiesString = new string();
        *allergiesString = *that.allergiesString;

        methods = new string();
        *methods = *that.methods;

        difficulty = new int();
        *difficulty = *that.difficulty;

        allergies = new Allergy[size];
        *allergies = *that.allergies;
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

    string toString(){
        return *name;
    }

    void setName(string newName){
        *name = newName;
    }

    void setDifficulty(int newDiff){
        *difficulty = newDiff;
    }

    void setMethods(string method){
        *methods = method;
    }

    string getMethods(){
        return *methods;
    }
    void setIngredients(string newIngredients){
        *ingredients = newIngredients;
    }

    void setAlleriges(string newAllergies){
        *allergiesString = newAllergies;
        // Set the array
    }

    int getDifficulty(){
        return *difficulty;
    }

    int getTime(){
        return this->timeToMake;
    }
    int getNoAllergies(){
        return sizeof(*allergies)/sizeof(Allergy);
    }
    Allergy* getAllergies(){
        return allergies;
    }
    string* getAllergiesString(){
        return allergiesString;
    }

    void setTime(int t){
        timeToMake = t;
    }

    friend ostream& operator<<( ostream& oStream, const Food &food){
        return (oStream << food.name);
    }

    friend string operator* (string s, int a){
        string toReturn;
        for (int var = 0; var < a; ++var) {
            toReturn = toReturn + s;
        }
        return toReturn;
    }

};



#endif // FOOD_H
