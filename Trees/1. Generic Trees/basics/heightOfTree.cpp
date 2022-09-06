#include <iostream>
#include "TreeNode.h"
using namespace std;

int getHeight(TreeNode<int>* root) {
    // Write your code here
    if(!root) return 0;
    
    int maxHeight = 0;
    for(auto child: root->children){
        int childHeight = getHeight(child);
        maxHeight = max(maxHeight, childHeight);
    }
    
    return maxHeight + 1;
}