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
    Node<T>* Iterator<T>::operator++ (int) {
        /*Node<T>* nextPtr = ptr;
        nextPtr = ptr->next_node();
        Iterator<T> iter (nextPtr);
        return iter;*/
        return ptr->next_node();
    }
    
    //"returns true if two iterators point to different items" - not intuitive
    template <typename T>  
    bool Iterator<T>::operator= (const Iterator<T> right) {
        if (right.ptr->contents() == this->ptr->contents()) {
            return false;
        }
        else {
            return true;
        }
    }

    template <typename T>
    string Iterator<T>::print() {
        return ptr->contents();
    }
    
//added to make program function just for strings   
template class Iterator<string>;
