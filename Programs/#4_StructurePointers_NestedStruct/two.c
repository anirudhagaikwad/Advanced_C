/*
Create structure for Person with data name and age.
Access structure data like name and age using pointer to structure.

*/

#include <stdio.h>

// Structure definition
struct Person {
    char name[50];
    int age;
};

int main() {
    // Structure variable declaration
    struct Person person1 = {"Mihir Sathe", 30};

    // Pointer to structure
    struct Person* ptr;

    // Assigning address of structure to pointer
    ptr = &person1;

    // Accessing structure members using pointer
    printf("Person Name: %s\n", ptr->name);
    printf("Person Age: %d\n", ptr->age);

    return 0;
}
/*
We have struct for Person.

Inside main we have created variable of Person struct and pointer variable of type Person struct.

Assign structure variable to structure pointer variable and print its data using arrow operator.

*/
