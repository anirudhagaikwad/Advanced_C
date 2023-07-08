/*
Given an array of integers A .

A represents a histogram i.e A[i] denotes height of the ith histogram's bar. Width of each bar is 1.

Find the area of the largest rectangle formed by the histogram.

Input: { 6, 2, 5, 4, 5, 1, 6 }
Output: Maximum area is 12

Input: {2, 1, 5, 6, 2, 3}
Output: Maximum area is 10

Input: {2}
Output: Maximum area is 2

*/
#include <stdio.h>
#include <stdlib.h>

#define MAX 1000

// Structure to represent a stack
typedef struct {
    int arr[MAX];   // Array to store elements of the stack
    int top;        // Index of the top element in the stack
} Stack;

// Function to initialize the stack
void init(Stack* s) {
    s->top = -1;    // Set the top index to -1 (empty stack)
}

// Function to push an element onto the stack
void push(Stack* s, int item) {
    if (s->top == MAX - 1) {             // Check if the stack is already full
        printf("Stack overflow!\n");
        exit(1);
    }
    s->arr[++(s->top)] = item;           // Increment the top index and assign the element to the stack
}

// Function to pop an element from the stack
int pop(Stack* s) {
    if (s->top == -1) {                  // Check if the stack is empty
        printf("Stack underflow!\n");
        exit(1);
    }
    return s->arr[(s->top)--];           // Decrement the top index and return the popped element
}

// Function to get the top element of the stack
int top(Stack* s) {
    if (s->top == -1) {                  // Check if the stack is empty
        printf("Stack is empty!\n");
        exit(1);
    }
    return s->arr[s->top];               // Return the top element of the stack
}

// Function to check if the stack is empty
int isEmpty(Stack* s) {
    return s->top == -1;                 // Return 1 if the stack is empty, 0 otherwise
}

// The main function to find the maximum rectangular area under the given histogram with n bars
int getMaxArea(int hist[], int n) {
    Stack s;
    init(&s);                            // Initialize the stack

    int max_area = 0;                    // Initialize max area
    int tp;                              // To store top of stack
    int area_with_top;                   // To store area with top bar as the smallest bar

    int i = 0;
    while (i < n) {
        if (isEmpty(&s) || hist[top(&s)] <= hist[i]) {
            push(&s, i++);                // If the current bar is higher than or equal to the bar at the top of the stack, push it onto the stack and move to the next bar
        }
        else {
            tp = pop(&s);                 // If the current bar is lower than the bar at the top of the stack, calculate the area with the popped bar as the smallest bar

            // Calculate the area with the popped bar as the smallest bar
            area_with_top = hist[tp] * (isEmpty(&s) ? i : i - top(&s) - 1);

            if (max_area < area_with_top)
                max_area = area_with_top;
        }
    }

    // Process the remaining bars in the stack
    while (!isEmpty(&s)) {
        tp = pop(&s);

        // Calculate the area with the popped bar as the smallest bar
        area_with_top = hist[tp] * (isEmpty(&s) ? i : i - top(&s) - 1);

        if (max_area < area_with_top)
            max_area = area_with_top;
    }

    return max_area;
}

int main() {
    int hist[] = { 2, 1, 5, 6, 2, 3 };
    int n = sizeof(hist) / sizeof(hist[0]);

    // Function call to find the maximum area
    printf("Maximum area is %d\n", getMaxArea(hist, n));
    return 0;
}
/*
The code implements a function getMaxArea that calculates the maximum rectangular area under a given histogram.
It uses a stack to efficiently process the bars of the histogram. The Stack structure represents the stack and provides functions
to initialize the stack, push elements onto the stack, pop elements from the stack, get the top element of the stack, and check if
the stack is empty.

In the main function, an example histogram is provided, and the getMaxArea function is called to find the maximum area.
The result is printed as output.

The program demonstrates the use of a stack data structure to solve a problem related to histograms efficiently.

*/
