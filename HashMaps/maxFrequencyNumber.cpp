#include <iostream>
#include <unordered_map>
#include <climits>
using namespace std;

int highestFrequency(int arr[], int n) {
    if(n == 0) return INT_MIN;
    unordered_map<int,int> freq; // number, freq
    
    int maxFreqEle = INT_MIN;
    
    for(int i=0; i<n; i++)freq[arr[i]]++;
    
    for(int i=0; i<n ; i++) if( freq[arr[i]] > freq[maxFreqEle] ) maxFreqEle = arr[i];
    
    return maxFreqEle;
}