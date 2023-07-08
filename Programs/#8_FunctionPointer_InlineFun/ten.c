/*
Implement C Program to calculate Factorial of a Number using Inline Function.
Constant: PI value is 3.1415

Input:  Enter a positive integer: 5
Output: Factorial of 5 is: 120

*/

#include <stdio.h>

static inline int factorial(int n) {
    if (n <= 1) //if number is return 1
        return 1;
    else
        return n * factorial(n - 1); //call recursively upto base condition
}

int main() {
    int num;

    printf("Enter a positive integer: ");
    scanf("%d", &num);

    int fact = factorial(num);

    printf("Factorial of %d is: %d\n", num, fact);

    return 0;
}
/*
This program calculates the factorial of a given number using an inline function factorial().
The user is prompted to enter a positive integer, and the factorial() function is called to compute the factorial recursively.
The resulting factorial value is then displayed on the screen.
*/

