/*
Create array of student structure. Print student details by looping on array of structure.
*/

#include <stdio.h>

// Structure definition
struct Student {
    char name[50];
    int rollNo;
};

int main() {
    // Array of structures
    struct Student students[3];

    // Input student information
    for (int i = 0; i < 3; i++) {
        printf("Enter name and roll number for student %d: ", i + 1);
        scanf("%s %d", students[i].name, &students[i].rollNo);
    }

    // Printing student information
    printf("\nStudent Information:\n");
    for (int i = 0; i < 3; i++) {
        printf("Name: %s, Roll Number: %d\n", students[i].name, students[i].rollNo);
    }

    return 0;
}
/*
we have Student structure which contains name and ROll no. as data members.

Inside main we have created array of structure.

We have used for loop to input student information and print it.

*/

