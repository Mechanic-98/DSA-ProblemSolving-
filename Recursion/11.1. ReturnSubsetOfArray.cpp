/***
You need to save all the subsets in the given 2D output array. 
And return the number of subsets(i.e. number of rows filled in output) from the given function.

In ith row of output array, 1st column contains length of the ith subset. 
And from 1st column actual subset follows.
For eg. Input : {1, 2}, then output should contain 
	{{0}, 		// Length of this subset is 0
	{1, 2},		// Length of this subset is 1
	{1, 1},		// Length of this subset is also 1
	{2, 1, 2}}	// Length of this subset is 2

Don’t print the subsets, just save them in output.
***/

#include <iostream>
using namespace std;

int subset(int input[], int n, int output[][20]) {
    // Write your code here
	if(n == 0){
        output[0][0] = 0;
        return 1;
    }
    int lenOfRem = subset(input+1, n-1, output);
    for(int i=0; i<lenOfRem; i++) {
        
        int sizeOfSubset = sizeof(output[i])/sizeof(output[i][0]);
        output[lenOfRem + i][0] = output[i][0] + 1;  // increase the size
        output[lenOfRem + i][1] = input[0];  // puting first element (ele not considered in recursion)
        for(int j=2; j<sizeOfSubset; j++) {  // putting rest of the elements
            output[lenOfRem + i][j] = output[i][j-1];
        }
        
    }
    
    return 2*lenOfRem;
}

int main() {
  int input[20],length, output[35000][20];
  cin >> length;
  for(int i=0; i < length; i++)
    cin >> input[i];
  
  int size = subset(input, length, output);

  for( int i = 0; i < size; i++) { 
	for( int j = 1; j <= output[i][0]; j++) { 
		cout << output[i][j] << " ";
    }
    cout << endl;
  }
}


