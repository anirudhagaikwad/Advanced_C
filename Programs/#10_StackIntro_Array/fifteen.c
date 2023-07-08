/*
Implement a C program to  which can get the maximum value in the stack in O(1) time without using an additional stack.

*/
#include <stdio.h>
#include <stdlib.h>

// Structure to represent a block in the stack
struct Block {
    int value;      // Value of the block
    int localMax;   // Local maximum value in the stack until this block
};

// Structure to represent the stack
typedef struct {
    struct Block* S;    // Array of blocks
    int size;           // Maximum size of the stack
    int top;            // Index of the top block in the stack
} Stack;

// Function to create a stack of a given size
Stack* createStack(int size) {
    Stack* stack = (Stack*)malloc(sizeof(Stack));                        // Allocate memory for the stack structure
    stack->S = (struct Block*)malloc(size * sizeof(struct Block));       // Allocate memory for the blocks array
    stack->size = size;                                                  // Set the maximum size of the stack
    stack->top = -1;                                                     // Initialize the top index to -1 (empty stack)
    return stack;
}

// Function to push an element onto the stack
void push(Stack* stack, int n) {
    if (stack->top == stack->size - 1) {                                 // Check if the stack is already full
        printf("Stack is full\n");
    }
    else {
        stack->top++;                                                    // Increment the top index

        if (stack->top == 0) {                                            // If it's the first element in the stack
            stack->S[stack->top].value = n;                               // Set the value of the block
            stack->S[stack->top].localMax = n;                            // Set the local maximum as the value itself
        }
        else {
            if (stack->S[stack->top - 1].localMax > n) {                   // If the previous block has a higher local maximum
                stack->S[stack->top].value = n;                            // Set the value of the block
                stack->S[stack->top].localMax = stack->S[stack->top - 1].localMax;    // Set the local maximum same as the previous block
            }
            else {
                stack->S[stack->top].value = n;                            // Set the value of the block
                stack->S[stack->top].localMax = n;                         // Set the local maximum as the value itself
            }
        }

        printf("%d inserted in stack\n", n);
    }
}

// Function to pop an element from the stack
void pop(Stack* stack) {
    if (stack->top == -1) {                                              // Check if the stack is empty
        printf("Stack is empty\n");
    }
    else {
        stack->top--;                                                    // Decrement the top index
        printf("Element popped\n");
    }
}

// Function to find the maximum element in the stack
void max(Stack* stack) {
    if (stack->top == -1) {                                              // Check if the stack is empty
        printf("Stack is empty\n");
    }
    else {
        printf("Maximum value in the stack: %d\n", stack->S[stack->top].localMax);   // Print the local maximum of the top block
    }
}

int main() {
    Stack* S1 = createStack(5);                                          // Create a stack of size 5

    push(S1, 2);
    max(S1);
    push(S1, 6);
    max(S1);
    pop(S1);
    max(S1);

    return 0;
}

/*
The code defines a stack data structure implemented using an array of blocks. The createStack function is used to create a stack of
a given size.
The push function is used to push an element onto the stack, maintaining the local maximum at each block. The pop function is used
to remove an element from the top of the stack. The max function is used to find and print the maximum value in the stack.

In the main function, a stack S1 of size 5 is created. Elements are then pushed onto the stack, and the maximum value in the stack
is printed after each operation.
*/
