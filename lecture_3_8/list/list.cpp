#include "list.h"

using namespace std;
    //Constructor
    //Sets head and tail to point to NULL
    list::list() {
        head = NULL;
        tail = NULL;
    }
    
    //Destructor
    list::~list(){
        
    }
     
    //Print
    //prints all items in the list 
    //@param = none
    //@return = none
    string list::print (){
        stringstream ss;
        Node* ptr = head;
        ss << "";

        while (ptr != NULL) {
            ss << ptr->contents() << " ";
            ptr = ptr->next_node();
        }
        
        
        return ss.str();
    }
    
    //Size
    //Returns the size of the list 
    //@param = none
    //@return = integer counter which counted all the items of the list
    int list::size () {
        Node* ptr = head;
        int counter = 0;
        
        while (ptr != NULL) {
            counter = counter + 1;
            ptr = ptr->next_node();
        }
        
        return counter;
    }
    
    //Pop
    //removes an item from the list
    //@param = none
    //@return = none
    void list::pop () {
        Node* ptr = head;
        Node* penultimateptr = new Node();
        
        if (head != NULL) {
        
        if (ptr->next_node() == NULL) {
            head = NULL;
            tail = NULL;
        }
        else {
            while (ptr->next_node()) {//search for last pointer and second to last pointer
                penultimateptr = ptr;
                ptr = ptr->next_node();
            }
            ptr = NULL;
            penultimateptr->set_next_node(ptr);
            tail = penultimateptr;
        }
        }
    }
    
    //Push
    //adds an item to the list
    //@param = name - a string that holds the content for the node
    //@return = none
    void list::push (string name){
        Node* newNode = new Node();
        newNode->set_contents(name);
        
        if (head == NULL) {
            head = newNode;
            tail = newNode;
        }
        else {
            tail->set_next_node(newNode);
            tail = newNode;
        }
    }
    
    //Peek
    //shows the tail of the list
    //@param = none
    //@return = string (the contents of the tail of the list)
    string list::peek() {
        return tail->contents();
    }