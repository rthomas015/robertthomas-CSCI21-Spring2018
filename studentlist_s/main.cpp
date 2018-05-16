#include <string>
#include <iostream>
#include <fstream>
#include <sstream>
#include "Iterator.h"
#include "node.h"
#include "list.h"
#include "student.h"

using namespace std;

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
    list studentList;

    //read file input
    while (!ifile.eof()) {
        currStudent currentStudent;
        getline(ifile,place_holder);
        
        ss.clear();
        ss << place_holder;
        ss >> currentStudent.firstName;
        ss >> currentStudent.secondName;
        
        Student anotherStudent(currentStudent.firstName,currentStudent.secondName);
        studentList.push(anotherStudent);
    }
    
    //print unsorted list
    cout << endl << "Unsorted List: " << endl;
    cout << studentList.print(); //<--stopped right here

    //print unsorted list w /iterator
    cout << endl << endl << "Iterated List: ";
    for (Iterator iter = studentList.begin(); iter != studentList.end(); iter++) {
        Node* tempPtr = iter.getPtr();
        Student tempStudent = tempPtr->contents();
        cout << endl << "Name: " << tempStudent.getfirstName() << " " << tempStudent.getsecondName();
    }
    
    //sort list by last name
    studentList.sort();
    
    //print sorted list w /iterator
    cout << endl << endl << "Iterated List (sorted by Last Name): ";
    for (Iterator iter = studentList.begin(); iter != studentList.end(); iter++) {
        Node* tempPtr = iter.getPtr();
        Student tempStudent = tempPtr->contents();
        cout << endl << "Name: " << tempStudent.getfirstName() << " " << tempStudent.getsecondName();
    }
    
    //close file
    ifile.close();
    
    return 0;
}