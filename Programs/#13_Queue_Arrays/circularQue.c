/*
 circular queue is a data structure that is similar to a regular queue but with a fixed size. It overcomes one of the limitations of a standard queue, where the elements cannot be inserted if the queue is full, by allowing the queue to wrap around and reuse space that becomes available after dequeuing elements. In a circular queue, when you reach the end of the queue, the next element is added at the beginning, effectively creating a circular behavior.

*/



#include <stdio.h>
#include <stdbool.h>

#define MAX_SIZE 5 // Maximum size of the circular queue

struct CircularQueue {
    int items[MAX_SIZE];
    int front, rear;
};

// Initialize the circular queue
void initQueue(struct CircularQueue* queue) {
    queue->front = -1;
    queue->rear = -1;
}

// Check if the circular queue is empty
bool isEmpty(struct CircularQueue* queue) {
    return (queue->front == -1 && queue->rear == -1);
}

// Check if the circular queue is full
bool isFull(struct CircularQueue* queue) {
    return ((queue->rear + 1) % MAX_SIZE == queue->front);
}

// Enqueue an element into the circular queue
void enqueue(struct CircularQueue* queue, int value) {
    if (isFull(queue)) {
        printf("Queue is full. Cannot enqueue.\n");
        return;
    }
    if (isEmpty(queue)) {
        queue->front = 0;
        queue->rear = 0;
    } else {
        queue->rear = (queue->rear + 1) % MAX_SIZE;
    }
    queue->items[queue->rear] = value;
}

// Dequeue an element from the circular queue
int dequeue(struct CircularQueue* queue) {
    int value;
    if (isEmpty(queue)) {
        printf("Queue is empty. Cannot dequeue.\n");
        return -1; // Return a sentinel value
    }
    value = queue->items[queue->front];
    if (queue->front == queue->rear) {
        // If only one element is in the queue
        queue->front = -1;
        queue->rear = -1;
    } else {
        queue->front = (queue->front + 1) % MAX_SIZE;
    }
    return value;
}

int main() {
    struct CircularQueue queue;
    initQueue(&queue);

    enqueue(&queue, 1);
    enqueue(&queue, 2);
    enqueue(&queue, 3);

    printf("Dequeued: %d\n", dequeue(&queue));
    printf("Dequeued: %d\n", dequeue(&queue));

    enqueue(&queue, 4);
    enqueue(&queue, 5);

    printf("Dequeued: %d\n", dequeue(&queue));
    printf("Dequeued: %d\n", dequeue(&queue));
    printf("Dequeued: %d\n", dequeue(&queue));

    return 0;
}

/*
In this example, we create a circular queue using a structure that contains an array of items, along with front and rear indices. The initQueue function initializes the queue, isEmpty checks if it's empty, and isFull checks if it's full. enqueue and dequeue are used to add and remove elements from the circular queue, respectively
*/

/*
Circular queues have various applications in computer science and real-world scenarios where a fixed-size, efficient, and circular data structure is required. Some common use cases for circular queues include:

1. **Buffer Management**: Circular queues are often used in buffering systems. For example, in a printer queue, incoming print jobs are placed in a circular queue. When the printer finishes a job, it dequeues the next job to be printed.

2. **Task Scheduling**: Operating systems often use circular queues for scheduling tasks. In a round-robin scheduling algorithm, tasks are assigned a fixed time slice and placed in a circular queue. The CPU executes tasks in a cyclic order, giving each task a chance to run.

3. **Data Buffering**: In data communication systems, circular queues can be used to buffer data during transmission. For example, in serial communication, data is sent or received in chunks and stored in a circular queue until it can be processed.

4. **Simulation**: Circular queues are used in simulations, such as discrete-event simulations, to manage events that occur over time. Events are scheduled and processed in a circular manner.

5. **Keyboard Input Buffer**: In many computer systems, keyboard input is managed using a circular queue. Keystrokes are stored in a buffer and processed one by one.

6. **Printing Spooling**: In print spooling systems, jobs are stored in a circular queue until they are printed. This ensures that the printer can continuously process print jobs without waiting for one job to complete before starting the next.

7. **Memory Management**: In memory allocation algorithms like the "circular first fit," circular queues can be used to manage and allocate memory blocks efficiently.

8. **Caching**: Circular queues can be employed in cache replacement policies like the Clock or Second Chance algorithm to manage cache entries efficiently.

9. **History Storage**: Circular queues can be used to store a history of recent events, measurements, or data points. When the queue is full, new data replaces the oldest data, ensuring a fixed-size history.

10. **Resource Sharing**: Circular queues can be used in scenarios where resources are shared among multiple processes. Processes can enqueue and dequeue resource requests, ensuring fair access.

11. **Traffic Management**: In networking and traffic management systems, circular queues can be used to manage incoming and outgoing network packets to ensure efficient data flow.

12. **Task Management in Real-Time Systems**: In real-time systems, tasks with fixed execution periods can be managed using circular queues to ensure tasks are executed at predefined intervals.

In essence, circular queues are versatile data structures that find applications in scenarios where elements need to be managed in a circular manner within a fixed-size container. They provide an efficient way to manage and utilize limited resources, schedule tasks, and buffer data.


*/
