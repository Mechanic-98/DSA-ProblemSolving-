#include <iostream>
#include <vector>
#include "BinaryTreeNode.h"
using namespace std;

// we are returning vector pointer because we need to update vector during recursion calls
//TC: O(N)
vector<int>* nodeToRootPath(BinaryTreeNode<int>* root, int k) {
    if(!root) return NULL;


    if(root->data == k) {
        vector<int> * path = new vector<int>();
        path->push_back(root->data); 
        return path;
    }

    vector<int> * leftOutput = nodeToRootPath(root->left, k);
    if(!leftOutput) {
        leftOutput->push_back(root->data); 
        return leftOutput;
    }

    vector<int> * rightOutput = nodeToRootPath(root->right, k);
    if(!rightOutput) {
        rightOutput->push_back(root->data); 
        return rightOutput;
    }

    return NULL;
}


// path from root
//TC: O(N)
vector<int>* rootToNode(BinaryTreeNode<int> *root , int data, vector<int> * path) {
	if(!root) return NULL;

    path->push_back(root->data);

    if(root->data == data) {
        return path;
    }
    vector<int> * leftPath = rootToNode(root->left, data, path);
    vector<int> * rightPath = rootToNode(root->right, data, path);

    if(leftPath) return leftPath;
    if(rightPath) return rightPath;

    path->pop_back();
    return NULL;
}