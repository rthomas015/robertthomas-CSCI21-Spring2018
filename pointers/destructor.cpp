/*
 * Name        : destructor.cpp
 * Author      : Luke Sathrum
 * Description : 
 */


#include <iostream>
using std::cout;
using std::cin;
using std::endl;

//create a class called Scores
class Scores {
 public:
 //constructor
  Scores(int size);
  //destructor
  ~Scores();
  
  void FillUp();
  void Output();
 private:
  //integer size_ = holds 
  //integer *scores_ = 
  int size_;
  int *scores_;
};

int main() {
  {
    //create a Scores object and pass 3 to its size
    Scores object(3);
    //Call FillUp function of object and requests multiple numbers from individual to fill up the array
    object.FillUp();
    //Prints out all the information in the class array
    object.Output();
    //leaves scope and calls destructor
    cout << "\nBefore leaving scope..\n";
  }
  cout << "After leaving scope..\n\n";

  {
    //creates a pointer to a new scores object and passes 2 to its size
    Scores *object = new Scores(2);
    //uses 'this' to call the object's FillUp function that the pointer is pointing to
    object->FillUp();
    //uses 'this' to call the object's Output function that the pointer is pointing to
    object->Output();
    cout << "\nBefore Delete...\n";
    //deletes the object
    delete object;
    //?Object pointer scores still exists?
    cout << "After Delete... still in scope\n\n";
  }

  return 0;
}
//Constructor
//sets the object's size_ to the amount passed as an argument
//sets the pointer scores_ to point to a new integer array? with size number of elements
Scores::Scores(int size) {
  cout << "The constructor has been called\n";
  size_ = size;
  scores_ = new int[size];
}

//Destructor
//Upon object losing scope scores_ pointer is deleted
Scores::~Scores() {
  cout << "The destructor has been called\n";
  delete[] scores_;
}

//Class Function Fill Up
//Iterates through the integer array created when the initial object is initialized
//Requests information from the user (an integer) that will populate each element of the array recursively
void Scores::FillUp() {
  for (int i = 0; i < size_; i++) {
    cout << "Enter score #" << (i + 1) << ": ";
    cin >> scores_[i];
  }
}

//Class function Output
//loops through the integer array and prints out all the values in the array
void Scores::Output() {
  for (int i = 0; i < size_; i++) {
    cout << "Score #" << (i + 1) << ": " << scores_[i] << endl;
  }
}
