/*
Implement the Quick Sort algorithm to sort an array of integers in ascending order.

Input:
9, 4, 7, 2, 1, 5, 8, 3, 6

Output:
Sorted array: 1 2 3 4 5 6 7 8 9

*/

#include <stdio.h>

// Function to swap two integer values
void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Function to partition the array and return the pivot index
int partition(int arr[], int low, int high) {
    int pivot = arr[high];
    int i = low - 1;

    for (int j = low; j <= high - 1; j++) {
        if (arr[j] < pivot) {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return (i + 1);
}

// Function to implement Quick Sort
void quickSort(int arr[], int low, int high) {
    if (low < high) {
        int pivotIndex = partition(arr, low, high);
        quickSort(arr, low, pivotIndex - 1);
        quickSort(arr, pivotIndex + 1, high);
    }
}

int main() {
    int arr[] = {9, 4, 7, 2, 1, 5, 8, 3, 6};
    int size = sizeof(arr) / sizeof(arr[0]);

    // Perform Quick Sort on the array
    quickSort(arr, 0, size - 1);

    printf("Sorted array: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }

    return 0;
}

/*
This program demonstrates the Quick Sort algorithm for sorting an array of integers.
The swap function is used to swap two integer values, and the partition function is responsible for
rearranging the array elements around a pivot. The quickSort function recursively applies the Quick Sort
algorithm to sort the array.
The sorted array is then displayed.
*/




