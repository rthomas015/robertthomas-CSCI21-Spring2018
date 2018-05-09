#include "stack.h"

using namespace std;
    //Constructor
    //Sets head and tail to point to NULL
    template <typename T>
    Stack<T>::Stack() {
        head = NULL;
        tail = NULL;
    }
    
    //Destructor
    template <typename T>
    Stack<T>::~Stack(){
        
    }
     
    //Print
    //prints all items in the Stack 
    //@param = none
    //@return = none
    template <typename T>
    string Stack<T>::print (){
        stringstream ss;
        Node<T>* ptr = tail;
        
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
    template <typename T>
    int Stack<T>::size () {
        Node<T>* ptr = tail;
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
    template <typename T>
    void Stack<T>::pop () {
        Node<T>* ptr = tail;
        Node<T>* penultimateptr = new Node<T>();
        
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
    template <typename T>
    void Stack<T>::push (T name){
        Node<T>* newNode = new Node<T>();
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
    template <typename T>
    T Stack<T>::peek_name() {
        return head->contents();
    }
    
    
//added to make program function just for strings   
template class Stack<string>;