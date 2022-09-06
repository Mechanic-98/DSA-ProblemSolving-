#include <iostream>
#include <queue>
#include <vector>
using namespace std;

typedef pair<int, pair<int, int> > ppi;

vector<int> mergeKSortedArrays(vector<vector<int>*> input) {
    
    vector<int> output;
    
    priority_queue<ppi, vector<ppi>, greater<ppi> > minHeap;
    
    for (int i = 0; i < input.size(); i++) minHeap.push({ input[i]->at(0), { i, 0 } });
    
    while (minHeap.empty() == false) {
        ppi curr = minHeap.top();
        minHeap.pop();

            // i ==> Array Number
            // j ==> Index in the array number
        int i = curr.second.first;
        int j = curr.second.second;

        output.push_back(curr.first);

            // The next element belongs to same array as
            // current.
        if (j + 1 < input[i]->size()) minHeap.push({ input[i]->at(j + 1), { i, j + 1 } });
    }
    
    return output;
    
}