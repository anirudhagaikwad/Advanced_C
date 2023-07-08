#include <stdio.h>

/* Implement addition of complex numbers using structures.
 Each complex number has a real part and an imaginary part.

Input:

Enter first complex number:
Real part: 3
Imaginary part: 2

Enter second complex number:
Real part: 1
Imaginary part: 2

Output:
Sum of complex numbers: 4.00 + 4.00i

*/

// Structure definition for Complex Number
struct Complex {
    float real;
    float imaginary;
};

// Function to add two complex numbers
struct Complex addComplex(struct Complex num1, struct Complex num2) {
    struct Complex result;
    result.real = num1.real + num2.real;
    result.imaginary = num1.imaginary + num2.imaginary;
    return result;
}

int main() {
    // Creating complex number structure variables
    struct Complex num1, num2, sum;

    // Inputting complex numbers
    printf("Enter first complex number:\n");
    printf("Real part: ");
    scanf("%f", &num1.real);
    printf("Imaginary part: ");
    scanf("%f", &num1.imaginary);
    printf("\n");

    printf("Enter second complex number:\n");
    printf("Real part: ");
    scanf("%f", &num2.real);
    printf("Imaginary part: ");
    scanf("%f", &num2.imaginary);
    printf("\n");

    // Adding complex numbers
    sum = addComplex(num1, num2);

    // Displaying the result
    printf("Sum of complex numbers: %.2f + %.2fi\n", sum.real, sum.imaginary);

    return 0;
}
/*
This program implements the addition of complex numbers using structures.
Each complex number has a real part and an imaginary part.
The program allows the user to input two complex numbers, adds them together using a separate function, and then displays the sum of the complex numbers.

*/
