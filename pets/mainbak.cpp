/*Pets
  By: Robert Thomas
  Date: 2/18/2018 
  Description: Write a program that has a pet class, and three derived classes for a 
  dog, cat and bird.

**Create derived classes for Dog, Cat, and Bird that inherit from the Pet class. 
**Include the appropriate functions from Pet for each subclass.
[]Each should have a separate header and cpp file (you will need a make file)
**Each class should have a default constructor and at least an overloaded constructor that allows you to set all class variables.
??Overload the print function for each of the subclasses.
**Write a main function that creates
**A bird named “Tweety” that talks
**A neutered cat named “Sylvester”
**An un-neutered dog name “Krypto”
**In your main test all of your functions. I will create a unit test.
**Extra points if you create your own unit test using the catch framework.
*/

#include <string>
#include <iostream>
#include <sstream>

using namespace std;

class Pet {
    public:
        //default constructor for pet that defaults all values to 0, false or blank.
        Pet() {
            name_ = "";
            species_ = 0;
            talks_ = false;
        }
        
        //overloaded constructor
        Pet(string name, int species, bool talks) {
            name_ = name;
            species_ = species;
            talks_ = talks;
        }
        
        //Setters
        void setName (string name) {
            name_ = name;
        }
        void setSpecies (int species) {
            species_ = species;
        }
        void setTalks (bool talks) {
            talks_ = talks;
        }
        
        //Getters
        const string getName () {
            return name_;
        }
        const int getSpecies () {
            return species_;
        }
        const bool getTalks () {
            return talks_;
        }
       
        //Print function
        string print() {
            stringstream ss;
            ss << endl << "Name: " << name_
               << endl << "Species: " << species_
               << endl << "Talks: " << talks_;
            return ss.str();
        }

    protected:
        string name_;
        int species_;
        bool talks_;
};

//Bird class derived from Pet class
class Bird : public Pet {
    public:
        //default constructor
        Bird () {
            isCaged_ = false;
            canSing_ = false;
            canFly_ = false;
            laidEggToday_ = false;
        }
        
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
        void setcanFly (bool canFly) {
            canFly_ = canFly;
        }
        void setcanSing (bool canSing) {
            canSing_ = canSing;
        }
        void setisCaged (bool isCaged) {
            isCaged_ = isCaged;
        }
        void setlaidEggToday (bool laidEggToday) {
            laidEggToday_ = laidEggToday;
        }
        
        //getters
        const bool getcanFly () {
            return canFly_;
        }
        const bool getcanSing () {
            return canSing_;
        }
        const bool getisCaged () {
            return isCaged_;
        }
        const bool getlaidEggToday () {
            return laidEggToday_;
        }
        
        bool fly () {
            bool isFlying = false;
                if (getcanFly() == true) {
                    isFlying = true;
                }
            return isFlying;
        }
        
        bool sing () {
            bool isSinging = false;
                if (getcanSing() == true) {
                    isSinging = true;
                }
            return isSinging;
        }
        
        bool layEgg () {
            bool eggLaidSuccess = false;
                if (getlaidEggToday() == false) {
                    //if no eggs laid today, bird lays an egg
                    eggLaidSuccess = true;
                }
                
            setlaidEggToday(eggLaidSuccess);
            
            return eggLaidSuccess;
        }
    
        string print () {
            //changed print to return a string rather than void since we're not supposed to have
            //cout statements in classes
            stringstream ss;
            ss << Pet::print() << endl << "is Caged: " << isCaged_
                 << endl << "able to sing: " << canSing_
                 << endl << "able to fly: " << canFly_
                 << endl << "laid an egg today: " << laidEggToday_;
                 
            return ss.str();
        }
        
    private:
        bool isCaged_;
        bool canSing_;
        bool canFly_;
        bool laidEggToday_;
};

//Dog class derived from Pet class
class Dog : public Pet {
    public:
        //default constructor
        Dog () {
            isNeutered_ = false;
            isCurrentlyBarking_ = false;
        }
        
        //overloaded constructor
        Dog (string name, int species, bool talks, bool isNeutered, bool isCurrentlyBarking) : Pet(name, species, talks) {
            name_ = name;
            species_ = species;
            talks_ = talks;
            isNeutered_ = isNeutered;
            isCurrentlyBarking_ = isCurrentlyBarking;
        }
        
        //setters
        void setisCurrentlyBarking (bool isCurrentlyBarking) {
            isCurrentlyBarking_ = isCurrentlyBarking;
        }
        
        void setisNeutered (bool isNeutered) {
            isNeutered_ = isNeutered;
        }
        
        //getters
        const bool getisCurrentlyBarking () {
            return isCurrentlyBarking_;
        }
        
        const bool getisNeutered() {
            return isNeutered_;
        }
        
