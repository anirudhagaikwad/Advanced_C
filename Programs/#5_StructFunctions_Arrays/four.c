/*
Create array of structure and access it with alternative name.
*/


#include <stdio.h>

// Structure definition
typedef struct {
    char name[50];
    int rollNo;
} Student;

int main() {
    // Typedef for array of structures
    typedef Student Students[3];

    // Array of structures
    Students students = {
        {"Ram", 1},
        {"Laxman", 2},
        {"Sita", 3}
    };

    // Printing student information
    printf("Student Information:\n");
    for (int i = 0; i < 3; i++) {
        printf("Name: %s, Roll Number: %d\n", students[i].name, students[i].rollNo);
    }

    return 0;
}

/*
In above program we have created alias name for array of structure 'Student'
*/
