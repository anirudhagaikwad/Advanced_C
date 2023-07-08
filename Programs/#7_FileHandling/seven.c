/*
Write a program to reverse the contents of a text file.
*/
#include <stdio.h>

int main() {
    FILE *file;
    char ch;
    long fileSize, i;

    // Open the file in read mode
    file = fopen("text.txt", "r");
    if (file == NULL) {
        printf("Unable to open the file.\n");
        return 1;
    }

    // Get the file size
    fseek(file, 0, SEEK_END);
    fileSize = ftell(file);

    // Read and print the file contents in reverse order
    for (i = fileSize - 1; i >= 0; i--) {
        fseek(file, i, SEEK_SET);
        ch = fgetc(file);
        printf("%c", ch);
    }

    // Close the file
    fclose(file);

    return 0;
}
/*
This program reverses the contents of a text file ("text.txt").
It opens the file in read mode and determines the file size using fseek and ftell functions.
Then, it reads and prints the file contents character by character in reverse order by positioning the file pointer using fseek and reading characters using fgetc.
Finally, it closes the file.
*/
