
/* Build a Library Management System using nested structures.
 Each book has a title and a structure representing the author,
 which consists of the author's first name and last name.
 */

#include <stdio.h>

// Structure definition for Author
struct Author {
    char firstName[50];
    char lastName[50];
};

// Structure definition for Book
struct Book {
    char title[100];
    struct Author author;
};

int main() {
    // Book variable declaration and initialization
    struct Book book1 = {
        "The Catcher in the Rye",
        {"J.D.", "Salinger"}
    };

    // Printing book information
    printf("Book Title: %s\n", book1.title);
    printf("Author: %s %s\n", book1.author.firstName, book1.author.lastName);

    return 0;
}

/*
This program implements a Library Management System using nested structures.
Each book has a title and an author, represented by a nested structure.
The program initializes book data and prints the book's title and author's name.
*/
