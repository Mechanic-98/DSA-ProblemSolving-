#include <iostream>
#include <queue>
#include "TreeNode.h"
using namespace std;

void print(TreeNode<int>* root){
    // Edge case not base case
    if(!root) return;

    cout<<root->data<<": ";
    for(int i=0; i<root->children.size(); i++){ // Base case is handled in the loop
        if(i == root->children.size() - 1) cout<<root->children[i]->data;
        else cout<<root->children[i]->data<<",";
    }

    cout<<'\n';

    for(auto child: root->children){ // Base case is handled in the loop
        print(child);
    }
}

void printLevelWise(TreeNode<int>* root) {
    // Write your code here
    if(!root) return;
    queue<TreeNode<int>*> pendingNodes;
    pendingNodes.push(root);

    while(!pendingNodes.empty()){
        TreeNode<int>* frontNode = pendingNodes.front();
        pendingNodes.pop();
        cout<<frontNode->data<<":";
        int numberOfChildren = frontNode->children.size();
        for(int i=0; i<numberOfChildren; i++){
            TreeNode<int>* childNode = frontNode->children[i];
            if(i == numberOfChildren -1) cout<<childNode->data;
            else cout<<childNode->data<<",";
            pendingNodes.push(childNode);
        }
        cout<<'\n';
    }
}