/* Store student information using union to represent different types of data.
 The student information can store either an integer roll number or a float CGPA.
*/

#include <stdio.h>

// Union definition for Student Information
union Student {
    int rollNumber;
    float cgpa;
};

int main() {
    // Creating a student information union
    union Student student;

    // Storing roll number
    student.rollNumber = 101;

    // Displaying roll number
    printf("Roll Number: %d\n", student.rollNumber);

    // Storing CGPA
    student.cgpa = 8.5;

    // Displaying CGPA
    printf("CGPA: %.2f\n", student.cgpa);

    return 0;
}
/*
This program showcases the use of a union to store student information, including roll number and CGPA.
The union Student can hold either an integer roll number or a float CGPA.
The program creates an instance of the union, stores a roll number, displays it, stores a CGPA, and displays it.
*/
