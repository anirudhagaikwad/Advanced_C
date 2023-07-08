/*
Define a structure for Person with its name and age.Create a function to update the age of the Person.
*/

#include <stdio.h>

// Structure definition using typedef
typedef struct {
    char name[50];
    int age;
} Person;

// Function to update person's age
void updateAge(Person* person, int newAge) {
    person->age = newAge;
}

int main() {
    // Structure variable declaration and initialization
    Person p = {"Rakesh Sharma", 39};

    // Function call to update age
    updateAge(&p, 35);

    // Printing updated age
    printf("Person's age: %d\n", p.age);

    return 0;
}
/*
We have created alias for Struct Person.

updateAge() function updates the age of the Person.

Inside main we have called updateAge() method to update age and finally printed the updated age of the person.


*/
