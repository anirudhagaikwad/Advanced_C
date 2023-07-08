/* Create an Employee Hierarchy System using nested structures.
 Each employee has a name and a structure representing their manager,
 which consists of the manager's name and a nested structure representing
 the manager's address.
*/

#include <stdio.h>

// Structure definition for Address
struct Address {
    char street[50];
    char city[50];
};

// Structure definition for Manager
struct Manager {
    char name[50];
    struct Address address;
};

// Structure definition for Employee
struct Employee {
    char name[50];
    struct Manager manager;
};

int main() {
    // Employee variable declaration and initialization
    struct Employee emp1 = {
        "Dhruv Rathee",
        {"Mayank Mehta", {"123 Main St", "Delhi"}}
    };

    // Printing employee information
    printf("Employee Name: %s\n", emp1.name);
    printf("Manager Name: %s\n", emp1.manager.name);
    printf("Manager Street: %s\n", emp1.manager.address.street);
    printf("Manager City: %s\n", emp1.manager.address.city);

    return 0;
}

/*
This program demonstrates an Employee Hierarchy System using nested structures.
Each employee has a name and a manager, represented by a nested structure.
The manager has a name and an address, represented by another nested structure.
The program initializes employee data and prints the employee's name, manager's name, and manager's address.

*/
