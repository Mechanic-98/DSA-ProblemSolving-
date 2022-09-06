#include <iostream>
#include <queue>
#include <vector>
using namespace std;


vector<int> kLargest(int arr[], int n, int k){
    vector<int> ans;
    priority_queue<int, vector<int>, greater<int>> minHeap;
    
    for(int i=0; i<n; i++) {
        minHeap.push(arr[i]);
        
        if(minHeap.size() > k) {
            minHeap.pop();
        }
    }
    
    while(!minHeap.empty()) {
        ans.push_back(minHeap.top());
        minHeap.pop();
    }
    
    return ans;

}