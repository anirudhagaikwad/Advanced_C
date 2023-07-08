/*
Given a array of string remove the consecutive same words in the array and return number of words in final array.

Input: {"blue", "sky", "sky", "blue", "plants"}
Output: 1

*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 100

struct Stack {
    int top;
    char items[MAX_SIZE][MAX_SIZE];
};

void initialize(struct Stack* stack) {
    stack->top = -1;
}

int isEmpty(struct Stack* stack) {
    return stack->top == -1;
}

int isFull(struct Stack* stack) {
    return stack->top == MAX_SIZE - 1;
}

void push(struct Stack* stack, char* item) {
    if (isFull(stack)) {
        printf("Stack Overflow\n");
        exit(EXIT_FAILURE);
    }
    strcpy(stack->items[++(stack->top)], item);
}

void pop(struct Stack* stack) {
    if (isEmpty(stack)) {
        printf("Stack Underflow\n");
        exit(EXIT_FAILURE);
    }
    stack->top--;
}

int removeConsecutiveSame(char v[][MAX_SIZE], int n) {
    struct Stack stack;
    initialize(&stack);

    // Start traversing the sequence
    for (int i = 0; i < n; i++) {
        // Push the current string if the stack is empty
        if (isEmpty(&stack))
            push(&stack, v[i]);
        else {
            char str[MAX_SIZE];
            strcpy(str, stack.items[stack.top]);

            // Compare the current string with stack top
            // If equal, pop the top
            if (strcmp(str, v[i]) == 0)
                pop(&stack);

            // Otherwise, push the current string
            else
                push(&stack, v[i]);
        }
    }

    // Return stack size
    return stack.top + 1;
}

int main() {
    char V[][MAX_SIZE] = {"blue", "sky", "sky", "blue", "plants"};
    int n = sizeof(V) / sizeof(V[0]);

    printf("%d\n", removeConsecutiveSame(V, n));

    return 0;
}
/*
This program removes consecutive duplicate strings from a given sequence and returns the size of the manipulated sequence.

The Stack structure represents a stack of strings. It keeps track of the top index and the array of string items.
The stack is implemented using an array.

The initialize function initializes the stack by setting the top index to -1.

The isEmpty function checks if the stack is empty by comparing the top index with -1.

The isFull function checks if the stack is full by comparing the top index with the maximum size of the stack.

The push function pushes a string item onto the stack. It first checks if the stack is full and displays an error message if it is.
Otherwise, it increments the top index and copies the string item to the corresponding position in the stack array using strcpy.

The pop function pops the top string item from the stack. It first checks if the stack is empty and displays an error message if it is.

Otherwise, it decrements the top index.

The removeConsecutiveSame function takes an array of strings v and its size n as input. It initializes a stack using the Stack
structure. It then traverses the sequence of strings. For each string, it compares it with the top string in the stack.
If they are equal, it pops the top string from the stack. If they are not equal, it pushes the current string onto the stack.
After traversing the entire sequence, it returns the size of the stack.

The main function demonstrates the usage of the removeConsecutiveSame function. It initializes an array of strings V and its size n.
It calls the removeConsecutiveSame function and prints the result.
*/
