/*
Quick sort is a popular sorting algorithm known for its efficiency and speed. It follows the divide-and-conquer strategy to sort an array or a list of elements. The basic idea is to select a "pivot" element from the array and partition the other elements into two sub-arrays or sub-lists, according to whether they are less than or greater than the pivot. The sub-arrays are then sorted recursively. This process continues until the entire array is sorted.
*/
#include <stdio.h>

// Function to swap two elements in an array
void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Function to partition the array and return the pivot index
int partition(int arr[], int low, int high) {
    int pivot = arr[high]; // Choose the last element as the pivot
    int i = (low - 1); // Index of the smaller element

    for (int j = low; j < high; j++) {
        // If the current element is less than or equal to the pivot
        if (arr[j] <= pivot) {
            i++;
            // Swap arr[i] and arr[j]
            swap(&arr[i], &arr[j]);
        }
    }

    // Swap arr[i + 1] and arr[high] (pivot)
    swap(&arr[i + 1], &arr[high]);
    return (i + 1);
}

// Function to perform the Quick Sort
void quickSort(int arr[], int low, int high) {
    if (low < high) {
        // Find pivot index (partitioning)
        int pivotIndex = partition(arr, low, high);

        // Recursively sort elements before and after the pivot
        quickSort(arr, low, pivotIndex - 1);
        quickSort(arr, pivotIndex + 1, high);
    }
}

int main() {
    int arr[] = {64, 25, 12, 22, 11};
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("Original array: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    quickSort(arr, 0, n - 1);

    printf("Sorted array: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}

/*

swap: A helper function to swap two elements in an array.

partition: This function takes the last element as the pivot, places the pivot element at its correct position in the sorted array, and arranges all smaller elements to the left and larger elements to the right of the pivot.

quickSort: The main Quick Sort function that recursively divides the array and sorts the sub-arrays.

pivot : is a chosen element from the array that serves as a reference point for partitioning the array into two sub-arrays during each step of the sorting process. The primary purpose of the pivot is to help rearrange the elements in the array so that elements less than the pivot come before it, and elements greater than the pivot come after it.

*/
