#include <string>
#include <iostream>
#include "node.h"

using namespace std;

        //Constructor
        template<typename T>
        Node<T>::Node() {
            //player_ = "";
            nextNode_ = NULL;
            //gamesPlayed = 0;
        }
        
        template<typename T>
        Node<T>::Node(T name) {
            player_ = name;
            nextNode_ = NULL;
        }
        
        template<typename T>
        Node<T>::Node(T name, Node* nextNode) {
            this->player_ = name;
            this->nextNode_ = nextNode;
        }
        
        //Destructor
       /* Node::~Node (){
            //this breaks stuff
            delete nextNode_;
        }*/
        
        //getContents
        template<typename T>
        T Node<T>::contents () const{
            return player_; 
        }
        
        template<typename T>
        Node<T>* Node<T>::next_node() const {
            return nextNode_;
        }

        template<typename T>
        void Node<T>::set_contents (T newStudent) {
            player_ = newStudent;
        }
        
        template<typename T>
        void Node<T>::set_next_node (Node* nextNode) {
            nextNode_ = nextNode;
        }
        
//added to make program function just for strings    
template class Node<string>;