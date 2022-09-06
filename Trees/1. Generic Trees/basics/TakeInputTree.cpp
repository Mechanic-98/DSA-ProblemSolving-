#include <iostream>
#include <queue>
#include "TreeNode.h"
using namespace std;

TreeNode<int>* takeInput() {
    int rootData;
    cout<<"Enter data for root"<<'\n';
    cin>>rootData;
    // allways allocate TreeNode dynamically
    TreeNode<int> * root = new TreeNode<int>(rootData);

    int n;
    cout<<"Enter number of children for"<<rootData<<'\n';
    cin>>n;

    for(int i=0; i<n; i++){
        TreeNode<int>* child = takeInput();
        root->children.push_back(child);
    }

    return root;
}

TreeNode<int> * takeInputLevelWise(){
    int rootData;
    cout<<"Enter data for root"<<'\n';
    cin>>rootData;

    TreeNode<int> * root = new TreeNode<int>(rootData);

    queue<TreeNode<int>*> pendingNodes;
    pendingNodes.push(root);

    while(!pendingNodes.empty()){
        TreeNode<int> * frontNode = pendingNodes.front();
        pendingNodes.pop();

        int numberOfChildren;
        cout<<"Enter number of children for "<<frontNode->data<<'\n';
        cin>>numberOfChildren;
        for(int i=0; i<numberOfChildren; i++){
            int childData;
            cout<<"Enter data for "<<i<<"th child of"<<frontNode->data<<'\n';
            cin>>childData;

            TreeNode<int>* childNode = new TreeNode<int>(childData);
            frontNode->children.push_back(childNode);
            pendingNodes.push(childNode);
        }
    }

    return root;
}