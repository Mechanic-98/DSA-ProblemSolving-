#include <iostream>
#include <utility>
#include "BinaryTreeNode.h"
using namespace std;

pair<Node<int>*, Node<int>*> helper(BinaryTreeNode<int>* root) {
    pair<Node<int>*, Node<int>*> ans = {NULL,NULL};
    if(!root) return ans;  // head, tail
    
    pair<Node<int>*, Node<int>*> leftPair = helper(root->left);
    pair<Node<int>*, Node<int>*> rightPair = helper(root->right);
    
    Node<int>* rootNode = new Node<int>(root->data);
    if(leftPair.first) {
        leftPair.second->next = rootNode;
        ans.first = leftPair.first;
    }
    else {
        ans.first = rootNode;
    }
    
    if(rightPair.first) {
        rootNode->next = rightPair.first;
    	ans.second = rightPair.second;
    } else {
        ans.second = rootNode;
    }
    
    
    return ans;
}

Node<int>* constructLinkedList(BinaryTreeNode<int>* root) {
	// Write your code here
    if(!root) return NULL;
    
    pair<Node<int>*, Node<int>*> ans = helper(root);
    return ans.first;
    
}