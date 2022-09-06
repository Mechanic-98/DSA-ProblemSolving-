/*
Given an integer n, using phone keypad find out all the possible strings that can be made 
using digits of input n.
Return empty string for numbers 0 and 1.

Note : 1. The order of strings are not important.
2. Input and output has already been managed for you. 
You just have to populate the output array and return the count of elements populated in the output array.
 */



#include <iostream>
#include <string>
using namespace std;


int keypad(int num, string output[]){
    /* Insert all the possible combinations of the integer number into the output string array. You do not need to
    print anything, just return the number of strings inserted into the array.
    */
    string keypadArray[] = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
    
    if(num == 0 ) {
        output[0] = "";
        return 1;
    }
    int n = num%10;
    num = num/10;
    int smalloutputsize = keypad(num, output);
    
    string input = keypadArray[n];
    int ans_size = smalloutputsize * (input.size());
    string temp[ans_size]; int k=0;
    
    for(int i=0; i<smalloutputsize; i++) {
        for(int j=0; j<input.size(); j++)  {
            temp[k] = output[i] + input[j] ;
            k++;
        }
    }
    
    for(int i=0; i<ans_size; i++) {
        output[i] = temp[i];
    }
    
    
    return ans_size;
}

int main(){
    int num;
    cin >> num;

    string output[10000];
    int count = keypad(num, output);
    for(int i = 0; i < count && i < 10000; i++){
        cout << output[i] << endl;
    }
    return 0;
}