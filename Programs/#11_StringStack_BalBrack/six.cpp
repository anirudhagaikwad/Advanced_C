/*
Given a string containing brackets ('(', ')', '[', ']', '{', '}'), write a program to count the number of balanced expressions in the string.

Input: Enter the brackets: ([{()}]){
Output: Number of balanced expressions: 4

*/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#define MAX_SIZE 100

// Structure for stack
struct Stack {
    int top;
    unsigned capacity;
    char* array;
};

// Function to create a stack
struct Stack* createStack(unsigned capacity) {
    struct Stack* stack = (struct Stack*)malloc(sizeof(struct Stack));
    stack->top = -1;
    stack->capacity = capacity;
    stack->array = (char*)malloc(stack->capacity * sizeof(char));
    return stack;
}

// Function to check if brackets are matching
bool areBracketsMatching(char opening, char closing) {
    if (opening == '(' && closing == ')')
        return true;
    else if (opening == '[' && closing == ']')
        return true;
    else if (opening == '{' && closing == '}')
        return true;
    else
        return false;
}

// Function to count the number of balanced expressions
int countBalancedExpressions(char brackets[]) {
    struct Stack* stack = createStack(MAX_SIZE);
    int length = strlen(brackets);
    int count = 0;

    // Traverse through the given brackets
    for (int i = 0; brackets[i] != '\0'; i++) {
        // If opening bracket, push it to stack
        if (brackets[i] == '(' || brackets[i] == '[' || brackets[i] == '{') {
            stack->array[++stack->top] = brackets[i];
        }
        // If closing bracket, check if it matches the top of the stack
        else if (brackets[i] == ')' || brackets[i] == ']' || brackets[i] == '}') {
            if (stack->top != -1 && areBracketsMatching(stack->array[stack->top], brackets[i])) {
                stack->top--;
                count++;
            }
        }
    }

    return count;
}


int main() {
    char brackets[MAX_SIZE];
    printf("Enter the brackets: ");
    scanf("%s", brackets);

    int count = countBalancedExpressions(brackets);
    printf("Number of balanced expressions: %d\n", count);

    return 0;
}


/*
The program uses a stack implemented using a dynamic array to count the number of balanced expressions in the given string.
It scans the string character by character and pushes opening brackets onto the stack.
Whenever a closing bracket is encountered, it checks if it matches the top of the stack by calling the areBracketsMatching() function.
If they do, the top element is popped from the stack, and the count of balanced expressions is incremented. The total count is returned at the end.

*/



