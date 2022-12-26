#include <iostream>
#include "TreeNode.h"
using namespace std;

int countNodes(TreeNode<int> * root){
    if(!root) return 0;
    int ans = 1;

    for(auto child: root->children){
        ans += countNodes(child);
    }

    return ans;
}

