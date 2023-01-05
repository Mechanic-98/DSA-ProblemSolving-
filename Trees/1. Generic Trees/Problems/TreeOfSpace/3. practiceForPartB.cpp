/*
to optimise->
    maintain lockedDescendantCount -> to check if descendants are locked
    maintain isLockable -> to check if ancestors are locked
*/

#include <vector>
#include <string>
#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <queue>
#define ll long long

using namespace std;

class TreeNode
{
public:
    bool isLocked;
    // bool isLockable;
    int idThatLockedNode;
    int lockedDescendantCount;
    TreeNode *parentNode;
    unordered_set<TreeNode *> lockedDescendents;
    vector<TreeNode *> childrenNodes;

    TreeNode()
    {
        isLocked = false;
        // isLockable = true;
        idThatLockedNode = -1;
        lockedDescendantCount = 0;
        parentNode = NULL;
    }

    TreeNode(TreeNode *parent)
    {
        isLocked = false;
        // isLockable = true;
        idThatLockedNode = -1;
        lockedDescendantCount = 0;
        parentNode = parent;
    }
};

bool locking(TreeNode *nodeToBeLocked, int uuid)
{
    // checking descendents by lockedDescendentCount
    if (nodeToBeLocked->isLocked ||
        nodeToBeLocked->lockedDescendantCount != 0)
        return false;
    TreeNode *currentNode = nodeToBeLocked;

    // checking ancestors O(H)
    while (currentNode->parentNode != NULL)
    {
        if (currentNode->parentNode->isLocked)
            return false;
        currentNode = currentNode->parentNode;
    }

    // locking node O(1)
    nodeToBeLocked->idThatLockedNode = uuid;
    nodeToBeLocked->isLocked = true;
    currentNode = nodeToBeLocked;

    // informing ancestors O(H)
    while (currentNode->parentNode != NULL)
    {
        currentNode->parentNode->lockedDescendantCount++;
        currentNode->parentNode->lockedDescendents.insert(nodeToBeLocked);
        currentNode = currentNode->parentNode;
    }

    return true;
}

bool unlocking(TreeNode *nodeToBeUnlocked, int uuid)
{
    // checking if node can be unlocked
    if (!nodeToBeUnlocked->isLocked || (nodeToBeUnlocked->isLocked && uuid != nodeToBeUnlocked->idThatLockedNode))
        return false;

    // Unlocking node O(1)
    nodeToBeUnlocked->isLocked = false;
    nodeToBeUnlocked->idThatLockedNode = -1;

    // informing ancestors O(H)
    TreeNode *currentNode = nodeToBeUnlocked;
    while (currentNode->parentNode != NULL)
    {
        currentNode->parentNode->lockedDescendantCount--;
        currentNode->parentNode->lockedDescendents.erase(nodeToBeUnlocked);
        currentNode = currentNode->parentNode;
    }

    return true;
}

// O(N * (logN base m))
bool upgrade(TreeNode *nodeToBeUpgraded, int uuid)
{
    // checking node
    if (nodeToBeUpgraded->isLocked)
        return false;
    TreeNode *currentNode = nodeToBeUpgraded;

    // checking ancestors O(H)
    while (currentNode->parentNode != NULL)
    {
        if (currentNode->parentNode->isLocked)
            return false;
        currentNode = currentNode->parentNode;
    }

    // checking descendents O(N)

    // currentNode = nodeToBeUpgraded;
    // queue<TreeNode *> pendingNodes;
    // pendingNodes.push(currentNode);
    // bool isUpgradePossible = false;

    // while (!pendingNodes.empty())
    // {
    //     TreeNode *frontNode = pendingNodes.front();
    //     pendingNodes.pop();

    //     for (TreeNode *childNode : frontNode->childrenNodes)
    //     {
    //         if (childNode->isLocked && childNode->idThatLockedNode != uuid)
    //             return false;
    //         if (childNode->isLocked)
    //             // possibilty: store it in a vector
    //             isUpgradePossible = true;
    //         pendingNodes.push(childNode);
    //     }
    // }

    if (nodeToBeUpgraded->lockedDescendents.empty() == false)
        return false;

    for (TreeNode *lockedChild : nodeToBeUpgraded->lockedDescendents)
    {
        if (lockedChild->idThatLockedNode != uuid)
            return false;
    }

    // unlocking all descendents O(N X H) => O(N * logN)

    // currentNode = nodeToBeUpgraded;
    // pendingNodes.push(currentNode);
    // while (!pendingNodes.empty())
    // {
    //     TreeNode *frontNode = pendingNodes.front();
    //     pendingNodes.pop();

    //     for (TreeNode *childNode : frontNode->childrenNodes)
    //     {
    //         if (childNode->isLocked)
    //         {
    //             if (!unlocking(childNode, uuid)) // O(H)
    //                 return false;
    //         }
    //         pendingNodes.push(childNode);
    //     }
    // }

    for (TreeNode *lockedDescendents : nodeToBeUpgraded->lockedDescendents)
    {
        if (!unlocking(lockedDescendents, uuid))
            return false;
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
3. checking descendents O(N) -> O(K)
4. unlocking all descendents O(K X H) => O(K * logN(base m)) where; k is number of locked descendents
*/