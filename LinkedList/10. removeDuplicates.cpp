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

Node* removeDuplicates(Node* head) {
    if(head == NULL || head->next == NULL) return head;

    Node* curHead = head;

    while(curHead->next) {
        if(curHead->data == curHead->next->data) {
            Node* nodeToBeDeleted = curHead->next;
            curHead->next = curHead->next->next;
            delete nodeToBeDeleted;
        } else {
            curHead = curHead->next;
        }
    }

    return head;
}