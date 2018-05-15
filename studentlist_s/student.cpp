#include "student.h"

    //Constructor
    Student::Student(){
        firstName_ = "";
        secondName_ = "";
    }
    
    //Overloaded Constructor
    Student::Student(string firstname, string secondname) {
        firstName_ = firstname;
        secondName_ = secondname;
    }
    
    //Getters
    const string Student::getfirstName() {
        return firstName_;
    }
    
    const string Student::getsecondName() {
        return secondName_;
    }
    
    
    //Setters
    void Student::setfirstName(string firstName) {
        firstName_ = firstName;
    }
    
    void Student::setsecondName(string secondName) {
        secondName_ = secondName;
    }
    
    //Destructor
    Student::~Student() {
        //not needed
    }
    
/*
    //overloaded operator (add student)
    void Student::operator<<(Student addStudent) {
        //dont really understand as the list is a group of objects
        //this makes it sound like the object is supposed to have a list instead
    }
    
    bool Student::operator<(const Student& student_2){
        //second argument is implict this
        return (secondName_ < student_2.secondName_);
    }
*/