
void merge(int array[], int const left, int const mid, int const right) {
    // Size of two subarrays
    int sizeOFSubArrayOne = mid - left + 1;
    int sizeOFSubArrayTwo = right - mid;
    
    // temp two subarrays
    int subArrayOne[sizeOFSubArrayOne];
    int subArrayTwo[sizeOFSubArrayTwo];
    
    // copy every element from main array to two divided subarrays
    for(int i=0; i<sizeOFSubArrayOne; i++) {  // from left to mid
        subArrayOne[i] = array[left + i];
    }
    for(int i=0; i<sizeOFSubArrayTwo; i++) { // from mid+1 to end
        subArrayTwo[i] = array[mid+1 + i];
    }
    
    
    // transfer elements in subarray 1 and 2 to their proper place in main array
    int indexOfSubarrayOne = 0, indexOfSubarrayTwo = 0, indexOfMergedArray = left;
    
    while(indexOfSubarrayOne < sizeOFSubArrayOne && indexOfSubarrayTwo < sizeOFSubArrayTwo) {
        if(subArrayOne[indexOfSubarrayOne] <= subArrayTwo[indexOfSubarrayTwo]) {  // if element of subarray 1 at that idx is smaller than ele which is there at same idx in subarray 2
            array[indexOfMergedArray] = subArrayOne[indexOfSubarrayOne];  // put that element in main array
            indexOfSubarrayOne++;  //  increase the idx of that subarray whose ele got selected
        } else {
            array[indexOfMergedArray] = subArrayTwo[indexOfSubarrayTwo];
            indexOfSubarrayTwo++;
        }
        indexOfMergedArray++;  // as the the place at that idx is filled
    }
    
    
    // if the subarrays are unequally divided in case the main array has odd number of elements
    
    // copy the remaining elements of subarray 1
    while(indexOfSubarrayOne < sizeOFSubArrayOne){
        array[indexOfMergedArray] = subArrayOne[indexOfSubarrayOne];
        indexOfSubarrayOne++;
        indexOfMergedArray++;
    }
    
    // copy the remaining elements of subarray 1
    while(indexOfSubarrayTwo < sizeOFSubArrayTwo){
        array[indexOfMergedArray] = subArrayTwo[indexOfSubarrayTwo];
        indexOfSubarrayTwo++;
        indexOfMergedArray++;
    }
}

void mergeSortHelper(int input[], int start, int end) {
    if(start >= end) return;  // if input array is empty or have just one element
    
    int mid = start + (end-start)/2;
    
    mergeSortHelper(input, start, mid);
    mergeSortHelper(input, mid+1, end);
    merge(input, start, mid, end);
}


void mergeSort(int input[], int size){
	// Write your code here
    
    mergeSortHelper(input, 0, size-1);
}
