#ifndef FOOD_H
#define FOOD_H

#include <iostream>
#include <stdlib.h>
#include <string>
#include "consumable.cpp"
#include "allergies.h"
#include <vector>
#include "helper.h"

// Here we demonstrate initializer lists, memory mananagement and pointers.

using namespace helper;
using namespace std;

class Food : public consumable // Inherit from Consumable
{
private: // Private instance variables
    int noIngredients;
    int timeToMake;
    int size;
    int* difficulty;// Couple of pointers
    string* methods;
    string* ingredients;
    string* allergiesString;
    Allergy* allergies;

public:
    Food(string name = "name") : consumable(name) {
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

    Food(string name,
         int diff,
         int numberOfIngredients,
         int timeInMinutes,
         string listOfIngredients,
         string listOfAllergies,
         string listOfMethods)

    try : consumable(name),
          timeToMake{timeInMinutes},
          noIngredients{numberOfIngredients},
          difficulty{new int()}
        {
        // Allocate locations in the heap to work from
        size = 0;
        methods = new string();
        ingredients = new string();
        allergiesString = new string();
        allergies = new Allergy[size];

        // Now assign the data passed as arguments
        *difficulty = diff;
        *ingredients = listOfIngredients;
        *allergiesString = listOfAllergies;
        *methods = listOfMethods;

        timeToMake = timeInMinutes;

        // Split the string of allergies based on comma seperation
        vector<string> temp = split(*allergiesString, ',');
        size = temp.capacity();
        allergies = new Allergy[size];

        // Populate (copy) the allergies constructed
        for (int i = 0; i < temp.capacity(); ++i)
            allergies[i] = Allergy(temp.at(i));

        }
        catch(const exception &e)
        {
            cout << "Broken : " << e.what() << endl;
        };

    // Delete the memory used in the heap
    ~Food(){
        delete methods;
        delete ingredients;
        delete allergiesString;
        delete difficulty;
        delete[] allergies;
    }

    // Deep-Copy constructor
    Food(const Food &that) : consumable(that){
        // Shallow copies
        this -> noIngredients = that.noIngredients;
        this->size = that.size;
        this->timeToMake = that.timeToMake;

        // Deep copies
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

    // Returns bool if allergy exists within the instance
    bool contains(const Allergy toCompare){
        for (int i = 0; i < size; ++i)
        {
            if( toCompare.name == (*(allergies + i)).name){ // Pointer arithmetic
                return true;
            }
        }

        return false;
    }

    string getName(){
        return *(this->name);
    }

    // Override virtual function
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
    }

    int getDifficulty(){
        return *difficulty;
    }

    int getTime(){
        return this->timeToMake;
    }

    void setTime(int t){
        timeToMake = t;
    }

    // Some cool arithmetics
    int getNoAllergies(){
        return size;
    }

    Allergy* getAllergies(){
        return allergies;
    }

    string* getAllergiesString(){
        return allergiesString;
    }

    // Unary operator to return formatted string of ingredients
    string operator!(){
        vector<string> ing = helper::split(*this->ingredients, '-');
        string result = "Ingredients: \n";
        for(string s : ing){
            result.append(" - ").append(s).append("\n");

        }
        return result.append("\n");
    }

    // Friend : Overloaded operator for output stream.
    friend ostream& operator<<( ostream& oStream, const Food &food){
        return (oStream << food.name);
    }

    // Friend : String overloaded * for concatenated string of given instance.
    friend string operator* (string s, int a){
        string toReturn;
        for (int var = 0; var < a; ++var) {
            toReturn = toReturn + s;
        }
        return toReturn;
    }

};

#endif // FOOD_H
