/*
Write a C program using Function Pointer to Calculate the Square of a Number

Input:
Enter a number: 9

Output:
Square of 9 is 81

*/

#include <stdio.h>

int square(int num) {
    return num * num;
}

int main() {
    int number;

    printf("Enter a number: ");
    scanf("%d", &number);

    // Declare a function pointer and assign the square function to it
    int (*ptr)(int) = square;

    // Call the function using the function pointer
    int result = ptr(number);

    printf("Square of %d is %d\n", number, result);

    return 0;
}

/*
 This program demonstrates the usage of a function pointer to calculate the square of a number.
 The square function takes an integer as input and returns the square of that number.
 The main function prompts the user to enter a number and assigns the square function to a function pointer
 named ptr. The ptr function pointer is then used to call the square function, and the result is displayed.
*/
