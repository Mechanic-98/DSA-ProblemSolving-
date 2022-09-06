#include <iostream>
using namespace std;

class Node
{
public:
	int data;
	Node *next;
	Node(int data)
	{
		this->data = data;
		this->next = NULL;
	}
};


Node *takeinput()
{
	int data;
	cin >> data;
	Node *head = NULL, *tail = NULL;
	while (data != -1)
	{
		Node *newnode = new Node(data);
		if (head == NULL)
		{
			head = newnode;
			tail = newnode;
		}
		else
		{
			tail->next = newnode;
			tail = newnode;
		}
		cin >> data;
	}
	return head;
}

void print(Node *head)
{
	Node *temp = head;
	while (temp != NULL)
	{
		cout << temp->data << " ";
		temp = temp->next;
	}
	cout << endl;
}

int sizeOfLinkedList(Node* head) {
    if(!head) return 0;
    int size = 0;
    while(head) {
        size++;
        head = head->next;
    }
    
    return size;
}

// [1-2-3-4-5] k=3; Ans => [3-2-1-5-4]
Node *kReverse(Node *head, int k)
{
	//Write your code here
    if (!head || k == 1) return head;
    
    Node* dummy = new Node(-1);
    dummy->next = head;
    
    Node* curNode = NULL, *prevNode = dummy, *nextNode = dummy;
    
    int size = sizeOfLinkedList(dummy); // O(N)
    
    while(nextNode) {
        curNode = prevNode->next;
        nextNode = curNode->next;
        
        int toLoop = size > k ? k : size - 1;
        
        for(int i=1; i<toLoop; i++) {
            curNode->next = nextNode->next;
            nextNode->next = prevNode->next;
            prevNode->next = nextNode;
            nextNode = curNode->next;
        }
        
        prevNode = curNode;
        size -= k;
    }
    
    return dummy->next;
    
}


// [1-2-3-4-5] k=3;  Ans => [3-2-1-4-5] 
Node* reverseKGroup(Node* head, int k) {
    if(!head || k == 1 || !head->next) return head;
        
    Node* dummy = new Node(-1);
    dummy->next = head;
    Node* curNode = NULL, *prevNode = dummy, *nextNode = dummy;
        
    int size = sizeOfLinkedList(head);
        
    while(size >= k) {
        curNode = prevNode->next;
        nextNode = curNode->next;
            
        for(int i=1; i<k; i++) {
            curNode->next = nextNode->next;
            nextNode->next = prevNode->next;
            prevNode->next = nextNode;
            nextNode = curNode->next;
        }
            
        prevNode = curNode;
        size = size - k;
    }
        
    return dummy->next;
}

int main()
{
	int t;
	cin >> t;

	while (t--)
	{
		Node *head = takeinput();
		int k;
		cin >> k;
		head = kReverse(head, k);
		print(head);
	}
	
	return 0;
}