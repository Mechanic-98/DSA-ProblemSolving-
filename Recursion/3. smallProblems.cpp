#include <iostream>
#include <math.h>
#include <algorithm>
#include <cstring>
using namespace std;

int power(int x, int n) {
    
    if(n == 0) return 1;
    return x * power(x,n-1);

}

void printAscendingOrder(int n){
    if(n==1) {
        cout<<1<<" ";
        return;
    }
    printAscendingOrder(n-1);
    cout<<n<<" ";
}

int countNumberOfDigits(int n){
    
    if(n==0) return 0;
    return countNumberOfDigits(n/10) + 1;
}

int sumOfArray(int input[], int n) {

    if(n==1) return input[0];
    return  input[0] + sumOfArray(input + 1, n-1);

}

bool checkIfNumberIsPresent(int input[], int size, int x) {
    
    if(size == 1) return input[0] == x;
    return (input[0] == x) || checkIfNumberIsPresent(input + 1, size -1, x);

}

int firstIndexOfNumber(int input[], int size, int x) {

    if(size == 0) return -1;
    if(input[0] == x) return 0;
    int ansFromRemArray = firstIndexOfNumber(input + 1, size - 1, x);
    return (ansFromRemArray == -1) ? ansFromRemArray : ansFromRemArray + 1;
}

int lastIndexOfNumber(int input[], int size, int x) {

    if(size == 0) return -1;
    int ansFromRemArray = lastIndexOfNumber(input + 1, size -1, x);
    
    if(ansFromRemArray == -1) {
        return (input[0] == x) ? 0 : ansFromRemArray;
    }
    return ansFromRemArray + 1;

}

int allIndexesOfNumber(int input[], int size, int x, int output[]) {

    if(size == 0) return 0;
    int ansFromSmall = allIndexesOfNumber(input +1, size - 1, x, output);
    
    if(input[0] == x){
        for(int i=ansFromSmall-1; i>=0; i--){  // shift elements to the right.
        	output[i+1] = output[i]+1;
    	}
        output[0] = 0;
        ansFromSmall++;
    } else {
        for(int i=ansFromSmall-1; i>=0; i--){  
        	output[i]++; // As starting index is now shifted to left.
    	}
        
    }
    
    return ansFromSmall;

}

int countZeros(int n) {  
    if(n <= 9) return (n == 0) ? 1 : 0;
    return (n % 10 == 0) ? (countZeros(n/10) + 1) : countZeros(n/10);
}

int multiplyNumbers(int m, int n) {
    if(m==0 || n==0) return 0;
    return  multiplyNumbers(m,n-1) + m;
}

double geometricSum(int k) {

    // 1 + 1/2 + 1/4 + 1/8 + ... + 1/(2^k) 

    if(k == 0) return 1.0;
    double small = geometricSum(k-1);
    return (1.0/pow(2,k)) + small;
}

bool checkPalindrome(char input[]) {
    int len = strlen(input);
    if(len <= 1) return true;
    if(input[0] != input[len-1]){
        return false;
    }
    input[len-1] = '\0';
    return checkPalindrome(input + 1);
}

int sumOfDigits(int n) {
    if(n==0) return 0;
    return (n%10) + sumOfDigits(n/10);
}