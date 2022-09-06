#include <iostream>
#include "TreeNode.h"
using namespace std;

void preOrderTraversal(TreeNode<int>* root){  // root first
    if(!root) return;

    cout<<root->data<<" ";
    int numberOfChildren = root->children.size();
    for(int i=0; i<numberOfChildren; i++){
        preOrderTraversal(root->children[i]);
    }
}

