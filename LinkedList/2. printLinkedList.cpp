#include <iostream>
using namespace std;
class node {
    public:
    int data;
    node* next;

    node(int data) {
        this->data = data;
        next = NULL;
    }
};

void pirntLinkedList(node* head) {
    while(head) {
        cout<<head->data<<"->";
        head = head->next;
    }
    cout<<"NULL"<<endl;
}