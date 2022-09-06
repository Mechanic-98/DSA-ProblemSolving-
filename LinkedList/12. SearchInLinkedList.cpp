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


// Recursive Approach

int findNodeRec(Node* head, int n) {
    if(!head) return -1;
    else if(head->data == n) return 0;

    int smallAns = findNodeRec(head->next, n);

    if(smallAns == -1) return -1;
    return smallAns + 1;
}

// Iterative Approach

int findNode(Node *head, int n)
{
	//Write your code here
    if(head == NULL) return -1;
    int idx = 0;
    
    while(head) {
        if(head->data == n) {
            return idx;
        }
        idx++;
        head = head->next;
    }
    
    return -1;
}