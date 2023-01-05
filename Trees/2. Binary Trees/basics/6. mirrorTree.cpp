#include <iostream>
#include "BinaryTreeNode.h"
using namespace std;

/*
For a given Binary Tree of type integer,
update it with its corresponding mirror image.

              1                                            1
        2           3              ->                 3          2
    4       5   6       7                          7       6   5      4
*/

void mirrorBinaryTree(BinaryTreeNode<int> *root)
{

    if (!root)
        return;

    mirrorBinaryTree(root->left);
    mirrorBinaryTree(root->right);

    if (root->left || root->right)
    {
        BinaryTreeNode<int> *temp = root->left;
        root->left = root->right;
        root->right = temp;
    }
}