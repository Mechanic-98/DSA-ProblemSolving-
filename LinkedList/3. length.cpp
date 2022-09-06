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

int length(Node* head) {
    if(head == NULL) return 0;

    int size = 0;
    while(head) {
        size++;
        head = head->next;
    }

    return size;
}

int lengthRecursively(Node* head) {
    if(head == NULL) return 0;

    return lengthRecursively(head->next) + 1;
}