/* Store employee salary details using a union to represent different types of salaries.
The employee salary can be stored either as an integer basic salary or as a float hourly wage.
*/

#include <stdio.h>

// Union definition for Employee Salary
union EmployeeSalary {
    int basicSalary;
    float hourlyWage;
};

int main() {
    // Creating an employee salary union
    union EmployeeSalary salary;

    // Storing basic salary
    salary.basicSalary = 5000;

    // Displaying basic salary
    printf("Basic Salary: %d\n", salary.basicSalary);

    // Storing hourly wage
    salary.hourlyWage = 10.50;

    // Displaying hourly wage
    printf("Hourly Wage: %.2f\n", salary.hourlyWage);

    return 0;
}
/*
This program showcases the use of a union to store employee salary details, including basic salary and hourly wage.
The union EmployeeSalary can hold either an integer basic salary or a float hourly wage.
The program creates an instance of the union, stores a basic salary, displays it, stores an hourly wage, and displays it.


*/
