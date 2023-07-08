/*
Implement C Program to calculate Power of a Number using Inline Function.

Input:  Enter the base: 5
        Enter the exponent: 3
Output: 5.00 raised to the power of 3 is: 125.00

*/

#include <stdio.h>

static inline double power(double base, int exponent) {
    double result = 1.0;

    //multiply the base by number of exponent times
    while (exponent > 0) {
        result *= base;
        exponent--;
    }

    return result;
}

int main() {
    double base;
    int exponent;

    printf("Enter the base: ");
    scanf("%lf", &base); //input base

    printf("Enter the exponent: ");
    scanf("%d", &exponent); //input exponent

    double result = power(base, exponent);

    printf("%.2lf raised to the power of %d is: %.2lf\n", base, exponent, result);

    return 0;
}

/*
This program calculates the power of a number using an inline function power().
The user is prompted to enter the base and exponent values, and the power() function is called to compute the result based
on the provided values.
The resulting value is then displayed on the screen.
*/
