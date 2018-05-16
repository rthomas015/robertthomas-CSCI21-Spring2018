#ifndef Iterator_h
#define Iterator_h

#include "node.h"
#include <string>
#include <iostream>

using namespace std;

class Iterator {
    private:
        Node* ptr;
        
    public:
        //Constructor
        Iterator ();
        
        //Overloaded Constructor
        //@param - Node pointer to point at/towards
        //@return - nothing
        Iterator (Node* aPtr);
        
        
        //getPtr - returns what the iterator is pointing at
        //@param - none
        //@return - returns a Node<T> pointer
        Node* getPtr() const{
            return ptr;
        }
        
        //Overloaded != (checks to see if two iterators are equal)
        //@param - the iterator on the right hand side of the equation
        //@return - true/false depending on if they do not equal
        bool operator!= (const Iterator right);
        
        //Overloaded -- (moves through the Queue backwards)
        //@param - int (generic) - required based on syntax
        //@return - Iterator that points to the previous item of the Queue
        Iterator operator-- (int);
        
        //Overloaded -- (moves through the Queue backwards)
        //@param - none (this is prefix --)
        //@return - Iterator that points to the previous item of the Queue
        Iterator& operator-- ();
        
        //Overloaded ++ (moves through the Queue forwards)
        //@param - int (generic) - required based on syntax
        //@return - Iterator that points to the next item of the Queue
        Iterator operator++ (int);
        
        //Overloaded ++ (moves through the Queue forwards)
        //@param - none (this is prefix ++)
        //@return - returns iteartor that points to the next item of the Queue
        Iterator& operator++();
        
        //Overloaded = (sets the left item equal to the right)
        //@param - an iterator on the right side of the equation
        //@return - an iterator value for the left side of the equation
        Iterator operator= (const Iterator right);
        
        //Overloaded =  (checks to see if two Iterator objects are equal)
        //@param - an Iterator object (the right side of the = equation)
        //@return - true (if the items are not equal) and false (if the items are equal)
        //this seems backwards or confusing, but i went with it
        bool operator== (const Iterator right);
        
        //Print function - prints the content of the thing the Iterator is pointing at
        //@param - none
        //@return - string of contents
        string print();
};

#endif