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

Node *reverseLinkedList(Node *head) {
    // Write your code here
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

bool isPalindrome(Node* head)
{
    if(head == NULL || head->next == NULL) return true;

    Node* slow = head;
    Node* fast = head;

    while(fast->next && fast->next->next) {
        slow = slow->next;
        fast = fast->next->next;
    }

    // break the list into two halves
    Node* secondHead = slow->next;
    slow->next = NULL;

    // reverse the second half
    secondHead = reverseLinkedList(secondHead);

    /* We have to preserve head and secondHead 
      as we have to join the list back*/
    Node* firstSubList = head;
    Node* secondSubList = secondHead;

    bool ans = true;


    // compare the two halves
    while(firstSubList && secondSubList) {
        if(firstSubList->data != secondSubList->data) {
            ans = false;
            break;
        }

        firstSubList = firstSubList->next;
        secondSubList = secondSubList->next;
    }


    // rejoin the list
    firstSubList = head;
    secondSubList = reverseLinkedList(secondHead);

    while(firstSubList->next) {
        firstSubList = firstSubList->next;
    }

    firstSubList->next = secondSubList;

    return ans;
    
}