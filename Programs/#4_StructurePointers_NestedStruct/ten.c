/* Develop a Student Enrollment System using nested structures.
 Each student has a name and a structure representing their enrollment,
 which consists of the enrollment number and a nested structure representing
 the enrollment date.
 */

#include <stdio.h>

// Structure definition for Date
struct Date {
    int day;
    int month;
    int year;
};

// Structure definition for Enrollment
struct Enrollment {
    int enrollmentNumber;
    struct Date enrollmentDate;
};

// Structure definition for Student
struct Student {
    char name[50];
    struct Enrollment enrollment;
};

int main() {
    // Student variable declaration and initialization
    struct Student stu1 = {
        "Alice",
        {12345, {1, 1, 2023}}
    };

    // Printing student information
    printf("Student Name: %s\n", stu1.name);
    printf("Enrollment Number: %d\n", stu1.enrollment.enrollmentNumber);
    printf("Enrollment Date: %d-%d-%d\n", stu1.enrollment.enrollmentDate.day,
           stu1.enrollment.enrollmentDate.month, stu1.enrollment.enrollmentDate.year);

    return 0;
}
/*
This program illustrates a Student Enrollment System using nested structures.
Each student has a name and an enrollment, represented by a nested structure.
The enrollment consists of an enrollment number and a date, represented by another nested structure.
The program initializes student data and prints the student's name, enrollment number, and enrollment date.

*/
