/*
Implement the queue data structure using linked list.
*/

#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Queue {
    struct Node* front;
    struct Node* rear;
};

// Function to create a new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Function to create an empty queue
struct Queue* createQueue() {
    struct Queue* queue = (struct Queue*)malloc(sizeof(struct Queue));
    queue->front = NULL;
    queue->rear = NULL;
    return queue;
}

// Function to check if the queue is empty
int isEmpty(struct Queue* queue) {
    return queue->front == NULL;
}

// Function to enqueue an element
void enqueue(struct Queue* queue, int data) {
    struct Node* newNode = createNode(data);
    if (isEmpty(queue)) {
        queue->front = queue->rear = newNode;

    }
    else{
        queue->rear->next = newNode;
       queue->rear = newNode;
    }
    printf("%d enqueued successfully\n", data);
}

// Function to dequeue an element
int dequeue(struct Queue* queue) {
    if (isEmpty(queue)) {
        printf("Queue is empty\n");
        return -1;
    }
    struct Node* temp = queue->front;
    int deletedElement = temp->data;
    queue->front = queue->front->next;
    if (queue->front == NULL)
        queue->rear = NULL;
    free(temp);
    printf("%d dequeued successfully\n", deletedElement);
    return deletedElement;
}

// Function to display the elements in the queue
void displayQueue(struct Queue* queue) {
    if (isEmpty(queue)) {
        printf("Queue is empty\n");
        return;
    }
    struct Node* current = queue->front;
    printf("Queue: ");
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

int main() {
    struct Queue* queue = createQueue();
    enqueue(queue, 10);
    enqueue(queue, 20);
    enqueue(queue, 30);
    enqueue(queue, 40);

    displayQueue(queue);

    dequeue(queue);
    dequeue(queue);

    displayQueue(queue);

    return 0;
}
/*
This program demonstrates the implementation of a queue using a linked list.
It includes functions to create a new node, create an empty queue, check if the queue is empty,
enqueue an element, dequeue an element, and display the elements in the queue. The program initializes the queue,
enqueues elements, displays the queue, dequeues elements, and displays the updated queue. The linked list implementation
allows dynamic allocation of memory for each node.
*/
