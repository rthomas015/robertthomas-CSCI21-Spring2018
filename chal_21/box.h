/*

 * Name        : box.h
 * Author      : Robert Thomas
 * Description : template class for Box that accepts different types of data
 */

Define a "header only" template class named Box with:- 
one data member 
contents (data type templated)
overloaded constructor 
one parameter newContents to be assigned to contents-
getter (getContents) and setter (setContents)- 
friend overloaded operator<<
*/

#ifndef box_h
#define box_h

#include <iostream>
#include <sstream>
#include <string>

using namespace std;

template<typename T>
class Box {
    private:
        T contents_;
        
    public:
    Box () {
        contents_ = T();
    }
    
    Box (T newContents) {
        contents_ = newContents;
    }
    
    const T getContents () {
        return contents_;    
    }
    
    void setContents (T newContents) {
        contents_ = newContents;
    }
    
    friend ostream& operator <<(ostream &out, const Box &boxobj) {
        out << boxobj.contents_;
        return out;
    }
};



#endif