#ifndef cat_h
#define cat_h

#include <iostream>
#include <string>
#include <sstream>
#include "pet.h"

class Cat : public Pet {
    public:
        //default constructor
        Cat ();
        //overloaded constructor
        Cat (string name, int species, bool talks, bool isNeutered, bool isHissing, bool isMeowing, bool isPurring) : Pet(name, species, talks) {
            isNeutered_ = isNeutered;
            isHissing_ = isHissing;
            isMeowing_ = isMeowing;
            isPurring_ = isPurring;
        }
        
        //getters
        const bool getisMeowing();
        const bool getisPurring();
        const bool getisHissing();
        const bool getisNeutered();
        
        //setters
        void setisMeowing(bool isMeowing);
        void setisPurring(bool isPurring);
        void setisHissing(bool isHissing);
        
        void setisNeutered (bool isNeutered);
        
        string print ();
        
    private:
        bool isNeutered_;
        bool isHissing_;
        bool isMeowing_;
        bool isPurring_;
};

#endif