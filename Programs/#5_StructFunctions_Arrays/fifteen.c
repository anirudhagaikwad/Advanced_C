#include <stdio.h>

/* Implement a Student Management System using functions and structures.
 Each student has a roll number and a structure representing their details,
 which consists of the name, age, and marks.
*/

// Structure definition for Student
struct Student {
    int rollNumber;
    char name[50];
    int age;
    int marks;
};

// Function to display student details
void displayStudent(struct Student std) {
    printf("Roll Number: %d\n", std.rollNumber);
    printf("Name: %s\n", std.name);
    printf("Age: %d\n", std.age);
    printf("Marks: %d\n", std.marks);
    printf("\n");
}

int main() {
    // Creating a student structure variable
    struct Student std;

    // Inputting student details
    printf("Enter student details:\n");
    printf("Roll Number: ");
    scanf("%d", &std.rollNumber);
    printf("Name: ");
    scanf("%s", std.name);
    printf("Age: ");
    scanf("%d", &std.age);
    printf("Marks: ");
    scanf("%d", &std.marks);
    printf("\n");

    // Displaying student details using the function
    printf("Student Details:\n");
    displayStudent(std);

    return 0;
}

/*
This program showcases a Student Management System using functions and structures.
Each student has a roll number and details such as name, age, and marks, represented by a structure.
The program allows the user to input student details and then displays the student information using a separate function.
*/
