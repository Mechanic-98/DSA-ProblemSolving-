#include <vector>
#include <queue>
#include <BinaryTreeNode.h>
using namespace std;

vector<int> leftView(BinaryTreeNode<int> *root)
{
    vector<int> leftViewOrder;
    if (!root)
        return leftViewOrder;

    queue<BinaryTreeNode<int> *> pendingNodes;
    pendingNodes.push(root);

    while (!pendingNodes.empty())
    {
        int numberOfNodesPerLevel = pendingNodes.size();

        for (int i = 0; i < numberOfNodesPerLevel; i++)
        {
            BinaryTreeNode<int> *frontNode = pendingNodes.front();
            pendingNodes.pop();

            if (i == 0)
                leftViewOrder.push_back(frontNode->data);
            if (frontNode->left)
                pendingNodes.push(frontNode->left);
            if (frontNode->right)
                pendingNodes.push(frontNode->right);
        }
    }

    return leftViewOrder;
}