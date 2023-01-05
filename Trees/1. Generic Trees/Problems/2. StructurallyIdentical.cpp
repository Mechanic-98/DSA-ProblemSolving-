#include <iostream>
#include "TreeNode.h"
using namespace std;

/*
Structural Identical
If the two given trees are made of nodes with the same values and the nodes
are arranged in the same way, then the trees are called identical.
*/

bool areIdentical(TreeNode<int> *root1, TreeNode<int> *root2)
{
    // Write your code here
    if (!root1 && !root2)
        return true;
    if (!root1 && root2 || (root1 && !root2))
        return false;

    bool flag = (root1->data == root2->data) && (root1->children.size() == root2->children.size());

    if (flag)
    {
        for (int i = 0; i < root1->children.size(); i++)
        {
            flag = flag && areIdentical(root1->children[i], root2->children[i]);
        }
    }

    return flag;
}