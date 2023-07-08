/*
Given two sorted arrays arr1[] and arr2[] of sizes n and m in non-decreasing order.
Merge them in sorted order without using any extra space.
Modify arr1 so that it contains the first N elements and modify arr2 so that it contains the last M elements.

Input:
n = 4, arr1[] = [1 3 5 7]
m = 5, arr2[] = [0 2 6 8 9]

Output:
arr1[] = [0 1 2 3]
arr2[] = [5 6 7 8 9]

*/

#include <stdio.h>

// Function to merge the arrays without using extra space.
void mergeArrays(int arr1[], int arr2[], int n, int m)
{
    // Traverse both arrays from the last element to the first element.
    // Start with the last element of arr1 and the last element of arr2.
    int i = n - 1;
    int j = m - 1;
    int k = n + m - 1; // Index to store the merged elements.

    while (i >= 0 && j >= 0)
    {
        // If the current element of arr1 is greater than the current element of arr2,
        // place it at the last index of arr1 and decrement the indices.
        if (arr1[i] > arr2[j])
        {
            arr1[k] = arr1[i];
            i--;
        }
        // If the current element of arr2 is greater than or equal to the current element of arr1,
        // place it at the last index of arr1 and decrement the indices.
        else
        {
            arr1[k] = arr2[j];
            j--;
        }
        k--;
    }

    // If there are any remaining elements in arr2, copy them to arr1.
    while (j >= 0)
    {
        arr1[k] = arr2[j];
        j--;
        k--;
    }
}

int main()
{
    int n, m;
    printf("Enter the size of the first array (arr1): ");
    scanf("%d", &n);
    printf("Enter the size of the second array (arr2): ");
    scanf("%d", &m);

    int arr1[n + m]; // Create an array to store the merged elements of arr1 and arr2.
    int arr2[m];

    printf("Enter the elements of the first array (arr1) in non-decreasing order: ");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr1[i]);
    }

    printf("Enter the elements of the second array (arr2) in non-decreasing order: ");
    for (int i = 0; i < m; i++)
    {
        scanf("%d", &arr2[i]);
    }

    mergeArrays(arr1, arr2, n, m);

    printf("Merged array (arr1) with the first %d elements: ", n);
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr1[i]);
    }
    printf("\n");

    printf("Modified array (arr2) with the last %d elements: ", m);
    for (int i = n; i < n + m; i++)
    {
        printf("%d ", arr1[i]);
    }
    printf("\n");

    return 0;
}
