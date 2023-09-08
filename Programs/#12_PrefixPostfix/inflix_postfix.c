#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_SIZE 100

// Stack implementation
struct Stack {
    int top;
    char items[MAX_SIZE];
};

// Function to initialize an empty stack
void initialize(struct Stack* stack) {
    stack->top = -1;
}

// Function to check if the stack is empty
int isEmpty(struct Stack* stack) {
    return stack->top == -1;
}

// Function to push a character onto the stack
void push(struct Stack* stack, char value) {
    if (stack->top == MAX_SIZE - 1) {
        printf("Stack overflow!\n");
        exit(1);
    }
    stack->items[++stack->top] = value;
}

// Function to pop a character from the stack
char pop(struct Stack* stack) {
    if (isEmpty(stack)) {
        printf("Stack underflow!\n");
        exit(1);
    }
    return stack->items[stack->top--];
}

// Function to check if a character is an operator (+, -, *, /)
int isOperator(char c) {
    return (c == '+' || c == '-' || c == '*' || c == '/');
}

// Function to get the precedence of an operator
int getPrecedence(char c) {
    if (c == '+' || c == '-')
        return 1;
    if (c == '*' || c == '/')
        return 2;
    return 0; // Parentheses have the highest precedence
}

// Function to convert infix expression to postfix expression
void infixToPostfix(char* infixExpression, char* postfixExpression) {
    struct Stack stack;
    initialize(&stack);
    int postfixIndex = 0;

    for (int i = 0; infixExpression[i]; i++) {
        char currentChar = infixExpression[i];

        if (isdigit(currentChar)) {
            postfixExpression[postfixIndex++] = currentChar;
        } else if (currentChar == '(') {
            push(&stack, currentChar);
        } else if (currentChar == ')') {
            while (!isEmpty(&stack) && stack.items[stack.top] != '(') {
                postfixExpression[postfixIndex++] = pop(&stack);
            }
           
            if (!isEmpty(&stack) && stack.items[stack.top] == '(')
                pop(&stack); // Pop the '('
        } else if (isOperator(currentChar)) {
            while (!isEmpty(&stack) && getPrecedence(stack.items[stack.top]) >= getPrecedence(currentChar)) {
                postfixExpression[postfixIndex++] = pop(&stack);
            }
            push(&stack, currentChar);
        }
    }

    while (!isEmpty(&stack)) {
        if (stack.items[stack.top] == '(') {
            printf("Unbalanced parentheses in the expression.\n");
            exit(1);
        }
        postfixExpression[postfixIndex++] = pop(&stack);
    }

    postfixExpression[postfixIndex] = '\0'; // Null-terminate the postfix expression
}

int main() {
    char infixExpression[MAX_SIZE];
    char postfixExpression[MAX_SIZE];
    
    printf("Enter an infix expression: ");
    scanf("%s", infixExpression);
    
    infixToPostfix(infixExpression, postfixExpression);
    
    printf("Postfix expression: %s\n", postfixExpression);
    
    return 0;
}







/*
Infix notation is the standard way to write mathematical expressions, with operators between operands and the use of parentheses to indicate the order of operations. Converting infix expressions to postfix notation can simplify the evaluation process and remove the need for parentheses.

Here's an algorithm for converting an infix expression to postfix notation using the Shunting Yard algorithm:

Initialize an empty stack for operators and an empty output queue for the postfix expression.
Scan the infix expression from left to right.
For each element in the expression:
a. If it's an operand (a number), add it to the output queue.
b. If it's an operator (+, -, *, /, etc.):
i. Pop operators from the stack and add them to the output queue until you encounter an operator with lower precedence or an open parenthesis '(' or the stack is empty.
ii. Push the current operator onto the stack.
c. If it's an open parenthesis '(', push it onto the stack.
d. If it's a closing parenthesis ')':
i. Pop operators from the stack and add them to the output queue until you encounter an open parenthesis '('.
ii. Pop and discard the open parenthesis '(' from the stack.
After scanning the entire expression, pop any remaining operators from the stack and add them to the output queue.
The output queue now contains the postfix expression.
*/
