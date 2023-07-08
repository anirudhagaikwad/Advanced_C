/*
Write a C program using Function Pointer to Calculate Factorial of a Number

Input:
Enter a number: 5
Output:
Factorial of 5 is 120
*/

#include <stdio.h>

unsigned long long factorial(int num) {
    if (num == 0) {
        return 1;
    } else {
        return num * factorial(num - 1);
    }
}

int main() {
    int number;

    printf("Enter a number: ");
    scanf("%d", &number);

    // Declare a function pointer and assign the factorial function to it
    unsigned long long (*ptr)(int) = factorial;

    // Call the function using the function pointer
    unsigned long long result = ptr(number);

    printf("Factorial of %d is %llu\n", number, result);

    return 0;
}

/*

 This program demonstrates the usage of a function pointer to calculate the factorial of a number.
 The factorial function is a recursive function that calculates the factorial of a non-negative integer.
 The main function prompts the user to enter a number and assigns the factorial function to a function pointer named ptr.
 The ptr function pointer is then used to call the factorial function, and the result is displayed.
*/
