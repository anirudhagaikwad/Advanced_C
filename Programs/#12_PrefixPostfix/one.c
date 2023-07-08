/*
Evaluate a given postfix expression using a stack data structure.

Input:
Enter a postfix expression: 52+83-*4/

Output:
Result: 8

Input:
Enter a postfix expression: 456*+

Output:
Result: 34

*/

#include <stdio.h>
#include <stdbool.h>
#include <ctype.h>
#include <string.h>
#define MAX_SIZE 100

int stack[MAX_SIZE];
int top = -1;

//push element to top of the stack
void push(int value) {
    if (top == MAX_SIZE - 1) {
        printf("Stack Overflow\n");
        return;
    }
    stack[++top] = value;
}

//pop element from top of the stack
int pop() {
    if (top == -1) {
        printf("Stack Underflow\n");
        return -1;
    }
    return stack[top--];
}

int evaluatePostfix(char* expression) {
    int len = strlen(expression);
    for (int i = 0; i < len; i++) {
        if (isdigit(expression[i]))
            //push digits on expression to the stack
            push(expression[i] - '0');
        else {
            //if operator is found then pop two topmost operands from stack
            int operand2 = pop();
            int operand1 = pop();

            //perform operation on two operands based on operator
            switch (expression[i]) {
                case '+':
                    push(operand1 + operand2);
                    break;
                case '-':
                    push(operand1 - operand2);
                    break;
                case '*':
                    push(operand1 * operand2);
                    break;
                case '/':
                    push(operand1 / operand2);
                    break;
                case '%':
                    push(operand1 % operand2);
                    break;
            }
        }
    }
    return pop();
}

int main() {
    char expression[100];
    printf("Enter a postfix expression: ");
    scanf("%[^\n]%*c", expression);
    int result = evaluatePostfix(expression);
    printf("Result: %d\n", result);
    return 0;
}
/*
This program evaluates a given postfix expression using a stack.
It scans the expression from left to right. If a digit is encountered, it is pushed onto the stack.
If an operator is encountered, it pops two operands from the stack, performs the operation, and pushes
the result back onto the stack.
Finally, the program returns the top element of the stack, which represents the evaluated result.
*/
