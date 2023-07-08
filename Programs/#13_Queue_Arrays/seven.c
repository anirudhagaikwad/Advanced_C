/*
You are given an array of integers nums, there is a sliding window of size k which is moving from the very left of
the array to the very right. You can only see the k numbers in the window. Each time the sliding window moves right by one position.
Return the max sliding window.

Example 1:

Input: nums = [1,3,-1,-3,5,3,6,7], k = 3
Output: [3,3,5,5,6,7]

Explanation:
Window position                Max
---------------               -----
[1  3  -1] -3  5  3  6  7       3
 1 [3  -1  -3] 5  3  6  7       3
 1  3 [-1  -3  5] 3  6  7       5
 1  3  -1 [-3  5  3] 6  7       5
 1  3  -1  -3 [5  3  6] 7       6
 1  3  -1  -3  5 [3  6  7]      7
*/

#include <stdio.h>

// Function to find the maximum element in a sliding window
void maxSlidingWindow(int nums[], int size, int k)
{
    // Create a temporary array to store the indices of the elements
    int temp[size];
    int front = 0, rear = 0;
    temp[rear++] = 0;

    // Process the first 'k' elements to find the maximum
    for (int i = 1; i < k; i++)
    {
        // Remove smaller elements from the rear of the queue
        while (rear > front && nums[i] >= nums[temp[rear - 1]])
            rear--;

        // Add the current element at the rear of the queue
        temp[rear++] = i;
    }

    // Process the remaining elements
    for (int i = k; i < size; i++)
    {
        // The front element is the maximum for the previous window
        printf("%d ", nums[temp[front]]);

        // Remove elements that are no longer in the current window
        while (rear > front && temp[front] <= i - k)
            front++;

        // Remove smaller elements from the rear of the queue
        while (rear > front && nums[i] >= nums[temp[rear - 1]])
            rear--;

        // Add the current element at the rear of the queue
        temp[rear++] = i;
    }

    // Print the maximum element of the last window
    printf("%d\n", nums[temp[front]]);
}

int main()
{
    int nums[] = {1, 3, -1, -3, 5, 3, 6, 7};
    int k = 3;
    int size = sizeof(nums) / sizeof(nums[0]);

    maxSlidingWindow(nums, size, k);

    return 0;
}

/*
    Given an array and a window size, find the maximum element in each sliding window of size k using Queue data structure.
*/
