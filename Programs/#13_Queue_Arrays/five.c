/*
You are given a snake and ladder board represented by an array moves[] of size N, where N is the total number of cells on the board.
Each cell can be considered as a vertex on the board. The value of moves[i] represents the cell number to which a snake or ladder at
cell i takes you. If there is no snake or ladder from a cell i, then moves[i] is set to -1.

Your task is to find the minimum number of dice throws required to reach the last cell (cell N-1) from the first cell (cell 0).
You can only move to an adjacent cell (i.e., the cell with a number 1 greater than the current cell) if there is no snake or ladder at
that cell.
If there is a snake or ladder at a cell, you can directly jump to the cell indicated by the snake or ladder.

*/
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <limits.h>

// An entry in the queue used in BFS
struct queueEntry
{
    int v; // Vertex number
    int dist; // Distance of this vertex from source
};

// Function to create a new queue entry
struct queueEntry createQueueEntry(int v, int dist)
{
    struct queueEntry qe;
    qe.v = v;
    qe.dist = dist;
    return qe;
}

// Function to perform BFS and find the minimum number of dice throws
int getMinDiceThrows(int move[], int N)
{
// Create an array to mark visited cells
    bool visited[N];
    for (int i = 0; i < N; i++)
        visited[i] = false;

// Create a queue for BFS
    struct queueEntry queue[N];
    int front = 0, rear = 0;

// Mark the node 0 as visited and enqueue it
    visited[0] = true;
    queue[rear++] = createQueueEntry(0, 0);

// Perform BFS
    struct queueEntry qe;
    while (front != rear)
    {
        qe = queue[front++];
        int v = qe.v; // Vertex number

        // If the front vertex is the destination vertex, we are done
        if (v == N - 1)
            break;

        // Enqueue the adjacent vertices (or cell numbers reachable through a dice throw)
        for (int j = v + 1; j <= (v + 6) && j < N; ++j)
        {
            // If this cell is already visited, then ignore
            if (!visited[j])
            {
                // Calculate its distance and mark it as visited
                struct queueEntry a = createQueueEntry(0, (qe.dist + 1));
                visited[j] = true;

                // Check if there is a snake or ladder at 'j'
                // If so, update the destination vertex accordingly
                if (move[j] != -1)
                    a.v = move[j];
                else
                    a.v = j;
                queue[rear++] = a;
            }
        }
    }

// Return the distance of the last vertex in the queue
    return qe.dist;
}

int main()
{
   //board of 30 blocks
    int N = 30;
    int moves[N];
    for (int i = 0; i < N; i++)
        moves[i] = -1;

// Ladders
    moves[2] = 21;
    moves[4] = 7;
    moves[10] = 25;
    moves[19] = 28;

// Snakes
    moves[26] = 0;
    moves[20] = 8;
    moves[16] = 3;
    moves[18] = 6;

    printf("Min Dice throws required is %d", getMinDiceThrows(moves, N));

    return 0;
}
/*
This C program finds the minimum number of dice throws required to reach the last cell from the first cell in a given snake and ladder board.
It uses a Breadth-First Search (BFS) approach to find the shortest path.

The getMinDiceThrows function takes an array move[] and the size N as input, where N represents the number of cells on the board.
The move[] array stores the information about snakes and ladders. If there is no snake or ladder from a cell i, then move[i] is set
to -1. Otherwise, move[i] contains the cell number to which the snake or ladder at i takes.

The algorithm starts by initializing an array visited[] to mark visited cells and a queue queue[] to perform BFS.
The node 0 (representing the first cell) is marked as visited and enqueued with a distance of 0.

The BFS begins by dequeuing a vertex from the queue. If the dequeued vertex is the destination vertex (last cell),
the algorithm breaks from the loop. Otherwise, it enqueues the adjacent vertices (or cell numbers reachable through a dice throw)
that are not visited yet. It calculates the distance and marks them as visited. If there is a snake or ladder at the adjacent vertex,
it updates the destination vertex accordingly.

Once the BFS completes, the distance of the last vertex is returned as the minimum number of dice throws required.

In the main function, a sample board with snakes and ladders is constructed, and the getMinDiceThrows function is called.
The minimum number of dice throws is then printed.
*/
