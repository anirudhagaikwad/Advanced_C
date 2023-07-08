/*
Maths teacher has given a algebraic string of characters, ‘+’, ‘-‘ operators.
Students need to show simplified string without parentheses. Help students to show
simplified string.

Input: (a-(b+c)+d)
Output: a-b-c+d

Input: a-(b-c-(d+e))-f
output: a-b+c+d+e-f

*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LENGTH 100

// Function to simplify the string
char* simplify(char* str)
{
    int len = strlen(str);

    // Resultant string of max length equal
    // to length of input string
    char* res = (char*)malloc((len + 1) * sizeof(char));
    int index = 0, i = 0;

    // Create empty stack
    int stack[MAX_LENGTH];
    stack[0] = 0;
    int top = 0;

    while (i < len) {
        // Don't do any operation
        if (str[i] == '(' && i == 0) {
            i++;
            continue;
        }

        if (str[i] == '+') {
            // If top is 1, flip the operator
            if (stack[top] == 1)
                res[index++] = '-';

            // If top is 0, append the same operator
            if (stack[top] == 0)
                res[index++] = '+';

        } else if (str[i] == '-') {
            if (stack[top] == 1) {
                if (res[index - 1] == '+' || res[index - 1] == '-')
                    res[index - 1] = '+'; // Overriding previous sign
                else
                    res[index++] = '+';
            } else if (stack[top] == 0) {
                if (res[index - 1] == '+' || res[index - 1] == '-')
                    res[index - 1] = '-'; // Overriding previous sign
                else
                    res[index++] = '-';
            }
        } else if (str[i] == '(' && i > 0) {
            if (str[i - 1] == '-') {
                // x is opposite to the top of stack
                int x = (stack[top] == 1) ? 0 : 1;
                stack[++top] = x;
            } else if (str[i - 1] == '+') {
                // Push value equal to top of the stack
                stack[++top] = stack[top];
            }
        } else if (str[i] == ')') {
            // Pop the stack once for closing parentheses
            top--;
        } else {
            // Copy the character to the result
            res[index++] = str[i];
        }
        i++;
    }

    res[index] = '\0';
    return res;
}

int main()
{
    char s1[] = "(a-(b+c)+d)";
    char s2[] = "a-(b-c-(d+e))-f";
    char* result1 = simplify(s1);
    char* result2 = simplify(s2);

    printf("%s \n %s \n",s1, result1);
    printf("%s \n %s",s2, result2);

    free(result1);
    free(result2);

    return 0;
}
/*
This program simplifies algebraic strings by removing redundant parentheses and flipping the signs of expressions.
The simplified strings are then printed to the console.

The simplify function takes a string as input and returns a new string that represents the simplified version.
It uses a stack to keep track of the signs and performs operations accordingly. The function traverses the input string character by character and applies the following rules:

If the character is '+', it checks the top of the stack:
If the top is 1, it flips the operator to '-' in the result string.
If the top is 0, it appends the same operator '+' to the result string.
If the character is '-', it checks the top of the stack:
If the top is 1, it overrides the previous sign with '+' in the result string.
If the top is 0, it overrides the previous sign with '-' in the result string.
If the character is '(', it checks the previous character:
If the previous character is '-', it pushes the opposite sign (0 or 1) to the stack.
If the previous character is '+', it pushes the current top of the stack to the stack.
If the character is ')', it pops the stack to remove the effect of the corresponding opening parentheses.
For any other character, it copies the character to the result string.
The main function demonstrates the usage of the simplify function by passing two example strings, s1 and s2.
The simplified strings are then printed to the console.

Note that the program dynamically allocates memory for the result strings using malloc and frees the memory using free to
avoid memory leaks.
*/
