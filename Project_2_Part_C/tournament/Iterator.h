#ifndef Iterator_h
#define Iterator_h

#include "node.h"
#include <string>
#include <iostream>

using namespace std;

template <class T>
class Iterator {
    private:
        Node<T>* ptr;
        
    public:
        //Constructor
        Iterator<T> ();
        
        //Overloaded Constructor
        //@param - Node pointer to point at/towards
        //@return - nothing
        Iterator<T> (Node<T>* aPtr);
        
        
        //getPtr - returns what the iterator is pointing at
        //@param - none
        //@return - returns a Node<T> pointer
        Node<T>* getPtr() const{
            return ptr;
        }
        
        //Overloaded != (checks to see if two iterators are equal)
        //@param - the iterator on the right hand side of the equation
        //@return - true/false depending on if they do not equal
        bool operator!= (const Iterator<T> right);
        
        //Overloaded -- (moves through the Queue backwards)
        //@param - int (generic) - required based on syntax
        //@return - Iterator that points to the previous item of the Queue
        Iterator<T> operator-- (int);
        
        //Overloaded -- (moves through the Queue backwards)
        //@param - none (this is prefix --)
        //@return - Iterator that points to the previous item of the Queue
        Iterator<T>& operator-- ();
        
        //Overloaded ++ (moves through the Queue forwards)
        //@param - int (generic) - required based on syntax
        //@return - Iterator that points to the next item of the Queue
        Iterator<T> operator++ (int);
        
        //Overloaded ++ (moves through the Queue forwards)
        //@param - none (this is prefix ++)
        //@return - returns iteartor that points to the next item of the Queue
        Iterator<T>& operator++();
        
        //Overloaded = (sets the left item equal to the right)
        //@param - an iterator on the right side of the equation
        //@return - an iterator value for the left side of the equation
        Iterator<T> operator= (const Iterator<T> right);
        
        //Overloaded =  (checks to see if two Iterator objects are equal)
        //@param - an Iterator object (the right side of the = equation)
        //@return - true (if the items are not equal) and false (if the items are equal)
        //this seems backwards or confusing, but i went with it
        bool operator== (const Iterator<T> right);
        
        //Print function - prints the content of the thing the Iterator is pointing at
        //@param - none
        //@return - string of contents
        string print();
};

#endif