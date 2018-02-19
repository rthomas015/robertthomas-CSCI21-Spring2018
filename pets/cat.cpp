#include "cat.h"

        //default constructor
        Cat::Cat () {
            isNeutered_ = false;
            isHissing_ = false;
            isMeowing_ = false;
            isPurring_ = false;
        }

        //getters
        const bool Cat::getisMeowing() {
            return isMeowing_;
        }
        
        const bool Cat::getisPurring() {
            return isPurring_;
        }
        
        const bool Cat::getisHissing() {
            return isHissing_;
        }
        
        const bool Cat::getisNeutered() {
            return isNeutered_;
        }
        
        //setters
        void Cat::setisMeowing(bool isMeowing) {
            isMeowing_ = isMeowing;
            /*can't physically do both at same time - probably best practice is to use 
              an integer to determine what state the cat is in, rather than
              multiple booleans that are mutually exclusive, so the function is not setting 
              three variables at once
            setisPurring (false);
            setisHissing (false);
            */
        }
        void Cat::setisPurring(bool isPurring) {
            isPurring_ = isPurring;
            /*can't do both at same time, but causes undefined behavior
            setisMeowing (false);
            setisHissing (false);
            */
        }
        void Cat::setisHissing(bool isHissing) {
            isHissing_ = isHissing;
            /*can't do both at same time, but causes undefined behavior
            setisMeowing (false);
            setisHissing (false);
            */
        }
        
        void Cat::setisNeutered (bool isNeutered) {
            isNeutered_ = isNeutered;
        }
        
        string Cat::print () {
            //changed print to return a string rather than void since we're not supposed to have
            //cout statements in classes
            stringstream ss;
            ss << Pet::print() << endl << "neutered: " << isNeutered_
                 << endl << "hissing currently: " << isHissing_
                 << endl << "meowing currently: " << isMeowing_
                 << endl << "purring currently: " << isPurring_;
                 
            return ss.str();
        }