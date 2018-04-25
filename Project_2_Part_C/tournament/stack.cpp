#include "stack.h"

using namespace std;
    //Constructor
    //Sets head and tail to point to NULL
    Stack::Stack() {
        head = NULL;
        tail = NULL;
    }
    
    //Destructor
    Stack::~Stack(){
        
    }
     
    //Print
    //prints all items in the Stack 
    //@param = none
    //@return = none
    string Stack::print (){
        stringstream ss;
        Node* ptr = tail;
        
        while (ptr != NULL) {
            ss << ptr->contents() << " ";
            ptr = ptr->next_node();
        }
        
        return ss.str();
    }
    
    //Size
    //Returns the size of the Stack 
    //@param = none
    //@return = integer counter which counted all the items of the Stack
    int Stack::size () {
        Node* ptr = tail;
        int counter = 0;
        
        while (ptr != NULL) {
            counter = counter + 1;
            ptr = ptr->next_node();
        }
        
        return counter;
    }
    
    //Pop
    //removes an item from the top of the Stack
    //@param = none
    //@return = none
    void Stack::pop () {
        Node* ptr = tail;
        Node* penultimateptr = new Node();
        
        if (tail != NULL) {
            if (tail->next_node() == NULL) {
                head = NULL;
                tail = NULL;
            }
        
            else {
                while (ptr->next_node()) {
                    penultimateptr = ptr;
                    ptr = ptr->next_node();
                }
                ptr = NULL;
                penultimateptr->set_next_node(ptr);
                head = penultimateptr;
            }
        }
    }
    
    //Push
    //adds an item to the top of the Stack
    //@param = name - a string that holds the content for the node
    //@return = none
    void Stack::push (string name){
        Node* newNode = new Node();
        newNode->set_contents(name);
        
        if (tail == NULL) {
            head = newNode;
            tail = newNode;
        }
        else {
            head->set_next_node(newNode);
            head = newNode;
        }
    }
    
    
    //Peek
    //shows the head of the Stack
    //@param = none
    //@return = string (the contents of the head of the Stack)
    string Stack::peek() {
        return head->contents();
    }