#include <iostream>
#include "TreeNode.h"
using namespace std;

void printAtLevelK(TreeNode<int> * root, int k){
    if(!root) return;
    if(k == 0) {
        cout<<root->data; return;
    }

    for(auto child: root->children){
        printAtLevelK(child, k-1);
    }
}

int getLeafNodeCount(TreeNode<int>* root) {
    
    if(!root) return 0;
    
    int numberOfChildren = root->children.size(), ans = 0;
    if(numberOfChildren == 0) return 1;
    else {
        for(int i=0; i<numberOfChildren; i++){
        	ans += getLeafNodeCount(root->children[i]);
    	}
    }
    
    return ans;
}