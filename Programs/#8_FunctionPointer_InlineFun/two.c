/*
 Write a C program using Function Pointer to Perform Arithmetic Operations
*/

#include <stdio.h>

int add(int a, int b) {
    return a + b;
}

int subtract(int a, int b) {
    return a - b;
}

int multiply(int a, int b) {
    return a * b;
}

int main() {
    int num1, num2;
    int (*operation)(int, int);

    printf("Enter two numbers: ");
    scanf("%d %d", &num1, &num2);

    // Prompt the user to select an operation
    printf("Select an operation:\n");
    printf("1. Addition\n");
    printf("2. Subtraction\n");
    printf("3. Multiplication\n");
    printf("Enter your choice: ");

    int choice;
    scanf("%d", &choice);

    // Assign the corresponding operation function to the function pointer
    switch (choice) {
        case 1:
            operation = add;
            break;
        case 2:
            operation = subtract;
            break;
        case 3:
            operation = multiply;
            break;
        default:
            printf("Invalid choice.\n");
            return 1;
    }

    // Call the selected operation using the function pointer
    int result = operation(num1, num2);

    printf("Result: %d\n", result);

    return 0;
}
/*
This program demonstrates the usage of a function pointer to perform arithmetic operations on two numbers.
The program defines three arithmetic functions: add, subtract, and multiply. The main function prompts the user
to enter two numbers and selects an operation based on the user's choice. The selected operation function is assigned
to a function pointer named operation, and then the function pointer is used to call the selected operation and
display the result.

*/
