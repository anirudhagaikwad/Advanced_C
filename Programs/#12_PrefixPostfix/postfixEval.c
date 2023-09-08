#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_SIZE 100

// Stack implementation
struct Stack {
    int top;
    int items[MAX_SIZE];
};

// Function to initialize an empty stack
void initialize(struct Stack* stack) {
    stack->top = -1;
}

// Function to check if the stack is empty
int isEmpty(struct Stack* stack) {
    return stack->top == -1;
}

// Function to push an element onto the stack
void push(struct Stack* stack, int value) {
    if (stack->top == MAX_SIZE - 1) {
        printf("Stack overflow!\n");
        exit(1);
    }
    stack->items[++stack->top] = value;
}

// Function to pop an element from the stack
int pop(struct Stack* stack) {
    if (isEmpty(stack)) {
        printf("Stack underflow!\n");
        exit(1);
    }
    return stack->items[stack->top--];
}

// Function to evaluate a postfix expression
int evaluatePostfix(char* expression) {
    struct Stack stack;
    initialize(&stack);

    for (int i = 0; expression[i]; i++) {
        if (isdigit(expression[i])) {
            push(&stack, expression[i] - '0');
        } else {
            int operand2 = pop(&stack);
            int operand1 = pop(&stack);
            switch (expression[i]) {
                case '+':
                    push(&stack, operand1 + operand2);
                    break;
                case '-':
                    push(&stack, operand1 - operand2);
                    break;
                case '*':
                    push(&stack, operand1 * operand2);
                    break;
                case '/':
                    push(&stack, operand1 / operand2);
                    break;
                default:
                    printf("Invalid operator: %c\n", expression[i]);
                    exit(1);
            }
        }
    }

    if (!isEmpty(&stack))
        return pop(&stack);
    else {
        printf("Invalid expression\n");
        exit(1);
    }
}

int main() {
    char postfixExpression[MAX_SIZE];
    printf("Enter a postfix expression: ");
    scanf("%s", postfixExpression);
    int result = evaluatePostfix(postfixExpression);
    printf("Result: %d\n", result);
    return 0;
}








/*
Postfix notation, also known as Reverse Polish Notation (RPN), is a way to represent mathematical expressions without the need for parentheses to indicate the order of operations. In postfix notation, operators come after their operands. To evaluate a postfix expression, you can use a stack data structure.

Here's an algorithm for evaluating a postfix expression:

Initialize an empty stack to store operands.
Scan the expression from left to right.
For each element in the expression:
a. If it's an operand (a number), push it onto the stack.
b. If it's an operator (+, -, *, /, etc.):
i. Pop the top two elements from the stack as operands.
ii. Apply the operator to these operands.
iii. Push the result back onto the stack.
After scanning the entire expression, the result should be the only element left on the stack.


*/
