#include <iostream>
#include <stack>
#include "BinaryTreeNode.h"
using namespace std;

int countnodes(BinaryTreeNode<int> *root) {
    if(!root) return 0;
    
    return 1+ countnodes(root->left) +countnodes (root->right);
}

void printNodesSumToS(BinaryTreeNode<int> *root, int s) {
    int totalnodes=countnodes(root);
    int count=0;
    
    stack<BinaryTreeNode<int>* > inorder;
    stack<BinaryTreeNode<int>* > revinorder;
    
    // Traverse inorder wise to push everything to left
    BinaryTreeNode<int> *temp=root;
    
    while(temp){
        inorder.push(temp);
       
        temp=temp->left;
    }
    
    // Traverse revinorder wise to push everything to right
    temp=root;
    while(temp) {
        revinorder.push(temp);
       
        temp=temp->right;
    }
    
    
    // Till we check all elements
    while (count<totalnodes -1){  //totalnodes -1 because at the end root will remain in both stacks
        BinaryTreeNode<int> *top1=inorder.top();
        BinaryTreeNode<int> *top2=revinorder.top();
        
        
        // Similar to binary search conditions
        if(top1->data + top2->data == s) {
            cout<<top1->data<<" "<<top2->data<<'\n';
            
            
            // pushing inorder successor for left (Just greater)
            BinaryTreeNode<int> * top = top1;
            inorder.pop();
            count++;
            
            if(top->right) {
                top = top->right;
                while(top) {
                    inorder.push(top);
                    top = top->left;
                }
            }
            
            // pushing revinorder successor for right (Just smaller)
            top = top2;
            revinorder.pop();
            count++;
            
            if(top->left) {
                top = top->left;
                while(top) {
                    revinorder.push(top);
                    top = top->right;
                }
            } 
            
        } else if (top1->data + top2->data > s) {
            BinaryTreeNode<int> * top = top2;
            revinorder.pop();
            count++;
            
            if(top->left) {
                top = top->left;
                while(top) {
                    revinorder.push(top);
                    top = top->right;
                }
            } 
            
        } else {
            BinaryTreeNode<int> * top = top1;
            inorder.pop();
            count++;
            
            if(top->right) {
                top = top->right;
                while(top) {
                    inorder.push(top);
                    top = top->left;
                }
            }
        }
    }
}