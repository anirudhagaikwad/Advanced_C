//Implement a stack data structure using an Structure and perform push, pop, and display operations.
#include <stdio.h>
#include <stdlib.h>
#define MAX_SIZE 100

// Structure to represent a stack
struct Stack {
    int items[MAX_SIZE];
    int top;
};

// Initialize a new stack
void initialize(struct Stack *stack) {
    stack->top = -1;
}

// Check if the stack is empty
int isEmpty(struct Stack *stack) {
    return stack->top == -1;
}

// Check if the stack is full
int isFull(struct Stack *stack) {
    return stack->top == MAX_SIZE - 1;
}

// Push an item onto the stack
void push(struct Stack *stack, int value) {
    if (isFull(stack)) {
        printf("Stack overflow! Cannot push %d\n", value);
    } else {
        stack->top++;
        stack->items[stack->top] = value;
    }
}

// Pop an item from the stack
int pop(struct Stack *stack) {
    if (isEmpty(stack)) {
        printf("Stack underflow! Cannot pop\n");
        return -1; // Return a sentinel value
    } else {
        int poppedItem = stack->items[stack->top];
        stack->top--;
        return poppedItem;
    }
}

// Peek at the top item of the stack without removing it
int peek(struct Stack *stack) {
    if (isEmpty(stack)) {
        printf("Stack is empty\n");
        return -1; // Return a sentinel value
    } else {
        return stack->items[stack->top];
    }
}


void display(struct Stack *stack) {
    if (isEmpty(stack)) {
        printf("Stack is empty\n");
    } else {
        printf("Stack elements: ");
        for (int i = 0; i <= stack->top; i++) {
            printf("%d ", stack->items[i]);
        }
        printf("\n");
    }
}

int main() {
    struct Stack stack;
    initialize(&stack);

    push(&stack, 10);
    push(&stack, 20);
    push(&stack, 30);
    
    display(&stack);
    printf("Top element: %d\n", peek(&stack));

    printf("Popped element: %d\n", pop(&stack));
    printf("Popped element: %d\n", pop(&stack));

    printf("Top element: %d\n", peek(&stack));

    return 0;
}




/*
The `top` variable being initialized as `-1` in the stack structure is a common convention to indicate an empty stack. The `top` variable keeps track of the index of the top element in the stack. In this convention:

- When the stack is empty, `top` is `-1` because there are no elements in the stack.
- When you push an element onto the stack, you increment `top` to `0`, indicating that the first element is at index `0`.
- When you push more elements onto the stack, you continue to increment `top`, so the top element is always at index `top`.

By initializing `top` to `-1`, you ensure that the stack starts out empty and that the first pushed element will be at index `0`, as expected. When `top` is `-1`, the stack is effectively considered empty, and when you increment it to `0`, the stack starts having elements.

This convention makes it easy to manage the stack and implement push and pop operations without needing to manage special cases for an empty stack.
*/
