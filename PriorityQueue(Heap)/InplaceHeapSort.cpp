
void upHeapifyToBuildHeap(int *arr, int n) {
    
    for(int i=1; i<n; i++) {
        int childIndex = i;


        while(childIndex > 0) {
            int parentIndex = (childIndex - 1) / 2;

            if(arr[parentIndex] > arr[childIndex]) {
                int temp = arr[childIndex];
                arr[childIndex] = arr[parentIndex];
                arr[parentIndex] = temp;
            } else break;

            childIndex = parentIndex;
        }
    }

}

void downHeapifyToSort(int * arr, int n) {
    int size = n;
    
    while(size > 1) {
        int temp = arr[0];
        arr[0] = arr[size - 1];
        arr[size-1] = temp;
        size--;
        
        int parentIndex = 0;
        int leftChildIndex = 2 * parentIndex + 1;
        int rightChildIndex = 2 * parentIndex + 2;
        
        while(leftChildIndex < size) {
            int minElementIndex = parentIndex;
            
            if(arr[minElementIndex] > arr[leftChildIndex]) minElementIndex = leftChildIndex;
            if(rightChildIndex < size && arr[minElementIndex] > arr[rightChildIndex]) minElementIndex = rightChildIndex;
            
            if(minElementIndex == parentIndex) break;
            
            int temp = arr[minElementIndex];
            arr[minElementIndex] = arr[parentIndex];
            arr[parentIndex] = temp;
            
            parentIndex = minElementIndex;
            leftChildIndex = 2 * parentIndex + 1;
        	rightChildIndex = 2 * parentIndex + 2;
        }
    }
}


void heapSort(int arr[], int n) {
    // Write your code
    upHeapifyToBuildHeap(arr, n);
    downHeapifyToSort(arr, n);
}