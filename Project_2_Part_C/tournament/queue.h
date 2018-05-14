//Queue
/* A implementation of a Queue data structure - first in first out */

#ifndef queue_H
#define queue_H

#include <iostream>
#include <sstream>
#include <string>
#include "node.h"
#include "Iterator.h"

using namespace std;

//class Queue
//templated but made for strings only based on cpp
template <class T>
class Queue {
    
    private:
        Node<T>* head;
        Node<T>* tail;

    public:
        //Constructor
        Queue();
        
        //Push
        //adds an item to the back of the Queue
        //@param - T info: takes in data of type T and places it at the back of the Queue
        //@return - none
        void push(T info);
        
        //Pop
        //Removes an item from the Queue (the first item to go into the Queue)
        //@param - none
        //@return - none
        void pop();
        
        //Print
        //Prints all the contents of each node contained in the Queue
        //@param - none
        //@return - none
        string print();
        
        //peek_name
        //displays the item that is at the beginning of the queue
        //@param - none
        //@return - node contents of type T
        T peek_name();
        
        //Size
        //calculates the size of the Queue
        //@param - none
        //@return - integer
        int size();
        
        //friend class Iterator
        friend class Iterator<T>;
        
        //Returns an iterator to the front of the Queue
        Iterator<T> begin();
        
        //Returns an iterator to one past the end of the line/Queue
        Iterator<T> end();
        
        //Returns an iterator to the end of the line/Queue (the head)
        Iterator<T> rbegin();
};

#endif