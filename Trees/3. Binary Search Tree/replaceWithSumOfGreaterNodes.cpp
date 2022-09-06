#include <iostream>
#include "BinaryTreeNode.h"
using namespace std;

int replaceWithLargerNodesSumHelper(BinaryTreeNode<int> * root, int sum) {
    if(!root) return sum;
    
    int rightSum = replaceWithLargerNodesSumHelper(root->right, sum);
    sum = root->data + rightSum;
    root->data = sum;
    int leftSum = replaceWithLargerNodesSumHelper(root->left, sum);
    sum = leftSum;
    
    return sum;
}

void replaceWithLargerNodesSum(BinaryTreeNode<int> *root) {
    if(!root) return;
    
    replaceWithLargerNodesSumHelper(root, 0);
}