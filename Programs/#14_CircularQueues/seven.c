/*
You have been tasked with implementing a program for a ticket booking system.
The system allows users to book tickets and cancel them if needed. Your goal is to create a program that
can simulate this ticket booking system using a circular queue.

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

// Function to book a ticket
void bookTicket(struct CircularQueue* queue, int ticketNumber) {
    if (isFull(queue)) {
        printf("Ticket booking system is full. Please try again later.\n");
        return;
    }
    if (isEmpty(queue)) {
        queue->front = 0;
    }
    queue->rear = (queue->rear + 1) % SIZE;
    queue->arr[queue->rear] = ticketNumber;
    printf("Ticket %d booked successfully.\n", ticketNumber);
}

// Function to cancel a ticket
void cancelTicket(struct CircularQueue* queue) {
    if (isEmpty(queue)) {
        printf("Ticket booking system is empty. No tickets to cancel.\n");
        return;
    }
    int ticketNumber = queue->arr[queue->front];
    if (queue->front == queue->rear) {
        queue->front = queue->rear = -1;
    } else {
        queue->front = (queue->front + 1) % SIZE;
    }
    printf("Ticket %d canceled successfully.\n", ticketNumber);
}


int main() {
    struct CircularQueue* ticketQueue = createCircularQueue();

    bookTicket(ticketQueue, 1);
    bookTicket(ticketQueue, 2);
    bookTicket(ticketQueue, 3);
    cancelTicket(ticketQueue);
    bookTicket(ticketQueue, 4);
    bookTicket(ticketQueue, 5);
    bookTicket(ticketQueue, 6); // Ticket booking system is full
    cancelTicket(ticketQueue);
    cancelTicket(ticketQueue);
    cancelTicket(ticketQueue);
    cancelTicket(ticketQueue);
    cancelTicket(ticketQueue); // Ticket booking system is empty

    return 0;
}
/*
This program simulates a ticket booking system using a circular queue. It allows booking tickets and canceling tickets.
If the ticket booking system is full, it displays a message to try again later.
If the ticket booking system is empty, it displays a message indicating no tickets to cancel.

*/
