#include "bs_tree.h"

using namespace std;

    BSTree::BSTree() {
        root = NULL;
        size_ = 0;
    }
    
    int BSTree::size() {
        //doesn't take an argument so can't recursively count
        //adds and subtracts upon add and removing
        return size_;
    }
    
    string BSTree::InOrder() {
        stringstream ss;
        BSTNode* ptr = root;
        
        if (ptr != NULL) {
            //prints it in order into a string
            //ss << recursiveOrder(ptr,FindMin());
            //ss << return recursiveOrder(ss.str());
        }
        else { //tree is empty so return empty string
            
        }
        
        return ss.str();
    }
    

    bool BSTree::Insert(int x) {
        BSTNode* ptr = root;
        BSTNode* penultimateptr = NULL;
        BSTNode* newNode = new BSTNode(x);
        
        if (ptr == NULL) {
            root = newNode;
            size_ = size_ + 1;
            return true;
        }
        else {
            while (ptr != NULL) { //then there is something in the list
                if (x == ptr->contents()) { //equal
                    return false;
                }
                else if (x < ptr->contents()) { //go left
                    penultimateptr = ptr;
                    ptr = ptr->left_child();
                }
                else { //go right
                    penultimateptr = ptr;
                    ptr = ptr->right_child();
                }
            }
        }
        
        if (penultimateptr != NULL) {
            if (x < penultimateptr->contents()) {
                penultimateptr->set_left_child(newNode);
                size_ = size_ + 1;
                return true;
            }
            else if (x > penultimateptr->contents()) {
                penultimateptr->set_right_child(newNode);
                size_ = size_ + 1;
                return true;
            }
            else {
                return false;
            }
        }
        
    }
    
    void BSTree::Clear() {
        root = NULL; //doesn't actually delete everything, can't be the right way
        size_ = 0;
    }