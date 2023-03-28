#ifndef ALLERGYBITSTRUCT_H
#define ALLERGYBITSTRUCT_H

#include <bitset>
#include <cstdint>
#include <iostream>
#include <string>
using namespace std;

union AllergyBit{
    struct{
        unsigned int wheat : 1;
        unsigned int milk : 1;
        unsigned int fish : 1;
        unsigned int nuts : 1;
    };
    unsigned int x;
    char z;
};

enum class AllergyBitStruct{
    wheat = 1 << 0,
    milk  = 1 << 1,
    fish  = 1 << 2,
    nuts  = 1 << 3
};

struct AllergyFlag{
    uint8_t flagValues = 0;

    void setFlag(string flagStr){
        AllergyBitStruct flag;

        if     (flagStr == "wheat") flag = AllergyBitStruct::wheat;
        else if(flagStr == "milk") flag = AllergyBitStruct::milk;
        else if(flagStr == "nuts") flag = AllergyBitStruct::nuts;
        else if(flagStr == "fish") flag = AllergyBitStruct::fish;
        else{ return ; }

        flagValues |= (int) flag;
    }

    bool hasFlag(string flagStr){
        AllergyBitStruct flag;

        if     (flagStr == "wheat") flag = AllergyBitStruct::wheat;
        else if(flagStr == "milk") flag = AllergyBitStruct::milk;
        else if(flagStr == "nuts") flag = AllergyBitStruct::nuts;
        else if(flagStr == "fish") flag = AllergyBitStruct::fish;
        else{ return false; }

        return ((flagValues & (int) flag) == (int) flag);
    }

    void printBits(){
        cout << std::bitset<4>(flagValues) << endl;
    }
};

#endif // ALLERGYBITSTRUCT_H
