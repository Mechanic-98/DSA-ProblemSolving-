#include <iostream>
#include "TreeNode.h"
using namespace std;

void postOrderTraversal(TreeNode<int> * root){
    if(!root) return;
    int numberOfChildren = root->children.size();
    for(int i=0; i<numberOfChildren; i++){
        postOrderTraversal(root->children[i]);
    }
    cout<<root->data<<" ";
}