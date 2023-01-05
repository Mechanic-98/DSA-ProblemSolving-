#include <iostream>
#include <queue>
#include "BinaryTreeNode.h"
using namespace std;

BinaryTreeNode<int>* takeInput() {
    int n; cin>>n;
    if(n == -1) return NULL;
    BinaryTreeNode<int>* root = new BinaryTreeNode<int>(n);
    root->left =takeInput();
    root->right = takeInput();

    return root;
}

BinaryTreeNode<int>* takeInputLevelWise() {
    int n; cin>>n;
    if(n == -1) return NULL;

    BinaryTreeNode<int>* root = new BinaryTreeNode<int>(n);
    queue<BinaryTreeNode<int>*> q;
    q.push(root);

    while(!q.empty()){
        BinaryTreeNode<int>* frontNode = q.front(); q.pop();
        int leftChildData; cin>>leftChildData;
        if(leftChildData != -1) {
            frontNode->left = new BinaryTreeNode<int>(leftChildData);
            q.push(frontNode->left);
        }
        int rightChildData; cin>>rightChildData;
        if(rightChildData != -1) {
            frontNode->right = new BinaryTreeNode<int>(rightChildData);
            q.push(frontNode->right);
        }
    }

    return root;
}