/*
Write a program that aims to create a simple calculator that performs basic arithmetic calculations on two numbers.
It uses a structure called Calculator to store the two numbers. The user is prompted to enter the numbers,
and the program calculates and displays the sum, difference, product, and quotient of the numbers.

Example:
Enter first number: 43
Enter second number: 98

Calculator Results
Sum: 141.00
Difference: -55.00
Product: 4214.00
Quotient: 0.44

*/
#include <stdio.h>

// Structure to store two numbers for calculations
struct Calculator {
    float num1;
    float num2;
};

int main() {
    struct Calculator calculator;

    // Prompting the user to enter the first number
    printf("Enter first number: ");
    scanf("%f", &calculator.num1);

    // Prompting the user to enter the second number
    printf("Enter second number: ");
    scanf("%f", &calculator.num2);

    // Calculating the sum of the two numbers
    float sum = calculator.num1 + calculator.num2;

    // Calculating the difference between the two numbers
    float difference = calculator.num1 - calculator.num2;

    // Calculating the product of the two numbers
    float product = calculator.num1 * calculator.num2;

    // Calculating the quotient of the two numbers
    float quotient = calculator.num1 / calculator.num2;

    // Displaying the results of the calculations
    printf("\nCalculator Results\n");
    printf("Sum: %.2f\n", sum);
    printf("Difference: %.2f\n", difference);
    printf("Product: %.2f\n", product);
    printf("Quotient: %.2f\n", quotient);

    return 0;
}
/*
This program performs basic arithmetic calculations on two numbers. It uses a structure called Calculator
to store the two numbers. The user is prompted to enter the numbers,and the program calculates and
displays the sum, difference, product, and quotient of the numbers.
*/
