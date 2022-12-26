#include <iostream>
#include "TreeNode.h"
using namespace std;

TreeNode<int>* maxDataNode(TreeNode<int>* root) {
    
    if(!root) return NULL;
    
    TreeNode<int>* maxNode = root;
    for(auto child: root->children){
        TreeNode<int>* maxFromSubTree = maxDataNode(child);
        maxNode = maxFromSubTree->data > maxNode->data ? maxFromSubTree: maxNode;
    }
    
    return maxNode;
}