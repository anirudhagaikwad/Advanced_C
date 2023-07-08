/*
Implement C Program to find Maximum of Two Numbers using Inline Function.

Input: Enter two numbers: 54 32
Output: Maximum number is: 54

*/
#include <stdio.h>

//inline function to find maximum of two numbers
static inline int max(int a, int b) {
    return (a > b) ? a : b;
}

int main() {
    int num1, num2;

    printf("Enter two numbers: ");
    scanf("%d %d", &num1, &num2);

    int result = max(num1, num2);

    printf("Maximum number is: %d\n", result);

    return 0;
}
/*
This program uses an inline function max() to calculate the maximum of two numbers.
The user is prompted to enter two numbers, and the max() function is called to determine the maximum value.
The result is then displayed on the screen.
*/
