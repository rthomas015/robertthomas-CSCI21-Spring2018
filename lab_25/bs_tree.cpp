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
           BSTNode* par = NULL;
           BSTNode* ptr = root;
           
           if (ptr == NULL) {
                return false;
           }
           
           while (ptr != NULL) { 
              if (ptr->contents() == key) { // Node found 
                 if (!ptr->left_child() && !ptr->right_child()) {        // Remove leaf
                    if (!par) { // Node is root
                       root = NULL;
                    }
                    else if (par->left_child() == ptr) {
                       par->set_left_child(NULL);
                    }
                    else {
                       par->set_right_child(NULL);
                    }
                 }
                 else if (ptr->left_child() && !ptr->right_child()) {     // Remove node with only left child
                    if (!par) { // Node is root
                       root = ptr->left_child();
                    }
                    else if (par->left_child() == ptr) {
                       par->set_left_child(ptr->left_child());
                    }
                    else {
                       par->set_right_child(ptr->left_child());
                    }
                 }
                 else if (!ptr->left_child() && ptr->right_child()) {     // Remove node with only right child
                    if (!par){ // Node is root
                       root = ptr->right_child();
                    }
                    else if (par->left_child() == ptr) {
                       par->set_left_child(ptr->right_child());
                    }
                    else {
                       par->set_right_child(ptr->right_child());
                    }
                }
                 else {                             // Remove node with two children
                    // Find successor (leftmost child of right subtree)
                    BSTNode* suc = ptr->right_child();
                    
                    while (suc->left_child() != NULL) {
                       suc = suc->left_child();
                    }
                    
                    ptr = suc;                 // Copy successor to current node
                    //TreeRemove(ptr->right_child(), suc->key)     // Remove successor from right subtree
                    // Node found and removed
                 }
                 
                 size_ = size_ - 1;
                 return true;
            }
              else if (ptr->contents() < key) { // Search right
                 par = ptr;
                 ptr = ptr->right_child();
              }
              
              else { // Search left
                 par = ptr;
                 ptr = ptr->left_child();
              }
              //
              //else {
             //     return false;
              //} if (ptr->contents() > key)
        
           }

        return false; // Node not found
    }