/*
Write two structures 'Date'(for DOB) and 'Employee' which contains relevant data members, nest Date structure in Employee Structure.
Print details of Employee.

*/

#include <stdio.h>

// Structure definition
struct Date {
    int day;
    int month;
    int year;
};

struct Employee {
    char name[50];
    struct Date dob;
};

int main() {
    // Structure variable declaration and initialization
    struct Employee emp1 = {
        "Ravin Agarwal",
        {10, 6, 1992}
    };

    // Printing employee information
    printf("Employee Name: %s\n", emp1.name);
    printf("Date of Birth: %d-%d-%d\n", emp1.dob.day, emp1.dob.month, emp1.dob.year);

    return 0;
}
/*
We have first struct as Date to store day,month and year of DOB.

Second struct is Employee which have two variables for name and Date structure.

We have nested Date struct in Employee struct

Finally we have printed Employee data.

*/
