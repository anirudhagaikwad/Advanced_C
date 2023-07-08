/*
You are tasked with implementing a program to simulate the Hot Potato game.
In this game, a group of players stands in a circle and passes a "hot potato" to each other.
The game continues until only one player remains, who is declared the winner.
Your goal is to create a program that can simulate this game using a circular queue.


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

// Function to add a player to the game queue
void enqueue(struct CircularQueue* queue, int player) {
    if (isFull(queue)) {
        printf("Game queue is full. Cannot add more players.\n");
        return;
    }
    if (isEmpty(queue)) {
        queue->front = 0;
    }
    queue->rear = (queue->rear + 1) % SIZE;
    queue->arr[queue->rear] = player;
    printf("Player %d joined the game.\n", player);
}

// Function to remove and return the next player from the game queue
int dequeue(struct CircularQueue* queue) {
    if (isEmpty(queue)) {
        printf("Game queue is empty. No players remaining.\n");
        return -1;
    }
    int player = queue->arr[queue->front];
    if (queue->front == queue->rear) {
        queue->front = queue->rear = -1;
    } else {
        queue->front = (queue->front + 1) % SIZE;
    }
    printf("Player %d is out of the game.\n", player);
    return player;
}

// Function to simulate the hot potato game
void hotPotatoGame(struct CircularQueue* queue, int numPlayers, int hopCount) {
    printf("Starting Hot Potato Game with %d players and hop count of %d.\n", numPlayers, hopCount);
    for (int i = 1; i <= numPlayers; i++) {
        enqueue(queue, i);
    }
    while (!isEmpty(queue)) {
        for (int i = 1; i < hopCount; i++) {
            int player = dequeue(queue);
            enqueue(queue, player);
        }
        int eliminatedPlayer = dequeue(queue);
        printf("Player %d is eliminated.\n", eliminatedPlayer);
    }
    printf("Hot Potato Game ended.\n");
}

int main() {
    struct CircularQueue* gameQueue = createCircularQueue();

    hotPotatoGame(gameQueue, 5, 3);

    return 0;
}
/*
This program simulates the hot potato game using a circular queue.
It allows adding players to the game queue and removes players from the game queue based on a hop count.
Each player is eliminated when the hop count reaches them.
The game continues until only one player remains
*/
