/*
Locking the tree of space
You have a world map represented as an M-Ary tree (sample tree below)

You need to define three operations on it
    lock(X, uid)
    unlock(X, uid)
    upgradeLock(x, uid)
where X the name of a node in the tree (that would be unique) and uid is the user who is
performing the operation
Here are the definitions for the Operations:

1. Lock(X, uid)
    Lock takes an exclusive access on the subtree rooted at X. It is formally defined like this:
    Once lock(X, uid) succeeds, then:
        lock(A, anyUserId) should fail (returns false), where A is a descendent of X,
        lock(B, anyUserId) should fail (returns false), where X is a descendent of B
        Lock operation cannot be performed on a node which is already locked i.e.
            lock(X, anyUserId) should fail (returns false).

2. Unlock(X, uid)
    Unlock reverts what was done by the Lock operation. It can only be called on same node on
    which user uid had called a Lock on before. Returns true if it is successful.

3. UpgradeLock(X, uid)
    It helps the user uid upgrade their lock to an ancestor node. It is only possible if the
    node X already has locked descendants and all of them are only locked by the same user
    uid. Upgrade should fail if there is any node which is descendant of X that is locked by
    a different user. Successful Upgrade will 'Lock' the node. UpgradeLock call shouldn't
    violate the consistency model that Lock/Unlock function requires.


Notes:

1) The number of nodes in the tree N is very large. So, optimize the time complexity for
the above algorithms.

2) The below section contains the input format.
    The first line contains the number of Nodes in the tree (N).
    The second line contains number of children per node (value m in m-ary Tree).
    The third line contains number of queries (Q).
    Next N lines contains the NodeName (string) in the m-Ary Tree.
    Next Q lines contains queries which are in format: OperationType NodeName UserId
    OperationType →<br>
    1 for Lock<br>
    2 for unlock<br>
    3 for upgradeLock
    NodeName → Name of any node (unique) in m-Ary Tree.
    UserId → Integer value representing a unique user.


Example input:
7
2
3
World
Asia
Africa
China
India
SouthAfrica
Egypt
1 China 9
2 India 9
3 Asia 9

With the above input you represents a 2-ary tree with 7 nodes as follows:
                      World
                  /             \
              Asia               Africa
            /      \          /         \
        China     India    SouthAfrica    Egypt


Additional Notes:
1) Here ‘1 China 3’ indicates the following ‘OperationType NodeName UserId’
2) The tree is always fully balanced
3) Constraints on the inputs are as follows<br>
        1 <= N <= 5 * 10^5
        1 <= m <= 30
        1 <= Q <= 5 * 10^5
        1 <= length of NodeName <= 20
4) Optimize the time complexity
    Lock  - O(log<sub>m</sub>N)  -> sub is subscript -> read: log N base m
    Unlock - O(log<sub>m</sub>N)
    UpgradeLock - O(numberOfLockedNodes * log<sub>m</sub>N)
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
    bool isLockable; // to check ancestors
    int idThatLockedNode;
    TreeNode *parentNode;
    vector<TreeNode *> childrenNodes;

    TreeNode()
    {
        isLocked = false;
        isLockable = true;
        idThatLockedNode = -1;
        parentNode = NULL;
    }

    TreeNode(TreeNode *parent)
    {
        isLocked = false;
        isLockable = true;
        idThatLockedNode = -1;
        parentNode = parent;
    }
};

// T.C. O(numberOfNodes)
bool locking(TreeNode *nodeToBeLocked, int uuid) // change name to lock
{
    // checking ancestors by isLockable
    if (nodeToBeLocked->isLocked || !nodeToBeLocked->isLockable)
        return false;
    TreeNode *currentNode = nodeToBeLocked;
    queue<TreeNode *> pendingNodes;
    pendingNodes.push(currentNode);

    // checking descendent by BFS O(N)
    while (!pendingNodes.empty())
    {
        TreeNode *frontNode = pendingNodes.front();
        pendingNodes.pop();

        for (TreeNode *childNode : frontNode->childrenNodes)
        {
            if (childNode->isLocked)
                return false;
            pendingNodes.push(childNode);
        }
    }

    nodeToBeLocked->idThatLockedNode = uuid; // check if name can be changed?
    nodeToBeLocked->isLocked = true;
    pendingNodes.push(currentNode);

    // informing descendents
    while (!pendingNodes.empty())
    {
        TreeNode *frontNode = pendingNodes.front();
        pendingNodes.pop();

        for (TreeNode *childNode : frontNode->childrenNodes)
        {
            childNode->isLockable = false;
            pendingNodes.push(childNode);
        }
    }

    return true;
}

bool unlocking(TreeNode *nodeTobeUnlocked, int uuid)
{
    // check for isLockable not required
    if (nodeTobeUnlocked->isLockable == false || !nodeTobeUnlocked->isLocked || (nodeTobeUnlocked->isLocked && uuid != nodeTobeUnlocked->idThatLockedNode))
        return false;

    TreeNode *currentNode = nodeTobeUnlocked;
    nodeTobeUnlocked->isLocked = false;
    nodeTobeUnlocked->idThatLockedNode = -1;
    queue<TreeNode *> pendingNodes;
    pendingNodes.push(currentNode);

    while (!pendingNodes.empty())
    {
        TreeNode *frontNode = pendingNodes.front();
        pendingNodes.pop();

        for (TreeNode *childNode : frontNode->childrenNodes)
        {
            childNode->isLockable = true;
            pendingNodes.push(currentNode);
        }
    }

    return true;
}

bool upgrade(TreeNode *nodeToBeUpgraded, int uuid) // O(N*N)
{
    // checking ancestors
    if (nodeToBeUpgraded->isLockable == false || nodeToBeUpgraded->isLocked)
        return false;
    TreeNode *currentNode = nodeToBeUpgraded;
    queue<TreeNode *> pendingNodes;
    pendingNodes.push(currentNode);
    bool isUpgradePossible = false;

    // checking descendents O(N)
    while (!pendingNodes.empty())
    {
        TreeNode *frontNode = pendingNodes.front();
        pendingNodes.pop();

        for (TreeNode *childNode : frontNode->childrenNodes)
        {
            if (childNode->isLocked && childNode->idThatLockedNode != uuid)
                return false;
            if (childNode->isLocked)
                isUpgradePossible = true;
            pendingNodes.push(childNode);
        }
    }

    if (!isUpgradePossible)
        return false;

    pendingNodes.push(currentNode);

    // unlocking all descendents O(N X N)
    while (!pendingNodes.empty())
    {
        TreeNode *frontNode = pendingNodes.front();
        pendingNodes.pop();

        for (TreeNode *childNode : frontNode->childrenNodes)
        {
            if (childNode->isLocked)
            {
                if (!unlocking(childNode, uuid)) // O(N)
                    return false;
            }
            pendingNodes.push(childNode);
        }
    }

    return locking(nodeToBeUpgraded, uuid);
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

        // if (queryNumber == 1)
        // {
        //     answer = locking(nodeToBeProcessed, uuid);
        // }

        // else if (queryNumber == 2)
        // {
        //     answer = unlocking(nodeToBeProcessed, uuid);
        // }

        // else
        // {
        //     answer = upgrade(nodeToBeProcessed, uuid);
        // }

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