#include <iostream>
#include "TreeNode.h"
using namespace std;

TreeNode<int> *maxSumNode(TreeNode<int> *root)
{
    // Write your code here
    if (!root)
        return NULL;

    TreeNode<int> *maxNode;
    int maxSum;
    int sum = 0;
    sum += root->data;
    for (auto child : root->children)
    {
        sum += child->data;
    }

    maxSum = sum;
    maxNode = root;

    for (auto child : root->children)
    {
        TreeNode<int> *tempNode = maxSumNode(child);
        int tempSum = tempNode->data;
        for (auto tempChild : tempNode->children)
        {
            tempSum += tempChild->data;
        }

        if (tempSum > maxSum)
        {
            maxSum = tempSum;
            maxNode = tempNode;
        }
    }

    return maxNode;
}