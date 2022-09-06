/* Given a string S, compute recursively a new string where identical chars
 that are adjacent in the original string are separated from each other by a "*". */

#include <iostream>
#include <cstring>
using namespace std;

 void pairStar(char input[]) {
    if(input[0] == '\0' || input[1] == '\0') return;
    
    if(input[0] == input[1]) {
        int len = strlen(input);
        input[len+1] = '\0';  // extending character array.
        for(int i=len-1; i>=1; i--) {  // shifting all elements till idx1 to the right by 1 place.
            input[i+1] = input[i];
        }
        input[1] = '*';
    }
    
    pairStar(input+1);
}