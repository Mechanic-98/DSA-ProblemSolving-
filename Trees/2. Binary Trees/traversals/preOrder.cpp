#include <iostream>
#include "BinaryTreeNode.h"
using namespace std;

void preOrder(BinaryTreeNode<int> *root) {
	
    if(!root) return;
    
    cout<<root->data<<" ";
    preOrder(root->left);
    preOrder(root->right);
}