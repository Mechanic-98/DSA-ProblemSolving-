#include <iostream>
#include "BinaryTreeNode.h"
#include <climits>
using namespace std;

pair<int, int> getMinAndMax(BinaryTreeNode<int> *root) {
	if(!root) return {INT_MAX, INT_MIN};
    
    pair<int, int> leftAns = getMinAndMax(root->left);
    pair<int, int> rightAns = getMinAndMax(root->right);
    
    pair<int,int> ans;
    ans.first = min(root->data,min(leftAns.first, rightAns.first));
    ans.second = max(root->data,max(leftAns.second, rightAns.second));
    
    return ans;
}