        string print () {
            //changed print to return a string rather than void since we're not supposed to have
            //cout statements in classes
            stringstream ss;
            ss << Pet::print() << endl << "neutered: " << isNeutered_
               << endl << "Is currently barking: " << isCurrentlyBarking_;
               
            return ss.str();
        }
        
    private:
        bool isNeutered_;
        bool isCurrentlyBarking_;
};

class Cat : public Pet {
    public:
        //default constructor
        Cat () {
            isNeutered_ = false;
            isHissing_ = false;
            isMeowing_ = false;
            isPurring_ = false;
        }
        //overloaded constructor
        Cat (string name, int species, bool talks, bool isNeutered, bool isHissing, bool isMeowing, bool isPurring) : Pet(name, species, talks) {
            isNeutered_ = isNeutered;
            isHissing_ = isHissing;
            isMeowing_ = isMeowing;
            isPurring_ = isPurring;
        }
        
        //getters
        const bool getisMeowing() {
            return isMeowing_;
        }
        
        const bool getisPurring() {
            return isPurring_;
        }
        
        const bool getisHissing() {
            return isHissing_;
        }
        
        const bool getisNeutered() {
            return isNeutered_;
        }
        
        //setters
        void setisMeowing(bool isMeowing) {
            isMeowing_ = isMeowing;
            /*can't physically do both at same time - probably best practice is to use 
              an integer to determine what state the cat is in, rather than
              multiple booleans that are mutually exclusive, so the function is not setting 
              three variables at once
            setisPurring (false);
            setisHissing (false);
            */
        }
        void setisPurring(bool isPurring) {
            isPurring_ = isPurring;
            /*can't do both at same time, but causes undefined behavior
            setisMeowing (false);
            setisHissing (false);
            */
        }
        void setisHissing(bool isHissing) {
            isHissing_ = isHissing;
            /*can't do both at same time, but causes undefined behavior
            setisMeowing (false);
            setisHissing (false);
            */
        }
        
        void setisNeutered (bool isNeutered) {
            isNeutered_ = isNeutered;
        }
        
        string print () {
            //changed print to return a string rather than void since we're not supposed to have
            //cout statements in classes
            stringstream ss;
            ss << Pet::print() << endl << "neutered: " << isNeutered_
                 << endl << "hissing currently: " << isHissing_
                 << endl << "meowing currently: " << isMeowing_
                 << endl << "purring currently: " << isPurring_;
                 
            return ss.str();
        }
        
    private:
        bool isNeutered_;
        bool isHissing_;
        bool isMeowing_;
        bool isPurring_;
};

int main () {
    Bird Tweety("Tweety", 1, true, true, true, true, true);
    Cat Sylvester ("Sylvester", 2, false, false, false, false, false);
    Dog Krypto ("Name", 3, false, false, false);
    Pet Test_Pet;
    Bird Test_Bird;
    Cat Test_Cat;
    Dog Test_Dog;
    
    
    cout << Tweety.print()
         << endl
         << Sylvester.print()
         << endl
         << Krypto.print();
         
    //Testing Pet functions
    Test_Pet.setName ("Test_Name");
    Test_Pet.setSpecies (2);
    Test_Pet.setTalks (false);

    cout << endl
         << Test_Pet.getName()
         << endl
         << Test_Pet.getSpecies()
         << endl
         << Test_Pet.getTalks()
         << endl;
    
    //Testing bird functions    
    Test_Bird.setcanFly (true);
    Test_Bird.setcanSing (true);
    Test_Bird.setisCaged (true);
    Test_Bird.setlaidEggToday (true);

    cout << Test_Bird.getcanFly()
         << endl
         << Test_Bird.getcanSing()
    << endl <<
    Test_Bird.getisCaged()
    << endl <<
    Test_Bird.getlaidEggToday()
    << endl <<

    Test_Bird.fly()
    << endl <<
    Test_Bird.sing()
    << endl <<
    Test_Bird.layEgg()
    << endl;
    
    //testing Dog Functions
    Test_Dog.setisCurrentlyBarking (true);
    Test_Dog.setisNeutered (true);

    cout << endl
         << "Barking: " << Test_Dog.getisCurrentlyBarking()
         << endl
         << "Neutered:" << Test_Dog.getisNeutered();
    
    //testing Cat Functions
    
    Test_Cat.setisMeowing (false);
    Test_Cat.setisPurring (true);
    Test_Cat.setisHissing (true);
    Test_Cat.setisNeutered (true);
    
    cout << endl
         << Test_Cat.getisMeowing()
         << endl << 
    Test_Cat.getisPurring ()
        << endl<< 
    Test_Cat.getisHissing ()
        << endl << 
    Test_Cat.getisNeutered();
    
    
    return 0;
}