/* Develop a program to calculate the grade of a student using functions and structures.
 Each student has a roll number and a structure representing their marks,
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
    int rollNumber;
    struct Marks marks;
};

// Function to calculate the grade
char calculateGrade(struct Student std) {
    int totalMarks = std.marks.subject1 + std.marks.subject2 + std.marks.subject3;
    float averageMarks = totalMarks / 3.0;

    if (averageMarks >= 90) {
        return 'A';
    } else if (averageMarks >= 80) {
        return 'B';
    } else if (averageMarks >= 70) {
        return 'C';
    } else if (averageMarks >= 60) {
        return 'D';
    } else {
        return 'F';
    }
}

int main() {
    // Creating a student structure variable
    struct Student std;

    // Inputting student details
    printf("Enter student details:\n");
    printf("Roll Number: ");
    scanf("%d", &std.rollNumber);
    printf("Marks (Subject 1): ");
    scanf("%d", &std.marks.subject1);
    printf("Marks (Subject 2): ");
    scanf("%d", &std.marks.subject2);
    printf("Marks (Subject 3): ");
    scanf("%d", &std.marks.subject3);
    printf("\n");

    // Calculating and displaying the grade using the function
    printf("Student Grade: %c\n", calculateGrade(std));

    return 0;
}

/*
This program calculates the grade of a student using functions and structures.
Each student has a roll number and marks in three subjects, represented by a structure.
The program allows the user to input student details and then calculates and displays the student's grade based on
the average marks using a separate function.
*/
