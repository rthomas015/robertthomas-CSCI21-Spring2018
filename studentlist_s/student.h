#ifndef student_H
#define student_H

#include <string>
#include <iostream>
#include <sstream>

using namespace std;

class Student {
  private:
    string firstName_,  
            secondName_;
    
    public:
    //Constructor
    Student();
    
    //Overloaded Constructor
    Student(string firstname, string secondname);
    
    //Getters
    const string getfirstName();
    
    const string getsecondName();
    
    
    //Setters
    void setfirstName(string firstName);
    
    void setsecondName(string secondName);
    
    //Destructor
    ~Student();

    //overloaded operator (add student)
    //void operator<<(Student addStudent);
    
    //bool operator<(const Student& student_2);

};

#endif