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

int size(Node* head) {
    int size = 0;
    while(head){
        size++;
        head = head->next;
    }
    
    return size;
}

Node *appendLastNToFirst(Node *head, int n)
{
    //Write your code here
    if(head == NULL || head->next == NULL) return head;
    
    int length = size(head);
    if(n == 0 || n == length) return head;
    
    int count = 1;
    Node* newHead;
    Node* newTail;
    Node* temp = head;
    
    while(temp->next) {
        if(count == length - n) newTail = temp;
        if(count == length - n +1) newHead = temp;
        count++;
        temp = temp->next;
    }
    
    temp->next = head;
    newTail->next = NULL;
    
    return newHead;
}