#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
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

// Approach 1 Merge list one by one ;  T.C: O(N X M)  S.C: O(1) 

Node* mergeTwoSortedListsRecursively(Node* head1, Node* head2) {  // O(N) N -> Number of nodes
    if(head1==NULL) return head2;
    if(head2==NULL) return head1;

    Node* finalHead = head1->data <= head2->data ? head1 : head2;
    finalHead->next = head1->data <= head2->data ? 
        mergeTwoSortedListsRecursively(head1->next, head2) : 
        mergeTwoSortedListsRecursively(head1, head2->next);

    return finalHead;
}

Node* mergeKListsOneByOne(vector<Node*>& lists) {
    if(lists.size() == 0) return NULL;
        
    Node* head = lists[0];
        
    for(int i=1; i<lists.size(); i++) {
        head = mergeTwoSortedListsRecursively(head, lists[i]);
    }
        
    return head;
}


// Approach 2 Creating sorted vector with data and create new list from that

Node* mergeKListsFromSortedVector(vector<Node*> & lists) {
    if(lists.size() == 0) return NULL;
    vector<int> dataList;
    Node* head = NULL;
    Node* tail = NULL;

    for(int i=0; i<lists.size(); i++) {
        Node* temp = lists[i];
        while(temp) {
            dataList.push_back(temp->data);
            temp = temp->next;
        }
    }
        
    sort(dataList.begin(), dataList.end()); // NlogN.  we can improve time complexity by using priority queue  -> NlogM
        
    for(int ele: dataList) {
        Node* newNode = new Node(ele);
        if(!head) {
            head = newNode; tail = newNode;
        } else {
            tail->next = newNode;
            tail = tail->next;
        }
    }
        
    return head;
}

// Approach 3 imporve Time complexity by using priority queue

Node* mergeKListsUsingPriorityQueue(vector<Node*> & lists) {
    if(lists.size() == 0) return NULL;
    priority_queue<int,vector<int>,greater<int>> minHeap;
    Node* head = NULL;
    Node* tail = NULL;

    for(int i=0; i<lists.size(); i++) {
        Node* temp = lists[i];
        while(temp) {
            minHeap.push(temp->data);
            temp = temp->next;
        }
    }
        
    //sort(dataList.begin(), dataList.end()); // NlogN.  we can improve time complexity by using priority queue  -> NlogM

    
    while(!minHeap.empty()) {
        Node* newNode = new Node(minHeap.top());
        minHeap.pop();
        if(!head) {
            head = newNode; tail = newNode;
        } else {
            tail->next = newNode;
            tail = tail->next;
        }
    }
        
    return head;
}