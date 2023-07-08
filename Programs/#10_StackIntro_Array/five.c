/*
Write a C program to perform DFS traversal on Graph using stack data structure.

Example:
Enter the number of vertices: 5
Enter the adjacency matrix:
0 1 0 0 1
1 0 1 1 1
0 1 0 1 0
0 1 1 0 1
1 1 0 1 0
Enter the starting vertex: 0
DFS Traversal: 0 4 3 2 1


*/

#include <stdio.h>
#include <stdbool.h>

#define MAX_SIZE 100

int adjMatrix[MAX_SIZE][MAX_SIZE];
bool visited[MAX_SIZE];
int stack[MAX_SIZE];
int top = -1;

// Push element onto the stack
void push(int value) {
    stack[++top] = value;
}

// Pop element from the stack
int pop() {
    return stack[top--];
}

// Check if the stack is empty
bool isStackEmpty() {
    return top == -1;
}

// Perform DFS traversal using a stack
void dfs(int startVertex, int numVertices) {
    push(startVertex);
    visited[startVertex] = true;

    printf("DFS Traversal: ");

    while (!isStackEmpty()) {
        int currentVertex = pop();
        printf("%d ", currentVertex);

        for (int i = 0; i < numVertices; i++) {
            if (adjMatrix[currentVertex][i] && !visited[i]) {
                push(i);
                visited[i] = true;
            }
        }
    }

    printf("\n");
}

int main() {
    int numVertices;

    printf("Enter the number of vertices: ");
    scanf("%d", &numVertices);

    printf("Enter the adjacency matrix:\n");
    for (int i = 0; i < numVertices; i++) {
        for (int j = 0; j < numVertices; j++) {
            scanf("%d", &adjMatrix[i][j]);
        }
    }

    // Initialize visited array
    for (int i = 0; i < numVertices; i++) {
        visited[i] = false;
    }

    int startVertex;
    printf("Enter the starting vertex: ");
    scanf("%d", &startVertex);

    dfs(startVertex, numVertices);

    return 0;
}
