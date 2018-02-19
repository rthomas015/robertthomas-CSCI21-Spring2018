#ifndef dog_h
#define dog_h

#include <iostream>
#include <string>
#include <sstream>

using std::string;

//Dog class derived from Pet class
class Dog : public Pet {
    public:
        //default constructor
        Dog ();
        
        //overloaded constructor
        Dog (string name, int species, bool talks, bool isNeutered, bool isCurrentlyBarking) : Pet(name, species, talks) {
            name_ = name;
            species_ = species;
            talks_ = talks;
            isNeutered_ = isNeutered;
            isCurrentlyBarking_ = isCurrentlyBarking;
        }
        
        //setters
        void setisCurrentlyBarking (bool isCurrentlyBarking);
        void setisNeutered (bool isNeutered);
        
        //getters
        const bool getisCurrentlyBarking ();
        const bool getisNeutered();
        
        string print ();
        
    private:
        bool isNeutered_;
        bool isCurrentlyBarking_;
};

#endif