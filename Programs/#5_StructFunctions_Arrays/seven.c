/*Develop an Employee Payroll System using an array of structures.
 Each employee has an employee ID and a structure representing their salary,
 which consists of the basic salary, allowances, and deductions.
 */

#include <stdio.h>

// Structure definition for Salary
struct Salary {
    float basicSalary;
    float allowances;
    float deductions;
};

// Structure definition for Employee
struct Employee {
    int employeeID;
    struct Salary salary;
};

int main() {
    // Array of structures to store employee data
    struct Employee employees[3];

    // Inputting employee information
    printf("Enter details for 3 employees:\n");
    for (int i = 0; i < 3; i++) {
        printf("Employee %d:\n", i + 1);
        printf("Employee ID: ");
        scanf("%d", &employees[i].employeeID);
        printf("Basic Salary: ");
        scanf("%f", &employees[i].salary.basicSalary);
        printf("Allowances: ");
        scanf("%f", &employees[i].salary.allowances);
        printf("Deductions: ");
        scanf("%f", &employees[i].salary.deductions);
        printf("\n");
    }

    // Displaying employee information
    printf("Employee Details:\n");
    for (int i = 0; i < 3; i++) {
        printf("Employee ID: %d\n", employees[i].employeeID);
        printf("Basic Salary: %.2f\n", employees[i].salary.basicSalary);
        printf("Allowances: %.2f\n", employees[i].salary.allowances);
        printf("Deductions: %.2f\n", employees[i].salary.deductions);
        printf("\n");
    }

    return 0;
}

/*
This program demonstrates an Employee Payroll System using an array of structures.
Each employee has an employee ID and a salary, represented by a nested structure.
The salary consists of the basic salary, allowances, and deductions.
The program allows the user to input details for 3 employees and then displays the employee information.
*/
