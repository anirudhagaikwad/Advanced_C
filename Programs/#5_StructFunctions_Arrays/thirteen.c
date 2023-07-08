#include <stdio.h>

/* Implement a Library Book Management System using functions and structures.
 Each book has a book ID and a structure representing its details,
 which consists of the title, author, and year of publication.
*/

// Structure definition for Book
struct Book {
    int bookID;
    char title[100];
    char author[50];
    int year;
};

// Function to display book details
void displayBook(struct Book book) {
    printf("Book ID: %d\n", book.bookID);
    printf("Title: %s\n", book.title);
    printf("Author: %s\n", book.author);
    printf("Year of Publication: %d\n", book.year);
    printf("\n");
}

int main() {
    // Creating a book structure variable
    struct Book book;

    // Inputting book details
    printf("Enter book details:\n");
    printf("Book ID: ");
    scanf("%d", &book.bookID);
    printf("Title: ");
    scanf("%s", book.title);
    printf("Author: ");
    scanf("%s", book.author);
    printf("Year of Publication: ");
    scanf("%d", &book.year);
    printf("\n");

    // Displaying book details using the function
    printf("Book Details:\n");
    displayBook(book);

    return 0;
}
/*
 This program demonstrates a Library Book Management System using functions and structures.
 Each book has a book ID and details such as title, author, and year of publication, represented by a structure.
 The program allows the user to input book details and then displays the book information using a separate function.
*/
