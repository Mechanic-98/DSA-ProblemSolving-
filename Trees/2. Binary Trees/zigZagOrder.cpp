#include <iostream>
#include <stack>
#include "BinaryTreeNode.h"
using namespace std;

void zigZagOrder(BinaryTreeNode<int> *root) {
    if(!root) return;
    
    stack<BinaryTreeNode<int>*> currentLevel;
    stack<BinaryTreeNode<int>*> nextLevel;
    bool leftToRight = true;
    
    currentLevel.push(root); 
    
    while(!currentLevel.empty()) {
        BinaryTreeNode<int>* topNode = currentLevel.top(); currentLevel.pop();
        
        if(topNode) {
            cout<<topNode->data<<" ";
            if(leftToRight) {
                if(topNode->left) nextLevel.push(topNode->left);
                if(topNode->right) nextLevel.push(topNode->right);
            } else {
                if(topNode->right) nextLevel.push(topNode->right);
                if(topNode->left) nextLevel.push(topNode->left);
            }
        } 
        
        if(currentLevel.empty()) {
            cout<<'\n';
            swap(currentLevel, nextLevel);
            leftToRight = !leftToRight;
        }
    }
    
}