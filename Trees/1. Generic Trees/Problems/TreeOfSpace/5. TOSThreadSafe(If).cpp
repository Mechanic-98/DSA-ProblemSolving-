/*
to optimise->
    maintain lockedDescendantCount -> to check if descendants are locked
    maintain isLockable -> to check if ancestors are locked
*/

#include <vector>
#include <string>
#include <iostream>
#include <unordered_map>
#include <queue>
#define ll long long

using namespace std;

class TreeNode
{
public:
    bool isLocked;
    bool isResourceInUse;
    int idThatLockedNode;
    int lockedDescendantCount;
    TreeNode *parentNode;
    vector<TreeNode *> childrenNodes;

    TreeNode()
    {
        isLocked = false;
        isResourceInUse = false;
        idThatLockedNode = -1;
        lockedDescendantCount = 0;
        parentNode = NULL;
    }

    TreeNode(TreeNode *parent)
    {
        isLocked = false;
        isResourceInUse = false;
        idThatLockedNode = -1;
        lockedDescendantCount = 0;
        parentNode = parent;
    }
};

bool locking(TreeNode *nodeToBeLocked, int uuid)
{
    // check if any other thread is working on this node
    while (nodeToBeLocked->isResourceInUse)
        ;
    nodeToBeLocked->isResourceInUse = true; // marking the node as engaged

    // checking descendents by lockedDescendentCount
    if (nodeToBeLocked->isLocked ||
        nodeToBeLocked->lockedDescendantCount != 0)
    {
        nodeToBeLocked->isResourceInUse = false;
        return false;
    }

    // checking ancestors O(H)
    TreeNode *currentNode = nodeToBeLocked;
    vector<TreeNode *> nodesInUse;
    nodesInUse.push_back(currentNode);
    while (currentNode->parentNode != NULL)
    {
        while (currentNode->parentNode->isResourceInUse)
            ;
        currentNode->parentNode->isResourceInUse = true;
        nodesInUse.push_back(currentNode->parentNode);
        if (currentNode->parentNode->isLocked)
        {
            for (int i = 0; i < nodesInUse.size(); i++)
            {
                nodesInUse[i]->isResourceInUse = false;
            }
            return false;
        }
        currentNode = currentNode->parentNode;
    }

    // locking node O(1)
    nodeToBeLocked->idThatLockedNode = uuid;
    nodeToBeLocked->isLocked = true;
    currentNode = nodeToBeLocked;

    // informing ancestors O(H)
    while (currentNode->parentNode != NULL)
    {
        currentNode->parentNode->isResourceInUse = false;
        currentNode->parentNode->lockedDescendantCount++;
        currentNode = currentNode->parentNode;
    }

    currentNode->isResourceInUse = false;
    return true;
}

bool unlocking(TreeNode *nodeToBeUnlocked, int uuid)
{
    while (nodeToBeUnlocked->isResourceInUse)
        ;
    nodeToBeUnlocked->isResourceInUse = true;
    // checking if node can be unlocked
    if (!nodeToBeUnlocked->isLocked || (nodeToBeUnlocked->isLocked && uuid != nodeToBeUnlocked->idThatLockedNode))
    {
        nodeToBeUnlocked->isResourceInUse = false;
        return false;
    }

    // Unlocking node O(1)
    nodeToBeUnlocked->isLocked = false;
    nodeToBeUnlocked->idThatLockedNode = -1;

    // informing ancestors O(H)
    TreeNode *currentNode = nodeToBeUnlocked;
    while (currentNode->parentNode != NULL)
    {
        while (currentNode->parentNode->isResourceInUse)
            ;
        currentNode->parentNode->lockedDescendantCount--;
        currentNode = currentNode->parentNode;
    }

    nodeToBeUnlocked->isResourceInUse = false;
    return true;
}

