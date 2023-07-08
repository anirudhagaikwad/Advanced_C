/*
Given an array of integers and an integer k, find the kth smallest element in the array.

Input:
Original array: 10 7 8 9 1 5

Output:
Sorted array: 1 5 7 8 9 10
The 4th smallest element is 8


*/

#include <stdio.h>

// Function to swap two elements
void swap(int* a, int* b) {
    int t = *a;
    *a = *b;
    *b = t;
}

// Partition function for QuickSort
int partition(int arr[], int low, int high) {
    int pivot = arr[high];
    int i = (low - 1);

    for (int j = low; j <= high - 1; j++) {
        if (arr[j] < pivot) {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return (i + 1);
}

// Quicksort function
void quickSort(int arr[], int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

// Function to find the kth smallest element
int findKthSmallest(int arr[], int low, int high, int k) {
    if (k > 0 && k <= (high - low + 1)) {
        int pi = partition(arr, low, high);

        // If the partition index is the kth smallest element
        if (pi - low == k - 1)
            return arr[pi];

        // If the partition index is more than kth smallest element,
        // then recur for the left subarray
        if (pi - low > k - 1)
            return findKthSmallest(arr, low, pi - 1, k);

        // Else recur for the right subarray
        return findKthSmallest(arr, pi + 1, high, k - pi + low - 1);
    }

    // If k is out of range, return -1
    return -1;
}


int main() {
    int arr[] = {10, 7, 8, 9, 1, 5};
    int n = sizeof(arr) / sizeof(arr[0]);
    int k = 4;

    printf("Original array: ");
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");

    quickSort(arr, 0, n - 1);

    printf("Sorted array: ");
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");

    int kthSmallest = findKthSmallest(arr, 0, n - 1, k);
    if (kthSmallest != -1)
        printf("The %dth smallest element is %d\n", k, kthSmallest);
    else
        printf("Invalid value of k\n");

    return 0;
}


/*
 The program uses the QuickSort algorithm to sort the array in ascending order.
 After sorting, it finds the kth smallest element by recursively partitioning the array based on
 the pivot element until the desired position (k-1) is reached. If the desired position is found,
 the element at that position is returned as the kth smallest element. If the desired position is
 to the left of the pivot, the left subarray is recursively processed. Otherwise, the right subarray is recursively processed.
 The program prints the original array, the sorted array, and the kth smallest element.

*/
