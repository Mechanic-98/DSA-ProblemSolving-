/*
Given an integer n, using phone keypad find out and 
print all the possible strings that can be made using digits of input n.
 */

#include <iostream>
#include <string>
using namespace std;

void printKeypadHelper(int num, string output) {
    if(num == 0) {
        cout<<output<<endl;
        return;
    }
    string keypadArray[] = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
    int n = num%10;
    string input = keypadArray[n];
    num = num/10;
    for(int i=0; i<input.size(); i++) {
        printKeypadHelper(num, input[i] + output);
    }
}

void printKeypad(int num){
    /*
    Given an integer number print all the possible combinations of the keypad. 
    You do not need to return anything just print them.
    */
    string output = "";
    printKeypadHelper(num, output);
}

int main(){
    int num;
    cin >> num;

    printKeypad(num);

    return 0;
}