/*
Reverse a given string using a stack data structure.

Input:
Enter a string: Hello World
Original string: Hello World

Output:
Reversed string: dlroW olleH

*/
#include <stdio.h>
#include <string.h>
#define MAX_SIZE 100

char stack[MAX_SIZE];
int top = -1;

void push(char ch) {

    //check for stack is full or not
    if (top == MAX_SIZE - 1) {
        printf("Stack Overflow\n");
        return;
    }
    //push element to stack
    stack[++top] = ch;
}

char pop() {

    //check for stack is empty or not
    if (top == -1) {
        printf("Stack Underflow\n");
        return -1;
    }
    //remove element from top of the stack
    return stack[top--];
}

void reverseString(char* str) {
    int len = strlen(str);

    //push all characters of the string one by one
    for (int i = 0; i < len; i++)
        push(str[i]);

    //pop all characters of the string one by one and store in same string
    for (int i = 0; i < len; i++)
        str[i] = pop();

    //after this, str will contain reversed string
}

int main() {
    char str[100];
    printf("Enter a string: ");
    scanf("%[^\n]%*c", str);
    printf("Original string: %s\n", str);
    reverseString(str);
    printf("Reversed string: %s\n", str);
    return 0;
}
/*
This program demonstrates how to reverse a given string using a stack.
It first pushes each character of the string onto the stack and then pops the characters in reverse order
to obtain the reversed string.
*/
