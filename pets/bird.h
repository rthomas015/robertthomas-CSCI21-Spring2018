#ifndef bird_h
#define bird_h

#include <iostream>
#include <string>
#include <sstream>
#include "pet.h"

using std::string;

class Bird : public Pet {
    public:
        //default constructor
        Bird ();
        
        //overloaded constructor
        Bird (string name, int species, bool talks, bool isCaged, bool canSing, bool canFly, bool laidEggToday) : Pet (name, species, talks)
        {
            isCaged_ = isCaged;
            canSing_ = canSing;
            canFly_ = canFly;
            laidEggToday_ = laidEggToday;
        }
        
        //birds can fly, peck, sing, lay eggs
        //setters
        void setcanFly (bool canFly);
        void setcanSing (bool canSing);
        void setisCaged (bool isCaged);
        void setlaidEggToday (bool laidEggToday);
        
        //getters
        const bool getcanFly ();
        const bool getcanSing ();
        const bool getisCaged ();
        const bool getlaidEggToday ();
        
        bool fly ();
        bool sing ();
        bool layEgg ();
    
        string print ();
        
    private:
        bool isCaged_;
        bool canSing_;
        bool canFly_;
        bool laidEggToday_;
};

#endif