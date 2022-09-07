#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

/* 
if it was about removing duplicates characters then we could have used array
to store presence (size: 256)
but integers can have any value thus we have used unordered_map. 
*/


// O(N)
vector<int> removeDuplicates(int * arr, int n) {
    vector<int> output;
    unordered_map<int, bool> seen;

    for(int i=0; i<n; i++) {
        if(seen.count(arr[i]) > 0) continue;

        seen[arr[i]] = true;
        output.push_back(arr[i]);
    }

    return output;
}