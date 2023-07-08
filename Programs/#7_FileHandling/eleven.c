/*
Write a program to append new content to an existing text file.
*/
#include <stdio.h>

int main() {
    FILE *file;
    char content[100];

    // Open the file in append mode
    file = fopen("text.txt", "a");
    if (file == NULL) {
        printf("Unable to open the file.\n");
        return 1;
    }

    // Prompt the user to enter new content
    printf("Enter content to append: ");
    fgets(content, sizeof(content), stdin);

    // Append the content to the file
    fprintf(file, "%s", content);

    // Close the file
    fclose(file);

    printf("Content appended successfully.\n");

    return 0;
}
/*
This program appends new content to an existing text file ("text.txt").
It opens the file in append mode, prompts the user to enter new content, and reads the input using fgets.
Then, it appends the content to the file using fprintf. Finally, it closes the file and displays a success message.
*/
