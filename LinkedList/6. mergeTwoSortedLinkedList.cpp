#include <iostream>
using namespace std;
class Node {
    public:
    int data;
    Node* next;

    Node(int data) {
        this->data = data;
        next = NULL;
    }
};

Node* mergeTwoSortedListsRecursively(Node* head1, Node* head2) {
    if(head1==NULL) return head2;
    if(head2==NULL) return head1;

    Node* finalHead = head1->data <= head2->data ? head1 : head2;
    finalHead->next = head1->data <= head2->data ? 
        mergeTwoSortedListsRecursively(head1->next, head2) : 
        mergeTwoSortedListsRecursively(head1, head2->next);

    return finalHead;
}

Node *mergeTwoSortedLinkedLists(Node *head1, Node *head2)
{
    //Write your code here
    if(head1==NULL) return head2;
    if(head2==NULL) return head1;
    
    Node* finalHead = NULL;
    Node* finalTail = NULL;
    
    while(head1 && head2) {
        if(head1->data <= head2->data) {
            if(finalHead == NULL) {
                finalHead = head1;
                finalTail = head1;
                head1 = head1->next;
            } else {
                finalTail->next = head1;
            	head1 = head1->next;
            	finalTail = finalTail->next;
            }
            
        } else {
            if(finalHead == NULL) {
                finalHead = head2;
                finalTail = head2;
                head2 = head2->next;
            } else {
                finalTail->next = head2;
            	head2 = head2->next;
            	finalTail = finalTail->next;
            }
        }
    }
    
    if(head1 == NULL) {
        finalTail->next = head2;
    } 
    if(head2 == NULL) {
        finalTail->next = head1;
    }
    
    return finalHead;
}