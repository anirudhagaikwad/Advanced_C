/*
Write a program to count the number of lines in a text file.
*/
#include <stdio.h>

int main() {
    FILE *file;
    char ch;
    int lineCount = 0;

    // Open the file in read mode
    file = fopen("text.txt", "r");
    if (file == NULL) {
        printf("Unable to open the file.\n");
        return 1;
    }

    // Count the number of lines
    while ((ch = fgetc(file)) != EOF) {
        if (ch == '\n') {
            lineCount++;
        }
    }

    // Close the file
    fclose(file);

    printf("Number of lines: %d\n", lineCount);

    return 0;
}
/*
This program counts the number of lines in a text file ("text.txt").
It opens the file in read mode and initializes a line count variable to 0.
Then, it reads each character from the file and increments the line count whenever it encounters a newline character.
Finally, it closes the file and prints the total number of lines.
*/
