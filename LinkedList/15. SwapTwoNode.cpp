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

Node *swapNodes(Node *head, int i, int j)
{
	//Write your code here
    if(head == NULL) return head;
    if(i == j) return head;
    if(i > j) {
        int a = i; i = j; j = a;
    }
    Node* temp = head;
    Node* nodeBeforeI = NULL;
    Node* nodeAtI = NULL;
    Node* nodeBeforeJ = NULL;
    Node* nodeAtJ = NULL;
    
    int idx = 0;
    if(i == 0) {
        while(temp) {
            if(idx == j - 1) {
                nodeBeforeJ = temp;
                nodeAtJ = temp->next;
            }
            idx++;
            temp = temp->next;
        }
        
        if(j == 1) {
            head->next = head->next->next;
            nodeAtJ->next = head;
            return nodeAtJ;
        }
        
        nodeBeforeJ->next = head;
        Node* nodeAfterJ = nodeAtJ->next;
        nodeAtJ->next = head->next;
        head->next = nodeAfterJ;
        return nodeAtJ;
    }
    
    while(temp) {
        if(idx == i-1) {
            nodeBeforeI = temp;
            nodeAtI = temp->next;
        }
        if(idx == j-1) {
            nodeBeforeJ = temp;
            nodeAtJ = temp->next;
        }
        idx++;
        temp = temp->next;
    }
    nodeBeforeI->next = nodeAtJ;
    nodeBeforeJ->next = nodeAtI;
    Node* nodeAfterI = nodeAtI->next;
    nodeAtI->next = nodeAtJ->next;
    nodeAtJ->next = nodeAfterI;
    
    return head;
    
}

int main()
{
	int t;
	cin >> t;
	while (t--)
	{
		int i, j;
		Node *head = takeinput();
		cin >> i;
		cin >> j;
		head = swapNodes(head, i, j);
		print(head);
	}
	return 0;
}