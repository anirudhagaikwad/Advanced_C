/*
Round-Robin Scheduling Simulation:-
You have been assigned the task of developing a program to simulate a process scheduling queue.
The queue will hold a set of processes that need to be executed.
Your goal is to create a program that can add processes to the scheduling queue and execute them in the order they were added.

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

// Function to add a process to the scheduling queue
void enqueue(struct CircularQueue* queue, int process) {
    if (isFull(queue)) {
        printf("Scheduling queue is full. Cannot add more processes.\n");
        return;
    }
    if (isEmpty(queue)) {
        queue->front = 0;
    }
    queue->rear = (queue->rear + 1) % SIZE;
    queue->arr[queue->rear] = process;
    printf("Process %d added to the scheduling queue.\n", process);
}

// Function to execute and remove the next process from the scheduling queue
void executeProcess(struct CircularQueue* queue) {
    if (isEmpty(queue)) {
        printf("Scheduling queue is empty. No processes to execute.\n");
        return;
    }
    int process = queue->arr[queue->front];
    if (queue->front == queue->rear) {
        queue->front = queue->rear = -1;
    } else {
        queue->front = (queue->front + 1) % SIZE;
    }
    printf("Executing process %d...\n", process);
}

int main() {
    struct CircularQueue* schedulingQueue = createCircularQueue();

    enqueue(schedulingQueue, 1);
    enqueue(schedulingQueue, 2);
    enqueue(schedulingQueue, 3);
    executeProcess(schedulingQueue);
    enqueue(schedulingQueue, 4);
    enqueue(schedulingQueue, 5);
    executeProcess(schedulingQueue);
    executeProcess(schedulingQueue);
    executeProcess(schedulingQueue);
    executeProcess(schedulingQueue); // Scheduling queue is empty

    return 0;
}

/*
This program simulates the round-robin scheduling algorithm using a circular queue.
It allows adding processes to the scheduling queue and executing them in a circular manner.
If the scheduling queue is empty, it displays a message indicating no processes to execute.
*/

