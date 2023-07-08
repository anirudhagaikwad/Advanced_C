/*
Write a c program to evaluate a prefix expression using stack.

Input: +*732
Output: 23

*/

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include<string.h>

// Structure for stack node
struct StackNode {
    int data;
    struct StackNode* next;
};

// Function to create a new stack node
struct StackNode* createNode(int data) {
    struct StackNode* node = (struct StackNode*)malloc(sizeof(struct StackNode));
    node->data = data;
    node->next = NULL;
    return node;
}

// Function to check if the stack is empty
int isEmpty(struct StackNode* root) {
    return !root;
}

// Function to push an element onto the stack
void push(struct StackNode** root, int data) {
    struct StackNode* newNode = createNode(data);
    newNode->next = *root;
    *root = newNode;
}

// Function to pop an element from the stack
int pop(struct StackNode** root) {
    if (isEmpty(*root))
        return -1;
    struct StackNode* temp = *root;
    *root = (*root)->next;
    int popped = temp->data;
    free(temp);
    return popped;
}

// Function to perform arithmetic operations
int performOperation(char operator, int operand1, int operand2) {
    switch (operator) {
        case '+':
            return operand1 + operand2;
        case '-':
            return operand1 - operand2;
        case '*':
            return operand1 * operand2;
        case '/':
            return operand1 / operand2;
    }
    return 0;
}

// Function to evaluate prefix expression
int evaluatePrefixExpression(char* expression) {
    struct StackNode* stack = NULL;
    int i;

    // Read the expression in reverse order
    for (i = strlen(expression) - 1; i >= 0; i--) {
        // If current character is an operand, push it onto the stack
        if (isdigit(expression[i]))
            push(&stack, expression[i] - '0');
        else {
            // If current character is an operator, pop two operands from the stack,
            // perform the operation, and push the result back onto the stack
            int operand1 = pop(&stack);
            int operand2 = pop(&stack);
            int result = performOperation(expression[i], operand1, operand2);
            push(&stack, result);
        }
    }
    // The final result will be the top element of the stack
    return pop(&stack);
}


int main() {
    char expression[] = "+*732";
    int result = evaluatePrefixExpression(expression);
    printf("Result: %d\n", result);
    return 0;
}
/*
This C program evaluates a prefix expression using a stack data structure. In a prefix expression, the operator is placed before
its operands. The program reads a prefix expression as a character array and evaluates it to obtain the result.

The program defines a stack node structure (StackNode) to represent the nodes of the stack. Each stack node contains the data
(integer value) and a pointer to the next node.

The program provides functions to create a new stack node, check if the stack is empty, push an element onto the stack,
and pop an element from the stack.

The performOperation function takes an operator and two operands and performs the corresponding arithmetic operation (+, -, *, /).

The evaluatePrefixExpression function evaluates the prefix expression. It reads the expression in reverse order and processes each
character. If the character is an operand (digit), it is converted to an integer and pushed onto the stack. If the character is an
operator, two operands are popped from the stack, the operation is performed, and the result is pushed back onto the stack.
Finally, the top element of the stack is the result of the prefix expression.

The main function initializes a prefix expression (expression) and calls the evaluatePrefixExpression function to obtain the result.
The result is then printed to the console.
*/
