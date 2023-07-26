/*
Given a string containing brackets ('(', ')', '[', ']', '{', '}'),
write a program to find the length of the longest balanced substring.

Input: Enter the brackets: ([]{}[])
Output: Length of the longest balanced substring: 8

Input: Enter the brackets: ([]})
Output: Length of the longest balanced substring: 2

*/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define MAX_SIZE 100

// Structure for stack
struct Stack {
    int top;
    unsigned capacity;
    int* array;
};

// Function to create a stack
struct Stack* createStack(unsigned capacity) {
    struct Stack* stack = (struct Stack*)malloc(sizeof(struct Stack));
    stack->top = -1;
    stack->capacity = capacity;
    stack->array = (int*)malloc(stack->capacity * sizeof(int));
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

// Function to find the length of the longest balanced substring
int findLongestBalancedSubstring(char brackets[]) {
    struct Stack* stack = createStack(MAX_SIZE);
    stack->array[++stack->top] = -1;
    int maxLength = 0;

    // Traverse through the given brackets
    for (int i = 0; brackets[i] != '\0'; i++) {
        // If opening bracket, push its index to stack
        if (brackets[i] == '(' || brackets[i] == '[' || brackets[i] == '{') {
            stack->array[++stack->top] = i;
        }
        // If closing bracket, check if it matches the top of the stack
        else if (brackets[i] == ')' || brackets[i] == ']' || brackets[i] == '}') {
            if (stack->top != -1 && areBracketsMatching(brackets[stack->array[stack->top]], brackets[i])) {
                stack->top--;
                if (i - stack->array[stack->top] > maxLength)
                    maxLength = i - stack->array[stack->top];
            } else {
                stack->array[++stack->top] = i;
            }
        }
    }

    return maxLength;
}

int main() {
    char brackets[MAX_SIZE];
    printf("Enter the brackets: ");
    scanf("%s", brackets);

    int length = findLongestBalancedSubstring(brackets);
    printf("Length of the longest balanced substring: %d\n", length);

    return 0;
}

/*
The program uses a stack implemented using a dynamic array to find the length of the longest balanced substring in the given string.
It scans the string character by character and pushes the index of opening brackets onto the stack. Whenever a closing bracket is encountered,
it checks if it matches the top of the stack by calling the areBracketsMatching() function.
If they do, the top element is popped from the stack, and the length of the balanced substring is calculated.
The maximum length encountered is stored in maxLength, which is returned at the end.
*/
