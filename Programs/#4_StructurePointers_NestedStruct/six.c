/* Implement an Employee Management System using nested structures.
 Each employee has a name and a structure representing their address,
 which consists of street, city, and pin code.
*/


#include <stdio.h>

// Structure definition for Address
struct Address {
    char street[50];
    char city[50];
    int pinCode;
};

// Structure definition for Employee
struct Employee {
    char name[50];
    struct Address address;
};

int main() {
    // Employee variable declaration and initialization
    struct Employee emp1 = {
        "Sarang Desai",
        {"123 Sadashiv Peth", "Pune", 12345}
    };

    // Printing employee information
    printf("Employee Name: %s\n", emp1.name);
    printf("Street: %s\n", emp1.address.street);
    printf("City: %s\n", emp1.address.city);
    printf("Pin Code: %d\n", emp1.address.pinCode);

    return 0;
}

/*
This program represents an Employee Management System using nested structures.
Each employee has a name and an address, which is represented by a nested structure.
The program demonstrates the declaration and initialization of employee data and prints the employee's name and address information.

*/
