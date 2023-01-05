#include <iostream>
#include "BinaryTreeNode.h"
using namespace std;

int height(BinaryTreeNode<int>* root) {
    if(!root) return 0;
    
    return 1 + max( height(root->left), height(root->right) );
}