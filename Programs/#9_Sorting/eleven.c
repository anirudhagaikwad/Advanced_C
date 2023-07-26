/*
Given an array of intervals where intervals[i] = [starti, endi], merge all overlapping intervals,
and return an array of the non-overlapping intervals that cover all the intervals in the input.

Input: intervals = [[1,3],[2,6],[8,10],[15,18]]
Output: [[1,6],[8,10],[15,18]]
Explanation: Since intervals [1,3] and [2,6] overlap, merge them into [1,6].

*/

#include <stdio.h>
#include <stdlib.h>

// Structure to represent an interval
typedef struct {
    int start;
    int end;
} Interval;

// Function to compare intervals based on the start value
int compareIntervals(const void* a, const void* b) {
    const Interval* intervalA = (const Interval*)a;
    const Interval* intervalB = (const Interval*)b;
    return intervalA->start - intervalB->start;
}

// Function to merge overlapping intervals
Interval* mergeIntervals(Interval* intervals, int intervalsSize, int* mergedSize) {
    // Sort the intervals based on the start value
    qsort(intervals, intervalsSize, sizeof(Interval), compareIntervals);

    Interval* mergedIntervals = (Interval*)malloc(intervalsSize * sizeof(Interval));
    int i, j;

    // Merge the intervals
    for (i = 0, j = 0; i < intervalsSize; i++) {
        if (j == 0 || intervals[i].start > mergedIntervals[j - 1].end) {
            // If the current interval does not overlap with the previous merged interval,
            // add it as a new merged interval
            mergedIntervals[j] = intervals[i];
            j++;
        } else {
            // If the current interval overlaps with the previous merged interval,
            // update the end value of the previous merged interval
            if (intervals[i].end > mergedIntervals[j - 1].end) {
                mergedIntervals[j - 1].end = intervals[i].end;
            }
        }
    }

    *mergedSize = j;
    return mergedIntervals;
}

// Function to print intervals
void printIntervals(Interval* intervals, int size) {
    for (int i = 0; i < size; i++) {
        printf("[%d, %d] ", intervals[i].start, intervals[i].end);
    }
    printf("\n");
}

int main() {
    // Example input intervals
    Interval intervals[] = {{1, 3}, {2, 6}, {8, 10}, {15, 18}};
    int size = sizeof(intervals) / sizeof(Interval);

    // Merge intervals
    int mergedSize;
    Interval* mergedIntervals = mergeIntervals(intervals, size, &mergedSize);

    // Print merged intervals
    printf("Merged Intervals: ");
    printIntervals(mergedIntervals, mergedSize);

    // Free dynamically allocated memory
    free(mergedIntervals);

    return 0;
}
