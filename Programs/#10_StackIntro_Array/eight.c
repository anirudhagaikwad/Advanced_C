/*
Given an array of n elements and q queries. Query contains array of index i, find the next greater element of that index i
and print its value.
If there is no such greater element to its right then print -1.

Input:
arr[] = {3, 4, 2, 7, 5, 8, 10, 6}
        query indexes = {1, 4, 6}
Output: 7 8 -1

*/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>

#define MAX_SIZE 100

// Function to calculate the next greater element indexes
void next_greatest(int next[], int a[], int n)
{
    // Use of stack in C using an array
    int stack[MAX_SIZE];
    int top = -1;

    // Push the 0th index to the stack
    stack[++top] = 0;

    // Traverse the array from the 1st to the nth index
    for (int i = 1; i < n; i++)
    {
        // Iterate until the stack is empty
        while (top != -1)
        {
            // Get the topmost index in the stack
            int cur = stack[top];

            // If the current element is greater than the element at the top index,
            // then this will be the next greatest index of the element at the top index
            if (a[cur] < a[i])
            {
                // Assign the current index as the next greatest index for the top index element
                next[cur] = i;

                // Pop the top index as its greater element has been found
                top--;
            }
            // If not greater, break the loop
            else
                break;
        }
        // Push the current index to find its next greatest element
        stack[++top] = i;
    }

    // Assign -1 to the remaining indexes in the stack as no element is greater than them on the right
    while (top != -1)
    {
        int cur = stack[top];

        // Mark it as -1 as no element is greater than it on the right
        next[cur] = -1;

        top--;
    }
}

// Function to answer the queries in O(1)
int answer_query(int a[], int next[], int n, int index)
{
    // Retrieve the next greater element position
    int position = next[index];

    // If the position is -1, no greater element is found on the right
    if (position == -1)
        return -1;
    // Return the value of the element at the position
    else
        return a[position];
}

int main()
{
    int a[] = {3, 4, 2, 7, 5, 8, 10, 6};
    int n = sizeof(a) / sizeof(a[0]);

    // Initialize the next array as 0
    int next[MAX_SIZE] = {0};

    // Calculate the next greatest element indexes
    next_greatest(next, a, n);

    // Answer the queries
    printf("%d ", answer_query(a, next, n, 1));
    printf("%d ", answer_query(a, next, n, 4));
    printf("%d ", answer_query(a, next, n, 6));

    return 0;
}

/*
This program finds the next greater element for each element in an array and answers multiple queries to retrieve the next greater
element for a given index.

The next_greatest function takes an array a and its length n as input. It uses a stack implemented using an array to store the
indexes of elements in the array. The function iterates through the array from the 1st index to the nth index. It compares each
element with the element at the top index of the stack.
If the current element is greater than the element at the top index, it assigns the current index as the next greatest index for
the element at the top index and pops the top index from the stack. This process continues until the current element is not greater
than the element at the top index. Finally, it assigns -1 to the remaining indexes in the stack as no element in the array is greater
than them on the right.

The answer_query function takes the array a, the next greatest element indexes next, the length of the array n, and the index for
which the next greater element is to be retrieved as input. It retrieves the next greater element's position from the next array
and returns the value of the element at that position. If the position is -1, it means no greater element is found on the right,
and it returns -1.

The main function demonstrates the usage of the next_greatest and answer_query functions. It initializes an example array a and its
length n. It initializes the next array as 0 and calculates the next greatest element indexes by calling the next_greatest function.
It then answers three queries using the answer_query function and prints the results.
*/
