/*
Sonu wants to paint her club house that has n boards with different lengths.
The length of ith board is given by arr[i] where arr[] is an array of n integers.
She hired k painters for this work and each painter takes 1 unit time to paint 1 unit of the board.

The problem is to find the minimum time to get this job done if all painters start together with
the constraint that any painter will only paint continuous boards, say boards numbered {2,3,4}
or only board {1} or nothing but not boards {2,4,5}.

Input: N = 4, A = {10, 20, 30, 40}, K = 2
Output : 60


Input: N = 6, A = { 10, 20, 60, 50, 30, 40 }, K = 3
Output : 90

*/
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#define max(x,y) ((x>y)?x:y)

// Function to calculate sum between two indices in array
int sum(int arr[], int from, int to)
{
	int total = 0;
	for (int i = from; i <= to; i++)
		total += arr[i];
	return total;
}

// Function to find the minimum of all possible maximum k-1 partitions
int partition(int arr[], int n, int k)
{
	// Base cases
	if (k == 1) // One partition
		return sum(arr, 0, n - 1);
	if (n == 1) // One board
		return arr[0];

	int best = INT_MAX;

	// Find the minimum of all possible maximum k-1 partitions
	// to the left of arr[i], with i elements. Put the k-1 th
	// divider between arr[i-1] & arr[i] to get k-th partition.
	for (int i = 1; i <= n; i++)
		best = (best < (max(partition(arr, i, k - 1),
							sum(arr, i, n - 1)))) ? best : (max(partition(arr, i, k - 1), sum(arr, i, n - 1)));

	return best;
}

int main()
{
	int arr[] = { 10, 20, 30, 40 };
	int n = sizeof(arr) / sizeof(arr[0]);
	int k = 2;
	printf("%d\n", partition(arr, n, k));

	return 0;
}
/*
This C program solves the painter's partition problem. Given an array of lengths representing boards and the number of painters, the goal is to divide the boards among the painters in such a way that the maximum length of boards assigned to a painter is minimized.
The program uses a recursive approach to find the minimum of all possible maximum k-1 partitions.

The sum function calculates the sum of elements between two indices in the array. It iterates through the array and
adds the elements to the total variable.

The partition function is the main recursive function that solves the problem. It has three base cases: when there is only one partition (k == 1), it returns the sum of all elements; when there is only one board (n == 1), it returns the length of that board. Otherwise, it iterates through the array and finds the minimum of all possible maximum k-1 partitions to the left of arr[i]. It uses the sum function to calculate the sum of elements from arr[i] to arr[n-1].

The main function initializes the array of board lengths, arr, and determines its size, n. It also specifies the number of painters, k. It calls the partition function and prints the result.
*/
