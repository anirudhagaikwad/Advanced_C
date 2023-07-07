/*
C Program to check if number is even or odd using macro.

Input: 10
Output: 10 is even

Input: 99
Output: 99 is odd

Input: 0
Output: 0 is even

*/

#include <stdio.h>

// Macro to check if a number is even
#define IS_EVEN(num) ((num % 2) == 0)


void check(int num){
    if (IS_EVEN(num)) { // Check if the number is even
        printf("%d is even.", num);
    } else {
        printf("%d is odd.", num);
    }
}
int main() {
    int num = 0;

    check(num);

    return 0;
}

/*

we have a simple macro IS_EVEN defined using the preprocessor
directive #define.
It takes a number as input and uses the modulo operator
to check if the number is divisible by 2 (i.e., even).
The result of the check is used in an if-else statement to
print the appropriate message.

*/
