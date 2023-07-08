/*
You have given a balanced expression. Write a program to find if it contains duplicate parenthesis or not.
A set of parenthesis are duplicate if the same subexpression is surrounded by multiple parenthesis.

Input: (((a+(b))+c+d))
Output: Duplicate Found

Input: (((a+(b)))+(c+d))
Output: Duplicate Found

Input: ((a+(b))+(c+d))
Output: No Duplicates Found

*/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define MAX_LENGTH 100

// Function to find duplicate parenthesis in a balanced expression
bool findDuplicateParenthesis(char* str)
{
    // Create a stack of characters
    char stack[MAX_LENGTH];
    int top = -1;

    // Iterate through the given expression
    for (int i = 0; i < strlen(str); i++)
    {
        // If current character is closing parenthesis ')'
        if (str[i] == ')')
        {
            // Pop character from the stack
            char topChar = stack[top];
            top--;

            // Count the number of characters between a
            // closing and opening parenthesis
            // If this count is less than or equal to 1,
            // then the brackets are redundant, else not
            int elementsInside = 0;
            while (topChar != '(')
            {
                elementsInside++;
                topChar = stack[top];
                top--;
            }
            if (elementsInside < 1) {
                return true;
            }
        }

        // Push open parenthesis '(', operators, and operands to stack
        else
        {
            top++;
            stack[top] = str[i];
        }
    }

    // No duplicates found
    return false;
}


int main()
{
    // Input balanced expression
    char str[MAX_LENGTH] = "((a+(b))+(c+d))";
    //char str[MAX_LENGTH] ="(((a+(b)))+(c+d))";

    if (findDuplicateParenthesis(str))
        printf("Duplicate Found\n");
    else
        printf("No Duplicates Found\n");

    return 0;
}
/*
This program checks whether a given balanced expression contains duplicate parentheses or not.

The findDuplicateParenthesis function takes a string as input and returns true if duplicate parentheses are found, and false otherwise.
It uses a stack to keep track of the opening parentheses encountered. The function iterates through the input string character by character and applies the following rules:

If the current character is a closing parenthesis ')', it checks the top character of the stack:
If the top character is an opening parenthesis '(', it pops characters from the stack until an opening parenthesis is encountered.
It keeps track of the count of characters between the closing and opening parentheses. If this count is less than 1, it means that
duplicate parentheses are present, and it returns true.
If the current character is not a closing parenthesis, it pushes it onto the stack.
The main function demonstrates the usage of the findDuplicateParenthesis function by passing an example balanced expression str.
It prints "Duplicate Found" if duplicate parentheses are present in the expression, and "No Duplicates Found" otherwise.

Note that the program assumes that the input string is properly balanced, i.e., the number of opening and closing parentheses is
the same.

*/
