#include <iostream>
#include <algorithm>
#include <unordered_map>
using namespace std;

// DOUBLY LINKED LIST
class Node
{
public:
    int key, val;
    Node *next, *prev;

    Node(int key, int val)
    {
        this->key = key;
        this->val = val;
        next = NULL;
        prev = NULL;
    }
};
class LRUCache
{

    Node *head = new Node(-1, -1);
    Node *tail = new Node(-1, -1);
    int cap;
    unordered_map<int, Node *> keyMap;

    void addNode(Node *newNode)
    { // O(1)
        newNode->next = head->next;
        newNode->prev = head;
        newNode->next->prev = newNode;
        head->next = newNode;
    }

    void deleteNode(Node *nodeToBeDeleted)
    { // O(1)
        Node *nodeBefore = nodeToBeDeleted->prev;
        Node *nodeAfter = nodeToBeDeleted->next;
        nodeBefore->next = nodeAfter;
        nodeAfter->prev = nodeBefore;
        // delete nodeToBeDeleted;
    }

public:
    LRUCache(int capacity)
    {
        cap = capacity;
        head->next = tail;
        tail->prev = head;
    }

    int get(int key)
    { // O(1)
        if (keyMap.find(key) != keyMap.end())
        {
            Node *resultNode = keyMap[key];
            int resultValue = resultNode->val;
            keyMap.erase(key);
            deleteNode(resultNode);
            addNode(resultNode);
            keyMap[key] = head->next;
            return resultValue;
        }

        return -1;
    }

    void put(int key, int value)
    { // O(1)
        if (keyMap.find(key) != keyMap.end())
        {
            Node *existingNode = keyMap[key];
            keyMap.erase(key);
            deleteNode(existingNode);
        }
        if (keyMap.size() == cap)
        {
            Node *nodeToBeDeleted = tail->prev;
            keyMap.erase(nodeToBeDeleted->key);
            deleteNode(nodeToBeDeleted);
        }
        Node *newNode = new Node(key, value);
        addNode(newNode);
        keyMap[key] = head->next;
    }
};
