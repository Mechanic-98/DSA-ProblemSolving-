

bool isMaxHeap(int arr[], int n) {
    
    for(int i=0; i< n; i++) {
        int leftChildIndex = 2 * i + 1;
        int rightChildIndex = 2 * i + 2;
        
        if(leftChildIndex < n && arr[leftChildIndex] > arr[i]) return false;
        if(rightChildIndex < n && arr[rightChildIndex] > arr[i]) return false;
    }
    
    return true;
}