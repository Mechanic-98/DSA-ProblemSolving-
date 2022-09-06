#include <iostream>
#include <vector>
#include <queue>
#include "BinaryTreeNode.h"
using namespace std;

vector<Node<int>*> constructLinkedListForEachLevel(BinaryTreeNode<int> *root) {
    if(!root) return {};
    
    queue<BinaryTreeNode<int>*> q;
    q.push(root); q.push(NULL);
    vector<Node<int>*> v;
    Node<int>* tempNode = NULL;
    
    while(!q.empty()) {
        BinaryTreeNode<int>* frontNode = q.front(); q.pop();
        if(!frontNode) {
            tempNode = NULL;
            if(!q.empty()) q.push(NULL);
        } else {
            if(!tempNode) {
                tempNode = new Node<int>(frontNode->data);
                v.push_back(tempNode);
            }
            else {
                tempNode->next = new Node<int>(frontNode->data);
                tempNode = tempNode->next;
            }
            if(frontNode->left) q.push(frontNode->left);
        	if(frontNode->right) q.push(frontNode->right);
        }  
    }
    
    return v;
}