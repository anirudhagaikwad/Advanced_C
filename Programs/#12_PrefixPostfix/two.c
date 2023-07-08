/*
Convert a given infix expression to its corresponding postfix expression using a stack data structure.

Input:
Enter an infix expression: 5+4*7

Output:
Postfix expression: 547*+

*/

#include <stdio.h>
#include <stdbool.h>
#include <ctype.h>
#include <string.h>
#define MAX_SIZE 100

char stack[MAX_SIZE];
int top = -1;

//push element to top of the stack
void push(char ch) {
    if (top == MAX_SIZE - 1) {
        printf("Stack Overflow\n");
        return;
    }
    stack[++top] = ch;
}
//pop element from top of the stack
char pop() {
    if (top == -1) {
        printf("Stack Underflow\n");
        return -1;
    }
    return stack[top--];
}

//return precedence based upon operator encountered
int getPrecedence(char ch) {
    switch (ch) {
        case '^':
            return 3;
        case '*':
        case '/':
        case '%':
            return 2;
        case '+':
        case '-':
            return 1;
        default:
            return -1;
    }
}

void infixToPostfix(char* infix, char* postfix) {
    int len = strlen(infix);
    int j = 0;

    for (int i = 0; i < len; i++) {
        //if operand is found add it to postfix expression
        if (isalnum(infix[i]))
            postfix[j++] = infix[i];
        //push into stack if opening bracket is found
        else if (infix[i] == '(')
            push(infix[i]);
        else if (infix[i] == ')') {
            //pop from stack while opening bracket is not found
            while (top != -1 && stack[top] != '(')
                postfix[j++] = pop();
            if (top != -1 && stack[top] != '(')
                printf("Invalid infix expression\n");
            else
                pop();
        }
        else {
            //if operator is found check for precedence
            while (top != -1 && getPrecedence(infix[i]) <= getPrecedence(stack[top]))
                postfix[j++] = pop();
            push(infix[i]);
        }
    }

    while (top != -1)
        postfix[j++] = pop();

    postfix[j] = '\0';
}

int main() {
    char infix[100];
    printf("Enter an infix expression: ");
    scanf("%[^\n]%*c", infix);
    char postfix[100];
    infixToPostfix(infix, postfix);
    printf("Postfix expression: %s\n", postfix);
    return 0;
}
/*
This program converts a given infix expression to its corresponding postfix expression using a stack.
It scans the infix expression from left to right. If an operand is encountered, it is added to the postfix expression.
If an opening parenthesis is encountered, it is pushed onto the stack. If a closing parenthesis is encountered,
all operators on the stack are popped and added to the postfix expression until the opening parenthesis is reached.
If an operator is encountered, all operators on the stack with higher or equal precedence are popped and added to the
postfix expression, and the current operator is pushed onto the stack.
Finally, any remaining operators on the stack are popped and added to the postfix expression
*/
