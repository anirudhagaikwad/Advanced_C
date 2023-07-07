/*
C Program to identify valid range of the given number by defining upper and lower limits
using preprocessor directive.

Constants should defined in program
MAX_VALUE=100
MIN_VALUE=0

Input: 50
Output: Value is within the valid range.

Input: 150
Output: Value exceeds maximum limit..

Input: -10
Output: Value is below minimum limit.

*/

#include <stdio.h>

#define MAX_VALUE 100
#define MIN_VALUE 0

void check(int value){
     // This is a conditional statement using preprocessor directives
    #if (value > MAX_VALUE)
        printf("Value exceeds maximum limit.\n");
    #elif (value < MIN_VALUE)
        printf("Value is below minimum limit.\n");
    #else
        printf("Value is within the valid range.\n");
    #endif
}

int main() {
    int value = 50;  // variable initialization
    check(value);
    return 0;
}

/*
In this  program, we include the standard library stdio.h.
We define two constants, MAX_VALUE and MIN_VALUE, using the #define preprocessor directive.
These constants represent the maximum and minimum allowed values.

*/
