/*
 Implement a linked list in C and insert elements at the beginning of the list.
*/

#include <stdio.h>
#include <stdlib.h>

// Structure to represent a node in the linked list
struct Node {
    int data;
    struct Node* next;
};

// Function to insert a new node at the beginning of the linked list
void insertAtBeginning(struct Node** head, int data) {
    // Allocate memory for the new node
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));

    // Set the data and next pointer of the new node
    newNode->data = data;
    newNode->next = *head;

    // Make the new node the new head of the linked list
    *head = newNode;
}

// Function to display the elements of the linked list
void display(struct Node* head) {
    // Traverse the linked list and print the data of each node
    struct Node* temp = head;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main() {
    struct Node* head = NULL;

    // Insert elements at the beginning of the linked list
    insertAtBeginning(&head, 10);
    insertAtBeginning(&head, 20);
    insertAtBeginning(&head, 30);

    // Display the elements of the linked list
    printf("Linked List: ");
    display(head);

    return 0;
}


/*This program demonstrates the implementation of a linked list using structures. The structure Node represents a node in the linked list,
 consisting of an integer data and a pointer to the next node. The program includes two functions: insertAtBeginning and display.

The insertAtBeginning function inserts a new node with the given data at the beginning of the linked list.
It allocates memory for the new node, sets the data and next pointer, and makes the new node the new head of the list by updating
the head pointer.

The display function traverses the linked list from the head node and prints the data of each node. It starts with the head node,
iterates through the list using the next pointers, and prints the data of each node until reaching the end of the list.

In the main function, a linked list is created and elements are inserted at the beginning of the list using the insertAtBeginning
function. Then, the display function is called to print the elements of the list.

Overall, this program demonstrates the creation of a linked list, insertion of elements at the beginning,
and display of the elements using structures in C.

*/
