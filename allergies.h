#ifndef ALLERGIES_H
#define ALLERGIES_H
#include <string>

using namespace std;

// Allergy class
class Allergy
{

// Allergy's friend class Food
friend class Food;

public:
    Allergy();
    Allergy(string name);
    bool compareTo(const Allergy& that);

    string toString();

private:
    string name;
};

#endif // ALLERGIES_H
