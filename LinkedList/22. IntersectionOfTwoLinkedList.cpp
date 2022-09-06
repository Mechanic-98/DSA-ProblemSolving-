#include <iostream>
using namespace std;

class Node
{   public:
    int data;
    Node *next;
    Node(int val)
    {
        data=val;
        next=NULL;
    }
};

// https://leetcode.com/problems/intersection-of-two-linked-lists/discuss/1092898/JS-Python-Java-C%2B%2B-or-Easy-O(1)-Extra-Space-Solution-w-Visual-Explanation
Node *getIntersectionNode(Node *headA, Node *headB) {
    Node *tempHeadA = headA, *tempHeadB = headB;
    while (tempHeadA != tempHeadB) {
        tempHeadA = !tempHeadA ? headB : tempHeadA->next;
        tempHeadB = !tempHeadB ? headA : tempHeadB->next;
    }
    return tempHeadA;
}