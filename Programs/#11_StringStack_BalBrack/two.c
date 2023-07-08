/*
Mona has given a set of open and closed brackets of each type such as ( ),[ ], { } by his teacher
and he is asked to construct a valid set of brackets from the given set. A set is said to be valid if
1) Open brackets must be closed by the same type of closing brackets.
2) Open brackets must be closed in the correct order.
You have to determine that the set constructed by Mona is valid or not.

Input:
Enter an expression: ({})

Output:
The expression is balanced

Input:
Enter an expression: (({})}

Output:
The expression is not balanced

*/
#include <stdio.h>
#include <stdbool.h>
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

//remove element from top of the stack
char pop() {
    if (top == -1) {
        printf("Stack Underflow\n");
        return -1;
    }
    return stack[top--];
}

//function to check for expression is balanced or not
bool isBalanced(char* expression) {
    int len = strlen(expression);
    for (int i = 0; i < len; i++) {

        // if expression contains ( or { or [ push it to stack
        if (expression[i] == '(' || expression[i] == '{' || expression[i] == '[')
            push(expression[i]);
        else if (expression[i] == ')' || expression[i] == '}' || expression[i] == ']') {
            if (top == -1)
                return false;
            char topChar = pop();

            //check for right opening and closing parenthesis
            if ((expression[i] == ')' && topChar != '(') ||
                (expression[i] == '}' && topChar != '{') ||
                (expression[i] == ']' && topChar != '['))
                return false;
        }
    }
    return top == -1;
}

int main() {
    char expression[100];
    printf("Enter an expression: ");
    scanf("%[^\n]%*c", expression);
    if (isBalanced(expression))
        printf("The expression is balanced\n");
    else
        printf("The expression is not balanced\n");
    return 0;
}

/*
This program checks whether the given expression contains balanced parentheses or not using a stack.
It scans the expression from left to right and pushes an opening parenthesis onto the stack.
If a closing parenthesis is encountered, it checks whether it matches the top of the stack.
If all parentheses match and the stack is empty at the end, the expression is considered balanced.
*/


