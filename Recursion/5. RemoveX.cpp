/* Q. Given a string, compute recursively a new string where 
all 'x' chars have been removed. */

#include <iostream>
#include <cstring>
using namespace std;

void removeX(char input[]) {
    
    if(input[0] == '\0') return;
    removeX(input + 1);

    if(input[0] == 'x'){
        int n = strlen(input);
        if(n == 1){
            input[0] = '\0';
            return;
        }
        for(int i= 1; i<strlen(input); i++) {// shift all elements to the left by 1 place.
            input[i-1] = input[i];
            if(i == strlen(input) - 1){
                input[i] = '\0';
            }
        }
    }
}