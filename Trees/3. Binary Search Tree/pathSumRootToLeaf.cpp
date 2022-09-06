#include <iostream>
#include <string>
#include "BinaryTreeNode.h"
using namespace std;

void helper(BinaryTreeNode<int> * root, int k, string s){
    if(!root) return;
    
    s += to_string(root->data) + " ";
    
    if(root->data == k && root->left == NULL && root->right == NULL) {
        cout<<s<<'\n';
        return;
    }
    
    helper(root->left, k - root->data, s);
    helper(root->right, k - root->data, s);
}

void rootToLeafPathsSumToK(BinaryTreeNode<int> *root, int k) {
    // Write your code here
    if(!root) return;
    
    helper(root, k, "");
}