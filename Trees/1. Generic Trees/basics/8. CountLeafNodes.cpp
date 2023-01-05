#include <iostream>
#include <queue>
#include "TreeNode.h"
using namespace std;

int countLeafNodes(TreeNode<int> *root)
{
    if (!root)
        return 0;

    if (root->children.size() == 0)
        return 1;

    int sum = 0;
    for (int i = 0; i < root->children.size(); i++)
    {
        sum += countLeafNodes(root->children[i]);
    }

    return sum;
}