/*
Implement the Quick Sort algorithm to sort an array of custom struct elements based on a specific field (e.g., age).

Example:
Original ARray: {{"Alice", 25}, {"Bob", 19}, {"John", 37}, {"Emily", 32}}

Sorted array:
Name: Bob, Age: 19
Name: Alice, Age: 25
Name: Emily, Age: 32
Name: John, Age: 37

*/
#include <stdio.h>
#include <string.h>

// Custom struct representing a person
struct Person {
    char name[50];
    int age;
};

// Function to swap two struct elements
void swap(struct Person* a, struct Person* b) {
    struct Person temp;
    strcpy(temp.name, a->name);
    temp.age = a->age;
    strcpy(a->name, b->name);
    a->age = b->age;
    strcpy(b->name, temp.name);
    b->age = temp.age;
}

// Function to partition the array and return the pivot index
int partition(struct Person arr[], int low, int high) {
    struct Person pivot = arr[high];
    int i = low - 1;

    for (int j = low; j <= high - 1; j++) {
        if (arr[j].age < pivot.age) {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return (i + 1);
}

// Function to implement Quick Sort
void quickSort(struct Person arr[], int low, int high) {
    if (low < high) {
        int pivotIndex = partition(arr, low, high);
        quickSort(arr, low, pivotIndex - 1);
        quickSort(arr, pivotIndex + 1, high);
    }
}

int main() {
    struct Person arr[] = {{"Alice", 25}, {"Bob", 19}, {"John", 37}, {"Emily", 32}};
    int size = sizeof(arr) / sizeof(arr[0]);

    // Perform Quick Sort on the array
    quickSort(arr, 0, size - 1);

    printf("Sorted array:\n");
    for (int i = 0; i < size; i++) {
        printf("Name: %s, Age: %d\n", arr[i].name, arr[i].age);
    }

    return 0;
}
/*
This program demonstrates the Quick Sort algorithm for sorting an array of custom struct elements.
In this example, the Person struct represents a person with a name and an age.
The swap function is used to swap two struct elements, and the partition function is responsible for rearranging
the array elements based on the age field. The quickSort function recursively applies the Quick Sort algorithm to
sort the struct array. The sorted array is then displayed.
*/
