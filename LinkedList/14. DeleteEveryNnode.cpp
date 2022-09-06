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

Node *skipMdeleteN(Node *head, int M, int N)
{
	// Write your code here
    if(head == NULL) return head;
    if(M == 0) return NULL;
    if(N == 0) return head;
    
    Node* temp = head;
    while(temp) {
        int toSkip = M-1;
        int toDel = N;
        while(toSkip-- && temp->next) {
            temp = temp->next;
        }
        while(toDel-- && temp->next) {
            Node* nodeToBeDeleted = temp->next;
            temp->next = temp->next->next;
            delete nodeToBeDeleted;
        }
        temp = temp->next;
    }
    
    return head;
}

int main()
{
	int t;
	cin >> t;
	while (t--)
	{
		Node *head = takeinput();
		int m, n;
		cin >> m >> n;
		head = skipMdeleteN(head, m, n);
		print(head);
	}
	return 0;
}