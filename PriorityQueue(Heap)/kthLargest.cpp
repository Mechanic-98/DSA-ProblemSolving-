#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int kthLargest(int* arr, int n, int k) {
    
    priority_queue<int, vector<int>, greater<int>> minHeap;
    
    for(int i=0; i< n; i++) {
    	minHeap.push(arr[i]);
        
        if(minHeap.size() > k) minHeap.pop();
    }
    
    return minHeap.top();
}