/*
Write a C program that demonstrates the usage of ftell and fseek functions.
The program reads data from a binary file containing student records and allows the user to navigate through the records using file position indicators.
*/
#include <stdio.h>
#include <stdlib.h>

struct Student {
    int rollNumber;
    char name[50];
    int age;
};

void displayStudentRecord(FILE *file, long int position) {
    struct Student student;

    // Move the file pointer to the given position
    fseek(file, position, SEEK_SET);

    // Read the student record at the given position
    fread(&student, sizeof(struct Student), 1, file);

    // Display the student record
    printf("Roll Number: %d\n", student.rollNumber);
    printf("Name: %s\n", student.name);
    printf("Age: %d\n", student.age);
    printf("----------------\n");
}

int main() {
    FILE *file;
    long int position;
    int choice;

    file = fopen("students.dat", "rb");
    if (file == NULL) {
        printf("Unable to open the file.\n");
        return 1;
    }

    do {
        printf("\n------ Student Navigation Menu ------\n");
        printf("1. Display current student record\n");
        printf("2. Move to next student record\n");
        printf("3. Move to previous student record\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                // Get the current position using ftell
                position = ftell(file);

                // Display the student record at the current position
                displayStudentRecord(file, position);
                break;
            case 2:
                // Move the file pointer forward by the size of a student record
                fseek(file, sizeof(struct Student), SEEK_CUR);

                // Get the new position using ftell
                position = ftell(file);

                // Display the student record at the new position
                displayStudentRecord(file, position);
                break;
            case 3:
                // Move the file pointer backward by twice the size of a student record
                fseek(file, -2 * sizeof(struct Student), SEEK_CUR);

                // Get the new position using ftell
                position = ftell(file);

                // Display the student record at the new position
                displayStudentRecord(file, position);
                break;
            case 4:
                printf("Exiting program.\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
                break;
        }
    } while (choice != 4);

    fclose(file);

    return 0;
}
/*
In this scenario, the program interacts with a binary file ("students.dat") containing student records. It allows the user to navigate through the records using the ftell and fseek functions.

The program defines a structure Student to represent a student, which includes fields for the roll number, name, and age. The function displayStudentRecord displays the student record at a given position in the file.

The main function presents a menu to the user with options to display the current student record, move to the next student record, move to the previous student record, or exit the program. For each choice, the program utilizes ftell to get the current file position, fseek to move the file pointer, and displayStudentRecord to display the student record at the new position.

By using ftell and fseek, the program allows the user to navigate through the student records in the file, displaying one record at a time. It demonstrates the usage of file position indicators to track the current position and perform relative movements within the file.

This program can be extended to include additional functionalities, such as searching for specific student records or modifying existing records based on user requirements.

*/

