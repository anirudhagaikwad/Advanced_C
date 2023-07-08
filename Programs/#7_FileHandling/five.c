/*
Write a program to count the number of words in a text file.
*/
#include <stdio.h>

int main() {
    FILE *file;
    char ch;
    int wordCount = 0;

    // Open the file in read mode
    file = fopen("text.txt", "r");
    if (file == NULL) {
        printf("Unable to open the file.\n");
        return 1;
    }

    // Count the number of words
    while ((ch = fgetc(file)) != EOF) {
        if (ch == ' ' || ch == '\n' || ch == '\t') {
            wordCount++;
        }
    }

    // Close the file
    fclose(file);

    printf("Number of words: %d\n", wordCount);

    return 0;
}
/*
This program counts the number of words in a text file ("text.txt").
It opens the file in read mode and initializes a word count variable to 0. Then, it reads each character from the file and increments the word count whenever it encounters a space, newline, or tab character.
Finally, it closes the file and prints the total number of words.
*/
