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



Node* insertNode(Node* head, int idx, int data) {
    Node* newNode = new Node(data);
    if(idx == 0) {
        newNode->next = head;
        head = newNode;
        return head;
    }
    
    Node* temp = head;
    idx = idx-1;
    while(idx-- && head) {
        temp = temp->next;
    }
    
    if(temp) {
        newNode->next = temp->next;
        temp->next = newNode;
    }
    
    return head;
}


// Recursively

Node* insertNodeRec(Node *head, int i, int data) {
	// Write your code here
    if(head == NULL) return head;
    
    if(i == 0) {
        Node* newNode = new Node(data);
        newNode->next = head;
        head = newNode;
        return head;
    }
    Node* remHead = insertNode(head->next, i-1, data);
    head->next = remHead;
    return head;
}
