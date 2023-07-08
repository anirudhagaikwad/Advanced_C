/*
You are tasked with implementing a cache management system using a circular queue data structure.
The system should be able to add pages to the cache and display the contents of the cache.

Write Function to add a page to the cache. If the cache is full, it should replace the page at the front of the queue with the
new page and display a message "Cache is full. Page <page> replaced." Otherwise, it should add the page to the rear of the queue
and display a message "Page <page> added to the cache."

Write Function to display the contents of the cache. If the cache is empty, it should display a message "Cache is empty." Otherwise,
it should display the cache contents in the order they are stored in the circular queue, separated by a space.

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

// Function to add a page to the cache
void addPage(struct CircularQueue* queue, int page) {
    if (isFull(queue)) {
        printf("Cache is full. Page %d replaced.\n", queue->arr[queue->front]);
        queue->front = (queue->front + 1) % SIZE;
    }
    if (isEmpty(queue)) {
        queue->front = 0;
    }
    queue->rear = (queue->rear + 1) % SIZE;
    queue->arr[queue->rear] = page;
    printf("Page %d added to the cache.\n", page);
}

// Function to display the contents of the cache
void displayCache(struct CircularQueue* queue) {
    if (isEmpty(queue)) {
        printf("Cache is empty.\n");
        return;
    }
    printf("Cache Contents: ");
    int i = queue->front;
    while (i != queue->rear) {
        printf("%d ", queue->arr[i]);
        i = (i + 1) % SIZE;
    }
    printf("%d\n", queue->arr[i]);
}

int main() {
    struct CircularQueue* cache = createCircularQueue();

    displayCache(cache); // Cache is empty
    addPage(cache, 1);
    addPage(cache, 2);
    addPage(cache, 3);
    displayCache(cache); // Cache Contents: 1 2 3
    addPage(cache, 4);
    addPage(cache, 5);
    addPage(cache, 6); // Cache is full. Page 1 replaced.
    displayCache(cache); // Cache Contents: 2 3 4 5 6

    return 0;
}

/*
This program simulates a cache replacement policy using a circular queue. It allows adding pages to the cache and
replacing pages when the cache is full. It also displays the contents of the cache. If the cache is full, it displays the
page that is being replaced.
If the cache is empty, it displays a message indicating that the cache is empty.

*/
