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

Node* findIntersection(Node* head1, Node* head2)
{
    // Your Code Here
    if(!head1) return head2;
    if(!head2) return head1;
    
    Node* finalHead = NULL, *finalTail = NULL;
    
    while(head1 && head2) {
        if(head1->data < head2->data) head1 = head1->next;
        else if (head2->data < head1->data) head2 = head2->next;
        else {
            if(!finalHead) {
                finalHead = head1; finalTail = head1;
            } else {
                finalTail->next = head1; finalTail = head1;
            }
            head1 = head1->next; head2 = head2->next;
        }
    }
    finalTail->next = NULL;
    
    return finalHead;
}