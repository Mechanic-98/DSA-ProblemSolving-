#include <iostream>
#include <queue>
#include "BinaryTreeNode.h"
using namespace std;

int height(BinaryTreeNode<int> *root)
{
    if (!root)
        return 0;

    return 1 + max(height(root->left), height(root->right));
}

int heightIterative(BinaryTreeNode<int> *root)
{
    if (!root)
        return 0;

    queue<BinaryTreeNode<int> *> pendingNodes;
    pendingNodes.push(root);
    int depth = 0;

    while (!pendingNodes.empty())
    {
        int numberOfNodesPerLevel = pendingNodes.size();

        for (int i = 0; i < numberOfNodesPerLevel; i++)
        {
            BinaryTreeNode<int> *tempNode = pendingNodes.front();
            pendingNodes.pop();

            if (tempNode->left)
                pendingNodes.push(tempNode->left);
            if (tempNode->right)
                pendingNodes.push(tempNode->right);
        }
        depth++;
    }

    return depth;
}