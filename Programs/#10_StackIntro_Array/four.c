/*
You have given a stack, delete the middle element of the stack without using any additional data structure.
Consider Middle element as:-
ceil((size_of_stack+1)/2)

start counting from bottom of the stack(element at the bottom is first element of stack)

Example:
Before deletion:
Stack: 41 25 33 42 5
Deleted Element: 33
After deletion:
Stack: 41 25 42 5

*/

#include <stdio.h>
#include <stdbool.h>
#define MAX_SIZE 100

int stack[MAX_SIZE];
int top = -1;

void push(int value) {
    if (top == MAX_SIZE - 1) {       // Check if the stack is full
        printf("Stack Overflow\n");  // Print an error message
        return;                      // Return from the function
    }
    stack[++top] = value;            // Increment top and push the value onto the stack
}

int pop() {
    if (top == -1) {                 // Check if the stack is empty
        printf("Stack Underflow\n"); // Print an error message
        return -1;                   // Return -1 to indicate underflow
    }
    return stack[top--];             // Decrement top and return the top element
}

int deleteMiddleElement() {
    int middleIndex = (top + 1) / 2;  // Calculate the index of the middle element
    int deletedElement = stack[middleIndex];  // Store the value of the middle element

    for (int i = middleIndex; i < top; i++)  // Shift all elements after the middle element to the left
        stack[i] = stack[i + 1];

    top--;                            // Decrement top to reflect the removal of the middle element

    return deletedElement;            // Return the deleted element
}

void displayStack() {
    if (top == -1) {                  // Check if the stack is empty
        printf("Stack is empty\n");   // Print a message indicating that the stack is empty
        return;                       // Return from the function
    }

    printf("Stack: ");                // Print a label for the stack

    for (int i = 0; i <= top; i++)     // Iterate through the elements of the stack
        printf("%d ", stack[i]);       // Print each element

    printf("\n");                     // Print a new line after displaying the stack
}

int main() {
    push(41);                          // Push elements onto the stack
    push(25);
    push(33);
    push(42);
    push(5);

    printf("Before deletion:\n");
    displayStack();                   // Display the stack before deletion

    int deletedElement = deleteMiddleElement();  // Delete the middle element and store its value

    printf("Deleted Element: %d\n", deletedElement);  // Print the deleted element

    printf("After deletion:\n");
    displayStack();                   // Display the stack after deletion

    return 0;
}

