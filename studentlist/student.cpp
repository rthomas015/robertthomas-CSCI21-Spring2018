#include <string>
#include <iostream>
#include <fstream>
#include <sstream>

using namespace std;

/*Class Student: 
    - first name (string)
    - last name (string)
*/

class Student {
  private:
    string firstName_,  
            secondName_;
    
    public:
    //Constructor
    Student(){
        firstName_ = "";
        secondName_ = "";
    }
    
    //Overloaded Constructor
    Student(string firstname, string secondname) {
        firstName_ = firstname;
        secondName_ = secondname;
    }
    
    //Getters
    const string getfirstName() {
        return firstName_;
    }
    
    const string getsecondName() {
        return secondName_;
    }
    
    
    //Setters
    void setfirstName(string firstName) {
        firstName_ = firstName;
    }
    
    void setsecondName(string secondName) {
        secondName_ = secondName;
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

int main () {
    ifstream ifile;
    ifile.open ("input.txt");
    string 
    
    while (!ifile.eof()) {
        getline()
    }
    
    ifile.close();
    
    return 0;
}