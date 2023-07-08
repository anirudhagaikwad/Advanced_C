/*
Implement the merge sort algorithm to sort a singly linked list in ascending order.

Example:
Original List: 60 50 40 30 20 10
Sorted List: 10 20 30 40 50 60

*/

#include <stdio.h>
#include <stdlib.h>

// Structure to represent a node in the linked list
struct Node {
    int data;
    struct Node* next;
};

// Function to merge two sorted linked lists and return the merged list
struct Node* mergeLists(struct Node* list1, struct Node* list2) {
    if (list1 == NULL)
        return list2;
    if (list2 == NULL)
        return list1;

    struct Node* mergedList = NULL;

    if (list1->data <= list2->data) {
        mergedList = list1;
        mergedList->next = mergeLists(list1->next, list2);
    } else {
        mergedList = list2;
        mergedList->next = mergeLists(list1, list2->next);
    }

    return mergedList;
}

// Function to split the linked list into two halves
void splitList(struct Node* source, struct Node** frontRef, struct Node** backRef) {
    struct Node* slow = source;
    struct Node* fast = source->next;

    while (fast != NULL) {
        fast = fast->next;
        if (fast != NULL) {
            slow = slow->next;
            fast = fast->next;
        }
    }

    *frontRef = source;
    *backRef = slow->next;
    slow->next = NULL;
}

// Function to perform merge sort on the linked list
void mergeSort(struct Node** headRef) {
    struct Node* head = *headRef;
    struct Node* front;
    struct Node* back;

    if (head == NULL || head->next == NULL)
        return;

    splitList(head, &front, &back);

    mergeSort(&front);
    mergeSort(&back);

    *headRef = mergeLists(front, back);
}

// Function to insert a new node at the beginning of the linked list
void insertAtBeginning(struct Node** headRef, int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = *headRef;
    *headRef = newNode;
}

// Function to display the elements of the linked list
void displayList(struct Node* head) {
    struct Node* temp = head;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main() {
    struct Node* head = NULL;

    insertAtBeginning(&head, 10);
    insertAtBeginning(&head, 20);
    insertAtBeginning(&head, 30);
    insertAtBeginning(&head, 40);
    insertAtBeginning(&head, 50);
    insertAtBeginning(&head, 60);

    printf("Original List: ");
    displayList(head);

    mergeSort(&head);

    printf("Sorted List: ");
    displayList(head);

    return 0;
}

/*
This program implements the merge sort algorithm on a singly linked list. The program defines a structure Node to represent a
node in the linked list.It includes functions such as mergeLists, splitList, mergeSort, insertAtBeginning, and displayList.

The mergeLists function merges two sorted linked lists and returns the merged list. It compares the elements of the two lists and
creates a new merged list by selecting the smaller element at each step.

The splitList function divides the linked list into two halves using the slow and fast pointer technique. It sets the frontRef and
backRef pointers to the heads of the two halves.

The mergeSort function performs the merge sort algorithm on the linked list. It recursively splits the list into two halves using
the splitList function, applies the merge sort algorithm on the two halves by recursively calling itself, and then merges the sorted
halves using the mergeLists function.

The insertAtBeginning function inserts a new node at the beginning of the linked list.

The displayList function displays the elements of the linked list.

In the main function, a linked list is created by inserting elements at the beginning. The original list is displayed.
Then, the mergeSort function is called to sort the list in ascending order. Finally, the sorted list is displayed.

This program demonstrates the merge sort algorithm's ability to sort a singly linked list by recursively dividing the list into
smaller halves, sorting them individually, and then merging them back together in sorted order.

*/
