#include <iostream>
using namespace std;

class ListNode
{
public:
    int val;
    ListNode *next;
    ListNode(int val)
    {
        this->val = val;
        next = NULL;
    }
};

class Solution
{
public:
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
    {
        int carryOver = 0;
        ListNode *newHead = new ListNode(0); // Dummy node
        ListNode *tempNode = newHead;        // to traverse

        while (carryOver || l1 || l2)
        {
            // use carry to compute
            carryOver += (l1 ? l1->val : 0) + (l2 ? l2->val : 0);
            tempNode->next = new ListNode(carryOver % 10);

            // move nodes
            tempNode = tempNode->next;
            if (l1)
                l1 = l1->next;
            if (l2)
                l2 = l2->next;

            // update carry
            carryOver /= 10;
        }

        return newHead->next;
    }
};