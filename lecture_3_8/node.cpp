#include <string>
#include <iostream>
#include "node.h"

using namespace std;

/*Class Node:
    - pointer to next student object

    //functions
    constructor
        thing
        next = null
    constructor 
    
    destructor
    
    
    insert
    delete
    getNext
    setNext
    getThing
    setThing
*/

        //Constructor
        Node::Node() {
            //nextNode_ = nullptr;
        }
        
        Node::Node(string name) {
            student_ = name;
            nextNode_ = NULL;
        }
        //Destructor
        Node::~Node (){
            //delete nextNode_;
        }
        
        //getContents
        const string Node::contents () {
            return student_; 
        }
        
        Node* Node::next_node() {
            return nextNode_;
        }

        void Node::set_contents (string newStudent) {
            student_ = newStudent;
        }
        
        void Node::set_next_node (Node* nextNode) {
            nextNode_ = nextNode;
        }