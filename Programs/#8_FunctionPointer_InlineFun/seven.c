/*
Write s function pointer program in C that involves sorting an array of strings in ascending order.
The program utilizes function pointers to dynamically choose the sorting algorithm at runtime.
Each sorting algorithm is implemented as a separate function, and the function pointer is used to select the
appropriate sorting function.

Input:
Choose sorting algorithm:
1. Bubble Sort
2. Selection Sort
Enter your choice: 1

Output:
Sorted array:
Alice
Bob
David
Emily
John

Input:
Choose sorting algorithm:
1. Bubble Sort
2. Selection Sort
Enter your choice: 2

Output:
Sorted array:
Alice
Bob
David
Emily
John

*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function pointer type for the sorting function
typedef void (*SortFunction)(char**, int);

// Bubble sort algorithm
void bubbleSort(char** arr, int size) {
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            if (strcmp(arr[j], arr[j + 1]) > 0) {
                char* temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

// Selection sort algorithm
void selectionSort(char** arr, int size) {
    for (int i = 0; i < size - 1; i++) {
        int minIndex = i;
        for (int j = i + 1; j < size; j++) {
            if (strcmp(arr[j], arr[minIndex]) < 0) {
                minIndex = j;
            }
        }
        if (minIndex != i) {
            char* temp = arr[i];
            arr[i] = arr[minIndex];
            arr[minIndex] = temp;
        }
    }
}

// Function to print the sorted array
void printArray(char** arr, int size) {
    printf("Sorted array:\n");
    for (int i = 0; i < size; i++) {
        printf("%s\n", arr[i]);
    }
}

int main() {
    char* arr[] = {"John", "Alice", "Bob", "David", "Emily"};
    int size = sizeof(arr) / sizeof(arr[0]);

    SortFunction sortFunc;  // Function pointer declaration

    // Prompt the user to choose the sorting algorithm
    int choice;
    printf("Choose sorting algorithm:\n");
    printf("1. Bubble Sort\n");
    printf("2. Selection Sort\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    // Assign the appropriate sorting function to the function pointer
    if (choice == 1) {
        sortFunc = bubbleSort;
    } else if (choice == 2) {
        sortFunc = selectionSort;
    } else {
        printf("Invalid choice!\n");
        return 1;
    }

    // Sort the array using the selected sorting algorithm
    sortFunc(arr, size);

    // Print the sorted array
    printArray(arr, size);

    return 0;
}
/*
This program demonstrates the usage of function pointers in C for sorting an array of strings.
The program presents the user with a choice to select either the Bubble Sort or Selection Sort algorithm.
The appropriate sorting algorithm is then assigned to the function pointer sortFunc.
The selected sorting algorithm is applied to sort the array of strings, and the sorted array is printed.

The program implements the Bubble Sort and Selection Sort algorithms as separate functions (bubbleSort and selectionSort).
These sorting functions take an array of strings and its size as arguments.
The printArray function is responsible for displaying the sorted array.
*/
