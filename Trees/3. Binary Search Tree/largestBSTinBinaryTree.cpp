#include <iostream>
#include <climits>
#include "BinaryTreeNode.h"
using namespace std;


class LargestBSTSubtreeReturnType {
    public:
    int maximum; 
    int minimum;
    int heightOfLargestBST;
    bool isBST;
};


// Utilized bottom yp approach of check BST
LargestBSTSubtreeReturnType largestBSTSubtreeHelper (BinaryTreeNode<int> * root) {
    LargestBSTSubtreeReturnType output;
    if(!root) {
        output.maximum = INT_MIN;
        output.minimum = INT_MAX;
        output.isBST = true;
        output.heightOfLargestBST = 0;
        return output;
    }
    
    LargestBSTSubtreeReturnType leftOutput = largestBSTSubtreeHelper(root->left);
    LargestBSTSubtreeReturnType rightOutput = largestBSTSubtreeHelper(root->right);
    
    output.minimum = min(root->data, min(leftOutput.minimum,rightOutput.minimum));
    output.maximum = max(root->data, max(leftOutput.maximum,rightOutput.maximum));
    output.isBST = leftOutput.isBST && rightOutput.isBST && (leftOutput.maximum < root->data) && (rightOutput.minimum > root->data);
    output.heightOfLargestBST = (output.isBST) ? max(leftOutput.heightOfLargestBST, rightOutput.heightOfLargestBST) + 1 : 
    											max(leftOutput.heightOfLargestBST, rightOutput.heightOfLargestBST);
    
    
    return output;
}

int largestBSTSubtree(BinaryTreeNode<int> *root) {
    LargestBSTSubtreeReturnType ans = largestBSTSubtreeHelper(root);
    return ans.heightOfLargestBST;
}