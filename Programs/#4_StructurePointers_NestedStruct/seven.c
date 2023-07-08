/*
 Create a Student Transcript System using nested structures.
 Each student has a name and a structure representing their marks,
 which consists of marks in three subjects.
*/

#include <stdio.h>

// Structure definition for Marks
struct Marks {
    int subject1;
    int subject2;
    int subject3;
};

// Structure definition for Student
struct Student {
    char name[50];
    struct Marks marks;
};

int main() {
    // Student variable declaration and initialization
    struct Student stu1 = {
        "Joya",
        {85, 90, 95}
    };

    // Printing student information
    printf("Student Name: %s\n", stu1.name);
    printf("Subject 1: %d\n", stu1.marks.subject1);
    printf("Subject 2: %d\n", stu1.marks.subject2);
    printf("Subject 3: %d\n", stu1.marks.subject3);

    return 0;
}

/*
This program simulates a Student Transcript System using nested structures.
Each student has a name and marks in three subjects, represented by a nested structure.
The program initializes student data and displays the student's name and marks in each subject.
*/
