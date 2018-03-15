#include <string>
#include <iostream>
#include <fstream>
#include <sstream>
#include <list>

using namespace std;

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
    
    //Destructor
    ~Student() {
        //not needed
    }

    //overloaded operator (add student)
    void operator<<(Student addStudent) {
        //dont really understand as the list is a group of objects
        //this makes it sound like the object is supposed to have a list instead
    }
    
    //used for std list sort command
    bool operator<(const Student& student_2){
        //second argument is implict this
        return (secondName_ < student_2.secondName_);
    }
};

//struct to hold data for currStudent
struct currStudent {
    string firstName;
    string secondName;
};

int main () {
    ifstream ifile;
    ifile.open ("input.txt");
    string place_holder = "";
    stringstream ss;
    list<Student> studentList;
    list<Student>::iterator iter;
    
    //read file input
    while (!ifile.eof()) {
        currStudent currentStudent;
        getline(ifile,place_holder);
        
        ss.clear();
        ss << place_holder;
        ss >> currentStudent.firstName;
        ss >> currentStudent.secondName;
        
        Student anotherStudent(currentStudent.firstName,currentStudent.secondName);
        studentList.push_back(anotherStudent);
    }
    
    //print unsorted list
    cout << endl << "Unsorted List: ";
    for (iter = studentList.begin(); iter != studentList.end(); iter++) {
        Student anotherStudent = *iter;
        cout << endl << "Name: " << anotherStudent.getfirstName() << " " << anotherStudent.getsecondName();
    }
    
    //sort list by last name
    studentList.sort();
    
    //print sorted list
    cout << endl << endl << "Sorted List (by last name): ";
    for (iter = studentList.begin(); iter != studentList.end(); iter++) {
        Student anotherStudent = *iter;
        cout << endl << "Name: " << anotherStudent.getfirstName() << " " << anotherStudent.getsecondName();
    }
    
    //close file
    ifile.close();
    
    return 0;
}