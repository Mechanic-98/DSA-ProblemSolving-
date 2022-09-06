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

class Pair {
    public:

    Node * head;
    Node * tail;
};


// O(N^2)
Node *reverseLinkedListRec1(Node *head)
{
    //Write your code here
    if(head == NULL || head->next == NULL ) return head;
    
    Node* headForRemainingList = reverseLinkedListRec1(head->next);
    
    Node* temp = headForRemainingList;
    while(temp->next) {
        temp = temp->next;
    }
    
    temp->next = head;
    head->next = NULL;
    return headForRemainingList;
}


// O(N)
Pair reverseLinkedListRec2(Node* head) {
    if(head == NULL || head->next == NULL) {
        Pair ans;
        ans.head = head;
        ans.tail = head;
        return ans;
    }

    Pair smallAns = reverseLinkedListRec2(head->next);

    smallAns.tail->next = head;
    head->next = NULL;
    Pair ans;
    ans.head = smallAns.head; ans.tail = head;
    return ans;
}


//O(N) (BEST)
Node* reverseLinkedListRec3(Node* head) {
    if(head == NULL || head->next == NULL) return head;

    Node* smallAns = reverseLinkedListRec3(head->next);

    head->next->next = head;
    head->next = NULL;

    return smallAns;
}


// ITERATIVE APPROACH O(N)

Node *reverseLinkedList(Node *head) {
    // Write your code here
    if(!head) return head;
    Node* prev = NULL;
    Node* cur = head;
    Node* nextPointer;
    
    while(cur) {
        nextPointer = cur->next;
        cur->next = prev;
        
        prev = cur;
        cur = nextPointer;
    }
    
    return prev;
}