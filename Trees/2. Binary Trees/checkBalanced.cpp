#include <iostream>
#include <utility>
#include <algorithm>
#include "BinaryTreeNode.h"
using namespace std;

int height(BinaryTreeNode<int>* root){
    if(!root) return 0;
    
    return 1 + max(height(root->left), height(root->right));
}

// O(N * height)
bool isBalanced(BinaryTreeNode<int> *root) {
	// Write your code here
    if(!root) return true;
    
    int lh = height(root->left);
    int rh = height(root->right);
    
    return isBalanced(root->left) && isBalanced(root->right) && (abs(rh - lh) <= 1);
}


// O(N) Optimised
pair<bool,int> helper(BinaryTreeNode<int> *root) {
    if(!root) return {true,0};
    
    pair<bool,int> leftAns = helper(root->left);
    pair<bool,int> rightAns = helper(root->right);
    
    pair<bool, int> ans;
    ans.first = leftAns.first && rightAns.first && (abs(leftAns.second - rightAns.second) <= 1) ;
    ans.second = 1 + max(leftAns.second, rightAns.second);
    
    return ans;
}

bool isBalanced2(BinaryTreeNode<int> *root) {
	// Write your code here
    if(!root) return true;
    
    pair<bool,int> ans = helper(root);
    
    return ans.first;
}