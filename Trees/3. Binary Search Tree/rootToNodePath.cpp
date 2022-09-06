#include <iostream>
#include <vector>
#include "BinaryTreeNode.h"
using namespace std;


// Ans is "from node to root" 
//TC: O(logN)
vector<int>* getPathFromNodeToRoot(BinaryTreeNode<int> *root , int data) { 
	if(!root) return NULL;

    if(root->data == data) {
        vector<int> * path = new vector<int>(); 
        // vector needs to be pointer here as we need to dynamically allocate it
        path->push_back(root->data);
        return path;
    }
    else if (root->data < data) {
        vector<int> * rightOutput = getPathFromNodeToRoot(root->right, data);
        if(rightOutput != NULL) {
            rightOutput->push_back(root->data);
            return rightOutput;
        }
        
    } else {
        vector<int> * leftOutput = getPathFromNodeToRoot(root->left, data);
        if(leftOutput != NULL) {
            leftOutput->push_back(root->data);
            return leftOutput;
        }
        
    }
    
    return NULL;
}

// if we want ans = "from root to node"
//TC: O(logN)
vector<int>* getPathFromRootToNode(BinaryTreeNode<int> *root , int data, vector<int> * path) {
	if(!root) return NULL;

    path->push_back(root->data);

    if(root->data == data) {
        return path;
    } else if (root->data > data) {
        vector<int> * leftPath = rootToNode(root->left, data, path);
        if(leftPath) return leftPath;
    } else {
        vector<int> * rightPath = rootToNode(root->right, data, path);
        if(rightPath) return rightPath;
    }


    path->pop_back();
    return NULL;
}