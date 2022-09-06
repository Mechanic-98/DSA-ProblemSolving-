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


Node* mergeTwoSortedLinkedLists(Node* head1, Node* head2) {
    
    if(head1 == NULL) return head2;
    if(head2 == NULL) return head1;
    
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
                finalTail = finalTail->next;
                head1 = head1->next;
            }
        } else {
            if(finalHead == NULL) {
                finalHead = head2;
                finalTail = head2;
                head2 = head2->next;
            } else {
                finalTail->next = head2;
                finalTail = finalTail->next;
                head2 = head2->next;
            }
        }
    }
    
    if(head1 == NULL) finalTail->next = head2;
    if(head2 == NULL) finalTail->next = head1;
    
    return finalHead;
}

Node* midpoint(Node* head) {
    Node* slow = head;
    Node* fast = head->next;
    
    while(fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;
    }
    
    return slow;
}

Node *mergeSort(Node *head)
{
	//Write your code here
    if(head == NULL || head->next == NULL) return head;
    
    Node* midNode = midpoint(head);
    
    Node* part1Head = head;
    Node* part2Head = midNode->next;
    midNode->next = NULL;
    
    part1Head = mergeSort(part1Head);
    part2Head = mergeSort(part2Head);
    
    Node* finalHead = mergeTwoSortedLinkedLists(part1Head, part2Head);
    
    return finalHead;
    
}