/*
You have given a string string, you need to print the reverse of individual words in string.

Input: Lonavala Lavasa Tamhini

Output: alavanoL asavaL inihmaT
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LENGTH 100

struct Stack {
    int top;
    char items[MAX_LENGTH];
};

// Function to initialize the stack
void initialize(struct Stack* stack) {
    stack->top = -1;
}

// Function to check if the stack is empty
int isEmpty(struct Stack* stack) {
    return stack->top == -1;
}

// Function to check if the stack is full
int isFull(struct Stack* stack) {
    return stack->top == MAX_LENGTH - 1;
}

// Function to push an item onto the stack
void push(struct Stack* stack, char item) {
    if (isFull(stack)) {
        printf("Stack Overflow\n");
        exit(EXIT_FAILURE);
    }
    stack->items[++(stack->top)] = item;
}

// Function to pop an item from the stack
char pop(struct Stack* stack) {
    if (isEmpty(stack)) {
        printf("Stack Underflow\n");
        exit(EXIT_FAILURE);
    }
    return stack->items[(stack->top)--];
}

// Function to reverse individual words of a string
void reverseWords(char* str) {
    struct Stack stack;
    initialize(&stack);

    // Traverse the given string
    for (int i = 0; i < strlen(str); ++i) {
        if (str[i] != ' ')
            push(&stack, str[i]);
        else {
            // Print the contents of the stack until a space is encountered
            while (isEmpty(&stack) == 0) {
                printf("%c", pop(&stack));
            }
            printf(" ");
        }
    }

    // Print the remaining characters in the stack
    while (isEmpty(&stack) == 0) {
        printf("%c", pop(&stack));
    }
}

int main() {
    char str[MAX_LENGTH] = "Lonavala Lavasa Tamhini";
    reverseWords(str);
    return 0;
}
/*
This program reverses the individual words in a given string using a stack data structure.

The struct Stack represents a stack with a top index and an array to store the items.
The functions initialize, isEmpty, isFull, push, and pop are implemented to perform stack operations.

The reverseWords function takes a string as input and traverses it character by character.
It pushes non-space characters onto the stack. When a space is encountered, it prints the contents of the stack (i.e.,
the characters of the word in reverse order) and adds a space. Finally, it prints the remaining characters in the stack.

In the main function, a string is initialized with a given value, and the reverseWords function is called to reverse
the individual words in the string. The result is displayed on the console.

Note that the program assumes a maximum string length of MAX_LENGTH to prevent stack overflow.
*/
