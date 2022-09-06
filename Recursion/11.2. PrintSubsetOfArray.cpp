#include <iostream>
using namespace std;

void helper(int input[], int size, int output[], int outputSize) {
    if(size == 0) {
        for(int i=0; i<outputSize; i++) {
            cout<<output[i]<<" ";
        }
        cout<<endl;
        return;
    }
    helper(input+1, size-1, output, outputSize);
    
    int temp[outputSize+1];
    
    for(int i=0; i<outputSize; i++) {
        temp[i] = output[i];
    }
    temp[outputSize] = input[0];
    
    
    helper(input+1, size-1, temp, outputSize+1);
}

void printSubsetsOfArray(int input[], int size) {
	// Write your code here
    int outputSize = 0;
    int output[outputSize];
    helper(input, size, output, outputSize);
}