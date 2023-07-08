/*
Implement the Quick Sort algorithm to sort an array of strings in lexicographical order.

Input:
{"banana", "apple", "grape", "orange", "pear"}

Output:
Sorted array:
apple banana grape orange pear

*/

#include <stdio.h>
#include <string.h>

// Function to swap two strings
void swap(char* a, char* b) {
    char temp[100];
    strcpy(temp, a);
    strcpy(a, b);
    strcpy(b, temp);
}

// Function to partition the array and return the pivot index
int partition(char arr[][100], int low, int high) {
    char pivot[100];
    strcpy(pivot, arr[high]);
    int i = low - 1;

    for (int j = low; j <= high - 1; j++) {
        if (strcmp(arr[j], pivot) < 0) {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[high]);
    return (i + 1);
}

// Function to implement Quick Sort
void quickSort(char arr[][100], int low, int high) {
    if (low < high) {
        int pivotIndex = partition(arr, low, high);
        quickSort(arr, low, pivotIndex - 1);
        quickSort(arr, pivotIndex + 1, high);
    }
}

int main() {
    char arr[][100] = {"banana", "apple", "grape", "orange", "pear"};
    int size = sizeof(arr) / sizeof(arr[0]);

    // Perform Quick Sort on the array
    quickSort(arr, 0, size - 1);

    printf("Sorted array:\n");
    for (int i = 0; i < size; i++) {
        printf("%s ", arr[i]);
    }

    return 0;
}
/*
This program demonstrates the Quick Sort algorithm for sorting an array of strings.
The swap function is used to swap two strings, and the partition function is responsible for rearranging
the array elements around a pivot string. The quickSort function recursively applies the Quick Sort algorithm
to sort the string array.
The sorted array is then displayed.
*/