// O(N * (logN base m))
bool upgrade(TreeNode *nodeToBeUpgraded, int uuid)
{
    while (nodeToBeUpgraded->isResourceInUse)
        ;
    nodeToBeUpgraded->isResourceInUse = true;
    // checking node
    if (nodeToBeUpgraded->isLocked)
    {
        nodeToBeUpgraded->isResourceInUse = false;
        return false;
    }

    // checking ancestors O(H)
    TreeNode *currentNode = nodeToBeUpgraded;
    vector<TreeNode *> nodesInUse;
    nodesInUse.push_back(currentNode);
    while (currentNode->parentNode != NULL)
    {
        while (currentNode->parentNode->isResourceInUse)
            ;
        currentNode->parentNode->isResourceInUse = true;
        nodesInUse.push_back(currentNode->parentNode);
        if (currentNode->parentNode->isLocked)
        {
            for (int i = 0; i < nodesInUse.size(); i++)
            {
                nodesInUse[i]->isResourceInUse = false;
            }
            return false;
        }
        currentNode = currentNode->parentNode;
    }

    // checking descendents O(N)
    currentNode = nodeToBeUpgraded;
    queue<TreeNode *> pendingNodes;
    pendingNodes.push(currentNode);
    bool isUpgradePossible = false;

    while (!pendingNodes.empty())
    {
        TreeNode *frontNode = pendingNodes.front();
        pendingNodes.pop();

        for (TreeNode *childNode : frontNode->childrenNodes)
        {
            while (childNode->isResourceInUse)
                ;
            childNode->isResourceInUse = true;
            nodesInUse.push_back(childNode);
            if (childNode->isLocked && childNode->idThatLockedNode != uuid)
            {
                for (int i = 0; i < nodesInUse.size(); i++)
                {
                    nodesInUse[i]->isResourceInUse = false;
                }
                return false;
            }
            if (childNode->isLocked)
                isUpgradePossible = true;
            pendingNodes.push(childNode);
        }
    }

    if (!isUpgradePossible)
    {
        for (int i = 0; i < nodesInUse.size(); i++)
        {
            nodesInUse[i]->isResourceInUse = false;
        }
        return false;
    }

    // unlocking all descendents O(N X H) => O(N * logN)
    pendingNodes.push(currentNode);
    while (!pendingNodes.empty())
    {
        TreeNode *frontNode = pendingNodes.front();
        pendingNodes.pop();

        for (TreeNode *childNode : frontNode->childrenNodes)
        {
            while (childNode->isResourceInUse)
                ;
            if (childNode->isLocked)
            {
                for (int i = 0; i < nodesInUse.size(); i++)
                {
                    nodesInUse[i]->isResourceInUse = false;
                }
                if (!unlocking(childNode, uuid)) // O(H)
                    return false;
            }
            childNode->isResourceInUse = false;
            pendingNodes.push(childNode);
        }
    }

    return locking(nodeToBeUpgraded, uuid); // O(H)
}

int main()
{
    int numberOfNodes, numberOfChildrenPerNode, numberOfQueries;
    cin >> numberOfNodes >> numberOfChildrenPerNode >> numberOfQueries;

    unordered_map<string, TreeNode *> nodeNameToTreeNodeMap;

    TreeNode *newTreeNode = new TreeNode();
    string nodeName;
    cin >> nodeName;

    nodeNameToTreeNodeMap[nodeName] = newTreeNode;

    queue<TreeNode *> pendingNodes;
    pendingNodes.push(newTreeNode);
    int currentCountOfNodes = 1;

    while (!pendingNodes.empty())
    {
        TreeNode *frontNode = pendingNodes.front();
        pendingNodes.pop();

        while (currentCountOfNodes < numberOfNodes &&
               frontNode->childrenNodes.size() < numberOfChildrenPerNode)
        {
            string nodeNameOfChildNode;
            cin >> nodeNameOfChildNode;

            TreeNode *childNode = new TreeNode(frontNode);
            nodeNameToTreeNodeMap[nodeNameOfChildNode] = childNode;
            frontNode->childrenNodes.push_back(childNode);
            pendingNodes.push(childNode);
            currentCountOfNodes++;
        }
    }

    for (int i = 0; i < numberOfQueries; i++)
    {
        int queryNumber, uuid;
        string name;
        bool answer;

        cin >> queryNumber >> name >> uuid;

        TreeNode *nodeToBeProcessed = nodeNameToTreeNodeMap[name];

        switch (queryNumber)
        {
        case 1:
            answer = locking(nodeToBeProcessed, uuid);
            break;
        case 2:
            answer = unlocking(nodeToBeProcessed, uuid);
            break;
        default:
            answer = upgrade(nodeToBeProcessed, uuid);
            break;
        }

        if (answer)
            cout << "true" << endl;
        else
            cout << "false" << endl;
    }

    return 0;
}

/*
Upgrade:
1. Is node locked or not? O(1)
2. checking ancestors O(H)
3. checking descendents O(N)
4. unlocking all descendents O(K X H) => O(K * logN(base m)) where; k is number of locked descendents
*/