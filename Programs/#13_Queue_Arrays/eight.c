/*
You are given a 2D grid representing rooms, walls, and gates. Each cell in the grid can be one of the following three types:

-1: A wall or an obstacle.
0: A gate.
INF: Infinity means an empty room. We use the value 2147483647 for INF as it represents a large enough value that can be
considered as infinite.
Fill each empty room with the distance to the nearest gate. If it is impossible to reach a gate, leave the room as INF.

Note:

The starting point for each room is 0, and it is guaranteed that at least one gate exists.
You can assume that the size of the grid is at most 100x100.
*/

#include <stdio.h>
#include <stdlib.h>

#define INF 2147483647

// Structure to represent a cell in the grid
struct Cell {
    int row;
    int col;
    int distance;
};

// Function to check if a cell is valid and empty
int isValidCell(int row, int col, int numRows, int numCols, int** grid) {
    return (row >= 0 && row < numRows && col >= 0 && col < numCols && grid[row][col] == INF);
}

// Function to fill each empty room with the distance to the nearest gate
void wallsAndGates(int** rooms, int numRows, int numCols) {
    // Define the directions: up, down, left, right
    int dr[] = {-1, 1, 0, 0};
    int dc[] = {0, 0, -1, 1};

    // Create a queue to perform breadth-first search
    struct Cell* queue = (struct Cell*)malloc(numRows * numCols * sizeof(struct Cell));
    int front = 0, rear = 0;

    // Enqueue all the gates (cells with value 0) into the queue
    for (int i = 0; i < numRows; i++) {
        for (int j = 0; j < numCols; j++) {
            if (rooms[i][j] == 0) {
                queue[rear].row = i;
                queue[rear].col = j;
                queue[rear].distance = 0;
                rear++;
            }
        }
    }

    // Perform breadth-first search to fill the empty rooms with distances
    while (front < rear) {
        struct Cell curr = queue[front++];
        int currRow = curr.row;
        int currCol = curr.col;
        int currDist = curr.distance;

        // Update the distance of each neighboring empty room if it is valid
        for (int i = 0; i < 4; i++) {
            int newRow = currRow + dr[i];
            int newCol = currCol + dc[i];
            if (isValidCell(newRow, newCol, numRows, numCols, rooms)) {
                rooms[newRow][newCol] = currDist + 1;
                queue[rear].row = newRow;
                queue[rear].col = newCol;
                queue[rear].distance = currDist + 1;
                rear++;
            }
        }
    }

    free(queue);
}

// Function to print the grid
void printGrid(int** grid, int numRows, int numCols) {
    for (int i = 0; i < numRows; i++) {
        for (int j = 0; j < numCols; j++) {
            if (grid[i][j] == INF) {
                printf("INF ");
            } else {
                printf("%d ", grid[i][j]);
            }
        }
        printf("\n");
    }
}

int main() {
    int numRows = 4;
    int numCols = 4;

    int** grid = (int**)malloc(numRows * sizeof(int*));
    for (int i = 0; i < numRows; i++) {
        grid[i] = (int*)malloc(numCols * sizeof(int));
        for (int j = 0; j < numCols; j++) {
            grid[i][j] = INF;
        }
    }

    // Set the walls and gates in the grid
    grid[0][1] = -1;
    grid[1][0] = -1;
    grid[1][2] = -1;
    grid[3][3] = 0;

    printf("Initial Grid:\n");
    printGrid(grid, numRows, numCols);

    wallsAndGates(grid, numRows, numCols);

    printf("\nGrid after filling with distances:\n");
    printGrid(grid, numRows, numCols);

    // Free allocated memory
    for (int i = 0; i < numRows; i++) {
        free(grid[i]);
    }
    free(grid);

    return 0;
}
/*
This C program aims to solve the problem of filling each empty room in a grid with the distance to the nearest gate.
The grid consists of rooms, walls, and gates, represented by different values.

The program defines a structure Cell to represent a cell in the grid. It contains the row and column indices of the cell,
along with the distance from the nearest gate.

The program defines a function isValidCell that checks if a cell is valid and empty by verifying its row and column indices,
the size of the grid, and the value in the corresponding grid cell.

The program defines the wallsAndGates function, which takes a 2D array representing the grid, the number of rows and columns, as input. This function fills each empty room with the distance to the nearest gate using a breadth-first search (BFS) algorithm.

Inside the wallsAndGates function, the directions (dr and dc) for up, down, left, and right movements are defined.

A queue is created to perform the BFS. The queue is implemented as an array of Cell structures, and it is dynamically allocated
using malloc.

The function enqueues all the gate cells (cells with a value of 0) into the queue, initializing their distances as 0.

The BFS is performed by dequeuing cells from the queue and updating the distances of neighboring empty rooms if they are valid.
The updated rooms are enqueued back into the queue.

After the BFS is complete, the function frees the memory allocated for the queue.

The program defines the printGrid function to display the grid. It iterates through the grid cells and prints the distance value
or "INF" if it represents an empty room.

In the main function, a 4x4 grid is created using dynamic memory allocation. Initially, all cells are set to INF except for the
walls and gates that are explicitly defined.

The initial grid is printed using the printGrid function.

The wallsAndGates function is called to fill the grid with distances to the nearest gates.

The grid after filling with distances is printed again.

Finally, the memory allocated for the grid is freed to avoid memory leaks.
*/
