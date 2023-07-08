/*
Write a C program to implement Circular Queue data structure using dynamic memory allocation.
*/
#include <stdio.h>
#include <stdlib.h>

// Structure for circular queue
struct CircularQueue {
    int* items;
    int front, rear;
    int size;
};

// Function to initialize circular queue
void init(struct CircularQueue* queue, int size) {
    queue->items = (int*)malloc(size * sizeof(int));
    queue->front = -1;
    queue->rear = -1;
    queue->size = size;
}

// Function to check if the circular queue is full
int isFull(struct CircularQueue* queue) {
    if ((queue->front == 0 && queue->rear == queue->size - 1) || (queue->front == queue->rear + 1))
        return 1;
    return 0;
}

// Function to check if the circular queue is empty
int isEmpty(struct CircularQueue* queue) {
    if (queue->front == -1)
        return 1;
    return 0;
}

// Function to add an element to the circular queue
void enqueue(struct CircularQueue* queue, int value) {
    if (isFull(queue)) {
        printf("Queue is full.\n");
        return;
    }
    if (isEmpty(queue))
        queue->front = 0;
    queue->rear = (queue->rear + 1) % queue->size;
    queue->items[queue->rear] = value;
    printf("Enqueued: %d\n", value);
}

// Function to remove an element from the circular queue
int dequeue(struct CircularQueue* queue) {
    if (isEmpty(queue)) {
        printf("Queue is empty.\n");
        return -1;
    }
    int removed = queue->items[queue->front];
    if (queue->front == queue->rear) {
        queue->front = -1;
        queue->rear = -1;
    }
    else
        queue->front = (queue->front + 1) % queue->size;
    return removed;
}

// Function to display the circular queue
void display(struct CircularQueue* queue) {
    if (isEmpty(queue)) {
        printf("Queue is empty.\n");
        return;
    }
    int i = queue->front;
    printf("Circular Queue: ");
    while (i != queue->rear) {
        printf("%d ", queue->items[i]);
        i = (i + 1) % queue->size;
    }
    printf("%d\n", queue->items[i]);
}

int main() {
    struct CircularQueue queue;
    int size = 5;
    init(&queue, size);

    enqueue(&queue, 1);
    enqueue(&queue, 2);
    enqueue(&queue, 3);
    enqueue(&queue, 4);
    enqueue(&queue, 5);
    display(&queue);

    int removed = dequeue(&queue);
    printf("Dequeued: %d\n", removed);

    display(&queue);
    enqueue(&queue, 6);
    display(&queue);

    free(queue.items);

    return 0;
}
/*
 This program implements a circular queue using dynamic memory allocation for the array.
 The CircularQueue structure contains a pointer to the array, front and rear pointers, and the size of the queue.
 The program provides functions to initialize the circular queue, check if it's full or empty, enqueue an element, dequeue an element,
 and display the contents of the circular queue. The main function demonstrates the usage of these functions by enqueueing elements,
 dequeueing an element, and displaying the circular queue.
*/
