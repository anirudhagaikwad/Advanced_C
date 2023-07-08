
/* Create an employee record using union to store different types of data.
The employee record can store either an integer employee ID or a string employee name.
*/

#include <stdio.h>
#include <string.h>


// Union definition for Employee Record
union Employee {
    int empID;
    char empName[50];
};

int main() {
    // Creating an employee record union
    union Employee emp;

    // Storing employee ID
    emp.empID = 101;

    // Displaying employee ID
    printf("Employee ID: %d\n", emp.empID);

    // Storing employee name
    strcpy(emp.empName, "John Doe");

    // Displaying employee name
    printf("Employee Name: %s\n", emp.empName);

    return 0;
}
/*
This program demonstrates the usage of a union to store different types of data in an employee record.
The union Employee can store either an integer employee ID or a string employee name.
The program creates an instance of the union, stores an employee ID, displays it, stores an employee name using strcpy,
and displays it.
*/
