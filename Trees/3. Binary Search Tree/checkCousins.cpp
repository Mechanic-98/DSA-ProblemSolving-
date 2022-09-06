

bool checkIfSibling(BinaryTreeNode<int> *root, int p1, int p2){
	if(!root) return false;
	if(root->left && root->right){
		if((root->left->data == p1 && root->right->data == p2) ||
			(root->left->data == p2 && root->right->data == p1)) return true;
	}
	return (checkIfSibling(root->left,p1,p2) || checkIfSibling(root->right,p1,p2));
}

bool isCousin(BinaryTreeNode<int> *root, int p, int q) {
    if(root == NULL) return false;
    
    bool checkForP, checkForQ;

    queue< BinaryTreeNode <int> * > pendingNodes;
    pendingNodes.push(root);
    
    
    while(!pendingNodes.empty()) {
        checkForP = false; checkForQ = false;
        int levelSize = pendingNodes.size();
        
        while(levelSize--) {
        	BinaryTreeNode<int> * frontNode = pendingNodes.front();
            pendingNodes.pop();

            if(frontNode->data == p) checkForP = true;
            else if (frontNode->data == q) checkForQ = true; 
            
            if(frontNode->left) pendingNodes.push(frontNode->left);
            if(frontNode->right) pendingNodes.push(frontNode->right);
        }
        
        if(checkForP && checkForQ && checkIfSibling(root, p, q) == false) return true;
        
    }
    
    return false;
}