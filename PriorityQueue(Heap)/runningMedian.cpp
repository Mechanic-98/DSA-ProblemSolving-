#include <iostream>
#include <queue>
#include <vector>
using namespace std;

void findMedian(int *arr, int n){
    if(n == 0) return;
    // maxHeap for left part
    priority_queue<int> maxHeap;
    
    //minHeap for right part
    priority_queue<int, vector<int>, greater<int>> minHeap;
    
    int median = arr[0];
    maxHeap.push(median);
    
    cout<<median<<" ";
    
    for(int i=1; i<n; i++) {
        int elementToConsider = arr[i];
        
        // left side heap has more elements
        if(maxHeap.size() > minHeap.size()) {
            if(elementToConsider < median) {
                minHeap.push(maxHeap.top());
                maxHeap.pop();
                maxHeap.push(elementToConsider);
            } else {
                minHeap.push(elementToConsider);
            }
            
            median = ( maxHeap.top() + minHeap.top() ) / 2;
        } 
        // right side heap has more elements
        else if (minHeap.size() > maxHeap.size()) {
            if(elementToConsider < median) {
                maxHeap.push(elementToConsider);
            } else {
                maxHeap.push(minHeap.top());
                minHeap.pop();
                minHeap.push(elementToConsider);
            }
            
            median = ( maxHeap.top() + minHeap.top() ) / 2;
        }
        // both sides has equal number of elements
        else {
            if(elementToConsider < median) {
                maxHeap.push(elementToConsider);
                median = maxHeap.top();
            } else {
                minHeap.push(elementToConsider);
                median = minHeap.top();
            }
            
        }
        
        cout<<median<<" ";
    }
}