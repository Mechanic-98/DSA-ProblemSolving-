#include <iostream>
#include <utility>
#include "TreeNode.h"
using namespace std;

// In this question we learnt when to use util function 
// to pass a data for all children during recursion

void secondLargestUtil(TreeNode<int>* root, pair< TreeNode<int>*, TreeNode<int>* > &p){
    if (root == NULL) return;
    
    if(p.first == NULL) p.first = root;
    else if (root->data > p.first->data){
        p.second = p.first; p.first = root;
    }
    
    else if(p.second == NULL){
        if(root->data < p.first->data){
            p.second = root;
        }
    }
    
    else if ( (root->data < p.first->data) && (root->data > p.second->data) ) p.second = root;
    
    for(auto child: root->children){
        secondLargestUtil(child, p);
    }
}

TreeNode<int>* getSecondLargestNode(TreeNode<int>* root) {
    
    pair< TreeNode<int>*, TreeNode<int>* > p = {NULL,NULL};
    
    secondLargestUtil(root, p);
    
    return p.second;
}