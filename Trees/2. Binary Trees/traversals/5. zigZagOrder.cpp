#include <iostream>
#include <vector>
#include <queue>
#include "BinaryTreeNode.h"
using namespace std;

vector<vector<int>> zigzagLevelOrder(BinaryTreeNode *root)
{
    vector<vector<int>> zigzagTraversal;
    if (!root)
        return zigzagTraversal;

    bool leftToRight = true;
    queue<BinaryTreeNode *> pendingNodes;
    pendingNodes.push(root);

    while (!pendingNodes.empty())
    {
        int numberOfNodes = pendingNodes.size();
        vector<int> dataPerLevel(numberOfNodes);

        for (int i = 0; i < numberOfNodes; i++)
        {
            BinaryTreeNode *currentNode = pendingNodes.front();
            pendingNodes.pop();
            int index = leftToRight ? i : numberOfNodes - 1 - i;
            dataPerLevel[index] = currentNode->val;

            if (currentNode->left)
                pendingNodes.push(currentNode->left);
            if (currentNode->right)
                pendingNodes.push(currentNode->right);
        }

        leftToRight = !leftToRight;
        zigzagTraversal.push_back(dataPerLevel);
    }

    return zigzagTraversal;
}