#include "allergies.h"

Allergy::Allergy(){}

Allergy::Allergy(string name) : name{name}{
}

// Compare the two instances based on their name
bool Allergy::compareTo(const Allergy& that){
  return name == that.name;
};

// toString() function returns name
string Allergy::toString(){
    return name;
}

