/* Write a recursive function to convert a given string into the number it represents.
 That is input will be a numeric string that contains only numbers,
 you need to convert the string into corresponding integer and return the answer. */

#include <iostream>
#include <cstring>
#include <math.h>
using namespace std;

 int stringToNumber(char input[]) {
    if(input[1] == '\0') return input[0] - '0';
    int small = stringToNumber(input+1);
    int multiplier = (int)(pow(10.0, (double)(strlen(input+1)) ));
    return (input[0] - '0') * multiplier + small;
}