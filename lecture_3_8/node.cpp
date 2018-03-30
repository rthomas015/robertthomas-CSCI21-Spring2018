#include <string>
#include <iostream>
#include "node.h"

//using namespace std;

        //Constructor
        Node::Node() {
            student_ = "";
            nextNode_ = NULL;
        }
        
        Node::Node(std::string name) {
            student_ = name;
            nextNode_ = NULL;
        } 
        
        Node::Node(std::string name, Node* nextNode) {
            this->student_ = name;
            this->nextNode_ = nextNode;
        }
        
        //Destructor
        Node::~Node (){
            //this breaks stuff
            //delete nextNode_;
        }
        
        //getContents
        std::string Node::contents () const{
            return student_; 
        }
        
        Node* Node::next_node() const {
            return nextNode_;
        }

        void Node::set_contents (std::string newStudent) {
            student_ = newStudent;
        }
        
        void Node::set_next_node (Node* nextNode) {
            nextNode_ = nextNode;
        }