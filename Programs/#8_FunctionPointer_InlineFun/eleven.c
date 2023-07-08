/*
Implement C Program to calculate Sum of Array Elements using Inline Function.
Define constant for array size.

Input:  Enter 5 elements: 4 5 6 2 1
Output: Sum of array elements is: 18

*/
#include <stdio.h>

#define SIZE 5 //define constant for SIZE

static inline int sumArray(int arr[], int size) {
    int sum = 0; //initialize sum as zero
    //calculate sum
    for (int i = 0; i < size; i++) {
        sum += arr[i]; //store sum
    }
    return sum;
}

int main() {
    int arr[SIZE];

    printf("Enter %d elements: ", SIZE);
    for (int i = 0; i < SIZE; i++) {
        scanf("%d", &arr[i]); //input array elements
    }

    int result = sumArray(arr, SIZE);

    printf("Sum of array elements is: %d\n", result);

    return 0;
}

/*
This program calculates the sum of elements in an array using an inline function sumArray().
The user is prompted to enter a specified number of elements, and the sumArray() function is called to compute
the sum of those elements.
The resulting sum is then displayed on the screen.
*/
