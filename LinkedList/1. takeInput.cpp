#include <iostream>
using namespace std;

class node
{
public:
    int data;
    node *next;

    node(int data)
    {
        this->data = data;
        next = NULL;
    }
};

template <typename T>
class node2
{
public:
    T data;
    node2 *next;

    node2(T data)
    {
        this->data = data;
        next = NULL;
    }
};

node *takeInput()
{
    int data;
    node *head = NULL;
    node *tail = NULL;
    while (cin >> data)
    {
        node *newNode = new node(data);
        if (head == NULL)
        {
            head = newNode;
            tail = newNode;
        }
        else
        {
            tail->next = newNode;
            tail = tail->next;
        }
    }

    return head;
}