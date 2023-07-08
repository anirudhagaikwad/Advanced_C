/*
You are tasked with implementing an undo-redo stack system using two stacks: undoStack and redoStack.
The system should allow users to perform undo and redo operations for a sequence of operations.

Example:
Enter an operation (Undo/Redo/Exit): A
Enter an operation (Undo/Redo/Exit): B
Enter an operation (Undo/Redo/Exit): Undo
Performing Undo for operation: B
Enter an operation (Undo/Redo/Exit): C
Enter an operation (Undo/Redo/Exit): Redo
Performing Redo for operation: B
Enter an operation (Undo/Redo/Exit): Redo
Redo stack is empty. Cannot perform Redo
Enter an operation (Undo/Redo/Exit): Exit
Exiting...

*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 100

struct Stack {
    char arr[MAX_SIZE][MAX_SIZE];
    int top;
};

// Function to initialize an empty stack
void initializeStack(struct Stack* stack) {
    stack->top = -1;
}

// Function to check if the stack is empty
int isEmpty(struct Stack* stack) {
    return stack->top == -1;
}

// Function to check if the stack is full
int isFull(struct Stack* stack) {
    return stack->top == MAX_SIZE - 1;
}

// Function to push an element onto the stack
void push(struct Stack* stack, char* element) {
    if (isFull(stack)) {
        printf("Stack overflow. Cannot push element %s\n", element);
        return;
    }
    strcpy(stack->arr[++stack->top], element);
}

// Function to pop the top element from the stack
char* pop(struct Stack* stack) {
    if (isEmpty(stack)) {
        printf("Stack underflow. Cannot pop element\n");
        return NULL;
    }
    return stack->arr[stack->top--];
}

// Function to perform Undo operation
void performUndo(struct Stack* undoStack, struct Stack* redoStack) {
    if (isEmpty(undoStack)) {
        printf("Undo stack is empty. Cannot perform Undo\n");
        return;
    }

    char* operation = pop(undoStack);
    printf("Performing Undo for operation: %s\n", operation);
    push(redoStack, operation);
}

// Function to perform Redo operation
void performRedo(struct Stack* undoStack, struct Stack* redoStack) {
    if (isEmpty(redoStack)) {
        printf("Redo stack is empty. Cannot perform Redo\n");
        return;
    }

    char* operation = pop(redoStack);
    printf("Performing Redo for operation: %s\n", operation);
    push(undoStack, operation);
}

int main() {
    struct Stack undoStack;
    initializeStack(&undoStack);

    struct Stack redoStack;
    initializeStack(&redoStack);

    char operation[MAX_SIZE];

    while (1) {
        printf("Enter an operation (Undo/Redo/Exit): ");
        fgets(operation, MAX_SIZE, stdin);
        operation[strcspn(operation, "\n")] = '\0'; // Remove trailing newline character

        if (strcmp(operation, "Undo") == 0) {
            performUndo(&undoStack, &redoStack);
        } else if (strcmp(operation, "Redo") == 0) {
            performRedo(&undoStack, &redoStack);
        } else if (strcmp(operation, "Exit") == 0) {
            printf("Exiting...\n");
            break;
        } else {
            push(&undoStack, operation);
        }
    }

    return 0;
}


/*
 This program uses two stacks to implement Undo and Redo operations.
 It allows the user to perform Undo and Redo operations by pushing the respective operations onto the stacks.
 The program continues to accept operations until the user chooses to exit.

*/
