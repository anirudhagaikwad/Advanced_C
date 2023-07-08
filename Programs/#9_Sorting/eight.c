/*
Given an array of integers, the task is to count the number of inversions in the array.
An inversion occurs when two elements in the array are out of order, i.e., if arr[i] > arr[j] and i < j.
The goal is to determine how far the array is from being sorted in ascending order.

Input: arr[] = {18, 14, 12, 11}
Output: 6
Explanation: Given array has six inversions: (18, 14), (14, 12), (18, 12), (18, 11), (14, 11), (12, 11).

*/
#include <stdio.h>
#include <stdlib.h>

int _mergeSort(int arr[], int temp[], int left, int right);
int merge(int arr[], int temp[], int left, int mid,
		int right);

// This function sorts the input array and returns the number of inversions in the array
int mergeSort(int arr[], int array_size)
{
	int* temp = (int*)malloc(sizeof(int) * array_size);
	return _mergeSort(arr, temp, 0, array_size - 1);
}

// An auxiliary recursive function that sorts the input array and returns the number
// of inversions in the array.
int _mergeSort(int arr[], int temp[], int left, int right)
{
	int mid, inv_count = 0;
	if (right > left) {
		// Divide the array into two parts and call
		// _mergeSortAndCountInv() for each of the parts
		mid = (right + left) / 2;

		// Inversion count will be the sum of inversions in
		// left-part, right-part and number of inversions in
		// merging
		inv_count += _mergeSort(arr, temp, left, mid);
		inv_count += _mergeSort(arr, temp, mid + 1, right);

		// Merge the two parts
		inv_count += merge(arr, temp, left, mid + 1, right);
	}
	return inv_count;
}

// This function merges two sorted  arrays and returns inversion count in the arrays.
int merge(int arr[], int temp[], int left, int mid,
		int right)
{
	int i, j, k;
	int inv_count = 0;

	i = left;
	j = mid;
	k = left;
	while ((i <= mid - 1) && (j <= right)) {
		if (arr[i] <= arr[j]) {
			temp[k++] = arr[i++];
		}
		else {
			temp[k++] = arr[j++];

			/*this is tricky -- see above
			* explanation/diagram for merge()*/
			inv_count = inv_count + (mid - i);
		}
	}

	// Copy the remaining elements of left subarray
	// (if there are any) to temp
	while (i <= mid - 1)
		temp[k++] = arr[i++];

	// Copy the remaining elements of right subarray
	// (if there are any) to temp
	while (j <= right)
		temp[k++] = arr[j++];

	// Copy back the merged elements to original array
	for (i = left; i <= right; i++)
		arr[i] = temp[i];

	return inv_count;
}


int main(int argv, char** args)
{
	int arr[] = { 18, 14, 12, 11};
	printf(" Number of inversions are %d \n",
		mergeSort(arr, 5));
	getchar();
	return 0;
}
/*
The provided C program implements a modified version of the Merge Sort algorithm to count the number of inversions in an array.
The program utilizes a divide-and-conquer approach to sort the array while keeping track of the inversions.

The mergeSort function is the entry point that initiates the sorting process. It dynamically allocates memory for a temporary array
called temp, which is used during the merge operation. The function then calls the _mergeSort function, which performs the actual sorting
 and inversion counting.

The _mergeSort function recursively divides the array into halves until individual elements are reached. It merges the sorted halves back
 together while counting the inversions. The inversions are counted during the merging process whenever an element from the right half
 is smaller than an element from the left half.

The merge function merges two sorted subarrays, updating the inversion count if necessary. It iterates through the elements of both
subarrays and copies them to the temporary array in the appropriate order. The inversions are counted by adding the number of remaining
elements in the left subarray when an element from the right subarray is chosen.

In the main function, an example array arr is provided. The mergeSort function is called with the array and its size. The number of
inversions is then printed as output.

Overall, this program efficiently uses the Merge Sort algorithm to determine the number of inversions in an array, providing insight
into how unsorted the array is.
*/
