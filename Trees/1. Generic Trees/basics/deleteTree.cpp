#include <iostream>
#include "TreeNode.h"
using namespace std;

// delete children first and then parent node
void deleteTree(TreeNode<int> * root){
    if(!root) return;

    for(int i=0; i< root->children.size(); i++){
        deleteTree(root->children[i]);
    }
    delete root;
}