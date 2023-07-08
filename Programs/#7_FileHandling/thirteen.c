/*
Write a C program that manages a library system, allowing users to perform operations such as adding books,
searching for books, and displaying the book catalog using file handling.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Book {
    char title[100];
    char author[100];
    int year;
};

void addBook() {
    struct Book book;
    FILE *file;

    file = fopen("library.txt", "ab");
    if (file == NULL) {
        printf("Unable to open the file.\n");
        return;
    }

    printf("Enter book title: ");
    scanf(" %[^\n]", book.title);
    printf("Enter author name: ");
    scanf(" %[^\n]", book.author);
    printf("Enter publication year: ");
    scanf("%d", &book.year);

    fwrite(&book, sizeof(struct Book), 1, file);

    fclose(file);

    printf("Book added successfully.\n");
}

void searchBook() {
    char keyword[100];
    struct Book book;
    FILE *file;

    file = fopen("library.txt", "rb");
    if (file == NULL) {
        printf("Unable to open the file.\n");
        return;
    }

    printf("Enter a keyword to search: ");
    scanf(" %[^\n]", keyword);

    int found = 0;

    while (fread(&book, sizeof(struct Book), 1, file) == 1) {
        if (strstr(book.title, keyword) != NULL || strstr(book.author, keyword) != NULL) {
            printf("Title: %s\n", book.title);
            printf("Author: %s\n", book.author);
            printf("Publication Year: %d\n", book.year);
            printf("-----------------\n");
            found = 1;
        }
    }

    if (!found) {
        printf("No books found matching the keyword.\n");
    }

    fclose(file);
}

void displayCatalog() {
    struct Book book;
    FILE *file;

    file = fopen("library.txt", "rb");
    if (file == NULL) {
        printf("Unable to open the file.\n");
        return;
    }

    printf("Library Catalog:\n");

    while (fread(&book, sizeof(struct Book), 1, file) == 1) {
        printf("Title: %s\n", book.title);
        printf("Author: %s\n", book.author);
        printf("Publication Year: %d\n", book.year);
        printf("-----------------\n");
    }

    fclose(file);
}

int main() {
    int choice;

    do {
        printf("\n------ Library System Menu ------\n");
        printf("1. Add a book\n");
        printf("2. Search for a book\n");
        printf("3. Display the book catalog\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addBook();
                break;
            case 2:
                searchBook();
                break;
            case 3:
                displayCatalog();
                break;
            case 4:
                printf("Exiting program.\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
                break;
        }
    } while (choice != 4);

    return 0;
}

/*
In this scenario, the program manages a library system. It allows users to add books to the library, search for books
based on keywords (such as book title or author name), and display the entire book catalog
*/
