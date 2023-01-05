#include <iostream>
#include "BinaryTreeNode.h"
using namespace std;

int countNodes(BinaryTreeNode<int>* root){
    if(!root) return 0;

    return 1 + countNodes(root->left) + countNodes(root->right);
}