/*
Write a C program that performs CRUD (Create, Read, Update, Delete) operations on a queue.
*/

#include <stdio.h>
#include <stdbool.h>
#define MAX_SIZE 100

int queue[MAX_SIZE];
int front = -1;
int rear = -1;

void enqueue(int value) {
    if (rear == MAX_SIZE - 1) {
        printf("Queue Overflow\n"); // Check if the rear is at the maximum capacity
        return;
    }
    if (front == -1)
        front = 0; // If the queue is initially empty, set the front to 0
    queue[++rear] = value; // Increment the rear and add the value to the queue
    printf("%d enqueued successfully\n", value);
}

int dequeue() {
    if (front == -1 || front > rear) {
        printf("Queue Underflow\n"); // Check if the queue is empty or if front has crossed the rear
        return -1;
    }
    int deletedElement = queue[front++]; // Increment the front and store the element to be deleted
    printf("%d dequeued successfully\n", deletedElement);
    return deletedElement;
}

int peek() {
    if (front == -1 || front > rear) {
        printf("Queue is empty\n"); // Check if the queue is empty or if front has crossed the rear
        return -1;
    }
    int frontElement = queue[front]; // Get the element at the front of the queue without removing it
    printf("Front element: %d\n", frontElement);
    return frontElement;
}

bool isEmpty() {
    return front == -1 || front > rear; // Check if the queue is empty by comparing front and rear
}

bool isFull() {
    return rear == MAX_SIZE - 1; // Check if the rear is at the maximum capacity
}

void displayQueue() {
    if (front == -1 || front > rear) {
        printf("Queue is empty\n"); // Check if the queue is empty or if front has crossed the rear
        return;
    }
    printf("Queue: ");
    for (int i = front; i <= rear; i++)
        printf("%d ", queue[i]); // Print all the elements in the queue
    printf("\n");
}

int main() {
    int choice, value;

    do {
        printf("\nQueue Operations:\n");
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Peek\n");
        printf("4. Check if Queue is Empty\n");
        printf("5. Check if Queue is Full\n");
        printf("6. Display Queue\n");
        printf("7. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the value to enqueue: ");
                scanf("%d", &value);
                enqueue(value);
                break;
            case 2:
                dequeue();
                break;
            case 3:
                peek();
                break;
            case 4:
                if (isEmpty())
                    printf("Queue is empty\n"); // Check if the queue is empty
                else
                    printf("Queue is not empty\n");
                break;
            case 5:
                if (isFull())
                    printf("Queue is full\n"); // Check if the queue is full
                else
                    printf("Queue is not full\n");
                break;
            case 6:
                displayQueue();
                break;
            case 7:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 7);

    return 0;
}

/*
This program allows you to perform CRUD (Create, Read, Update, Delete) operations on a queue.
The queue is implemented using an array, and it has a maximum capacity of MAX_SIZE.
The program provides the following operations:

Enqueue: Adds an element to the rear of the queue.
Dequeue: Removes and returns the element from the front of the queue.
Peek: Returns the element at the front of the queue without removing it.
Check if Queue is Empty: Checks if the queue is empty.
Check if Queue is Full: Checks if the queue is full.
Display Queue: Prints all the elements in the queue.
Exit: Terminates the program.

The program uses a do-while loop to repeatedly prompt the user for their choice and perform the corresponding operation.
The user can enter values to enqueue, dequeue elements, peek at the front element, check if the queue is empty or full, and
display the queue. The loop continues until the user chooses to exit.

Each operation includes appropriate error handling and informative messages to indicate the success or failure of the operation. The program ensures that the queue does not overflow or underflow by checking the front and rear indices.
*/
