#include <iostream>
#include <vector>
#include "BinaryTreeNode.h"
using namespace std;

vector<int>* getPath2(BinaryTreeNode<int> *root , int data, vector<int> * path) {
	if(!root) return NULL;

    path->push_back(root->data);

    if(root->data == data) {
        return path;
    }
    vector<int> * leftPath = getPath2(root->left, data, path);
    vector<int> * rightPath = getPath2(root->right, data, path);

    if(leftPath) return leftPath;
    if(rightPath) return rightPath;

    path->pop_back();
    return NULL;
}

// Approach 1  TC: O(2N) SC: O(H)
int getLCA(BinaryTreeNode <int>* root , int a, int b) {
    
    if(!root) return -1;
    vector<int> * pathForA = new vector<int>();
    vector<int> * pathForB = new vector<int>();
    
    pathForA = getPath2(root, a, pathForA);  // O(N)
    pathForB = getPath2(root, b, pathForB);  // O(N)
    
    if(!pathForA && !pathForB) {
        return -1;
    } else if (!pathForA) {
        int idx = pathForB->size() - 1;
        return pathForB->at(idx);
    } else if (!pathForB) {
        int idx = pathForA->size() - 1;
        return pathForA->at(idx);
    } else {
        int i;
        for(i=0; i< pathForA->size() && pathForB->size(); i++) {
            if(i == pathForB->size()) break;
            if(i == pathForA->size()) break;
            if(pathForA->at(i) != pathForB->at(i)) break;
        }
		

        return pathForA->at(i-1);
    }
    
}

// Approach 2

int getLCA2(BinaryTreeNode <int>* root , int a, int b) {
    
    if(!root) return -1;
    
    if(root->data == a || root->data == b) return root->data;
    
    int LCAFromLeft = getLCA2(root->left, a,b);
    int LCAFromRight = getLCA2(root->right,a,b);
    
    if(LCAFromLeft == -1 && LCAFromRight == -1) return -1; // Elements are not there in tree
    else if (LCAFromLeft == -1) return LCAFromRight; // When right has both elements
    else if (LCAFromRight == -1) return LCAFromLeft;  // When left has both elements
    
    return root->data;  // When right has one and left has other
}