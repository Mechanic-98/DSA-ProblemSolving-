#include <vector>
#include <queue>
using namespace std;

class TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode()
    {
        val = 0;
        left = NULL;
        right = NULL;
    }
    TreeNode(int x)
    {
        val = x;
        left = NULL;
        right = NULL;
    }
    TreeNode(int x, TreeNode *left, TreeNode *right)
    {
        val = x;
        this->left = left;
        this->right = right;
    }
};

class Solution
{
public:
    vector<vector<int>> levelOrder(TreeNode *root)
    {
        vector<vector<int>> dataOnDifferentLevels;
        if (!root)
            return dataOnDifferentLevels;

        // BFS traversal
        queue<TreeNode *> pendingNodes;
        pendingNodes.push(root);

        while (!pendingNodes.empty())
        {
            int numberOfNodes = pendingNodes.size();
            vector<int> dataPerLevel;

            for (int i = 0; i < numberOfNodes; i++)
            {
                TreeNode *currentNode = pendingNodes.front();
                pendingNodes.pop();
                dataPerLevel.push_back(currentNode->val);

                if (currentNode->left)
                    pendingNodes.push(currentNode->left);
                if (currentNode->right)
                    pendingNodes.push(currentNode->right);
            }

            dataOnDifferentLevels.push_back(dataPerLevel);
        }

        return dataOnDifferentLevels;
    }
};