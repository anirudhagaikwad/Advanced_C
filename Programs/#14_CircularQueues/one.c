/*
Write a C program to implement circular queue using array.

Constants:
MAX_SIZE = 5
*/

#include <stdio.h>
#define MAX_SIZE 5

int queue[MAX_SIZE];
int front = -1;
int rear = -1;

// Function to check if the queue is empty
int isEmpty() {
    return front == -1;
}

// Function to check if the queue is full
int isFull() {
    return (front == 0 && rear == MAX_SIZE - 1) || (front == rear + 1);
}

// Function to enqueue an element
void enqueue(int value) {
    if (isFull()) {
        printf("Queue is full\n");
        return;
    }
    if (front == -1)
        front = 0;
    rear = (rear + 1) % MAX_SIZE;
    queue[rear] = value;
    printf("%d enqueued successfully\n", value);
}

// Function to dequeue an element
int dequeue() {
    if (isEmpty()) {
        printf("Queue is empty\n");
        return -1;
    }
    int deletedElement = queue[front];
    if (front == rear)  // Reset front and rear when queue becomes empty
        front = rear = -1;
    else
        front = (front + 1) % MAX_SIZE;
    printf("%d dequeued successfully\n", deletedElement);
    return deletedElement;
}

// Function to display the elements in the queue
void displayQueue() {
    if (isEmpty()) {
        printf("Queue is empty\n");
        return;
    }
    printf("Queue: ");
    int i = front;
    while (i != rear) {
        printf("%d ", queue[i]);
        i = (i + 1) % MAX_SIZE;
    }
    printf("%d\n", queue[rear]);
}

int main() {
    enqueue(10);
    enqueue(20);
    enqueue(30);
    enqueue(40);
    enqueue(50);

    displayQueue();

    dequeue();

    displayQueue();

    enqueue(60);

    displayQueue();

    return 0;
}

/*
This program demonstrates the implementation of a circular queue using an array.
It includes functions to enqueue, dequeue, and display the elements in the queue.
The program initializes the queue, enqueues elements, displays the queue, dequeues elements, and displays the updated queue.
The circular nature of the queue allows efficient utilization of the available space.
*/
