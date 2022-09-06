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

Node* addTwoNumbers(Node* l1, Node* l2) {
    int carryOver = 0;
    Node* newHead = new Node(0);
    Node* temp = newHead;
    while(carryOver || l1 || l2) {
        carryOver += (l1 ? l1->data : 0) + (l2 ? l2->data : 0);
        temp->next = new Node(carryOver % 10);
        temp = temp->next;
        carryOver /= 10;
            
        if(l1) l1 = l1->next;
        if(l2) l2 = l2->next;
    }
        
    return newHead->next;
}