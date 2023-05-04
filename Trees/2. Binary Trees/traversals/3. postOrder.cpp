#include <iostream>
#include "BinaryTreeNode.h"
using namespace std;

void postOrder(BinaryTreeNode<int> *root) {
	
    if(!root) return;
    
    postOrder(root->left);
    postOrder(root->right);
    cout<<root->data<<" ";
}