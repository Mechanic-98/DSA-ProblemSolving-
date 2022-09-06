#include <iostream>
#include "BinaryTreeNode.h"
using namespace std;

BinaryTreeNode<int>* constructTreeHelper(int *input, int s, int e) {
    if(s > e) return NULL;
    
    int mid = s + (e-s)/2;
    BinaryTreeNode<int>* root = new BinaryTreeNode<int>(input[mid]);
    
    root->left = constructTreeHelper(input, s, mid-1);
    root->right = constructTreeHelper(input, mid+1, e);
    
    return root;
}

BinaryTreeNode<int>* constructTree(int *input, int n) {
	// Write your code here
    if(n == 0) return NULL;
    return constructTreeHelper(input, 0, n-1);
}