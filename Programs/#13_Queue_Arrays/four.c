/*
C program for BFS(Breadth-First Search) traversal of graph using queue data structure
*/

#include<stdio.h>
#include<stdlib.h>
#define MAX_SIZE 100

int adjMatrix[MAX_SIZE][MAX_SIZE];
int visited[MAX_SIZE];


struct queue
{
    int size;
    int f;
    int r;
    int* arr;
};

//check if queue is empty
int isEmpty(struct queue *q){
    if(q->r==q->f){
        return 1;
    }
    return 0;
}

//check if queue is full
int isFull(struct queue *q){
    if(q->r==q->size-1){
        return 1;
    }
    return 0;
}

//add element in queue
void enqueue(struct queue *q, int val){
    if(isFull(q)){
        printf("This Queue is full\n");
    }
    else{
        q->r++;
        q->arr[q->r] = val;
        // printf("Enqued element: %d\n", val);
    }
}

//remove element from queue
int dequeue(struct queue *q){
    int a = -1;
    if(isEmpty(q)){
        printf("This Queue is empty\n");
    }
    else{
        q->f++;
        a = q->arr[q->f];
    }
    return a;
}
void BFS(int start,int numVertices){
    // Initializing Queue (Array Implementation)
    struct queue q;
    q.size = 400;
    q.f = q.r = 0;
    q.arr = (int*) malloc(q.size*sizeof(int));

   // BFS Implementation
    int node;
    printf("%d ", start);
    visited[start] = 1;
    enqueue(&q, start); // Enqueue i for exploration
    while (!isEmpty(&q))
    {
        int node = dequeue(&q);
        for (int j = 0; j < numVertices; j++)
        {
            if(adjMatrix[node][j] ==1 && visited[j] == 0){
                printf("%d ", j);
                visited[j] = 1;
                enqueue(&q, j);
            }
        }
    }
}
int main(){
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
        visited[i] = 0;
    }

    int startVertex;
    printf("Enter the starting vertex: ");
    scanf("%d", &startVertex);

    BFS(startVertex, numVertices);


    return 0;
}

/*
This program performs the Breadth-First Search (BFS) algorithm on a graph represented by an adjacency matrix.
It starts from any vertex  and perform BFS traverse.
The visited array is used to keep track of the visited vertices.
*/
