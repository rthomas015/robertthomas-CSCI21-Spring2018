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
        Node* ptr = head;
       
        while(ptr != 0) {
            Node* next = ptr->next_node();
            delete ptr;
            ptr = next;
        }
    }
     
    
    //Print
    //prints all items in the list 
    //@param = none
    //@return = none
    string list::print (){
        stringstream ss;
        Student tempStu;
        Node* ptr = head;
        ss << "";

        while (ptr != NULL) {
            tempStu = ptr->contents();
            ss << tempStu.getfirstName();
            ss << " ";
            ss << tempStu.getsecondName();
            ss << endl;
            ptr = ptr->next_node();
        }
        
        return ss.str();
    }
    
    /*
    //Insert Before
    //inserts item into list
    //@param - location in list
    //@param - data to insert
    //@return - returns true if added and false if not
    bool list::insert(int location, Student aStu) {
        Node* newNode = new Node();
        newNode->set_contents(aStu);
        Node* ptr = head;
        Node* penultimateptr = NULL;
        
        int curLoc = 0;
        //if list is not empty
        if (head != NULL) {
            //loop to position
            while (ptr->next_node() != NULL && curLoc != location) {
                penultimateptr = ptr;
                ptr = ptr->next_node();
                curLoc = curLoc + 1;
            }
                
            if (location == 0) { //adding at beginning of list
                ptr->set_prev_node(newNode);
                head = newNode;
                head->set_next_node(ptr);
            }
            else if (location > size() || location < 0) { //outside of list
                return false;
            }  
            else if (location == size()) { //adding at end of list
                push(aStu);
            }
            else {
                penultimateptr->set_next_node(newNode);
                newNode->set_prev_node(penultimateptr);
                newNode->set_next_node(ptr);
                ptr->set_prev_node(newNode);
            }
        }
        //empty list
        else {
            head = newNode;
            tail = newNode;
        }
        
        return true;
    }*/
    
    /*
    //Remove
    //
    bool list::remove(string data) {
        Node* ptr = head;
        
        if (head != NULL) {
            
            while (ptr->next_node() != NULL && ptr->contents() != data) {
                ptr = ptr->next_node();
            }
            
            if (ptr->contents() == data) {
                
                if (ptr->next_node() == NULL) { 
                    //this is the first and only thing
                    pop();
                }
                else if (ptr == head && ptr != tail) {
                    //more than one thing and its the head
                    head = ptr->next_node();    
                }
                else if (ptr != head && ptr == tail) {
                    //more than one thing and its the tail
                    pop();
                }
                else {
                    //more than one thing and somewhere in middle
                    Node* prevPtr = ptr->prev_node();
                    Node* nextPtr = ptr->next_node();
                    prevPtr->set_next_node(ptr->next_node());
                    nextPtr->set_prev_node(ptr->prev_node());
                }
            }
            else {
                //didn't find
                return false;
            }
        }
        else {
            return false;
        }
        
        return true;
    }*/
    
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
    void list::push (Student aStu){
        Node* newNode = new Node();
        newNode->set_contents(aStu);
        
        if (head == NULL) {
            head = newNode;
            tail = newNode;
        }
        else {
            Node* tempPtr = new Node();
            tempPtr = tail;
            tail->set_next_node(newNode);
            tail = newNode;
            tail->set_prev_node(tempPtr);
        }
    }
    
    //Peek
    //shows the tail of the list
    //@param = none
    //@return = string (the contents of the tail of the list)
    Student list::peek() {
        if(tail != NULL) {
            return tail->contents();
        }

    }
    
    void list::sort() {
        Student tempStudent_1,
                tempStudent_2,
                phStudent;
        Node* tempNode = NULL;
        
        
        for (int i=0;i<size();i++) {
            
            for (Iterator iter = begin(); iter != end();iter++) {
                tempNode = iter.getPtr();
                tempStudent_1 = tempNode->contents();
                if (tempNode->next_node() != NULL){
                    tempNode = tempNode->next_node();
                }
                tempStudent_2 = tempNode->contents();

                if (tempStudent_1.getsecondName() < tempStudent_2.getsecondName()) {
                    tempNode->set_contents(tempStudent_1);
                    tempNode = tempNode->prev_node();
                    tempNode->set_contents(tempStudent_2);
                }
                
            }
        }
    }
    
    Iterator list::end() {
        Iterator iter;
        return iter;
    }
        
    Iterator list::begin() {
        Iterator iter(head);
        return iter;
    }
    
    Iterator list::rbegin() {
        Iterator iter(tail);
        return iter;
    }