/*
Given a string containing brackets ('(', ')', '[', ']', '{', '}'), write a program to find the maximum nesting depth of the brackets.

Input: Enter the brackets: ({[()]})
Output: Maximum nesting depth: 4

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

// Function to find the maximum nesting depth
int findMaxNestingDepth(char brackets[]) {
    struct Stack* stack = createStack(MAX_SIZE);
    int maxDepth = 0;
    int currentDepth = 0;

    // Traverse through the given brackets
    for (int i = 0; brackets[i] != '\0'; i++) {
        // If opening bracket, push it to stack and update current depth
        if (brackets[i] == '(' || brackets[i] == '[' || brackets[i] == '{') {
            stack->array[++stack->top] = brackets[i];
            currentDepth++;
            if (currentDepth > maxDepth)
                maxDepth = currentDepth;
        }
        // If closing bracket, check if it matches the top of the stack
        else if (brackets[i] == ')' || brackets[i] == ']' || brackets[i] == '}') {
            if (stack->top != -1 && areBracketsMatching(stack->array[stack->top], brackets[i])) {
                stack->top--;
                currentDepth--;
            }
        }
    }

    return maxDepth;
}

int main() {
    char brackets[MAX_SIZE];
    printf("Enter the brackets: ");
    scanf("%s", brackets);

    int maxDepth = findMaxNestingDepth(brackets);
    printf("Maximum nesting depth: %d\n", maxDepth);

    return 0;
}

/*
The program uses a stack implemented using a dynamic array to find the maximum nesting depth of the brackets in the given string.
It scans the string character by character and pushes opening brackets onto the stack. Whenever a closing bracket is encountered,
it checks if it matches the top of the stack by calling the areBracketsMatching() function. If they do, the top element is popped from the stack,
and the current depth is decremented. The maximum depth encountered is stored in maxDepth, which is returned at the end.

*/

