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
#include "pet.h"
#include "bird.h"
#include "cat.h"
#include "dog.h"

using namespace std;

//Bird class derived from Pet class

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