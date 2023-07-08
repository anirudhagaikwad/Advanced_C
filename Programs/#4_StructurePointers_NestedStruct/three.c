/*
Create structure and access structure data using Dynamic Allocation of Structure.
*/

#include <stdio.h>
#include <stdlib.h>

// Structure definition
struct Student {
    char name[50];
    int rollNo;
};

int main() {
    // Pointer to structure
    struct Student* ptr;

    // Dynamic allocation of structure
    ptr = (struct Student*)malloc(sizeof(struct Student));

    // Input student information
    printf("Enter name and roll number: ");
    scanf("%s %d", ptr->name, &ptr->rollNo);

    // Printing student information
    printf("Name: %s, Roll Number: %d\n", ptr->name, ptr->rollNo);

    // Freeing allocated memory
    free(ptr);

    return 0;
}
/*

We have pointer to struct Student which is dynamically allocated using malloc() function.

We have accessed struct data using -> operator.

Finally we have released memory allocated to struct pointer using free() function.
free() takes pointer as parameter and release the memory used by that pointer.

*/
