TreeNode *addOneRow(TreeNode *root, int val, int depth)
{
    if (depth == 1)
    {
        TreeNode *newNode = new TreeNode(val);
        newNode->left = root;
        return newNode;
    }

    queue<TreeNode *> pendingNodes;
    pendingNodes.push(root);
    int level = 0;

    while (!pendingNodes.empty())
    {

        int numberOfNodesInALevel = pendingNodes.size();

        level++;

        while (numberOfNodesInALevel--)
        {
            TreeNode *frontNode = pendingNodes.front();
            pendingNodes.pop();

            if (level != depth - 1)
            {
                if (frontNode->left)
                    pendingNodes.push(frontNode->left);
                if (frontNode->right)
                    pendingNodes.push(frontNode->right);
            }
            else
            {
                TreeNode *newLeftNode = new TreeNode(val);
                newLeftNode->left = frontNode->left;
                frontNode->left = newLeftNode;

                TreeNode *newRightNode = new TreeNode(val);
                newRightNode->right = frontNode->right;
                frontNode->right = newRightNode;
            }
        }
    }

    return root;
}