#include <iostream>
#include <unordered_map>
using namespace std;


int getPairsWithDifferenceK(int *arr, int n, int k) {
	unordered_map<int,int> freqMap; // number, freq
    int countOfPairs = 0;
    
    for(int i=0; i<n; i++){
        freqMap[arr[i]]++;
    }
    
    for(int i=0; i<n; i++){
        int ele1 = arr[i] + k, ele2 = arr[i] - k;
        
        if(ele1 == ele2){
            countOfPairs += ( (freqMap[arr[i]] - 1) * freqMap[arr[i]] )/2;
            break;
        }
        
        if(freqMap.count(ele1) > 0){
            countOfPairs += freqMap[arr[i]] * freqMap[ele1];
        }
        
        if(freqMap.count(ele2) > 0){
            countOfPairs += freqMap[arr[i]] * freqMap[ele2];
        }
        
        freqMap.erase(arr[i]);
    }
    
    return countOfPairs;
}