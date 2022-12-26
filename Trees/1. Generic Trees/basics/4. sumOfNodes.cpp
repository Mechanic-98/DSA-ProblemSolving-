#include <iostream>
#include "TreeNode.h"
using namespace std;

int sumOfNodes(TreeNode<int>* root) {
    
    if(!root) return 0;
    
    int ans = root->data;
    for(auto child: root->children){
        ans += sumOfNodes(child);
    }
    return ans;
}