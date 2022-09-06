#include <iostream>
#include "BinaryTreeNode.h"
using namespace std;

void mirrorBinaryTree(BinaryTreeNode<int>* root) {
    
    if(!root) return;
    
    mirrorBinaryTree(root->left);
    mirrorBinaryTree(root->right);
    
    if(root->left || root->right) {
        BinaryTreeNode<int>* temp = root->left;
        root->left = root->right;
        root->right = temp;
    }
        
}