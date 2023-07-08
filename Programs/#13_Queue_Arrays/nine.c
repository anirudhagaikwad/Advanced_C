/*
Write a C program that calculates the sliding window average for a given array of integers.
The program should implement a queue data structure using an array and provide functions to add and remove elements from the queue.
The sliding window average is calculated by maintaining a window of size 'k' and moving it through the array.
At each position of the window, the program should calculate and display the average of the elements within the window.

Example:

Input: { 1, 3, -1, -3, 5, 3, 6, 7 }
       K=3
Output:

    Average of window 1 to 3: 1.00
    Average of window 2 to 4: -0.33
    Average of window 3 to 5: 0.33
    Average of window 4 to 6: 1.67
    Average of window 5 to 7: 4.67
    Average of window 6 to 8: 5.33
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

// Function to find the sliding window average
void findSlidingWindowAverage(int arr[], int n, int k) {
    struct Queue* queue = createQueue();
    int sum = 0;

    for (int i = 0; i < k; i++) {
        enqueue(queue, arr[i]);
        sum += arr[i];
    }

    printf("Average of window 1 to %d: %.2f\n", k, (float)sum / k);

    for (int i = k; i < n; i++) {
        int removedItem = dequeue(queue);
        enqueue(queue, arr[i]);
        sum = sum - removedItem + arr[i];
        printf("Average of window %d to %d: %.2f\n", i - k + 2, i + 1, (float)sum / k);
    }
}

int main() {
    int arr[] = { 1, 3, -1, -3, 5, 3, 6, 7 };
    int n = sizeof(arr) / sizeof(arr[0]);
    int k = 3;
    findSlidingWindowAverage(arr, n, k);
    return 0;
}
/*
This C program demonstrates finding the sliding window average of an array. The program uses a queue data structure implemented using
an array to maintain a window of elements. The sliding window is moved one element at a time, and the average of the
elements within the window is calculated.

The struct Queue represents the queue with an array arr and front and rear pointers. The createQueue function is used to create an
empty queue by allocating memory and initializing the front and rear pointers.

The isEmpty function checks if the queue is empty by comparing the front pointer with -1.

The enqueue function adds an element to the rear of the queue. If the queue is full, it prints "Queue is full" and returns.
Otherwise, it increments the rear pointer, assigns the element to the corresponding position in the array, and updates the front
pointer if it was -1.

The dequeue function removes an element from the front of the queue. If the queue is empty, it prints "Queue is empty" and returns -1.
Otherwise, it retrieves the element at the front position, increments the front pointer, and updates the front and rear pointers to -1
if they become equal, indicating an empty queue.

The findSlidingWindowAverage function takes an array, its size n, and the window size k as input. It creates a queue and initializes
the sum to 0. It then iterates through the first k elements of the array, enqueues them, and updates the sum. It calculates and prints
the average of the first window.

In the subsequent iterations, it dequeues the first element of the previous window, enqueues the next element, updates the sum by
subtracting the dequeued element and adding the enqueued element, and calculates and prints the average of the current window.

Finally, in the main function, an example array arr is defined with its size n determined using the sizeof operator.
The window size k is set to 3. The findSlidingWindowAverage function is called with these parameters to find and print
the sliding window averages.
*/
