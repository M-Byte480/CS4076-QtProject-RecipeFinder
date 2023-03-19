#include <stdlib.h>
#include "allergies.h"

using namespace std;

Allergy::Allergy(){}

Allergy::Allergy(string name) : name{name}{
}

bool Allergy::compareTo(const Allergy& that){
  return name == that.name;
};

string Allergy::toString(){
    return name;
}

