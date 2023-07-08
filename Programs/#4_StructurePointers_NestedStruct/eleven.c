/*Implement an Employee Management System using pointers and structures.
 Each employee has an employee ID and a structure representing their details,
 which consists of the name, age, and salary.
*/

#include <stdio.h>
#include <stdlib.h>

// Structure definition for Employee
struct Employee {
    int employeeID;
    char name[50];
    int age;
    float salary;
};

int main() {
    // Creating a pointer to an employee structure
    struct Employee* empPtr;

    // Dynamically allocating memory for an employee structure
    empPtr = (struct Employee*)malloc(sizeof(struct Employee));

    // Inputting employee details using the pointer
    printf("Enter employee details:\n");
    printf("Employee ID: ");
    scanf("%d", &(empPtr->employeeID));
    printf("Name: ");
    scanf("%s", empPtr->name);
    printf("Age: ");
    scanf("%d", &(empPtr->age));
    printf("Salary: ");
    scanf("%f", &(empPtr->salary));
    printf("\n");

    // Displaying employee details using the pointer
    printf("Employee Details:\n");
    printf("Employee ID: %d\n", empPtr->employeeID);
    printf("Name: %s\n", empPtr->name);
    printf("Age: %d\n", empPtr->age);
    printf("Salary: %.2f\n", empPtr->salary);
    printf("\n");

    // Freeing the dynamically allocated memory
    free(empPtr);

    return 0;
}
/*
This program demonstrates an Employee Management System using pointers and structures.
It dynamically allocates memory for an employee structure using malloc().
The program allows the user to input employee details using the pointer and then displays the employee information.
*/
