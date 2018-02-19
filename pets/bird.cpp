#include "pet.h"
#include "bird.h"

        //default constructor
        Bird::Bird () {
            isCaged_ = false;
            canSing_ = false;
            canFly_ = false;
            laidEggToday_ = false;
        }
        
        //birds can fly, peck, sing, lay eggs
        //setters
        void Bird::setcanFly (bool canFly) {
            canFly_ = canFly;
        }
        void Bird::setcanSing (bool canSing) {
            canSing_ = canSing;
        }
        void Bird::setisCaged (bool isCaged) {
            isCaged_ = isCaged;
        }
        void Bird::setlaidEggToday (bool laidEggToday) {
            laidEggToday_ = laidEggToday;
        }
        
        //getters
        const bool Bird::getcanFly () {
            return canFly_;
        }
        const bool Bird::getcanSing () {
            return canSing_;
        }
        const bool Bird::getisCaged () {
            return isCaged_;
        }
        const bool Bird::getlaidEggToday () {
            return laidEggToday_;
        }
        
        bool Bird::fly () {
            bool isFlying = false;
                if (getcanFly() == true) {
                    isFlying = true;
                }
            return isFlying;
        }
        
        bool Bird::sing () {
            bool isSinging = false;
                if (getcanSing() == true) {
                    isSinging = true;
                }
            return isSinging;
        }
        
        bool Bird::layEgg () {
            bool eggLaidSuccess = false;
                if (getlaidEggToday() == false) {
                    //if no eggs laid today, bird lays an egg
                    eggLaidSuccess = true;
                }
                
            setlaidEggToday(eggLaidSuccess);
            
            return eggLaidSuccess;
        }
    
        string Bird::print () {
            //changed print to return a string rather than void since we're not supposed to have
            //cout statements in classes
            stringstream ss;
            ss << Pet::print() << endl << "is Caged: " << isCaged_
                 << endl << "able to sing: " << canSing_
                 << endl << "able to fly: " << canFly_
                 << endl << "laid an egg today: " << laidEggToday_;
                 
            return ss.str();
        }