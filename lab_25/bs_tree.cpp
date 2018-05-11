#include "bs_tree.h"

using namespace std;

    BSTree::BSTree() {
        root = NULL;
        size_ = 0;
    }
    
    int BSTree::size() {
        return RecursiveSize(root);
    }
    
    int BSTree::RecursiveSize(BSTNode* aNode) {
        int treeSize = 1;
        
        if (aNode == NULL) {
            return 0;
        }
        else {
            if (aNode->left_child() != NULL) {
                treeSize = treeSize + RecursiveSize(aNode->left_child());
            }
            if (aNode->right_child() != NULL) {
                treeSize = treeSize + RecursiveSize(aNode->right_child());
            }
        }
        
        return treeSize;
    }
    
    string BSTree::InOrder() {
        stringstream ss;
        ss << RecursiveInOrder(root);
        return ss.str();
    }
    
    string BSTree::RecursiveInOrder(BSTNode* aNode) {
        stringstream ss;
        if (aNode == NULL)
            return string();
            
        ss << RecursiveInOrder(aNode->left_child());
        ss << aNode->contents() << " ";
        ss << RecursiveInOrder(aNode->right_child());
    
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
                return true;
            }
            else if (x > penultimateptr->contents()) {
                penultimateptr->set_right_child(newNode);
                return true;
            }
            else {
                return false;
            }
        }
        
    }
    
    void BSTree::Clear() {
        root = NULL; //doesn't actually delete everything, can't be the right way
    }
    
         
    int BSTree::FindMin() {
        BSTNode* ptr = root;
        BSTNode* penultimateptr = root;
        
        while (ptr != NULL) {
            penultimateptr = ptr;
            ptr = ptr->left_child();
        }
        
        if (penultimateptr == NULL) {
            return 0;
        }
        else {
            return penultimateptr->contents();
        }
    }
    
    bool BSTree::Remove(int x) {
        return RecursiveRemove(x);
    }

    bool BSTree::RecursiveRemove(int key) {
        BSTNode* ptr = root;
        BSTNode* penultimateptr = NULL;
    
        if (ptr == NULL) {
            return false;
        }
        
        while (ptr != NULL) { //Tree is not empty
            if (ptr->contents() == key) {  //if equal then its found
                //No Children
                if (ptr->left_child() == NULL && ptr->right_child() == NULL) {        //there are no children
                    if (!penultimateptr) {
                        root = NULL;
                    }
                    else if (penultimateptr->left_child() == ptr) { //its the left node
                        penultimateptr->set_left_child(NULL);
                    }
                    else { //its the right node
                        penultimateptr->set_right_child(NULL);
                    }
                }
                //Left Child Only
                else if (ptr->left_child() != NULL && ptr->right_child() == NULL) { //Remove Node with only left child
                    if (!penultimateptr) {
                        root = ptr->left_child();
                    }
                    else if (penultimateptr->left_child() == ptr) {                     //its the left node
                        penultimateptr->set_left_child(ptr->left_child());
                    }
                    else {                                                              //its the right node
                        penultimateptr->set_right_child(ptr->left_child());
                    }
                }
                //Right Child Only
                else if (ptr->left_child() == NULL && ptr->right_child() != NULL) { //Remove Node with only right child
                    if (!penultimateptr) {
                        root = ptr->right_child();
                    }
                    else if (penultimateptr->left_child() == ptr) {                     //its the left node
                        penultimateptr->set_left_child(ptr->right_child());
                    }
                    else {                                                              //its the right node
                        penultimateptr->set_right_child(ptr->right_child());
                    }
                }
                //Two Children
                else {
                    // Find successor (leftmost child of right subtree)
                    BSTNode* suc = ptr->right_child();
                    
                    while (suc->left_child() != NULL) {
                       penultimateptr = suc;
                       suc = suc->left_child();
                    }
                    
                    // Copy successor value to current node
                    int x = suc->contents();
                    RecursiveRemove(x);
                    ptr->set_contents(x); 
                }
                
                return true;
            }
            else if (ptr->contents() < key) {   //if less than search right
                penultimateptr = ptr;
                ptr = ptr->right_child();
            }
            else {                              //if more than search left
                penultimateptr = ptr;
                ptr = ptr->left_child();
            }
        }
        
        return false;
    }