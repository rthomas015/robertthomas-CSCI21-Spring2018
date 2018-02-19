#include "pet.h"
#include "dog.h"

//Dog class derived from Pet class
        //default constructor
        Dog::Dog () {
            isNeutered_ = false;
            isCurrentlyBarking_ = false;
        }

        //setters
        void Dog::setisCurrentlyBarking (bool isCurrentlyBarking) {
            isCurrentlyBarking_ = isCurrentlyBarking;
        }
        
        void Dog::setisNeutered (bool isNeutered) {
            isNeutered_ = isNeutered;
        }
        
        //getters
        const bool Dog::getisCurrentlyBarking () {
            return isCurrentlyBarking_;
        }
        
        const bool Dog::getisNeutered() {
            return isNeutered_;
        }
        
        string Dog::print () {
            //changed print to return a string rather than void since we're not supposed to have
            //cout statements in classes
            stringstream ss;
            ss << Pet::print() << endl << "neutered: " << isNeutered_
               << endl << "Is currently barking: " << isCurrentlyBarking_;
               
            return ss.str();
        }