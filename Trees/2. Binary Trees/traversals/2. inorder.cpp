#include <iostream>
#include "BinaryTreeNode.h"
using namespace std;

void inorder(BinaryTreeNode<int>* root) {
    if(!root) return;

    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right); 
}