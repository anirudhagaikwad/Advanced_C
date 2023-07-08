/*
Write a C program to create Binary Search Tree using structure and perform inorder traversal on BST(Binary Search Tree).
*/

#include <stdio.h>
#include <stdlib.h>

// Structure to represent a node in the binary search tree
struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

// Function to create a new node with the given data
struct Node* createNode(int data) {
    // Allocate memory for the new node
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));

    // Set the data and pointers of the new node
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;

    return newNode;
}

// Function to insert a new node with the given data into the binary search tree
struct Node* insert(struct Node* root, int data) {
    // If the tree is empty, create a new node and return it as the root
    if (root == NULL) {
        return createNode(data);
    } else {
        // If the data is less than the root's data, insert it into the left subtree
        if (data < root->data) {
            root->left = insert(root->left, data);
        }
        // If the data is greater than or equal to the root's data, insert it into the right subtree
        else {
            root->right = insert(root->right, data);
        }
    }

    return root;
}

// Function to perform an inorder traversal of the binary search tree
void inorderTraversal(struct Node* root) {
    if (root != NULL) {
        // Traverse the left subtree
        inorderTraversal(root->left);

        // Print the data of the current node
        printf("%d ", root->data);

        // Traverse the right subtree
        inorderTraversal(root->right);
    }
}

int main() {
    struct Node* root = NULL;

    // Insert elements into the binary search tree
    root = insert(root, 50);
    insert(root, 30);
    insert(root, 20);
    insert(root, 40);
    insert(root, 70);
    insert(root, 60);
    insert(root, 80);

    // Perform inorder traversal and display the elements of the tree
    printf("Inorder traversal: ");
    inorderTraversal(root);

    return 0;
}
/*
 This program implements a binary search tree using structures. It defines a structure called Node to represent a node in the
 binary search tree. The program includes functions to create a new node, insert a new node into the tree, and perform an
 inorder traversal of the tree.

The createNode function creates a new node with the given data and returns it. The insert function inserts a new node with the given
data into the appropriate position in the tree based on the binary search tree property. The inorderTraversal function recursively
traverses the tree in an inorder manner, printing the data of each node.

In the main function, a binary search tree is created by inserting elements into it using the insert function. Then, the inorder traversal is performed using the inorderTraversal function to display the elements of the tree in sorted order.

Overall, this program demonstrates the creation, insertion, and inorder traversal of a binary search tree using structures in C.
*/

