class ListNode
{
public:
    int val;
    ListNode *next;
    ListNode(int x)
    {
        val = x;
        next = NULL;
    }
};

class Solution
{
public:
    void deleteNode(ListNode *node)
    {
        if (!node)
            return;

        // node is never a tail node
        node->val = node->next->val;
        ListNode *nodeToBeDeleted = node->next;
        node->next = node->next->next;
        delete nodeToBeDeleted;
    }
};