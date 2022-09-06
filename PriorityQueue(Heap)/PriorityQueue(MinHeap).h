#include <vector>

// We can use a template to make it generic
template<typename T>

class PriorityQueue {
    vector<int> pq; // Min Heap

    public: 

    PriorityQueue() {

    }

    bool isEmpty() {
        return pq.size() == 0;
    }

    // Number of elements in pq;
    int getSize() {
        return pq.size();
    }

    int getMin() {
        if(pq.isEmpty()) return -1;
        return pq[0];
    }

    // This is also the code for heap sort, we store elements in a heap
    // and then remove them in an ascending sorted order

    // T.C: O(NlogN) for inserting N elements
    //      O(NlogN) for removing N elements
    // so total time complexity = O(NlogN)

    // S.C: O(N)

    void insert(int data) {
        pq.push_back(data);

        int childIndex = pq.size() - 1;

        // Up-Heapify
        while(childIndex > 0) {
            int parentIndex = (childIndex - 1) / 2;

            if(pq[childIndex] < pq[parentIndex]) {
                int temp = pq[childIndex];
                pq[childIndex] = pq[parentIndex];
                pq[parentIndex] = temp;
            } else {
                break; // If we don't have to go till root to establish heap order property
            }

            childIndex = parentIndex;
        }
    }

    int pop() {
        if(pq.isEmpty()) return -1;
        int ans = pq[0];
        pq[0] = pq[pq.size()-1];
        pq.pop_back();

        int parentIndex = 0;
        int leftChildIndex = 2 * parentIndex + 1;
        int rightChildIndex = 2 * parentIndex + 2;

        // Down heapify
        while(leftChildIndex < pq.size()) {
            int minIndex = parentIndex;
            if(pq[minIndex] > pq[leftChildIndex]) minIndex = leftChildIndex;
            if(rightChildIndex < pq.size() &&
             pq[minIndex] > pq[rightChildIndex]) minIndex = rightChildIndex;

            if(parentIndex == minIndex) break; // H.O.P. established

            int temp = pq[minIndex];
            pq[minIndex] = pq[parentIndex];
            pq[parentIndex] = temp;

            parentIndex = minIndex;
            leftChildIndex = 2 * parentIndex + 1;
            rightChildIndex = 2 * parentIndex + 2;
        }

        return ans;
    }
}