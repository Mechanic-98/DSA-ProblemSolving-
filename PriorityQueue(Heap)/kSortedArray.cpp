#include <iostream>
#include <queue>
#include <vector>
using namespace std;

void kSortedArray(int * arr, int n, int k) {
    priority_queue<int, vector<int>, greater<int>> minHeap;
    
    int j=0;
    for(int i=0; i<n; i++) { // O(nlogk)
        minHeap.push(arr[i]);
        
        if(minHeap.size() > k) {
            arr[j] = minHeap.top();
            minHeap.pop();
            j++;
        }
    }
    
    while(!minHeap.empty()) {. // O(klogk)
        arr[j] = minHeap.top();
        minHeap.pop();
        j++;
    }
}

int main() {
    int arr[] = {10, 12, 15, 6, 9};
    kSortedArray(arr, 5, 3);
    for(int i=0; i<5; i++) {
        cout<<arr[i]<<" ";
    }
}