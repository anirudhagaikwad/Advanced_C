/* Implement an Employee Management System using functions and structures.
 Each employee has an employee ID and a structure representing their details,
 which consists of the name, age, and salary.
*/

#include <stdio.h>

// Structure definition for Employee
struct Employee {
    int employeeID;
    char name[50];
    int age;
    float salary;
};

// Function to display employee details
void displayEmployee(struct Employee emp) {
    printf("Employee ID: %d\n", emp.employeeID);
    printf("Name: %s\n", emp.name);
    printf("Age: %d\n", emp.age);
    printf("Salary: %.2f\n", emp.salary);
    printf("\n");
}

int main() {
    // Creating an employee structure variable
    struct Employee emp;

    // Inputting employee details
    printf("Enter employee details:\n");
    printf("Employee ID: ");
    scanf("%d", &emp.employeeID);
    printf("Name: ");
    scanf("%s", emp.name);
    printf("Age: ");
    scanf("%d", &emp.age);
    printf("Salary: ");
    scanf("%f", &emp.salary);
    printf("\n");

    // Displaying employee details using the function
    printf("Employee Details:\n");
    displayEmployee(emp);

    return 0;
}

/*
This program implements an Employee Management System using functions and structures.
Each employee has an employee ID and details such as name, age, and salary, represented by a structure.
The program allows the user to input employee details and then displays the employee information using a separate function.
*/
