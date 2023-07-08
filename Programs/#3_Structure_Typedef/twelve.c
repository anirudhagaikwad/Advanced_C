
/*
    Write a program that aims to store attendance of the student using Student structure.

    Example:
    Enter student name: Riya Mhetre
    Enter student roll number: 75
    Enter student attendance: 85

    Student Details
    Name: Riya Mhetre
    Roll Number: 75
    Attendance: 85

*/

#include <stdio.h>
#include <string.h>

// Structure to store student information
struct Student {
    char name[50];
    int rollNumber;
    int attendance;
};

int main() {
    struct Student student; // Declare a variable of type 'struct Student'

    printf("Enter student name: ");
    fgets(student.name, sizeof(student.name), stdin); // Read student name from input
    student.name[strcspn(student.name, "\n")] = '\0'; // Remove the trailing newline character

    printf("Enter student roll number: ");
    scanf("%d", &student.rollNumber); // Read student roll number from input

    printf("Enter student attendance: ");
    scanf("%d", &student.attendance); // Read student attendance from input

    printf("\nStudent Details\n");
    printf("Name: %s\n", student.name); // Display student name
    printf("Roll Number: %d\n", student.rollNumber); // Display student roll number
    printf("Attendance: %d\n", student.attendance); // Display student attendance

    return 0;
}

/*
This program manages student attendance. It uses a structure called Student to store student details such as name, roll number,
and attendance.
The user is prompted to enter the student information, and the program displays the entered details.
*/
