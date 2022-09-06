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


// Recursive approach
Node* swapPairsRec(Node* head) {
    if(!head || !head->next) return head;
        
    Node* temp = head->next;
        
    head->next = swapPairsRec(head->next->next);
    temp->next = head;
        
    return temp;
}

// Iterative approach

Node* swapPairs(Node* head) {
    if(!head || !head->next) return head; //If there are less than 2 nodes in the given nodes, then no need to do anything just return the list as it is.
		
    Node* dummyNode = new Node(-1);
        
    Node* prevNode=dummyNode;
    Node* currNode=head;
        
    while(currNode && currNode->next){
        prevNode->next = currNode->next;
        currNode->next = prevNode->next->next;
        prevNode->next->next = currNode;
            
        prevNode = currNode;
        currNode = currNode->next;
    }
        
    return dummyNode->next;
}