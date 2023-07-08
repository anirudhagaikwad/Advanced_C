/*
Implement C Program to calculate Fibonacci Series using Inline Function.

Input: Enter the number of terms: 5
Output: Fibonacci Series up to 5 terms: 0 1 1 2 3

*/

#include <stdio.h>

static inline void generateFibonacci(int limit) {
    //initial terms are 0 and 1 by default
    int num1 = 0, num2 = 1, nextTerm;

    printf("Fibonacci Series up to %d terms: ", limit);

    for (int i = 1; i <= limit; i++) {
        printf("%d ", num1);
        nextTerm = num1 + num2; //calculate next term by adding previous two
        num1 = num2;
        num2 = nextTerm;
    }

    printf("\n");
}

int main() {
    int terms;

    printf("Enter the number of terms: ");
    scanf("%d", &terms);

    generateFibonacci(terms);

    return 0;
}

/*
This program generates the Fibonacci series up to a specified number of terms using an inline function generateFibonacci().
The user is prompted to enter the number of terms, and the generateFibonacci() function is called to generate and display the
Fibonacci series based on the provided limit.
*/
