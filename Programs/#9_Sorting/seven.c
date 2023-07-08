/*
You are given an unsorted array of integers.
Implement a program that performs Merge Sort on the array to sort it in ascending order.
The program should also provide options to read the array from a file and write the sorted array to a file.

Example:

Enter the number of elements: 5
Enter the elements: 34 78 96 5 32
Original Array: 34 78 96 5 32
Sorted Array: 5 32 34 78 96
Enter the filename to save the sorted array: sortedd
Array written to the file successfully.


*/

#include <stdio.h>
#include <stdlib.h>

// Function to merge two subarrays of the array
void merge(int arr[], int left, int mid, int right) {
    int i, j, k;
    int n1 = mid - left + 1;
    int n2 = right - mid;

    // Create temporary arrays
    int* L = (int*)malloc(n1 * sizeof(int));
    int* R = (int*)malloc(n2 * sizeof(int));

    // Copy data to temporary arrays
    for (i = 0; i < n1; i++)
        L[i] = arr[left + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[mid + 1 + j];

    // Merge the temporary arrays back into arr[left..right]
    i = 0;  // Initial index of first subarray
    j = 0;  // Initial index of second subarray
    k = left;  // Initial index of merged subarray

    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    // Copy the remaining elements of L[], if any
    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    // Copy the remaining elements of R[], if any
    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }

    // Free temporary arrays
    free(L);
    free(R);
}

// Function to perform merge sort on the array
void mergeSort(int arr[], int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;

        // Sort first and second halves
        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);

        // Merge the sorted halves
        merge(arr, left, mid, right);
    }
}

// Function to display the elements of the array
void displayArray(int arr[], int size) {
    for (int i = 0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

// Function to read array from a file
void readArrayFromFile(char* filename, int arr[], int size) {
    FILE* file = fopen(filename, "r");
    if (file != NULL) {
        for (int i = 0; i < size; i++)
            fscanf(file, "%d", &arr[i]);
        fclose(file);
    } else {
        printf("Failed to open the file.\n");
    }
}

// Function to write array to a file
void writeArrayToFile(char* filename, int arr[], int size) {
    FILE* file = fopen(filename, "w");
    if (file != NULL) {
        for (int i = 0; i < size; i++)
            fprintf(file, "%d ", arr[i]);
        fclose(file);
        printf("Array written to the file successfully.\n");
    } else {
        printf("Failed to open the file.\n");
    }
}

int main() {
    int size;
    printf("Enter the number of elements: ");
    scanf("%d", &size);

    int* arr = (int*)malloc(size * sizeof(int));
    printf("Enter the elements: ");
    for (int i = 0; i < size; i++)
        scanf("%d", &arr[i]);

    printf("Original Array: ");
    displayArray(arr, size);

    mergeSort(arr, 0, size - 1);

    printf("Sorted Array: ");
    displayArray(arr, size);

    char filename[50];
    printf("Enter the filename to save the sorted array: ");
    scanf("%s", filename);

    writeArrayToFile(filename, arr, size);

    free(arr);

    return 0;
}

/*
The provided C program demonstrates the implementation of Merge Sort to sort an array of integers.
Here's a brief description of the code:

merge(): This function takes an array arr, indices left, mid, and right, and performs the merging of two sorted subarrays.
It creates temporary arrays L and R to store the left and right subarrays and then merges them back into the original array arr.

mergeSort(): This function is the main recursive function to perform Merge Sort. It takes an array arr, indices left, and right.
It recursively divides the array into two halves, sorts each half using mergeSort(), and then merges the two sorted halves using
merge().

displayArray(): This function takes an array arr and its size size as input and prints all the elements of the array on the console.

readArrayFromFile(): This function takes a file name filename, an array arr, and its size size as input.
It reads the elements of the array from a file with the given filename.

writeArrayToFile(): This function takes a file name filename, an array arr, and its size size as input.
It writes the elements of the array to a file with the given filename.

main(): In the main() function, the user is asked to enter the number of elements and the array elements themselves.
The original array is then displayed. The mergeSort() function is called to sort the array, and the sorted array is displayed.
The user is prompted to enter a filename to save the sorted array, and the writeArrayToFile()
function is called to write the sorted array to the specified file.
*/
