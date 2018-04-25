#include <string>
#include <iostream>
#include "node.h"

using namespace std;

        //Constructor
        Node::Node() {
            player_ = "";
            nextNode_ = NULL;
            //gamesPlayed = 0;
        }
        
        Node::Node(string name) {
            player_ = name;
            nextNode_ = NULL;
            //gamesPlayed = 0;
        } 
        
        Node::Node(string name, Node* nextNode) {
            this->player_ = name;
            this->nextNode_ = nextNode;
        }
        
        //Destructor
       /* Node::~Node (){
            //this breaks stuff
            delete nextNode_;
        }*/
        
        //getContents
        string Node::contents () const{
            return player_; 
        }
        
        Node* Node::next_node() const {
            return nextNode_;
        }

        void Node::set_contents (string newStudent) {
            player_ = newStudent;
        }
        
        void Node::set_next_node (Node* nextNode) {
            nextNode_ = nextNode;
        }
        
       /* int Node::get_gamesPlayed(){
            return gamesPlayed;
        }
    
        void Node::set_gamesPlayed(int gp){
            gamesPlayed = gp;
        }*/