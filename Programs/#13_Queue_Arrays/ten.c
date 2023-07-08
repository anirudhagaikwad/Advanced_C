/*
Write a C program that finds the first negative integer in every window of size 'k' in a given array.
The program should implement a queue data structure using an array and provide functions to add and remove elements from the queue.
The first negative integer in a window is the negative integer that appears first when moving the window through the array.

Input:  { 12, -1, -7, 8, -15, 30, 16, 28 }
        k=3
Output: -1 -1 -7 -15 -15 0
*/


#include <stdio.h>
#include <stdlib.h>

#define SIZE 100

// Structure to represent a queue
struct Queue {
    int arr[SIZE];
    int front, rear;
};

// Function to create an empty queue
struct Queue* createQueue() {
    struct Queue* queue = (struct Queue*)malloc(sizeof(struct Queue));
    queue->front = queue->rear = -1;
    return queue;
}

// Function to check if the queue is empty
int isEmpty(struct Queue* queue) {
    return queue->front == -1;
}

// Function to add an element to the queue
void enqueue(struct Queue* queue, int item) {
    if (queue->rear == SIZE - 1) {
        printf("Queue is full");
        return;
    }
    queue->arr[++queue->rear] = item;
    if (queue->front == -1) {
        queue->front = 0;
    }
}

// Function to remove an element from the queue
int dequeue(struct Queue* queue) {
    if (isEmpty(queue)) {
        printf("Queue is empty");
        return -1;
    }
    int item = queue->arr[queue->front];
    if (queue->front == queue->rear) {
        queue->front = queue->rear = -1;
    } else {
        queue->front++;
    }
    return item;
}

// Function to find the first negative integer in every window of size k
void findFirstNegativeInWindow(int arr[], int n, int k) {
    struct Queue* queue = createQueue();

    // Traverse through each window of size k
    for (int i = 0; i < n - k + 1; i++) {
        // Enqueue all negative integers in the current window
        for (int j = i; j < i + k; j++) {
            if (arr[j] < 0) {
                enqueue(queue, arr[j]);
                break; // Only enqueue the first negative integer in the window
            }
        }

        // If the queue is not empty, print the front element (first negative integer)
        // Otherwise, print 0 to indicate no negative integer in the window
        if (!isEmpty(queue)) {
            printf("%d ", queue->arr[queue->front]);
        } else {
            printf("0 ");
        }

        // Dequeue elements that are no longer in the current window
        while (!isEmpty(queue) && queue->front <= i) {
            dequeue(queue);
        }
    }
}

int main() {
    int arr[] = { 12, -1, -7, 8, -15, 30, 16, 28 };
    int n = sizeof(arr) / sizeof(arr[0]);
    int k = 3;

    printf("Array: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    printf("Window Size (k): %d\n", k);
    printf("First Negative Integers in Windows: ");

    findFirstNegativeInWindow(arr, n, k);

    return 0;
}


/*
This program finds the first negative integer in every window of size k in an array using a queue.
It creates a queue data structure and implements functions to add and remove elements from the queue.
The findFirstNegativeInWindow function iterates through the array, maintaining a queue of indices of negative integers in
the current window. It removes indices from the queue that are no longer part of the window and adds new indices if a negative
integer is encountered. The first negative integer in each window is printed, or 0 if no negative integer is found.
*/
