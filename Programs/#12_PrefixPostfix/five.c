/*
Convert a given infix expression to its corresponding prefix expression using a stack data structure.

Input:
Enter an infix expression: A*B+C/D

Output:
Prefix expression: +*AB/CD

Input:
Enter an infix expression: (a+b)*(c+d)

Output:
Prefix expression: *+ab+cd

*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define SIZE 100

// Structure to represent a stack
struct Stack {
    char arr[SIZE];
    int top;
};

// Function to create an empty stack
struct Stack* createStack() {
    struct Stack* stack = (struct Stack*)malloc(sizeof(struct Stack));
    stack->top = -1;
    return stack;
}

// Function to check if the stack is empty
int isEmpty(struct Stack* stack) {
    return stack->top == -1;
}

// Function to push an element onto the stack
void push(struct Stack* stack, char item) {
    if (stack->top == SIZE - 1) {
        printf("Stack is full");
        return;
    }
    stack->arr[++stack->top] = item;
}

// Function to pop an element from the stack
char pop(struct Stack* stack) {
    if (isEmpty(stack)) {
        printf("Stack is empty");
        return '\0';
    }
    return stack->arr[stack->top--];
}

// Function to return the precedence of an operator
int precedence(char operator) {
    if (operator == '+' || operator == '-')
        return 1;
    else if (operator == '*' || operator == '/')
        return 2;
    else if (operator == '^')
        return 3;
    else
        return -1;
}

// Function to check if a character is an operand
int isOperand(char character) {
    return (character >= 'a' && character <= 'z') ||
           (character >= 'A' && character <= 'Z');
}

// Function to convert infix expression to prefix expression
void infixToPrefix(char infix[], char prefix[]) {
    int infixLen = strlen(infix);
    int prefixIndex = 0;

    // Reverse the infix expression
    char reversedInfix[SIZE];
    for (int i = infixLen - 1; i >= 0; i--) {
        if (infix[i] == '(')
            reversedInfix[infixLen - 1 - i] = ')';
        else if (infix[i] == ')')
            reversedInfix[infixLen - 1 - i] = '(';
        else
            reversedInfix[infixLen - 1 - i] = infix[i];
    }

    // Create an empty stack for operators
    struct Stack* stack = createStack();

    for (int i = 0; i < infixLen; i++) {
        if (isOperand(reversedInfix[i])) {
            prefix[prefixIndex++] = reversedInfix[i];
        } else if (reversedInfix[i] == '(') {
            push(stack, reversedInfix[i]);
        } else if (reversedInfix[i] == ')') {
            while (!isEmpty(stack) && stack->arr[stack->top] != '(') {
                prefix[prefixIndex++] = pop(stack);
            }
            pop(stack); // Pop the '(' from the stack
        } else {
            while (!isEmpty(stack) && precedence(reversedInfix[i]) <= precedence(stack->arr[stack->top])) {
                prefix[prefixIndex++] = pop(stack);
            }
            push(stack, reversedInfix[i]);
        }
    }

    // Pop any remaining operators from the stack
    while (!isEmpty(stack)) {
        prefix[prefixIndex++] = pop(stack);
    }

    prefix[prefixIndex] = '\0';

    // Reverse the prefix expression
    int prefixLen = strlen(prefix);
    for (int i = 0; i < prefixLen / 2; i++) {
        char temp = prefix[i];
        prefix[i] = prefix[prefixLen - 1 - i];
        prefix[prefixLen - 1 - i] = temp;
    }
}

int main() {
    char infix[SIZE];
    printf("Enter an infix expression: ");
    fgets(infix, SIZE, stdin);
    infix[strlen(infix) - 1] = '\0'; // Remove newline character

    char prefix[SIZE];
    infixToPrefix(infix, prefix);
    printf("Prefix expression: %s\n", prefix);

    return 0;
}
