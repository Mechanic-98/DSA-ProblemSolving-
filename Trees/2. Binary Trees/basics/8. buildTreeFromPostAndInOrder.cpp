#include <iostream>
#include "BinaryTreeNode.h"
using namespace std;

/*
post = [left, right, root]
in = [left, root, right]
*/

int search(int *inorder, int inS, int inE, int data) {
    
    for(int i= inS; i<=inE; i++) {
        if(inorder[i] == data) return i;
    }

    return -1;
}

BinaryTreeNode<int>* buildTreeUtility(int *postorder, int *inorder, int postS, int postE, int inS, int inE) {
    if(postS > postE || inS > inE) return NULL;

    int rootData = postorder[postE];
    int rootIndex = search(inorder, inS, inE, rootData);

    int lInS = inS;
    int lInE = rootIndex - 1;
    int numberOfNodesInLeftSubTree = lInE - lInS;
    int lPostS = postS;
    int lPostE = numberOfNodesInLeftSubTree + lPostS;

    int rInS = rootIndex + 1;
    int rInE = inE;
    int numberOfNodesInRightSubTree = rInE - rInS;
    int rPostS = lPostE + 1;
    int rPostE = numberOfNodesInRightSubTree + rPostS;

    BinaryTreeNode<int>* root = new BinaryTreeNode<int>(rootData);
    root->left = buildTreeUtility(postorder, inorder, lPostS, lPostE, lInS, lInE);
    root->right = buildTreeUtility(postorder, inorder, rPostS, rPostE, rInS, rInE);
}

BinaryTreeNode<int>* buildTree(int *postorder, int postLength, int *inorder, int inLength) {
    return buildTreeUtility(postorder, inorder, 0, postLength - 1, 0, inLength - 1);
}