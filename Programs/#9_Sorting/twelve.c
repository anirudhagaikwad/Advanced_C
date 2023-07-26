/*
Given an array nums of size n, return the majority element.
The majority element is the element that appears more than ⌊n / 2⌋ times.
You may assume that the majority element always exists in the array.

Input: nums = [3,2,3]
Output: 3

Input: nums = [2,2,1,1,1,2,2]
Output: 2

*/

#include <stdio.h>

int majorityElement(int* nums, int numsSize) {
    int count = 1;
    int majority = nums[0];

    // Traverse the array starting from the second element
    for (int i = 1; i < numsSize; i++) {
        if (count == 0) {
            // If count is 0, update the majority element to the current element
            majority = nums[i];
            count = 1;
        } else if (nums[i] == majority) {
            // If the current element is equal to the majority element, increment the count
            count++;
        } else {
            // If the current element is different from the majority element, decrement the count
            count--;
        }
    }

    return majority;
}

int main() {
    int nums[] = {2, 2, 1, 1, 1, 2, 2};
    int numsSize = sizeof(nums) / sizeof(nums[0]);

    int result = majorityElement(nums, numsSize);
    printf("The majority element is: %d\n", result);

    return 0;
}
/*

The program uses Moore's Voting Algorithm to find the majority element in the given array. The algorithm assumes that the majority element always exists in the array.

The majorityElement function takes two parameters: nums, a pointer to the input array, and numsSize, the size of the array. It returns the majority element.

The program initializes the count variable to 1 and the majority variable to the first element of the array. It then traverses the array starting from the second element.

In each iteration, it compares the current element with the majority element. If the count is 0 (indicating that the current majority candidate does not have a majority so far), it updates the majority element to the current element and resets the count to 1.

If the current element is equal to the majority element, it increments the count. If the current element is different from the majority element, it decrements the count.

By the end of the loop, the majority element will be the element that appears more than ⌊n / 2⌋ times, as required. It is then returned by the function.
*/
