#include <stdio.h>
#define MAX_SIZE 100

int queue[MAX_SIZE];
int front = -1;
int rear = -1;

int isEmpty() {
    return front == -1;
}

int isFull() {
    return rear == MAX_SIZE - 1;
}

void enqueue(int value) {
    if (isFull()) {
        printf("Queue is full. Cannot enqueue.\n");
        return;
    }
    if (isEmpty()) {
        front = rear = 0;
    } else {
        rear++;
    }
    queue[rear] = value;
    printf("Element %d enqueued to the queue.\n", value);
}

void dequeue() {
    if (isEmpty()) {
        printf("Queue is empty. Cannot dequeue.\n");
        return;
    }
    printf("Element %d dequeued from the queue.\n", queue[front]);
    if (front == rear) {
        front = rear = -1;
    } else {
        front++;
    }
}

void display() {
    if (isEmpty()) {
        printf("Queue is empty.\n");
        return;
    }
    printf("Queue elements: ");
    for (int i = front; i <= rear; i++) {
        printf("%d ", queue[i]);
    }
    printf("\n");
}

int main() {
    enqueue(10);
    enqueue(20);
    enqueue(30);
    display();
    dequeue();
    display();
    return 0;
}

/*
In this code, we're implementing a basic queue using an array and providing operations like enqueue, dequeue, and display.

Here's a breakdown of the code:

We define the queue array, and the front and rear indices to keep track of the front and rear of the queue.
The isEmpty function checks if the queue is empty by verifying if front is -1.
The isFull function checks if the queue is full by checking if rear is equal to MAX_SIZE - 1.
The enqueue function adds elements to the rear of the queue:
It checks if the queue is full using isFull function.
If the queue is empty, it sets both front and rear to 0.
Otherwise, it increments rear and assigns the value to the rear index of the array.
The dequeue function removes elements from the front of the queue:
It checks if the queue is empty using isEmpty function.
If the queue has only one element, it resets front and rear to -1.
Otherwise, it increments front.
The display function displays the queue elements using the indices from front to rear.
In the main function, we enqueue three elements (10, 20, and 30), display the queue, dequeue an element, and display the updated queue.
This code demonstrates the basic functionality of a queue data structure using an array.

*/
