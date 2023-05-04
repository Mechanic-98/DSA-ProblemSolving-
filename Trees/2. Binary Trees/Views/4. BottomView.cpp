#include <BinaryTreeNode.h>
#include <vector>
#include <map>
#include <queue>
#include <utility>
using namespace std;

vector<int> bottomView(BinaryTreeNode<int> *root)
{
    vector<int> bottomViewOrder;
    if (!root)
        return bottomViewOrder;

    map<int, int> verticalLevelToNodeDataMapping;         // verticalLevel -> node's data
    queue<pair<int, BinaryTreeNode<int> *>> pendingNodes; // {vertical level , node}
    pendingNodes.push({0, root});

    while (!pendingNodes.empty())
    {
        auto frontNodePair = pendingNodes.front();
        pendingNodes.pop();

        int verticalLevel = frontNodePair.first;
        BinaryTreeNode<int> *frontNode = frontNodePair.second;

        verticalLevelToNodeDataMapping[verticalLevel] = frontNode->data;

        if (frontNode->left)
            pendingNodes.push({verticalLevel - 1, frontNode->left});
        if (frontNode->right)
            pendingNodes.push({verticalLevel + 1, frontNode->right});
    }

    for (auto it : verticalLevelToNodeDataMapping)
    {
        bottomViewOrder.push_back(it.second);
    }

    return bottomViewOrder;
}