/*
Write a macro function C to find the square of given number.

Input: 5
Output: The square of 5 is 25

Input: -2
Output: The square of -2 is 4

Input: 9
Output: The square of 9 is 81

*/

#include <stdio.h>
//macro to calculate square of given number.
#define SQUARE(x) ((x) * (x))

int main() {
    int num = -2;
    int result = SQUARE(num); //store the result in variable
    printf("The square of %d is %d.\n", num, result);

    return 0;
}

/*
This program defines a macro function SQUARE that calculates the square of a number.
The macro is used to square the num variable.
*/
