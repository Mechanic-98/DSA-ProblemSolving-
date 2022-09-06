#include <iostream>
using namespace std;

class Node {
   public:
    int data;
    Node *next;

    Node(int data) {
        this->data = data;
        next = NULL;
    }
};

class Stack {
	// Define the data members
    Node* head;
    int curSize;
   public:
    Stack() {
        // Implement the Constructor
        head = NULL; curSize = 0;
    }

	/*----------------- Public Functions of Stack -----------------*/

    int getSize() {
        // Implement the getSize() function
        return curSize;
    }

    bool isEmpty() {
        // Implement the isEmpty() function
        return curSize == 0;
    }

    void push(int element) {
        // Implement the push() function
        if(!head){
            head = new Node(element);
        } else {
            Node *newNode = new Node(element);
        	newNode->next = head;
        	head = newNode;
        }
        curSize++;
    }

    int pop() {
        // Implement the pop() function
        if(!head) return -1;
        
        Node* nodeToBeDeleted = head;
        int res = nodeToBeDeleted->data;
        head = head->next;
        delete nodeToBeDeleted;
        curSize--;
        return res;
    }

    int top() {
        // Implement the top() function
        if(!head) return -1;
        return head->data;
    }
};