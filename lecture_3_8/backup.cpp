#include <string>
#include <iostream>
#include "node.h"

using namespace std;

/*Class Student: 
    - first name (string)
    - last name (string)
    - ID number
*/

class Student {
  private:
    string firstName_,  
            secondName_,
            IDNumber_;
    public:
    Student(){
        firstName_ = "";
        secondName_ = "";
        IDNumber_ = "";
    }
    
    Student () {
        
    }
    //Getters
    const string getfirstName() {
        return firstName_;
    }
    
    const string getsecondName() {
        return secondName_;
    }
    
    const string getIDNumber() {
        return IDNumber_;
    }
    
    //Setters
    void setfirstName(string firstName) {
        firstName_ = firstName;
    }
    
    void setsecondName(string secondName) {
        secondName_ = secondName;
    }
    
    void setIDNumber(string IDNumber) {
        IDNumber_ = IDNumber;
    }
    
};

/*Class Node:
    - pointer to next student object

    //functions
    constructor
        thing
        next = null
    constructor 
    
    destructor
    
    
    insert
    delete
    getNext
    setNext
    getThing
    setThing
*/

class Node {
    private:
        Student Student_;
        Node* nextNode_;
        
    public:
        //Constructor
        Node() {
            nextNode_ = nullptr;
        }
        
        //Destructor
        ~Node (){
            delete nextNode_;
        }
        
        //Insert
        void setNext () {
            nextNode_++;
        }
        
        const Student getStudent() {
            return Student_;
        }
        
        void setStudent(Student newStudent) {
            
        }
        
};