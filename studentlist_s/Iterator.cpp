#include "Iterator.h"

using namespace std;

    Iterator::Iterator () {
        ptr = NULL;
    }
        
    //overloaded
    Iterator::Iterator (Node* aPtr) {
        ptr = aPtr;
    }
    
    Iterator& Iterator::operator++ () {
        ptr = ptr->next_node();
        return *this;
    }
    
    Iterator Iterator::operator++ (int) {
        /*Node<T>* nextPtr = ptr;
        nextPtr = ptr->next_node();
        Iterator<T> iter (nextPtr);
        return iter;*/
        //return ptr->next_node();
        
        Iterator tempPtr = *this;  
        ++*this;  
        return tempPtr;
    }
    
    Iterator& Iterator::operator-- () {
        ptr = ptr->prev_node();
        return *this;
    }
    
    Iterator Iterator::operator-- (int) {
        Iterator tempPtr = *this;  
        --*this;  
        return tempPtr;
    }

    bool Iterator::operator== (const Iterator right) {
        if (right.getPtr() == this->getPtr()) {
            return true;
        }
        else {
            return false;
        }
    }
    
    //returns opposite of ==
    bool Iterator::operator!= (const Iterator right) {
        if (right.getPtr() == this->getPtr()) {
            return false;
        }
        else {
            return true;
        }
        //return !(this == right);
    }
    
    Iterator Iterator::operator= (const Iterator right) {
        ptr = right.getPtr();
        return *this;
    }

    string Iterator::print() {
        /*if (ptr == NULL){
            return NULL;
        }
        else {
            return ptr->contents();
        }*/
    }
    
//added to make program function just for strings   
//template class Iterator<string>;