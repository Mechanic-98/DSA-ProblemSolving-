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


// Iteratively


Node *deleteNode(Node *head, int pos)
{
    // Write your code here.
    if(head == NULL) return head;
    if(pos == 0) {
        Node* temp = head;
        head = head->next;
        delete temp;
        return head;
    }
    
    pos = pos-1;
    Node* temp = head;
    while(pos-- && temp->next != NULL) {
        temp = temp->next;
    }
    
    if(temp->next != NULL) {
        Node* nodeToBeDeleted = temp->next;
        temp->next = nodeToBeDeleted->next;
        delete nodeToBeDeleted;
    }
    
    return head;
}

// Recursively


Node *deleteNodeRec(Node *head, int pos) {
	//Write your code here
    if(head == NULL) return head;
    
    if(pos == 0) {
        Node* nodeToBeDeleted = head;
        head = head->next;
        delete nodeToBeDeleted;
        return head;
    }
    
    Node* headForRem = deleteNodeRec(head->next, pos-1);
    head->next = headForRem;
    return head;
}