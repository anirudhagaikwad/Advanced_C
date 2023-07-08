/*
Write a C program using Function Pointer to Find the Maximum Number in an Array

Input: {9, 4, 7, 2, 1, 5, 8, 3, 6}
Output: 9

*/

#include <stdio.h>

int findMax(int *arr, int size) {
    int max = arr[0];

    for (int i = 1; i < size; i++) {
        if (arr[i] > max) {
            max = arr[i];
        }
    }

    return max;
}

int main() {
    int arr[] = {9, 4, 7, 2, 1, 5, 8, 3, 6};
    int size = sizeof(arr) / sizeof(arr[0]);

    // Declare a function pointer and assign the findMax function to it
    int (*ptr)(int *, int) = findMax;

    // Call the function using the function pointer
    int result = ptr(arr, size);

    printf("Maximum number: %d\n", result);

    return 0;
}
/*
This program demonstrates the usage of a function pointer to find the maximum number in an integer array.
The findMax function iterates through the array and keeps track of the maximum number encountered. The main function defines an integer
array and its size, and assigns the findMax function to a function pointer named ptr.
The ptr function pointer is then used to call the findMax function, and the maximum number is displayed.
*/
