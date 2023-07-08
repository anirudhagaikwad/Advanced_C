/*
You have been tasked with implementing a circular printer queue.
The printer has a limited capacity and can only hold a certain number of jobs at a time. Your goal is to create a program that
can add jobs to the printer queue and print them in the order they were added.

Implement a circular queue data structure to represent the printer queue using the given structure:

*/

#include <stdio.h>
#include <stdlib.h>

#define SIZE 5

// Structure to represent a circular queue
struct CircularQueue {
    int arr[SIZE];
    int front, rear;
};

// Function to create an empty circular queue
struct CircularQueue* createCircularQueue() {
    struct CircularQueue* queue = (struct CircularQueue*)malloc(sizeof(struct CircularQueue));
    queue->front = queue->rear = -1;
    return queue;
}

// Function to check if the circular queue is empty
int isEmpty(struct CircularQueue* queue) {
    return queue->front == -1;
}

// Function to check if the circular queue is full
int isFull(struct CircularQueue* queue) {
    return (queue->rear + 1) % SIZE == queue->front;
}

// Function to add a job to the printer queue
void enqueue(struct CircularQueue* queue, int job) {
    if (isFull(queue)) {
        printf("Printer queue is full. Please wait.\n");
        return;
    }
    if (isEmpty(queue)) {
        queue->front = 0;
    }
    queue->rear = (queue->rear + 1) % SIZE;
    queue->arr[queue->rear] = job;
    printf("Job %d added to the printer queue.\n", job);
}

// Function to print and remove the next job from the printer queue
void dequeue(struct CircularQueue* queue) {
    if (isEmpty(queue)) {
        printf("Printer queue is empty. No jobs to print.\n");
        return;
    }
    int job = queue->arr[queue->front];
    if (queue->front == queue->rear) {
        queue->front = queue->rear = -1;
    } else {
        queue->front = (queue->front + 1) % SIZE;
    }
    printf("Printing job %d...\n", job);
}

int main() {
    struct CircularQueue* printerQueue = createCircularQueue();

    enqueue(printerQueue, 1);
    enqueue(printerQueue, 2);
    enqueue(printerQueue, 3);
    dequeue(printerQueue);
    enqueue(printerQueue, 4);
    enqueue(printerQueue, 5);
    enqueue(printerQueue, 6); // Printer queue is full
    dequeue(printerQueue);
    dequeue(printerQueue);
    dequeue(printerQueue);
    dequeue(printerQueue);
    dequeue(printerQueue); // Printer queue is empty

    return 0;
}
/*
This program simulates a printer queue using a circular queue. It allows adding jobs to the printer queue
and printing them in the order they were added. If the printer queue is full, it displays a message to wait.
If the printer queue is empty, it displays a message indicating no jobs to print.
*/
