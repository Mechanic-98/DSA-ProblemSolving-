/* Given a string S, remove consecutive duplicates from it recursively. eg: aabccba -> abcba */

#include <iostream>
using namespace std;

void removeConsecutiveDuplicates(char *input) {
    
    if(input[0] == '\0') return;
    
    if(input[0] == input[1]) {
        int i=1;
        for(; input[i] != '\0'; i++) {
            input[i-1] = input[i];
        }
        input[i-1] = input[i];
        removeConsecutiveDuplicates(input);
    } else {
        removeConsecutiveDuplicates(input+1);
    }


}

int main() {
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    
    char s[100000];
    cin >> s;
    removeConsecutiveDuplicates(s);
    cout << s << endl;
}