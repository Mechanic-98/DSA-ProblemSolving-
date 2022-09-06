#include <iostream>
#include <vector>
#include "BinaryTreeNode.h"
using namespace std;


vector<int>* longestPath(BinaryTreeNode<int>* root) {
    
    if(root == NULL) {
        vector<int> * ans = new vector<int>();
        return ans;
    }
    
    vector<int> * leftPath = longestPath(root->left);
    vector<int> * rightPath = longestPath(root->right);
    
    if(leftPath->size() > rightPath->size()) {
        leftPath->push_back(root->data);
        return leftPath;
    }

    rightPath->push_back(root->data);
    return rightPath;
    

}