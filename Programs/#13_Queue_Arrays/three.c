/*
Write a  C program create a binary tree.
Do level order traversal for the binary tree using queue data structure.
*/

#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

struct Node* insert(struct Node* root, int data) {
    if (root == NULL)
        return createNode(data);
    if (data < root->data)
        root->left = insert(root->left, data);
    else if (data > root->data)
        root->right = insert(root->right, data);
    return root;
}

void levelOrderTraversal(struct Node* root) {
    if (root == NULL)
        return;

    int front = 0, rear = 0;
    struct Node* queue[100];

    queue[rear++] = root;
    while (front < rear) {
        struct Node* current = queue[front++];
        printf("%d ", current->data);

        if (current->left)
            queue[rear++] = current->left;
        if (current->right)
            queue[rear++] = current->right;
    }
}

int main() {
    struct Node* root = NULL;
    root = insert(root, 50);
    insert(root, 30);
    insert(root, 20);
    insert(root, 40);
    insert(root, 70);
    insert(root, 60);
    insert(root, 80);

    printf("Level Order Traversal: ");
    levelOrderTraversal(root);
    printf("\n");

    return 0;
}

/*
 This program demonstrates the usage of a queue for performing a level order traversal of a binary tree.
 The program includes functions to create a new node, insert nodes into the binary tree, and perform the
 level order traversal. The main function creates a binary tree and calls the levelOrderTraversal function to print
 the elements of the tree in level order using a queue.
*/
