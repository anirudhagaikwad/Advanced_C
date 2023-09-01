#include <stdio.h>
#include <stdbool.h>

#define MAX_SIZE 100

struct Queue {
    int items[MAX_SIZE];
    int front;
    int rear;
};

void initialize(struct Queue *queue) {
    queue->front = -1;
    queue->rear = -1;
}

bool isEmpty(struct Queue *queue) {
    return queue->front == -1 || queue->front > queue->rear;
}

bool isFull(struct Queue *queue) {
    return queue->rear == MAX_SIZE - 1;
}

void enqueue(struct Queue *queue, int value) {
    if (isFull(queue)) {
        printf("Queue Overflow\n");
        return;
    }
    if (queue->front == -1)
        queue->front = 0;
    queue->items[++queue->rear] = value;
    printf("%d enqueued successfully\n", value);
}

int dequeue(struct Queue *queue) {
    if (isEmpty(queue)) {
        printf("Queue Underflow\n");
        return -1;
    }
    int deletedElement = queue->items[queue->front++];
    printf("%d dequeued successfully\n", deletedElement);
    return deletedElement;
}

int peek(struct Queue *queue) {
    if (isEmpty(queue)) {
        printf("Queue is empty\n");
        return -1;
    }
    int frontElement = queue->items[queue->front];
    printf("Front element: %d\n", frontElement);
    return frontElement;
}

void displayQueue(struct Queue *queue) {
    if (isEmpty(queue)) {
        printf("Queue is empty\n");
        return;
    }
    printf("Queue: ");
    for (int i = queue->front; i <= queue->rear; i++)
        printf("%d ", queue->items[i]);
    printf("\n");
}

int main() {
    struct Queue queue;
    initialize(&queue);

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
                enqueue(&queue, value);
                break;
            case 2:
                dequeue(&queue);
                break;
            case 3:
                peek(&queue);
                break;
            case 4:
                if (isEmpty(&queue))
                    printf("Queue is empty\n");
                else
                    printf("Queue is not empty\n");
                break;
            case 5:
                if (isFull(&queue))
                    printf("Queue is full\n");
                else
                    printf("Queue is not full\n");
                break;
            case 6:
                displayQueue(&queue);
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

