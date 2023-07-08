/*
Implement C Program to calculate Simple Interest Calculation using Inline Function

Note the formula:
Simple Interest=(principal * rate * time) / 100

Input:  Enter principal amount: 220000
        Enter rate of interest: 11
        Enter time in years: 3

Output: Simple Interest is: 72600.00

*/

#include <stdio.h>

static inline float calculateSimpleInterest(float principal, float rate, int time) {
    return (principal * rate * time) / 100; //calculate simple interest
}

int main() {
    float principal, rate;
    int time;

    //input principal
    printf("Enter principal amount: ");
    scanf("%f", &principal);

    //input rate of interest
    printf("Enter rate of interest: ");
    scanf("%f", &rate);

    //input years
    printf("Enter time in years: ");
    scanf("%d", &time);

    float interest = calculateSimpleInterest(principal, rate, time);

    printf("Simple Interest is: %.2f\n", interest);

    return 0;
}

/*
This program calculates the simple interest based on the principal amount, rate of interest, and time using an inline function
calculateSimpleInterest(). The user is prompted to enter the required values, and the calculateSimpleInterest() function is called
to compute the simple interest.
The resulting interest value is then displayed on the screen.
*/
