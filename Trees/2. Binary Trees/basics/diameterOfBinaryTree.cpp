#include <iostream>
#include <utility>
#include <algorithm>
#include "BinaryTreeNode.h"
using namespace std;

// dia = max distance between two nodes

int height(BinaryTreeNode<int> root) {
    if(!root) return 0;

    return 1 + max(height(root->left), height(root->right));
}


// problem: we are calculating height twice that's why the TC: O(N * height)
// height = logN;
int dia(BinaryTreeNode<int>* root){
    if(!root) return 0;

    int op1 = height(root->left) + height(root->right);
    int op2 = dia(root->left);
    int op2 = dia(root->right);

    return max(op1, max(op2,op3));
}

// We are making calls agains and again for height, 
// that's why time complexity depends on height as well

pair<int,int> dia2(BinaryTreeNode<int>* root) {
    if(!root) return {0,0}; // {height, dia}

    pair<int,int> leftAns = dia2(root->left);
    pair<int,int> rightAns = dia2(root->right);

    int lh = leftAns.first;
    int ld = leftAns.second;
    int rh = rightAns.first;
    int rd = rightAns.second;

    pair<int,int> ans;
    ans.first = 1 + max(lh, rh);
    ans.second = max(lh + rh, max(rd, ld));

    return ans;
}