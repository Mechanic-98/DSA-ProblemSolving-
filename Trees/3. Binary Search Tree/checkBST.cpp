#include <iostream>
#include <climits>
#include "BinaryTreeNode.h"
using namespace std;

int maximum(BinaryTreeNode<int> * root) {
    if(!root) return INT_MIN;

    return max(root->data, max(maximum(root->left), maximum(root->right)));
}

int minimum(BinaryTreeNode<int> * root) {
    if(!root) return INT_MAX;

    return min(root->data, min(minimum(root->left), minimum(root->right)));
}


// TC(N) = TC(N/2) + k(N) = O(NlogN) = O(N * Height)
// since Height = logN;  Worst case -> O(N^2)
bool isBST(BinaryTreeNode<int> * root) {
    if(!root) return true;

    int leftMax = maximum(root->left);
    int rightMin = minimum(root->right);

    return (root->data > leftMax && root->data <= rightMin && isBST(root->left) && isBST(root->right));
}

// To improve this we can bring (max,min,isBST) in a single call.
// This will remove the redundant work of first calling max or min and then isBST again

// First way is to create a custom class
// This is a bottom up approach. TC = O(N)

class IsBSTReturn {
    public:
    int maximum; 
    int minimum;
    bool isBST;
}

IsBSTReturn isBST2Helper(BinaryTreeNode<int> * root){
    IsBSTReturn output;
    if(!root) {
        output.maximum = INT_MIN;
        output.minimum = INT_MAX;
        output.isBST = true;
        return output;
    }
    IsBSTReturn leftOuput = isBST2Helper(root->left);
    IsBSTReturn rightOutput = isBST2Helper(root->right);

    output.minimum = min(root->data, min(leftOutput.minimum,rightOutput.minimum));
    output.maximum = max(root->data, max(leftOutput.maximum,rightOutput.maximum));
    output.isBST = (root->data > leftOutput.maximum) && (root->data <= rightOutput.minimum)
            && leftOutput.isBST && rightOutput.isBST;
    
    return output;
}

bool isBST2(BinaryTreeNode<int> * root) {
    IsBSTReturn ans = isBST2Helper(root);
    return ans.isBST;
}


// second approach is a Top down approach (Best)

bool isBST3Helper(BinaryTreeNode<int> * root, BinaryTreeNode<int> * min, BinaryTreeNode<int> * max) {
    if(!root) return true;
    if(min && root->data <= min->data) return false;
    if(max && root->data >= max->data) return false;
    
    return isBST3Helper(root->left, min, root) && isBST3Helper(root->right, root, max);
}

bool isBST3(BinaryTreeNode<int> *root) {
	
    return isBST3Helper(root, NULL, NULL);
}