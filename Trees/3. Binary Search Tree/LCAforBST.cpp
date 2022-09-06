#include <iostream>
#include <vector>
#include "BinaryTreeNode.h"
using namespace std;

vector<int>* getPathFromRootToNode(BinaryTreeNode<int> *root , int data, vector<int> * path) {
	if(!root) return NULL;

    path->push_back(root->data);

    if(root->data == data) {
        return path;
    } else if (root->data > data) {
        vector<int> * leftPath = getPathFromRootToNode(root->left, data, path);
        if(leftPath) return leftPath;
    } else {
        vector<int> * rightPath = getPathFromRootToNode(root->right, data, path);
        if(rightPath) return rightPath;
    }


    path->pop_back();
    return NULL;
}


// Approach 1
int getLCA(BinaryTreeNode<int>* root , int val1 , int val2){
    // Write your code here
    if(!root) return -1;
    
    vector<int> * path1 = new vector<int>();
    vector<int> * path2 = new vector<int>();
    
    path1 = getPathFromRootToNode(root, val1, path1);
    path2 = getPathFromRootToNode(root, val2, path2);
    
    if(!path1 && !path2) return -1;
    else if (!path1) {
        int idx = path2->size() -1;
        return path2->at(idx);
    } else if (!path2) {
        int idx = path1->size() -1;
        return path1->at(idx);
    } else {
        int i;
        for(i =0; i< path1->size() && path2->size(); i++) {
            if(i == path1->size()) break;
            if(i == path2->size()) break;
            if(path1->at(i) != path2->at(i)) break;
        }

        return path1->at(i-1);
    }
    
}


// Approach 2

int getLCA2(BinaryTreeNode<int>* root , int val1 , int val2){
    if(!root) return -1;
    
    if(root->data == val1 || root->data == val2) return root->data;
    
    if(root->data > val1 && root->data > val2) {
        return getLCA(root->left, val1, val2);
    } else if (root->data < val1 && root->data < val2) {
        return getLCA(root->right, val1, val2);
    }
    
    int LCAFromLeft = getLCA(root->left, val1, val2);
    int LCAFromRight = getLCA(root->right, val1, val2);
    
    if(LCAFromLeft == -1 && LCAFromRight == -1) return -1; // Elements are not there in tree
    else if (LCAFromLeft == -1) return LCAFromRight; // When right has both elements
    else if (LCAFromRight == -1) return LCAFromLeft;  // When left has both elements
    
    return root->data;  // When right has one and left has other
}