/*
 Implement a program to manage student records in a school using nested structures.
 The program should store the school's name and details of two students,
 including their names, roll numbers, cities, and states.
*/

#include <stdio.h>

struct Address {
    char city[50];
    char state[50];
};

struct Student {
    char name[50];
    int rollNumber;
    struct Address address;
};

struct School {
    char name[100];
    struct Student students[100];
};

int main() {
    struct School school;
    strcpy(school.name, "XYZ School");

    // Creating and initializing the first student
    struct Student student1;
    strcpy(student1.name, "John Doe");
    student1.rollNumber = 1;
    strcpy(student1.address.city, "New York");
    strcpy(student1.address.state, "New York");

    // Creating and initializing the second student
    struct Student student2;
    strcpy(student2.name, "Jane Smith");
    student2.rollNumber = 2;
    strcpy(student2.address.city, "Los Angeles");
    strcpy(student2.address.state, "California");

    // Assigning the students to the school's student array
    school.students[0] = student1;
    school.students[1] = student2;

    // Displaying the school name and student details
    printf("School Name: %s\n", school.name);
    printf("Student 1: %s, Roll Number: %d, City: %s, State: %s\n", school.students[0].name, school.students[0].rollNumber, school.students[0].address.city, school.students[0].address.state);
    printf("Student 2: %s, Roll Number: %d, City: %s, State: %s\n", school.students[1].name, school.students[1].rollNumber, school.students[1].address.city, school.students[1].address.state);

    return 0;
}

/*
The program utilizes nested structures to manage student records in a school. It defines three structures: Address, Student, and School.
The Address structure holds the city and state details. The Student structure includes the student's name, roll number, and an Address
structure for their address. The School structure contains the school's name and an array of Student structures.

In the main function, a School structure named school is created and initialized with the school's name. Two Student structures,
student1 and student2, are also created and initialized with their respective details, including names, roll numbers, and addresses.
The Student structures are then assigned to the students array within the school structure.

Finally, the program displays the school name and the details of the two students, including their names, roll numbers, cities, and
states.
*/
