/*
C Program to Find Maximum of two numbers using predefined macros.

Input: 5,10
Output: The maximum number is: 10

Input: 98, 9890
Output: The maximum number is: 9890

Input: 8, -8
Output: The maximum number is: 8


*/

#include <stdio.h>

#define MAX(a, b) ((a) > (b) ? (a) : (b))

int main() {
    int x = 8, y = -8;
    int max = MAX(x, y);
    printf("The maximum number is: %d\n", max);

    return 0;
}

/*
This program demonstrates how to find the maximum of two numbers using a macro.
The MAX macro uses the ternary operator to compare the values of a and b and returns the larger one.
*/
