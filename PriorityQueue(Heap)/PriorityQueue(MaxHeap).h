#include <vector>
#include <climits>

class PriorityQueue {
    vector<int> pq;

   public:
    PriorityQueue() {
        
    }

    void insert(int element) {
        pq.push_back(element);

        int childIndex = pq.size() - 1;

        while(childIndex > 0) {
            int parentIndex = (childIndex - 1) / 2;

            if(pq[parentIndex] < pq[childIndex]) {
                int temp = pq[childIndex];
                pq[childIndex] = pq[parentIndex];
                pq[parentIndex] = temp;
            } else break;

            childIndex = parentIndex;
        }
    }

    int getMax() {
        if(isEmpty()) return INT_MIN;

        return pq[0];
    }

    int removeMax() {
        if(isEmpty()) return INT_MIN;

        int ans = pq[0];
        pq[0] = pq[pq.size() -1];
        pq.pop_back();

        int parentIndex = 0;
        int leftChildIndex = 2 * parentIndex + 1;
        int rightChildIndex = 2 * parentIndex + 2;

        // Down-Heapify
        while( leftChildIndex < pq.size()){
            int maxIndex = parentIndex;

            if(pq[maxIndex] < pq[leftChildIndex]) maxIndex = leftChildIndex;
            if(rightChildIndex < pq.size() &&
             pq[maxIndex] < pq[rightChildIndex]) maxIndex = rightChildIndex;
            
            if(parentIndex == maxIndex) break;

            int temp = pq[maxIndex];
            pq[maxIndex] = pq[parentIndex];
            pq[parentIndex] = temp;

            parentIndex = maxIndex;
            leftChildIndex = 2 * parentIndex + 1;
            rightChildIndex = 2 * parentIndex + 2;
        }

        return ans;
    }

    int getSize() { 
        return pq.size();
    }

    bool isEmpty() {
        return pq.size() == 0;
    }
};