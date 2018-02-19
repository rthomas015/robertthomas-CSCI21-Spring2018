#ifndef pet_h
#define pet_h

#include <iostream>
#include <string>
#include <sstream>

using std::string;
using std::stringstream;
using std::endl;

class Pet {
    public:
        //default constructor for pet that defaults all values to 0, false or blank.
        Pet();
        
        //overloaded constructor
        Pet(string name, int species, bool talks);
        
        //Setters
        void setName (string name);
        void setSpecies (int species);
        void setTalks (bool talks);
        
        //Getters
        const string getName ();
        const int getSpecies ();
        const bool getTalks ();
       
        //Print function
        string print();

    protected:
        string name_;
        int species_;
        bool talks_;
};

#endif