#include <iostream>
#include <queue>
#include "BinaryTreeNode.h"
using namespace std;

void printTree(BinaryTreeNode<int>* root){
    if(!root) return;

    cout<<root->data<<": ";

    if(root->left) cout<<"L->"<<root->left->data<<", ";
    if(root->right) cout<<"R->"<<root->right->data;
    cout<<'\n';
    printTree(root->left);
    printTree(root->right);
}

void printTreeLevelWise(BinaryTreeNode<int>* root){
    /*
    1: L2R3
    2: L4R5
    3: L6
    4: 
    5:
    6:
    */
    if(!root) return;

    queue<BinaryTreeNode<int>* > pendingNodes;
    pendingNodes.push(root);

    while(!pendingNodes.empty()){
        BinaryTreeNode<int>* frontNode = pendingNodes.front(); pendingNodes.pop();
        cout<<frontNode->data<<":";
        if(frontNode->left) {
            cout<<"L:"<<frontNode->left->data<<",";
            pendingNodes.push(frontNode->left);
        }
        if(frontNode->right) {
            cout<<"R:"<<frontNode->right->data;
            pendingNodes.push(frontNode->right);
        }
        cout<<'\n';
    }
}

void printTreeLevelAfterLevel(BinaryTreeNode<int> *root) {
    /*
    1
    2 3
    4 5 6
    */
    if(!root) return;
    
    queue<BinaryTreeNode<int>*> pendingNodes;
    pendingNodes.push(root); pendingNodes.push(NULL);
    
    while(!pendingNodes.empty()) {
        BinaryTreeNode<int>* frontNode = pendingNodes.front(); pendingNodes.pop();
        if(!frontNode) {
            cout<<'\n';
            if(!pendingNodes.empty()) pendingNodes.push(NULL);
        } else {
            cout<<frontNode->data<<" ";
        	if(frontNode->left) pendingNodes.push(frontNode->left);
        	if(frontNode->right) pendingNodes.push(frontNode->right);
        }
    }
}