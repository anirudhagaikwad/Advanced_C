/*
Create a student database using nested structures to store the name, roll number,
and marks of three subjects for multiple students. Calculate and display the
average marks for each student.
*/

#include <stdio.h>

// Structure definition for subject
struct Subject {
    char name[20];
    int marks;
};

// Structure definition for student
struct Student {
    char name[50];
    int rollNo;
    struct Subject subjects[3];
};

int main() {
    // Array of student structures
    struct Student students[3];

    // Input student information
    for (int i = 0; i < 3; i++) {
        printf("Enter name and roll number for student %d: ", i + 1);
        scanf("%s %d", students[i].name, &students[i].rollNo);
        for (int j = 0; j < 3; j++) {
            printf("Enter marks for subject %d: ", j + 1);
            scanf("%d", &students[i].subjects[j].marks);
        }
    }

    // Calculate and display average marks for each student
    printf("\nStudent Database:\n");
    for (int i = 0; i < 3; i++) {
        int totalMarks = 0;
        for (int j = 0; j < 3; j++) {
            totalMarks += students[i].subjects[j].marks;
        }
        float averageMarks = totalMarks / 3.0;
        printf("Name: %s, Roll Number: %d, Average Marks: %.2f\n",
               students[i].name, students[i].rollNo, averageMarks);
    }

    return 0;
}

/*
This program represents Student database using nested structure.
Each student have list of subjects represented by nested structure.
We have displayed all the records from student database.
*/

