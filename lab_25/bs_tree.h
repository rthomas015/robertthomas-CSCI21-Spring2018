#ifndef bs_tree_H
#define bs_tree_H

#include <string>
#include <iostream>
#include <sstream>
#include "bst_node.h"

using namespace std;

class BSTree {
    private:
        BSTNode* root;
        int size_;
        
    public:
        BSTree();
        int size();
        string InOrder();
        string RecursiveInOrder(BSTNode* aNode);
        
        int FindMin();
        
        bool Remove(int x);
        bool RecursiveRemove(int x);
        
        bool Insert(int x);
        
        void Clear();
        
        //int recursiveOrder(BSTNode* currentNode, int minimum);
        
        //BSTNode* findLocation(BSTNode* currentNode, int minimum);
        
        //BSTNode* recursivelyFindMinimum(BSTNode* currentNode, int minimum);
    


};

#endif