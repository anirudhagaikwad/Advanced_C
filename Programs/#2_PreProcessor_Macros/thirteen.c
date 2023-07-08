/*
C Program to calculate Modulo of given numbers using  macros.

Input: 13,3
Output: Result: 1

Input: 90,8
Output: Result: 2

Input: 17,6
Output: Result: 5

*/
#include <stdio.h>

#define Power(a, b) (a % b)


int main() {
    int result =Power(90,8);

    printf("Result: %d\n", result);

    return 0;
}
