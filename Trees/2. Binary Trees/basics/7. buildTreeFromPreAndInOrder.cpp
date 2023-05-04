#include <iostream>
#include "BinaryTreeNode.h"
using namespace std;

int search(int *inorder, int data, int inS, int inE)
{

    for (int i = inS; i <= inE; i++)
    {
        if (inorder[i] == data)
            return i;
    }

    return -1;
}

BinaryTreeNode<int> *buildTreeUtility(int *preorder, int *inorder, int preS, int preE, int inS, int inE)
{
    if (preS > preE || inS > inE)
        return NULL;

    int rootData = preorder[preS];

    int inOrderLength = inE - inS;
    int rootIndexInInorder = search(inorder, rootData, inS, inE);

    int lInS = inS;
    int lInE = rootIndexInInorder - 1;
    int numberOfElementsInLeft = lInE - lInS;
    int lPreS = preS + 1;
    int lPreE = numberOfElementsInLeft + lPreS;

    int rInS = rootIndexInInorder + 1;
    int rInE = inE;
    int numberOfElementsInRight = rInE - rInS;
    int rPreE = preE;
    int rPreS = rPreE - numberOfElementsInRight;

    BinaryTreeNode<int> *root = new BinaryTreeNode<int>(rootData);
    root->left = buildTreeUtility(preorder, inorder, lPreS, lPreE, lInS, lInE);
    root->right = buildTreeUtility(preorder, inorder, rPreS, rPreE, rInS, rInE);

    return root;
}

BinaryTreeNode<int> *buildTree(int *preorder, int preLength, int *inorder, int inLength)
{

    return buildTreeUtility(preorder, inorder, 0, preLength - 1, 0, inLength - 1);
}