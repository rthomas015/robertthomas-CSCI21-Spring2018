#include "pet.h"

        //default constructor for pet that defaults all values to 0, false or blank.
        Pet::Pet() {
            name_ = "";
            species_ = 0;
            talks_ = false;
        }
        
        //overloaded constructor
        Pet::Pet(string name, int species, bool talks) {
            name_ = name;
            species_ = species;
            talks_ = talks;
        }
        
        //Setters
        void Pet::setName (string name) {
            name_ = name;
        }
        void Pet::setSpecies (int species) {
            species_ = species;
        }
        void Pet::setTalks (bool talks) {
            talks_ = talks;
        }
        
        //Getters
        const string Pet::getName () {
            return name_;
        }
        const int Pet::getSpecies () {
            return species_;
        }
        const bool Pet::getTalks () {
            return talks_;
        }
       
        //Print function
        string Pet::print() {
            stringstream ss;
            ss << endl << "Name: " << name_
               << endl << "Species: " << species_
               << endl << "Talks: " << talks_;
            return ss.str();
        }