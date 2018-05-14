#include "Iterator.h"

using namespace std;

    template <typename T>    
    Iterator<T>::Iterator () {
        ptr = NULL;
    }
        
    //overloaded
    template <typename T>  
    Iterator<T>::Iterator (Node<T>* aPtr) {
        ptr = aPtr;
    }
    
    template <typename T>  
    Iterator<T>& Iterator<T>::operator++ () {
        ptr = ptr->next_node();
        return *this;
    }
    
    template <typename T>  
    Iterator<T> Iterator<T>::operator++ (int) {
        /*Node<T>* nextPtr = ptr;
        nextPtr = ptr->next_node();
        Iterator<T> iter (nextPtr);
        return iter;*/
        //return ptr->next_node();
        
        Iterator<T> tempPtr = *this;  
        ++*this;  
        return tempPtr;
    }
    
    template <typename T>  
    Iterator<T>& Iterator<T>::operator-- () {
        ptr = ptr->prev_node();
        return *this;
    }
    
    template <typename T>  
    Iterator<T> Iterator<T>::operator-- (int) {
        Iterator<T> tempPtr = *this;  
        --*this;  
        return tempPtr;
    }
    
    template <typename T>  
    bool Iterator<T>::operator== (const Iterator<T> right) {
        if (right.getPtr() == this->getPtr()) {
            return true;
        }
        else {
            return false;
        }
    }
    
    //returns opposite of ==
    template <typename T>  
    bool Iterator<T>::operator!= (const Iterator<T> right) {
        if (right.getPtr() == this->getPtr()) {
            return false;
        }
        else {
            return true;
        }
        //return !(this == right);
    }
    
    template <typename T>  
    Iterator<T> Iterator<T>::operator= (const Iterator<T> right) {
        ptr = right.getPtr();
        return *this;
    }

    template <typename T>
    string Iterator<T>::print() {
        if (ptr == NULL){
            return string();
        }
        else {
            return ptr->contents();
        }
    }
    
//added to make program function just for strings   
template class Iterator<string>;
