/*
You have given a string which contains brackets.
If the start index of the open bracket is given, find the index of the closing bracket.

Input: [earth[mars][neptune][urenus]]
       start 0
Output: 29

Input: [earth[mars][neptune][urenus]]
       start 29
Output: -1

Input: [earth[mars][neptune][urenus]]
       start 6
Output: 11


*/

#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#define MAX_SIZE 100

// Function to find index of closing bracket for given opening bracket.
void test(char expression[], int index) {
    int i;

    // If index given is invalid and is not an opening bracket.
    if (expression[index] != '[') {
        printf("%s, %d: -1\n", expression, index);
        return;
    }

    // Stack to store opening brackets.
    char stack[MAX_SIZE];
    int top = -1;

    // Traverse through string starting from given index.
    for (i = index; i < strlen(expression); i++) {

        // If current character is an opening bracket, push it in stack.
        if (expression[i] == '[')
            stack[++top] = expression[i];

        // If current character is a closing bracket, pop from stack.
        // If stack is empty, then this closing bracket is the required bracket.
        else if (expression[i] == ']') {
            if (top == -1) {
                printf("%s, %d: -1\n", expression, index);
                return;
            }
            top--;
            if (top == -1) {
                printf("%s, %d: %d\n", expression, index, i);
                return;
            }
        }
    }

    // If no matching closing bracket is found.
    printf("%s, %d: -1\n", expression, index);
}

int main() {
    test("[earth[mars][neptune][urenus]]", 0); // should be 29
    test("[earth[mars][neptune][urenus]]", 6); // should be 11
    test("[earth[mars][neptune][urenus]]", 12); // should be 20
    test("[earth[mars][neptune][urenus]][", 29); // No matching bracket
    return 0;
}
/*

*/
