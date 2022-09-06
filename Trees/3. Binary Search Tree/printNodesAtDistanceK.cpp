#include <iostream>
#include "BinaryTreeNode.h"
using namespace std;

void printNodesAtDepthK(BinaryTreeNode<int> * root, int k) {
    if(!root) return;
    
    if(k == 0) {
        cout<<root->data<<'\n';
        return;
    }
    
    printNodesAtDepthK(root->left, k-1);
    printNodesAtDepthK(root->right, k-1);
}


// Distance between root and node
int helper(BinaryTreeNode<int> * root, int node, int k) {
    if(!root) return -1;
    
    if(root->data == node) {
        printNodesAtDepthK(root, k);
        return 0;
    }
    
    // Distance between root of left Subtree to node
    int leftDistance = helper(root->left, node, k);
    if(leftDistance != -1) {
        if(leftDistance + 1 == k) cout<<root->data<<'\n';
        else printNodesAtDepthK(root->right, k - (leftDistance + 1) -1);
        
        return leftDistance + 1;
    }
    
    // Distance between root of right Subtree to node
    int rightDistance = helper(root->right, node, k);
    if(rightDistance != -1) {
        if(rightDistance + 1 == k)cout<<root->data<<'\n';
        else printNodesAtDepthK(root->left, k - (rightDistance + 1) -1);
        
        return rightDistance +1;
    }
    
    return -1;
}

void nodesAtDistanceK(BinaryTreeNode<int> *root, int node, int k) {
    // Write your code here
    if(!root) return;
    
    // Its not necesarry to catch the returned data
    helper(root, node, k);
    
    
}