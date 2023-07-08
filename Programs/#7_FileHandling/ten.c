/*
Write a program to search for a specific word in a text file.
*/
#include <stdio.h>
#include <string.h>

int main() {
    FILE *file;
    char word[50], buffer[100];
    int lineNumber = 1;

    // Open the file in read mode
    file = fopen("text.txt", "r");
    if (file == NULL) {
        printf("Unable to open the file.\n");
        return 1;
    }

    // Prompt the user to enter a word to search for
    printf("Enter a word to search: ");
    scanf("%s", word);

    // Search for the word in each line
    while (fgets(buffer, sizeof(buffer), file) != NULL) {
        if (strstr(buffer, word) != NULL) {
            printf("Word '%s' found at line %d\n", word, lineNumber);
        }
        lineNumber++;
    }

    // Close the file
    fclose(file);

    return 0;
}
/*
This program searches for a specific word in a text file ("text.txt"). It opens the file in read mode and prompts the user to enter a word to search for.
Then, it reads each line from the file using fgets and checks if the word exists in the line using strstr.
If a match is found, it prints the word and the line number.
Finally, it closes the file.
*/
