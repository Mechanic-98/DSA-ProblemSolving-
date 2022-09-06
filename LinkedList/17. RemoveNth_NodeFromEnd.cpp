/* Q. Given the head of a linked list, 
remove the nth node from the end of the list and return its head. */

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


// Challenge was to do this in single pass
 Node* removeNthFromEnd(Node* head, int n) {
        if(!head) return head;
        Node* slow = head, *fast = head;
        while(n--){
            fast = fast->next;
        }
        
        if(!fast) return head->next;
        
        while(fast->next) {
            slow = slow->next;
            fast = fast->next;
        }
        
        Node* nodeToBeDeleted = slow->next;
        slow->next = slow->next->next;
        delete nodeToBeDeleted;
        return head;
    }