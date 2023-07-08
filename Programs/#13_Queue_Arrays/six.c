/*
Write a C program to implement a Queue using stack
*/

#include <stdio.h>
#include <stdlib.h>

// Structure to represent a stack
struct Stack {
    int* array;     // Array to store elements
    int top;        // Index of the top element
    int capacity;   // Maximum capacity of the stack
};

// Function to create a new stack
struct Stack* createStack(int capacity) {
    struct Stack* stack = (struct Stack*)malloc(sizeof(struct Stack));
    stack->array = (int*)malloc(capacity * sizeof(int));
    stack->top = -1;
    stack->capacity = capacity;
    return stack;
}

// Function to check if the stack is empty
int isEmpty(struct Stack* stack) {
    return stack->top == -1;
}

// Function to check if the stack is full
int isFull(struct Stack* stack) {
    return stack->top == stack->capacity - 1;
}

// Function to push an element to the stack
void push(struct Stack* stack, int item) {
    if (isFull(stack)) {
        printf("Stack Overflow\n");
        return;
    }
    stack->array[++stack->top] = item;
}

// Function to pop an element from the stack
int pop(struct Stack* stack) {
    if (isEmpty(stack)) {
        printf("Stack Underflow\n");
        return -1;
    }
    return stack->array[stack->top--];
}

// Structure to represent a queue
struct Queue {
    struct Stack* stack1;   // Stack for enqueue operation
    struct Stack* stack2;   // Stack for dequeue operation
};

// Function to create a new queue
struct Queue* createQueue(int capacity) {
    struct Queue* queue = (struct Queue*)malloc(sizeof(struct Queue));
    queue->stack1 = createStack(capacity);
    queue->stack2 = createStack(capacity);
    return queue;
}

// Function to enqueue an element into the queue
void enqueue(struct Queue* queue, int item) {
    push(queue->stack1, item);
}

// Function to dequeue an element from the queue
int dequeue(struct Queue* queue) {
    if (isEmpty(queue->stack1) && isEmpty(queue->stack2)) {
        printf("Queue is empty\n");
        return -1;
    }
    if (isEmpty(queue->stack2)) {
        while (!isEmpty(queue->stack1)) {
            int item = pop(queue->stack1);
            push(queue->stack2, item);
        }
    }
    return pop(queue->stack2);
}

int main() {
    struct Queue* queue = createQueue(5);

    enqueue(queue, 1);
    enqueue(queue, 2);
    enqueue(queue, 3);
    enqueue(queue, 4);

    printf("%d\n", dequeue(queue));   // Output: 1
    printf("%d\n", dequeue(queue));   // Output: 2

    enqueue(queue, 5);
    enqueue(queue, 6);

    printf("%d\n", dequeue(queue));   // Output: 3
    printf("%d\n", dequeue(queue));   // Output: 4
    printf("%d\n", dequeue(queue));   // Output: 5
    printf("%d\n", dequeue(queue));   // Output: 6
    printf("%d\n", dequeue(queue));   // Output: Queue is empty

    return 0;
}
/*
This program demonstrates how to implement a queue using two stacks. The Stack structure represents a stack, and the Queue structure
represents a queue. The createStack function creates a new stack, and the isEmpty and isFull functions check if
the stack is empty or full, respectively. The push and pop functions are used to insert and remove elements from the stack.

The createQueue function creates a new queue with two stacks. The enqueue function inserts an element into the queue by pushing
it onto stack1. The dequeue function removes an element from the queue by transferring elements from stack1 to stack2 and popping
the top element from stack2.

In the main function, a queue is created, and elements are enqueued and dequeued from it.
The program demonstrates the basic operations of a queue, such as enqueueing elements 1, 2, 3, 4, 5, and 6,
and dequeuing them in the order 1, 2, 3, 4, 5, and 6.
*/
