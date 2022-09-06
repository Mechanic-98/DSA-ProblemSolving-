#include <iostream>
#include <queue>
#include <vector>
using namespace std;

vector<int> kSmallest(int arr[], int n, int k) {
    // Write your code here
    vector<int> ans;
    priority_queue<int> maxHeap;
    
    for(int i=0; i<n; i++) {
        maxHeap.push(arr[i]);
        
        if(maxHeap.size() > k) {
            maxHeap.pop();
        }
    }
    
    while(!maxHeap.empty()) {
        ans.push_back(maxHeap.top());
        maxHeap.pop();
    }
    
    return ans;
}