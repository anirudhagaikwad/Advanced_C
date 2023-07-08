/*
Write a file handling program in C that performs CRUD (Create, Read, Update, Delete) operations on a file using functions.
The program allows the user to interactively perform operations on a student database file.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure to represent a student
struct Student {
    int rollNumber;
    char name[50];
    int age;
};

// Function to create a new student record
void createStudentRecord() {
    struct Student student;
    FILE *file;

    // Open the file in append mode
    file = fopen("students.dat", "ab");
    if (file == NULL) {
        printf("Unable to open the file.\n");
        return;
    }

    // Prompt the user to enter student details
    printf("Enter roll number: ");
    scanf("%d", &student.rollNumber);
    printf("Enter name: ");
    scanf(" %[^\n]", student.name);
    printf("Enter age: ");
    scanf("%d", &student.age);

    // Write the student record to the file
    fwrite(&student, sizeof(struct Student), 1, file);

    // Close the file
    fclose(file);

    printf("Student record created successfully.\n");
}

// Function to read and display all student records
void readStudentRecords() {
    struct Student student;
    FILE *file;

    // Open the file in read mode
    file = fopen("students.dat", "rb");
    if (file == NULL) {
        printf("Unable to open the file.\n");
        return;
    }

    printf("Student Records:\n");

    // Read and display each student record
    while (fread(&student, sizeof(struct Student), 1, file) == 1) {
        printf("Roll Number: %d\n", student.rollNumber);
        printf("Name: %s\n", student.name);
        printf("Age: %d\n", student.age);
        printf("---------------\n");
    }

    // Close the file
    fclose(file);
}

// Function to update a student record
void updateStudentRecord() {
    int rollNumber;
    struct Student student;
    FILE *file;
    long int position;

    // Open the file in read-write mode
    file = fopen("students.dat", "r+b");
    if (file == NULL) {
        printf("Unable to open the file.\n");
        return;
    }

    // Prompt the user to enter the roll number of the student to update
    printf("Enter the roll number of the student to update: ");
    scanf("%d", &rollNumber);

    // Find the position of the student record in the file
    while (fread(&student, sizeof(struct Student), 1, file) == 1) {
        if (student.rollNumber == rollNumber) {
            position = ftell(file) - sizeof(struct Student);
            break;
        }
    }

    // Move the file pointer to the position of the student record
    fseek(file, position, SEEK_SET);

    // Prompt the user to enter the updated student details
    printf("Enter updated name: ");
    scanf(" %[^\n]", student.name);
    printf("Enter updated age: ");
    scanf("%d", &student.age);

    // Write the updated student record to the file
    fwrite(&student, sizeof(struct Student), 1, file);

    // Close the file
    fclose(file);

    printf("Student record updated successfully.\n");
}

// Function to delete a student record
void deleteStudentRecord() {
    int rollNumber;
    struct Student student;
    FILE *file, *tempFile;

    // Open the file in read mode
    file = fopen("students.dat", "rb");
    if (file == NULL) {
        printf("Unable to open the file.\n");
        return;
    }

    // Open a temporary file in write mode
    tempFile = fopen("temp.dat", "wb");
    if (tempFile == NULL) {
        printf("Unable to create temporary file.\n");
        fclose(file);
        return;
    }

    // Prompt the user to enter the roll number of the student to delete
    printf("Enter the roll number of the student to delete: ");
    scanf("%d", &rollNumber);

    // Copy all student records except the one to be deleted to the temporary file
    while (fread(&student, sizeof(struct Student), 1, file) == 1) {
        if (student.rollNumber != rollNumber) {
            fwrite(&student, sizeof(struct Student), 1, tempFile);
        }
    }

    // Close both files
    fclose(file);
    fclose(tempFile);

    // Delete the original file
    remove("students.dat");

    // Rename the temporary file to the original file name
    if (rename("temp.dat", "students.dat") != 0) {
        printf("Unable to delete the student record.\n");
        return;
    }

    printf("Student record deleted successfully.\n");
}

int main() {
    int choice;

    do {
        printf("\n------ Student Database Menu ------\n");
        printf("1. Create a new student record\n");
        printf("2. Read all student records\n");
        printf("3. Update a student record\n");
        printf("4. Delete a student record\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                createStudentRecord();
                break;
            case 2:
                readStudentRecords();
                break;
            case 3:
                updateStudentRecord();
                break;
            case 4:
                deleteStudentRecord();
                break;
            case 5:
                printf("Exiting program.\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
                break;
        }
    } while (choice != 5);

    return 0;
}
/*
This program allows the user to perform CRUD operations on a student database file ("students.dat"). It provides a menu-driven interface where the user can choose options to create a new student record, read all student records, update a student record, or delete a student record.

The program uses a structure Student to represent a student, which includes fields for roll number, name, and age. The program defines functions for each operation: createStudentRecord to create a new record, readStudentRecords to read and display all records, updateStudentRecord to update an existing record, and deleteStudentRecord to delete a record.

The main function presents a menu to the user and executes the corresponding function based on the user's choice. The program utilizes file handling functions like fopen, fclose, fwrite, fread, ftell, fseek, and remove to perform file operations.

This program provides a basic framework for managing a student database file using file handling in C. You can further enhance it by adding validation, searching, sorting, and other functionalities as per your requirements.
*/
