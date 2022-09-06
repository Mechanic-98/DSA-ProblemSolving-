/* Q. Given a string, compute recursively a new string where all 
appearances of "pi" have been replaced by "3.14". */

#include <iostream>
#include <cstring>
using namespace std;

void replacePi(char input[]) {
	
    if(input[0] == '\0' || input[1] == '\0') return;
    
    replacePi(input+1);
    
    if(input[0] == 'p' && input[1] == 'i') {
        for (int i = strlen(input); i >= 2; i--) {  // shifting all elements from idx:2, by 2 places
            input[i + 2] = input[i];
        }
 
        // Replacing with "3.14"
        input[0] = '3';
        input[1] = '.';
        input[2] = '1';
        input[3] = '4';
    }

}