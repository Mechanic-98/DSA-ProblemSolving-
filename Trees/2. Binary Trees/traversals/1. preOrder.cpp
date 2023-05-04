#include <iostream>
#include <vector>
#include <stack>
#include "BinaryTreeNode.h"
using namespace std;

void preOrder(BinaryTreeNode<int> *root)
{

    if (!root)
        return;

    cout << root->data << " ";
    preOrder(root->left);
    preOrder(root->right);
}

vector<int> preOrderIterative(BinaryTreeNode<int> *root)
{
    vector<int> preOrderTraversal;
    if (!root)
        return preOrderTraversal;

    stack<BinaryTreeNode<int> *> pendingNodes;
    pendingNodes.push(root);

    while (!pendingNodes.empty())
    {
        BinaryTreeNode<int> *tempNode = pendingNodes.top();
        pendingNodes.pop();
        preOrderTraversal.push_back(tempNode->data);

        if (tempNode->right)
            pendingNodes.push(tempNode->right);
        if (tempNode->left)
            pendingNodes.push(tempNode->left);
    }

    return preOrderTraversal;
}